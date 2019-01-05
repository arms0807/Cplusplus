#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
	Mat image = imread("test.jpg");

	if(image.empty()){
		cout<<"image can't be loaded"<<endl;
		cin.get();
		return -1;
	}

	bool isSuccess = imwrite("test_opencv_saved.jpg", image);
	if(!isSuccess){
		cout<<"Failed to save the image"<<endl;
		cin.get();
		return -1;
	}

	cout<<"Image saved successfully"<<endl;

	string windowName = "Saved image";
	namedWindow(windowName);
	imshow(windowName, image);

	waitKey(0);

	destroyWindow(windowName);

	return 0;
}