# gstreamer_openCV_test
* PC : Jetson AGX Xavier Developer Kit
* OS : Ubuntu 18.04
* Camera : e-con Systems e-CAM130_CUXVR_Quad


## 1. installation
* Before doing the work below, you should have to flash Ubuntu 18.04 with e-CAM130_CUXVR driver. (provided by e-con Systems)
### 1.1. Delete default OpenCV in Ubuntu 18.04

```
sudo apt-get remove libopencv*
sudo apt-get autoremove
sudo find /usr/local/ -name "*opencv*" -exec rm {} \;
```

### 1.2. Install Prerequisites

#### Update & Upgrade
```
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

### 1.3. Install OpenCV 3.4.0

#### Download OpenCV 3.4.0 repository

```
mkdir opencv
cd opencv
wget -O opencv.zip https://github.com/opencv/opencv/archive/3.4.0.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/3.4.0.zip
```

```
unzip opencv.zip
unzip opencv_contrib.zip
```

#### Build & Install OpenCV

```
cd opencv-3.4.0
mkdir build
cd build
```

```
cmake -D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D WITH_TBB=OFF \
-D WITH_IPP=OFF \
-D WITH_1394=OFF \
-D BUILD_WITH_DEBUG_INFO=OFF \
-D BUILD_DOCS=OFF \
-D INSTALL_C_EXAMPLES=ON \
-D INSTALL_PYTHON_EXAMPLES=ON \
-D BUILD_EXAMPLES=OFF \
-D BUILD_TESTS=OFF \
-D BUILD_PERF_TESTS=OFF \
-D WITH_QT=OFF \
-D WITH_GTK=ON \
-D WITH_OPENGL=ON \
-D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-3.4.0/modules \
-D WITH_V4L=ON  \
-D WITH_FFMPEG=ON \
-D WITH_XINE=ON \
-D BUILD_NEW_PYTHON_SUPPORT=ON \
-D PYTHON2_INCLUDE_DIR=/usr/include/python2.7 \
-D PYTHON2_NUMPY_INCLUDE_DIRS=/usr/lib/python2.7/dist-packages/numpy/core/include/ \
-D PYTHON2_PACKAGES_PATH=/usr/lib/python2.7/dist-packages \
-D PYTHON2_LIBRARY=/usr/lib/x86_64-linux-gnu/libpython2.7.so \
-D PYTHON3_INCLUDE_DIR=/usr/include/python3.6m \
-D PYTHON3_NUMPY_INCLUDE_DIRS=/usr/lib/python3/dist-packages/numpy/core/include/  \
-D PYTHON3_PACKAGES_PATH=/usr/lib/python3/dist-packages \
-D PYTHON3_LIBRARY=/usr/lib/x86_64-linux-gnu/libpython3.6m.so \
../
```

#### Compile
* Check CPU core

```
lscpu
```

* Put number of your CPU core after -j

```
make -j8
```

#### If error occured (recipe for target 'all failed make: Error2)
* Download protobuf install file at https://developers.google.com/protocol-buffers/

* Extract Archive

```
tar -xf protobuf-all-0.0.0.tar.gz
cd protobuf-all-0.0.0
```

* Build

```
sudo ./configure
sudo make
sudo make check
sudo make install
```

* Cache

```
sudo ldconfig
```

* Check installation finished

```
protoc --version
```

* Delete temporary files

```
cd ..
sudo rm -rf protobuf-*
```

#### Install OpenCV

```
sudo make install
sudo sh -c echo '/usr/local/lib/' > sudo /etc/ld.so.conf.d/opencv.conf
sudo ldconfig
```

#### Check

```
python
```

```python
import cv2
```
## 2. Usage
### 2.1. Compile

```
git clone https://github.com/bbaegi/gstreamer_openCV_test
cd ~/gstreamer_openCV_test
g++ gst_opencv_test.cpp -o gst_opencv_test `pkg-config --cflags --libs opencv`
```

### 2.2. Test

```
./gst_opencv_test
```
