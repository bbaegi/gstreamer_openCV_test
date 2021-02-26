// gst_opencv_test.cpp

#include <iostream>
#include <opencv2/opencv.hpp>


std::string gstreamer_pipeline (int camera_num, int capture_width, int capture_height, int display_width, int display_height) {
    return "v4l2src device=/dev/video" + std::to_string(camera_num)+ " ! video/x-raw, format=(string)UYVY, width=(int)" + std::to_string(capture_width)+ ", height=(int)" + std::to_string(capture_height)
            + " ! nvvidconv ! video/x-raw(memory:NVMM), format=(string)BGRx, width=(int)" + std::to_string(display_width)+ ", height=(int)" + std::to_string(display_height)
            + " ! nvvidconv ! video/x-raw, format=(string)BGRx"
            + " ! videoconvert ! video/x-raw, format=(string)BGR ! appsink "
           ;
}

int main()
{
    int capture_width = 3840 ;
    int capture_height = 2160 ;
    int display_width =  960 ;
    int display_height = 540 ;
    //int framerate = 30 ;
    //int flip_method = 0 ;

    std::string pipeline0 = gstreamer_pipeline(0, capture_width,
        capture_height,
        display_width,
        display_height
        //framerate,
        //flip_method
                                              );

    std::string pipeline1 = gstreamer_pipeline(1, capture_width,
        capture_height,
        display_width,
        display_height
        //framerate,
        //flip_method
                                              );

    std::string pipeline2 = gstreamer_pipeline(2, capture_width,
        capture_height,
        display_width,
        display_height
        //framerate,
        //flip_method
                                              );

    std::string pipeline3 = gstreamer_pipeline(3, capture_width,
        capture_height,
        display_width,
        display_height
        //framerate,
        //flip_method
                                              );

    std::cout << "Using pipeline: \n\t" << pipeline0 << "\n";
    std::cout << "Using pipeline: \n\t" << pipeline1 << "\n";
    std::cout << "Using pipeline: \n\t" << pipeline2 << "\n";
    std::cout << "Using pipeline: \n\t" << pipeline3 << "\n";


    cv::VideoCapture cap0(pipeline0, cv::CAP_GSTREAMER);
    cv::VideoCapture cap1(pipeline1, cv::CAP_GSTREAMER);
    cv::VideoCapture cap2(pipeline2, cv::CAP_GSTREAMER);
    cv::VideoCapture cap3(pipeline3, cv::CAP_GSTREAMER);

    if(!cap0.isOpened()) {
        std::cout<<"Failed to open camera0."<<std::endl;
        return (-1);
    }
    if(!cap1.isOpened()) {
        std::cout<<"Failed to open camera1."<<std::endl;
        return (-1);
    }
    if(!cap2.isOpened()) {
        std::cout<<"Failed to open camera1."<<std::endl;
        return (-1);
    }
    if(!cap3.isOpened()) {
        std::cout<<"Failed to open camera1."<<std::endl;
        return (-1);
    }

    cv::namedWindow("CSI Camera 0", cv::WINDOW_AUTOSIZE);
    cv::moveWindow("CSI Camera 0", 0, 0);
    cv::namedWindow("CSI Camera 1", cv::WINDOW_AUTOSIZE);
    cv::moveWindow("CSI Camera 1", 960, 0);
    cv::namedWindow("CSI Camera 2", cv::WINDOW_AUTOSIZE);
    cv::moveWindow("CSI Camera 2", 0, 540);
    cv::namedWindow("CSI Camera 3", cv::WINDOW_AUTOSIZE);
    cv::moveWindow("CSI Camera 3", 960, 540);

    cv::Mat img0;
    cv::Mat img1;
    cv::Mat img2;
    cv::Mat img3;

    std::cout << "Hit ESC to exit" << "\n" ;

    while(true)
    {
        if (!cap0.read(img0)) {
                std::cout<<"Capture read error"<<std::endl;
                break;
        }
        if (!cap1.read(img1)) {
                std::cout<<"Capture read error"<<std::endl;
                break;
        }
        if (!cap2.read(img2)) {
                std::cout<<"Capture read error"<<std::endl;
                break;
        }
        if (!cap3.read(img3)) {
                std::cout<<"Capture read error"<<std::endl;
                break;
        }

        cv::imshow("CSI Camera 0",img0);
        cv::imshow("CSI Camera 1",img1);
        cv::imshow("CSI Camera 2",img2);
        cv::imshow("CSI Camera 3",img3);

        int keycode = cv::waitKey(30) & 0xff ;
        if (keycode == 27) break ;
    }

    cap0.release();
    cap1.release();
    cap2.release();
    cap3.release();
    cv::destroyAllWindows() ;
    return 0;
}
