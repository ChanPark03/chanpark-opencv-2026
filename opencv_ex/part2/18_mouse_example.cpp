// 마우스를 따라다니는 사각형 박스를 만드세요.
// 마우스 오른쪽 버튼을 누르면 사각형 박스의 색깔이 랜덤으로 변경되도록 하세요.
// 왼쪽 버튼을 누르고 움직이면 선(사각형 박스의 색깔과 같은) 선이 그어지도록 하세요.
// 휠 버튼을 누르면(스포이드 기능) 마우스 위치의 픽셀 정보로 사각형 박스의 색깔을 변화 시키세요.

#include "colors.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

const String WINDOW_NAME = "Mouse Color Studio";
const Size CANVAS_SIZE(960, 620);

struct AppState
{
    Mat paintLayer;
    Mat paintMask;
    Mat sampleImage;
    Point mouse{CANVAS_SIZE.width / 2, CANVAS_SIZE.height / 2};
    Point previous;
    Scalar boxColor{55, 210, 255};
    bool drawing = false;
    bool sampled = false;
    int colorPulse = 0;
};

Scalar randomColor()
{
    static RNG rng((uint64)getTickCount());
    return Scalar(rng.uniform(35, 256), rng.uniform(35, 256), rng.uniform(35, 256));
}

Point clampPoint(Point pt)
{
    pt.x = clamp(pt.x, 0, CANVAS_SIZE.width - 1);
    pt.y = clamp(pt.y, 0, CANVAS_SIZE.height - 1);
    return pt;
}

Scalar textColorFor(const Scalar &color)
{
    double brightness = 0.114 * color[0] + 0.587 * color[1] + 0.299 * color[2];
    return brightness > 150 ? Color::Black : Color::White;
}

Mat makeBackground(int tick)
{
    Mat bg(CANVAS_SIZE, CV_8UC3);

    for (int y = 0; y < bg.rows; y++)
    {
        double ratio = (double)y / (bg.rows - 1);
        Vec3b *row = bg.ptr<Vec3b>(y);

        for (int x = 0; x < bg.cols; x++)
        {
            double wave = (sin((x + tick * 2) * 0.012) + 1.0) * 0.5;
            row[x] = Vec3b(
                saturate_cast<uchar>(34 + 28 * ratio + 16 * wave),
                saturate_cast<uchar>(42 + 34 * (1.0 - ratio)),
                saturate_cast<uchar>(58 + 38 * ratio + 18 * wave));
        }
    }

    for (int x = 0; x < bg.cols; x += 40)
        line(bg, Point(x, 0), Point(x, bg.rows), Scalar(58, 64, 80), 1, LINE_AA);

    for (int y = 0; y < bg.rows; y += 40)
        line(bg, Point(0, y), Point(bg.cols, y), Scalar(58, 64, 80), 1, LINE_AA);

    for (int i = 0; i < 38; i++)
    {
        int x = (i * 83 + tick * 2) % bg.cols;
        int y = (i * 47 + tick) % bg.rows;
        int radius = 1 + (i + tick / 12) % 3;
        Scalar glow(95 + i % 60, 110 + i % 70, 135 + i % 80);
        circle(bg, Point(x, y), radius, glow, FILLED, LINE_AA);
    }

    return bg;
}

void drawPaint(Mat &frame, const AppState &state)
{
    Mat shadow(frame.size(), frame.type(), Scalar::all(0));
    state.paintLayer.copyTo(shadow, state.paintMask);
    addWeighted(frame, 1.0, shadow, 0.22, 0, frame);
    state.paintLayer.copyTo(frame, state.paintMask);
}

void paintStroke(AppState &state, Point from, Point to)
{
    Scalar shadowColor(state.boxColor[0] * 0.35, state.boxColor[1] * 0.35, state.boxColor[2] * 0.35);

    line(state.paintLayer, from, to, shadowColor, 15, LINE_AA);
    line(state.paintLayer, from, to, state.boxColor, 7, LINE_AA);
    circle(state.paintLayer, to, 4, state.boxColor, FILLED, LINE_AA);

    line(state.paintMask, from, to, Scalar(255), 17, LINE_AA);
    circle(state.paintMask, to, 9, Scalar(255), FILLED, LINE_AA);
}

void drawCursorBox(Mat &frame, const AppState &state)
{
    Point center = clampPoint(state.mouse);
    int pulse = state.colorPulse;
    int boxSize = 72 + pulse / 2;
    Rect box(center.x - boxSize / 2, center.y - boxSize / 2, boxSize, boxSize);
    box &= Rect(0, 0, frame.cols, frame.rows);

    if (box.empty())
        return;

    rectangle(frame, box + Point(7, 7), Scalar(8, 10, 18), FILLED, LINE_AA);
    rectangle(frame, box, state.boxColor, FILLED, LINE_AA);

    Rect inner(box.x + 8, box.y + 8, max(1, box.width - 16), max(1, box.height - 16));
    rectangle(frame, inner, Scalar(255, 255, 255), 2, LINE_AA);
    rectangle(frame, box, Scalar(20, 20, 28), 2, LINE_AA);

    line(frame, Point(center.x - 18, center.y), Point(center.x + 18, center.y), textColorFor(state.boxColor), 2, LINE_AA);
    line(frame, Point(center.x, center.y - 18), Point(center.x, center.y + 18), textColorFor(state.boxColor), 2, LINE_AA);

    for (int r = boxSize / 2 + 8; r <= boxSize / 2 + 28; r += 10)
        circle(frame, center, r + pulse / 3, Scalar(state.boxColor[0] * 0.35, state.boxColor[1] * 0.35, state.boxColor[2] * 0.35), 1, LINE_AA);
}

void drawHud(Mat &frame, const AppState &state)
{
    Rect panel(18, 18, 430, 92);
    rectangle(frame, panel + Point(5, 5), Scalar(8, 10, 18), FILLED, LINE_AA);
    rectangle(frame, panel, Scalar(245, 245, 250), FILLED, LINE_AA);
    rectangle(frame, panel, Scalar(35, 38, 48), 2, LINE_AA);

    Rect swatch(34, 37, 56, 56);
    rectangle(frame, swatch, state.boxColor, FILLED, LINE_AA);
    rectangle(frame, swatch, Scalar(25, 25, 30), 2, LINE_AA);

    string bgr = "BGR (" + to_string((int)state.boxColor[0]) + ", " +
                 to_string((int)state.boxColor[1]) + ", " +
                 to_string((int)state.boxColor[2]) + ")";

    putText(frame, "Mouse Color Studio", Point(106, 48), FONT_HERSHEY_DUPLEX, 0.74, Scalar(25, 25, 34), 1, LINE_AA);
    putText(frame, bgr, Point(106, 76), FONT_HERSHEY_SIMPLEX, 0.55, Scalar(44, 51, 65), 1, LINE_AA);
    putText(frame, "Left-drag: draw   Right: random   Middle: eyedropper   ESC: exit",
            Point(106, 99), FONT_HERSHEY_SIMPLEX, 0.42, Scalar(70, 76, 88), 1, LINE_AA);

    if (state.sampled)
        putText(frame, "sampled", Point(366, 48), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 115, 0), 1, LINE_AA);
}

void onMouse(int event, int x, int y, int flags, void *userdata)
{
    AppState *state = (AppState *)userdata;
    Point current = clampPoint(Point(x, y));
    state->mouse = current;

    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        state->drawing = true;
        state->previous = current;
        paintStroke(*state, current, current);
        break;

    case EVENT_LBUTTONUP:
        state->drawing = false;
        break;

    case EVENT_MOUSEMOVE:
        if (state->drawing)
        {
            paintStroke(*state, state->previous, current);
            state->previous = current;
        }
        break;

    case EVENT_RBUTTONDOWN:
        state->boxColor = randomColor();
        state->sampled = false;
        state->colorPulse = 24;
        break;

    case EVENT_MBUTTONDOWN:
    case EVENT_MOUSEWHEEL:
    case EVENT_MOUSEHWHEEL:
        if (!state->sampleImage.empty())
        {
            Vec3b pixel = state->sampleImage.at<Vec3b>(current);
            state->boxColor = Scalar(pixel[0], pixel[1], pixel[2]);
            state->sampled = true;
            state->colorPulse = 24;
        }
        break;
    }
}

int main()
{
    AppState state;
    state.paintLayer = Mat(CANVAS_SIZE, CV_8UC3, Scalar::all(0));
    state.paintMask = Mat(CANVAS_SIZE, CV_8UC1, Scalar::all(0));

    namedWindow(WINDOW_NAME);
    setMouseCallback(WINDOW_NAME, onMouse, &state);

    int tick = 0;

    while (true)
    {
        Mat frame = makeBackground(tick);
        drawPaint(frame, state);
        state.sampleImage = frame.clone();

        drawCursorBox(frame, state);
        drawHud(frame, state);

        imshow(WINDOW_NAME, frame);

        int key = waitKey(1000 / 60);
        if (key == 27)
            break;
        if (key == 'c' || key == 'C')
        {
            state.paintLayer.setTo(Scalar::all(0));
            state.paintMask.setTo(Scalar::all(0));
        }

        state.colorPulse = max(0, state.colorPulse - 1);
        tick++;
    }

    destroyAllWindows();
    return 0;
}
