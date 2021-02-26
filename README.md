# gstreamer_openCV_test
* OS : Ubuntu 18.04

## 1. installation

### 1.1. Install OpenCV 3.4.0

#### Delete default OpenCV in Ubuntu 18.04

```console
sudo apt-get remove libopencv*
sudo apt-get autoremove
sudo find /usr/local/ -name "*opencv*" -exec rm {} \;
```

#### Install Prerequisites

```console
sudo apt-get update
sudo apt-get upgrade
```

#### Install Developer Tools

```
sudo apt-get install build-essential cmake unzip pkg-config
```

#### Install Libraries

* Install Image I/O

```
sudo apt-get install libjpeg-dev libpng-dev libtiff-dev
```

* Install Video I/O

```
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev v4l-utils libxvidcore-dev libx264-dev libxine2-dev
```

* Install Libraries for Video Streaming

```
sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev
```

* Install GTK Libraries for OpenCV GUI

```
sudo apt-get install libgtk-3-dev
```

* Install Libraries for supporting OpenGL

```
sudo apt-get install mesa-utils libgl1-mesa-dri libgtkgl2.0-dev libgtkglext1-dev
```

* Install Libraries for using OpenCV

```
sudo apt-get install libatlas-base-dev gfortran libeigen3-dev
```

#### Install Python

```
sudo apt-get install python2.7-dev python3-dev python-numpy python3-numpy
```
