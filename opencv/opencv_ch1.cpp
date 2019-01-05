#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

int main(){
	Mat image = imread("test.jpg");

	if(image.empty()){
		cout<<"No image exist"<<endl;
		cin.get();
		return -1;
	}

	string window_name = "first time opencv";

	namedWindow(window_name);

	imshow(window_name, image);

	waitKey(0); //wait for any key to close the window

	destroyWindow(window_name);
	return 0;
}