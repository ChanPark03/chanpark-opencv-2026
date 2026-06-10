# chanpark-opencv-2026

C++과 OpenCV를 공부하기 위한 학습 저장소입니다.

이 README는 짧은 소개 문서가 아니라, 공부한 주제를 다시 찾기 위한
**hyperlinked study map**입니다. 원하는 주제를 클릭하면 관련 설명과 예제
파일로 바로 이동할 수 있게 구성했습니다.

Notion note:

- [OpenCV study note](https://carpal-polonium-c12.notion.site/1-C-OpenCV-375541956f7a81fab32fd726e323eb7b)

## Quick Table of Contents

- [Study Roadmap](#study-roadmap)
- [Repository Structure](#repository-structure)
- [Subject Index](#subject-index)
- [Build and Run](#build-and-run)
- [OpenCV Basics](#opencv-basics)
- [Image and Mat](#image-and-mat)
- [Video and GStreamer](#video-and-gstreamer)
- [Drawing and Text](#drawing-and-text)
- [Keyboard Mouse and UI](#keyboard-mouse-and-ui)
- [FileStorage and Data](#filestorage-and-data)
- [Mask and ROI](#mask-and-roi)
- [Brightness Contrast and Histogram](#brightness-contrast-and-histogram)
- [Arithmetic and Filtering](#arithmetic-and-filtering)
- [Data Assets](#data-assets)
- [More Study Topics](#more-study-topics)
- [README Maintenance Notes](#readme-maintenance-notes)

## Study Roadmap

이 저장소는 아래 흐름으로 보면 좋습니다.

| Step | Topic | Main folder | Goal |
| --- | --- | --- | --- |
| 1 | C++ OpenCV 시작 | [`opencv_ex/part1`](opencv_ex/part1) | OpenCV include, project build, window 출력 흐름을 익힙니다. |
| 2 | `Mat` 기본 조작 | [`opencv_ex/part1`](opencv_ex/part1) | image matrix, pixel, ROI, copy, clone을 이해합니다. |
| 3 | 입력 영상과 비디오 | [`opencv_ex/part1`](opencv_ex/part1), [`opencv_ex/part2`](opencv_ex/part2) | image/video load, camera/video capture, save를 연습합니다. |
| 4 | 그리기와 텍스트 | [`opencv_ex/part2`](opencv_ex/part2) | line, rectangle, circle, marker, text, freetype을 사용합니다. |
| 5 | 사용자 입력 | [`opencv_ex/part2`](opencv_ex/part2) | keyboard, mouse callback, trackbar를 연결합니다. |
| 6 | 파일 저장과 데이터 | [`opencv_ex/part2`](opencv_ex/part2), [`data`](data) | XML/YAML/JSON 스타일 데이터 저장과 읽기를 다룹니다. |
| 7 | 마스크와 영상 합성 | [`opencv_ex/part2`](opencv_ex/part2) | mask image, ROI, selective copy를 이해합니다. |
| 8 | 밝기, 대비, 히스토그램 | [`opencv_ex/part3`](opencv_ex/part3) | pixel value 조정, contrast stretching, histogram equalization을 익힙니다. |
| 9 | 산술 연산과 필터링 | [`opencv_ex/part3`](opencv_ex/part3) | bitwise operation, blur, sharpening, bilateral filter를 실험합니다. |

## Repository Structure

| Path | Purpose |
| --- | --- |
| [`opencv_ex`](opencv_ex) | CMake 프로젝트 루트입니다. Part별 C++ 예제를 빌드합니다. |
| [`opencv_ex/CMakeLists.txt`](opencv_ex/CMakeLists.txt) | `part1/*.cpp`, `part2/*.cpp` 파일을 각각 실행 파일로 만드는 CMake 설정입니다. |
| [`opencv_ex/part1`](opencv_ex/part1) | OpenCV 기본 실행, `Mat`, image/video input 예제입니다. |
| [`opencv_ex/part2`](opencv_ex/part2) | drawing, font, keyboard, mouse, trackbar, FileStorage, mask 예제입니다. |
| [`opencv_ex/part3`](opencv_ex/part3) | 밝기/대비/히스토그램, 영상 산술 연산, 공간 필터링 예제입니다. |
| [`opencv_ex/part1/colors.hpp`](opencv_ex/part1/colors.hpp) | part1에서 사용하는 BGR 색상 상수입니다. |
| [`opencv_ex/part2/colors.hpp`](opencv_ex/part2/colors.hpp) | part2에서 사용하는 BGR 색상 상수입니다. |
| [`opencv_ex/part3/colors.hpp`](opencv_ex/part3/colors.hpp) | part3에서 사용하는 BGR 색상 상수입니다. |
| [`data`](data) | 예제에서 읽고 쓰는 이미지, 비디오, 폰트, cascade, JSON/XML 데이터입니다. |
| [`build`](build) | CMake build output입니다. 생성 파일이므로 학습 파일 목록에는 넣지 않습니다. |
| [`build/logs`](build/logs), [`opencv_ex/build/logs`](opencv_ex/build/logs) | build tool이 남기는 로그 폴더입니다. 생성물이라 주요 학습 파일로 다루지 않습니다. |

생성 파일은 학습 대상이 아닙니다. 예를 들어 `build/`, 실행 파일, `.o`,
`CMakeFiles/`, 저장 테스트로 만들어진 출력 파일은 실행 또는 빌드 중 만들어지는
결과물이므로 README의 주요 학습 파일로 다루지 않습니다.

## Subject Index

| Subject | Files | What to study |
| --- | --- | --- |
| [Build and Run](#build-and-run) | [`opencv_ex/CMakeLists.txt`](opencv_ex/CMakeLists.txt) | CMake, target, OpenCV link |
| [OpenCV Basics](#opencv-basics) | [`01_helloWorld.cpp`](opencv_ex/part1/01_helloWorld.cpp), [`02_basicOP.cpp`](opencv_ex/part1/02_basicOP.cpp) | include, namespace, image load, window |
| [Image and Mat](#image-and-mat) | [`03_matOP.cpp`](opencv_ex/part1/03_matOP.cpp), [`04_inputArray.cpp`](opencv_ex/part1/04_inputArray.cpp), [`05_matOp2.cpp`](opencv_ex/part1/05_matOp2.cpp) | `Mat`, matrix operation, input/output array |
| [Video and GStreamer](#video-and-gstreamer) | [`06_video.cpp`](opencv_ex/part1/06_video.cpp), [`07_gstreamer.cpp`](opencv_ex/part1/07_gstreamer.cpp), [`08_gstreamer_ex.cpp`](opencv_ex/part1/08_gstreamer_ex.cpp), [`09_videoSave.cpp`](opencv_ex/part2/09_videoSave.cpp) | video capture, stream, save |
| [Drawing and Text](#drawing-and-text) | [`10_drawing.cpp`](opencv_ex/part2/10_drawing.cpp), [`11_drawing_example.cpp`](opencv_ex/part2/11_drawing_example.cpp), [`12_drawing_example2.cpp`](opencv_ex/part2/12_drawing_example2.cpp), [`13_font.cpp`](opencv_ex/part2/13_font.cpp), [`14_freetype.cpp`](opencv_ex/part2/14_freetype.cpp) | shapes, animation, text, font |
| [Keyboard Mouse and UI](#keyboard-mouse-and-ui) | [`15_keyboard.cpp`](opencv_ex/part2/15_keyboard.cpp), [`16_tickmeter.cpp`](opencv_ex/part2/16_tickmeter.cpp), [`17_mouse.cpp`](opencv_ex/part2/17_mouse.cpp), [`18_mouse_example.cpp`](opencv_ex/part2/18_mouse_example.cpp), [`19_trackbar.cpp`](opencv_ex/part2/19_trackbar.cpp) | input event, callback, FPS, UI control |
| [FileStorage and Data](#filestorage-and-data) | [`20_filestorage.cpp`](opencv_ex/part2/20_filestorage.cpp), [`21_filestorage2.cpp`](opencv_ex/part2/21_filestorage2.cpp) | XML/YAML/JSON style storage |
| [Mask and ROI](#mask-and-roi) | [`22_mask.cpp`](opencv_ex/part2/22_mask.cpp), [`mask.bmp`](data/mask.bmp), [`mask_plane.bmp`](data/mask_plane.bmp) | mask, ROI, image composition |
| [Brightness Contrast and Histogram](#brightness-contrast-and-histogram) | [`23_brightness.cpp`](opencv_ex/part3/23_brightness.cpp), [`24_contrast.cpp`](opencv_ex/part3/24_contrast.cpp), [`25_histogram.cpp`](opencv_ex/part3/25_histogram.cpp) | brightness, contrast, histogram |
| [Arithmetic and Filtering](#arithmetic-and-filtering) | [`26_arithmetic.cpp`](opencv_ex/part3/26_arithmetic.cpp), [`27_embossing.cpp`](opencv_ex/part3/27_embossing.cpp), [`28_blurr.cpp`](opencv_ex/part3/28_blurr.cpp), [`29_sharpening.cpp`](opencv_ex/part3/29_sharpening.cpp), [`30_bilateral.cpp`](opencv_ex/part3/30_bilateral.cpp) | bitwise operation, convolution, blur, sharpen |

## Build and Run

이 프로젝트는 CMake로 빌드합니다. `opencv_ex/CMakeLists.txt`는 `part1`,
`part2`, `part3`의 `.cpp` 파일을 각각 하나의 실행 파일 target으로 만듭니다.

기본 빌드 흐름:

```bash
cmake -S opencv_ex -B build
cmake --build build
```

특정 예제만 빌드:

```bash
cmake --build build --target 18_mouse_example
```

실행:

```bash
./build/18_mouse_example
```

공부할 때 중요한 점:

- 파일 이름이 `18_mouse_example.cpp`이면 target 이름은 `18_mouse_example`입니다.
- 새 part 폴더를 추가하면 `CMakeLists.txt`의 `file(GLOB ...)` 목록에도 추가해야 합니다.
- OpenCV window 예제는 GUI display가 가능한 환경에서 실행해야 합니다.
- `ESC` 키로 종료하는 예제가 많습니다.

## OpenCV Basics

OpenCV는 컴퓨터 비전과 영상 처리에 사용하는 오픈 소스 라이브러리입니다.
이미지, 비디오, 카메라 입력, 도형 그리기, 객체 인식, 머신 러닝 등 다양한
기능을 제공합니다.

Related files:

- [`01_helloWorld.cpp`](opencv_ex/part1/01_helloWorld.cpp)
- [`02_basicOP.cpp`](opencv_ex/part1/02_basicOP.cpp)

Key notes:

- `#include <opencv2/opencv.hpp>`로 OpenCV 주요 기능을 include합니다.
- `cv::Mat`은 이미지와 행렬 데이터를 담는 기본 클래스입니다.
- `imread()`는 이미지를 읽고, `imshow()`는 window에 이미지를 보여줍니다.
- `waitKey()`는 keyboard 입력을 기다리면서 GUI event loop도 처리합니다.
- OpenCV의 기본 color order는 RGB가 아니라 BGR입니다.

### Computer vision and image processing

컴퓨터 비전은 이미지나 비디오에서 의미 있는 정보를 추출하는 기술입니다.
영상 처리는 입력 영상을 목적에 맞게 바꾸는 기술입니다.

예시:

- 노이즈 제거
- 이미지 향상
- 색상 조정
- 영상 분할
- 객체 검출
- 영상 인식

영상 처리 관련 배경 지식:

- C++
- 행렬
- 선형대수
- 미분
- 기하학
- 컴퓨터 그래픽스

## Image and Mat

영상은 위치 값과 밝기 값을 가진 화소들의 모음입니다. OpenCV에서는 이 데이터를
대부분 `Mat`으로 다룹니다.

Related files:

- [`03_matOP.cpp`](opencv_ex/part1/03_matOP.cpp)
- [`04_inputArray.cpp`](opencv_ex/part1/04_inputArray.cpp)
- [`05_matOp2.cpp`](opencv_ex/part1/05_matOp2.cpp)

Main classes:

| Class | Meaning | Main use |
| --- | --- | --- |
| `Mat` | image/matrix data | 이미지 저장, 행렬 연산, pixel 접근 |
| `Point` | 2D point | 좌표 표현 |
| `Scalar` | 1-4 channel value | 색상, 밝기, channel 값 |
| `Rect` | rectangle region | ROI, bounding box |
| `Size` | width and height | 이미지 크기, kernel 크기 |
| `RotatedRect` | rotated rectangle | 회전된 영역 표현 |

### Sampling and quantization

- 샘플링: 연속적인 영상을 일정한 간격의 화소로 나누어 표현하는 과정입니다.
- 양자화: 밝기 값을 제한된 bit 수의 정수로 표현하는 과정입니다.

### Grayscale and true color

- Grayscale image: 각 pixel이 밝기 정보만 가집니다. 보통 8-bit라서 값 범위는 `0`부터 `255`입니다.
- True color image: 각 pixel이 색상 정보를 가집니다. OpenCV에서는 보통 BGR 3-channel로 다룹니다.

### Image file formats

| Format | Note |
| --- | --- |
| BMP | 무압축 방식이라 품질이 좋지만 파일 크기가 큽니다. |
| JPG | 손실 압축 방식이라 파일 크기는 작지만 품질 손실이 생길 수 있습니다. |
| PNG | 무손실 압축 방식이고 투명 배경을 지원합니다. |
| GIF | 제한된 색상과 간단한 animation에 사용됩니다. |

## Video and GStreamer

비디오는 연속된 frame image로 생각할 수 있습니다. OpenCV에서는
`VideoCapture`로 입력을 받고, `VideoWriter`로 저장할 수 있습니다.

Related files:

- [`06_video.cpp`](opencv_ex/part1/06_video.cpp)
- [`07_gstreamer.cpp`](opencv_ex/part1/07_gstreamer.cpp)
- [`08_gstreamer_ex.cpp`](opencv_ex/part1/08_gstreamer_ex.cpp)
- [`09_videoSave.cpp`](opencv_ex/part2/09_videoSave.cpp)

공부 포인트:

- camera index 또는 video file path로 `VideoCapture`를 열 수 있습니다.
- 반복문에서 frame을 계속 읽고 `imshow()`로 보여줍니다.
- FPS, frame size, codec 설정은 video save에서 중요합니다.
- GStreamer는 여러 multimedia 요소를 pipeline으로 연결하는 framework입니다.
- OpenCV video capture에서 camera, stream, codec 처리를 확장할 때 GStreamer를 사용할 수 있습니다.

## Drawing and Text

OpenCV drawing 함수는 image 위에 도형과 text를 직접 그립니다. 이 기능은
디버깅, 시각화, UI overlay를 만들 때 자주 사용합니다.

Related files:

- [`10_drawing.cpp`](opencv_ex/part2/10_drawing.cpp)
- [`11_drawing_example.cpp`](opencv_ex/part2/11_drawing_example.cpp)
- [`12_drawing_example2.cpp`](opencv_ex/part2/12_drawing_example2.cpp)
- [`13_font.cpp`](opencv_ex/part2/13_font.cpp)
- [`14_freetype.cpp`](opencv_ex/part2/14_freetype.cpp)
- [`colors.hpp`](opencv_ex/part2/colors.hpp)

Main functions:

| Function | Use |
| --- | --- |
| `line()` | 선 그리기 |
| `rectangle()` | 사각형 그리기 |
| `circle()` | 원 그리기 |
| `ellipse()` | 타원 그리기 |
| `polylines()` | 여러 점을 연결한 선 그리기 |
| `drawMarker()` | marker symbol 그리기 |
| `putText()` | 기본 font text 출력 |

공부 포인트:

- `Scalar(blue, green, red)` 순서로 색상을 넣습니다.
- `LINE_AA`를 사용하면 선과 글자가 더 부드럽게 보입니다.
- 움직이는 화면은 원본 frame을 clone한 뒤 매 frame 새로 그리는 방식이 안전합니다.
- `freetype`을 사용하면 한글 등 더 다양한 font rendering을 실험할 수 있습니다.

## Keyboard Mouse and UI

OpenCV HighGUI는 간단한 window, keyboard, mouse, trackbar를 제공합니다.
큰 GUI framework는 아니지만 영상 처리 결과를 빠르게 확인하기 좋습니다.

Related files:

- [`15_keyboard.cpp`](opencv_ex/part2/15_keyboard.cpp)
- [`16_tickmeter.cpp`](opencv_ex/part2/16_tickmeter.cpp)
- [`17_mouse.cpp`](opencv_ex/part2/17_mouse.cpp)
- [`18_mouse_example.cpp`](opencv_ex/part2/18_mouse_example.cpp)
- [`19_trackbar.cpp`](opencv_ex/part2/19_trackbar.cpp)

### keyboard

[`15_keyboard.cpp`](opencv_ex/part2/15_keyboard.cpp)는 `waitKey()`로 key 입력을
받습니다.

공부 포인트:

- `waitKey(30)`은 약 30ms 동안 key 입력을 기다립니다.
- 반환값이 `27`이면 `ESC`입니다.
- 반환값이 `'v'` 또는 `'V'`인지 확인해서 기능을 켤 수 있습니다.

### TickMeter and FPS

[`16_tickmeter.cpp`](opencv_ex/part2/16_tickmeter.cpp)는 실행 시간과 FPS 감각을
익히기 위한 예제입니다.

공부 포인트:

- `getTickCount()`는 현재 tick 값을 반환합니다.
- `getTickFrequency()`는 1초당 tick 수를 반환합니다.
- frame 처리 시간에 따라 `waitKey()` 대기 시간을 조정할 수 있습니다.

### mouse callback

[`17_mouse.cpp`](opencv_ex/part2/17_mouse.cpp)는 `setMouseCallback()`을 사용합니다.

공부 포인트:

- callback 함수는 mouse event가 발생할 때 OpenCV가 호출합니다.
- `EVENT_LBUTTONDOWN`, `EVENT_LBUTTONUP`, `EVENT_MOUSEMOVE`로 drag를 만들 수 있습니다.
- callback의 `void *data`에 `Mat`이나 app state pointer를 넘길 수 있습니다.

### Mouse Color Studio

[`18_mouse_example.cpp`](opencv_ex/part2/18_mouse_example.cpp)는 mouse event를
사용한 interactive drawing 예제입니다.

기능:

- mouse를 따라다니는 색상 사각형
- right click으로 random color 변경
- left drag로 현재 색상 선 그리기
- middle click 또는 wheel event로 eyedropper color sampling
- `C`로 그림 지우기
- `ESC`로 종료

### trackbar

[`19_trackbar.cpp`](opencv_ex/part2/19_trackbar.cpp)는 `createTrackbar()`를 사용합니다.

공부 포인트:

- trackbar 값이 바뀔 때 callback이 호출됩니다.
- slider value를 image 처리 parameter로 연결할 수 있습니다.
- threshold, brightness, color level 조절 같은 실험에 유용합니다.

## FileStorage and Data

OpenCV `FileStorage`는 C++ object, vector, matrix 같은 값을 파일로 저장하고
다시 읽을 때 사용합니다.

Related files:

- [`20_filestorage.cpp`](opencv_ex/part2/20_filestorage.cpp)
- [`21_filestorage2.cpp`](opencv_ex/part2/21_filestorage2.cpp)
- [`mydata.json`](data/mydata.json)

공부 포인트:

- `FileStorage::WRITE`로 값을 저장합니다.
- `FileStorage::READ`로 저장된 값을 읽습니다.
- `String`, `int`, `Point`, `vector`, `Mat` 같은 값을 저장할 수 있습니다.
- XML, YAML, JSON 스타일 데이터 흐름을 비교해 볼 수 있습니다.

## Mask and ROI

Mask는 어떤 pixel을 사용할지 선택하는 image입니다. 보통 흰색은 사용, 검은색은
제외처럼 생각하면 됩니다.

Related files:

- [`22_mask.cpp`](opencv_ex/part2/22_mask.cpp)
- [`mask.bmp`](data/mask.bmp)
- [`mask_plane.bmp`](data/mask_plane.bmp)
- [`mask_smile.bmp`](data/mask_smile.bmp)

공부 포인트:

- ROI는 image 안의 특정 rectangle 영역입니다.
- mask를 사용하면 특정 영역만 copy하거나 합성할 수 있습니다.
- binary mask와 grayscale mask의 차이를 관찰하면 좋습니다.
- `copyTo(dst, mask)` 형태는 OpenCV에서 자주 쓰는 패턴입니다.

## Brightness Contrast and Histogram

`opencv_ex/part3`는 pixel value를 직접 바꾸면서 영상이 어떻게 달라지는지
확인하는 예제로 시작합니다.

Related files:

- [`23_brightness.cpp`](opencv_ex/part3/23_brightness.cpp)
- [`24_contrast.cpp`](opencv_ex/part3/24_contrast.cpp)
- [`25_histogram.cpp`](opencv_ex/part3/25_histogram.cpp)

### brightness

[`23_brightness.cpp`](opencv_ex/part3/23_brightness.cpp)는 grayscale image에
밝기 값을 더하는 여러 방식을 비교합니다.

공부 포인트:

- `add(img, 100, img2)`는 saturation 처리를 포함한 OpenCV 방식입니다.
- `img + 100`처럼 직접 더할 때와 결과 차이를 비교할 수 있습니다.
- pixel loop로 `at<uchar>(j, i)`에 접근하면 직접 연산 흐름을 볼 수 있습니다.

### contrast

[`24_contrast.cpp`](opencv_ex/part3/24_contrast.cpp)는 대비 조정, contrast
stretching, histogram equalization을 비교합니다.

공부 포인트:

- 단순 곱셈은 전체 밝기 차이를 키웁니다.
- `(img - 128)` 기준 조정은 중간 밝기를 기준으로 contrast를 바꿉니다.
- `minMaxLoc()`로 최소/최대값을 찾고 `0~255` 범위로 stretching할 수 있습니다.
- `equalizeHist()`는 grayscale histogram을 평탄화해 대비를 개선합니다.

### histogram

[`25_histogram.cpp`](opencv_ex/part3/25_histogram.cpp)는 grayscale histogram을
계산하고 image로 그리는 helper 함수를 포함합니다.

공부 포인트:

- `calcHist()`는 pixel value 분포를 계산합니다.
- grayscale histogram은 보통 256개 bin으로 봅니다.
- histogram image를 그리면 밝기 분포와 contrast 변화를 눈으로 비교할 수 있습니다.

## Arithmetic and Filtering

영상 산술 연산과 filtering은 pixel을 조합하거나 주변 pixel을 함께 사용해
새로운 영상을 만드는 기본 기법입니다.

Related files:

- [`26_arithmetic.cpp`](opencv_ex/part3/26_arithmetic.cpp)
- [`27_embossing.cpp`](opencv_ex/part3/27_embossing.cpp)
- [`28_blurr.cpp`](opencv_ex/part3/28_blurr.cpp)
- [`29_sharpening.cpp`](opencv_ex/part3/29_sharpening.cpp)
- [`30_bilateral.cpp`](opencv_ex/part3/30_bilateral.cpp)

### arithmetic

[`26_arithmetic.cpp`](opencv_ex/part3/26_arithmetic.cpp)는 두 grayscale image를
bitwise 연산과 산술 연산으로 조합합니다.

공부 포인트:

- `bitwise_and`, `bitwise_or`, `bitwise_xor`, `bitwise_not`은 binary mask 감각을 익히기 좋습니다.
- `add`, `subtract`, `absdiff`는 pixel 값의 합과 차이를 비교합니다.
- `addWeighted()`는 두 영상을 비율로 섞을 때 사용합니다.

### convolution filters

[`27_embossing.cpp`](opencv_ex/part3/27_embossing.cpp)는 `filter2D()`와 직접 만든
kernel로 embossing 효과를 적용합니다.

공부 포인트:

- kernel 값이 주변 pixel을 어떻게 섞을지 결정합니다.
- `filter2D()`는 직접 만든 2D filter를 image에 적용합니다.
- `BORDER_REPLICATE`는 가장자리 pixel 처리 방식 중 하나입니다.

### blur and sharpening

[`28_blurr.cpp`](opencv_ex/part3/28_blurr.cpp)와
[`29_sharpening.cpp`](opencv_ex/part3/29_sharpening.cpp)는 camera frame에 blur와
sharpening을 적용합니다.

공부 포인트:

- `blur()`는 평균 filter를 적용합니다.
- `GaussianBlur()`는 Gaussian 분포를 이용해 더 자연스럽게 흐립니다.
- 원본과 blur image의 차이를 이용하면 sharpening 효과를 만들 수 있습니다.
- trackbar 값을 parameter로 연결하면 filter 강도를 실시간으로 바꿀 수 있습니다.

### bilateral filter

[`30_bilateral.cpp`](opencv_ex/part3/30_bilateral.cpp)는 noise를 추가한 뒤
Gaussian blur와 bilateral filter 결과를 비교합니다.

공부 포인트:

- Gaussian blur는 noise를 줄이지만 edge도 함께 흐려질 수 있습니다.
- `bilateralFilter()`는 edge를 보존하면서 noise를 줄이는 데 사용합니다.
- filter 결과를 나란히 띄우면 smoothing 방식의 차이를 비교하기 좋습니다.

## Data Assets

`data` 폴더에는 예제에서 사용하는 image, video, font, cascade, model 파일이
있습니다.

대표 파일:

| File | Use |
| --- | --- |
| [`lenna.bmp`](data/lenna.bmp) | 기본 image load, display, drawing 실습 |
| [`vtest.avi`](data/vtest.avi) | video capture 실습 |
| [`NanumPenScript-Regular.ttf`](data/NanumPenScript-Regular.ttf) | freetype font 실습 |
| [`haarcascade_frontalface_default.xml`](data/haarcascade_frontalface_default.xml) | face cascade 실험용 데이터 |
| [`haarcascade_eye.xml`](data/haarcascade_eye.xml) | eye cascade 실험용 데이터 |
| [`mnist_cnn.pb`](data/mnist_cnn.pb) | DNN/model 실험용 데이터 |
| [`mydata.json`](data/mydata.json) | FileStorage read/write 실습 |

## More Study Topics

다음 단계로 더 공부하면 좋은 주제입니다.

| Topic | Why it matters | Related files |
| --- | --- | --- |
| Color space | BGR, RGB, HSV, grayscale 변환 이해 | `cvtColor`, image examples |
| Filtering | blur, Gaussian, sharpening, edge detection | `Mat`, convolution examples |
| Thresholding | mask와 segmentation의 시작점 | trackbar, mask examples |
| Contours | object boundary를 찾는 기본 흐름 | [`contours.bmp`](data/contours.bmp) |
| Feature matching | image matching과 object detection 기초 | [`box.png`](data/box.png), [`box_in_scene.png`](data/box_in_scene.png) |
| Cascade detection | 얼굴/눈 검출 흐름 이해 | cascade XML files |
| DNN | OpenCV에서 deep learning model 사용 | [`mnist_cnn.pb`](data/mnist_cnn.pb) |

## README Maintenance Notes

새 예제 파일을 추가할 때는 아래 순서로 README도 같이 업데이트하면 찾기 쉽습니다.

1. [Subject Index](#subject-index)에 주제와 파일을 추가합니다.
2. 관련 topic section의 `Related files`에 링크를 추가합니다.
3. 실행 target이 생기면 [Build and Run](#build-and-run)에 실행 예시를 추가합니다.
4. `data` 파일을 새로 사용하면 [Data Assets](#data-assets)에 용도를 적습니다.
5. 생성 파일은 README 주요 목록에 넣지 않습니다.
