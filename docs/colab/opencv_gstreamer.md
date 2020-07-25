# OpenCV-with-Gstreamer-cpp
### Installing OpenCV
* Install accepted answer in [this forum](https://devtalk.nvidia.com/default/topic/1020915/opencv-and-webcam-problem-pixel-format-of-incoming-image-is-unsupported-by-opencv/)
* Download latest OpenCV version from --> https://github.com/jetsonhacks/buildOpenCVTX2
### Installing gstreamer
* ```
   sudo apt-get install libgstreamer1.0-0 gstreamer1.0-plugins-base \
   gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly \
   gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools \
   gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-pulseaudio
  ```
* For media IO
  ```
  sudo apt-get install zlib1g-dev libjpeg-dev libwebp-dev libpng-dev libtiff5-dev libjasper-dev libopenexr-dev libgdal-dev
  ```
* For video IO
  ```
  sudo apt-get install libdc1394-22-dev libavcodec-dev libavformat-dev libswscale-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev yasm libopencore-amrnb-dev libopencore-amrwb-dev libv4l-dev libxine2-dev
  ```
* Install gst-libav

  https://www.archlinux.org/packages/extra/x86_64/gst-libav/

***

* Compile the cpp code below with
   ```
   g++ opencv_gst.cpp -o app `pkg-config --cflags --libs opencv/`
   ```
* On receiver side run the following command:

  ```
    gst-launch-1.0 udpsrc port=5000 ! application/x-rtp, encoding-name=H264,payload=96 !  rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! ximagesink sync=false
  ```

***

### Example Code for combining three frames and streaming
 ```c
   #include <stdio.h>
   #include <opencv2/highgui/highgui.hpp>
   #include <opencv2/opencv.hpp>
   #include "opencv2/core/core.hpp"
   #include <iostream>
   using namespace std;
   using namespace cv;

   int main(int argc, char** argv) {

    cv::VideoCapture cap1("v4l2src device=\"/dev/video0\" ! video/x-raw, width=640, height=480, format=RGB ! videoconvert ! appsink");
    if (!cap1.isOpened()) {
        printf("=ERR= can't create video capture\n");
        return -1;
    }

    cv::VideoCapture cap2("v4l2src device=\"/dev/video1\" ! video/x-raw, width=640, height=480, format=RGB ! videoconvert ! appsink");
    if (!cap2.isOpened()) {
        printf("=ERR= can't create video capture\n");
        return -1;
    }

    cv::VideoCapture cap3("v4l2src device=\"/dev/video2\" ! video/x-raw, width=640, height=480, format=RGB ! videoconvert ! appsink");
    if (!cap3.isOpened()) {
        printf("=ERR= can't create video capture\n");
        return -1;
    }
   

    // second part of sender pipeline
    cv::VideoWriter writer1;
    writer1.open("appsrc ! videoconvert ! x264enc noise-reduction=10000 tune=zerolatency byte-stream=true bitrate=3000 threads=2 ! h264parse config-interval=1 ! rtph264pay ! udpsink host=10.42.0.1 port=5000", 0, (double)30, cv::Size(960, 720), true);
    if (!writer1.isOpened()) {
        printf("=ERR= can't create video writer\n");
        return -1;
    }


    cv::Mat frame1;
    cv::Mat frame2;
    cv::Mat frame3;
    
    int key;
    Mat both;
    int width = 480, height = 360;
    both = Mat(height * 2, width * 2, CV_MAKETYPE(8, 3), CV_RGB(100, 100, 100));

    while (true) {

        cap1 >> frame1;
        if (frame1.empty())
            break;
        cap2 >> frame2;
	if (frame2.empty())
	    break;
        cap3 >> frame3;
	if (frame3.empty())
	    break;

      cv::resize(frame1, frame1, cv::Size(), 0.75, 0.75);
      cv::resize(frame2, frame2, cv::Size(), 0.75, 0.75);
      cv::resize(frame3, frame3, cv::Size(), 0.75, 0.75);
      /* Process the frame here*/
	frame1.copyTo(Mat(both, Rect(0, 0, width, height)));
	frame2.copyTo(Mat(both, Rect(480, 0, width, height)));
        frame3.copyTo(Mat(both, Rect(0, 360, width, height)));
	frame2.copyTo(Mat(both, Rect(480, 360, width, height)));
	//imshow("images", both);
	writer1 << both;
        key = cv::waitKey( 10 );
    }
}
```