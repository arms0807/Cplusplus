#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

int main(){
	cv::Mat blank(800,600,CV_8UC3, cvScalar(250,20,30)); //last parameter is BGR

	std::string name = "opencv_blank";

	cv::namedWindow(name);

	cv::imshow(name, blank);

	cv::waitKey(0);

	cv::destroyWindow(name);
	return 0;
}