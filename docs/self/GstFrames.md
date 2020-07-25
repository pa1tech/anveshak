# GStreamer Combining Frames

## Using `videomixer` plugin to combine multiple feeds
* Video mixer helps us to combine multiple frames into a single frame, which can be encoded and transmitted via UDP
* Example transmission:
```
gst-launch-1.0 videomixer name=mix ! videoconvert ! \
x264enc tune=zerolatency byte-stream=true  bitrate=3000 threads=2 ! \
h264parse config-interval=1 ! rtph264pay ! udpsink host=127.0.0.1 port=5001 \
videotestsrc pattern=13 ! \
video/x-raw, width=640, height=480 ! \
videobox border-alpha=0 top=0 left=-640 ! mix. \
v4l2src device="/dev/video0" !  \
video/x-raw, width=640, height=480 !  \
videobox border-alpha=0 top=0 left=0 ! mix.
```
* Reception:
```
gst-launch-1.0 udpsrc port=5001 ! application/x-rtp, encoding-name=H264,payload=96 ! \
rtph264depay ! h264parse ! avdec_h264 ! \
videoconvert ! ximagesink sync=false
```

***

#### Important links:
* videomixer: https://gstreamer.freedesktop.org/documentation/videomixer/index.html?gi-language=c
* GStreamer cheatsheet: http://wiki.oz9aec.net/index.php/Gstreamer_cheat_sheet
* https://stackoverflow.com/questions/47959443/how-can-i-have-4-videos-as-1-using-gstreamer-with-1-large-to-the-left-and-3-sma
* H264 specs: http://www.lighterra.com/papers/videoencodingh264/