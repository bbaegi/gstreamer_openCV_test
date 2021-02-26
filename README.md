# gstreamer_openCV_test
* OS : Ubuntu 18.04
===
## 1. installation

### 1.1. Install OpenCV 3.4.0
#### Delete default OpenCV in Ubuntu 18.04
```
sudo apt-get remove libopencv*
sudo apt-get autoremove
sudo find /usr/local/ -name "*opencv*" -exec rm {} \;
```
