#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(){
	Mat image = imread("test.jpg");

	if(image.empty()){
		cout<<"can't read the image"<<endl;
		cin.get();
		return -1;
	}

	Mat imageBrightnessenhance50;
	//The first parameter is the output variable_name which we want to save into.
	//second is the type of image. If the value is negative, then the image will be the same as the input image
	//third is alpha, which the image will multiply this number then do the following works.
	//Forth is beta, which will be added to the pixels.
	//The third and forth parameter will be like y = ax+b;
	image.convertTo(imageBrightnessenhance50, -1, 1, 50);

	Mat imageBrightnessenhance100;
	image.convertTo(imageBrightnessenhance100, -1, 1, 100);

	Mat imageBrightnesslow50;
	image.convertTo(imageBrightnesslow50, -1, 1, -50);

	Mat imageBrightnesslow100;
	image.convertTo(imageBrightnesslow100, -1, 1, -100);

	//Windows name
	string origin_image = "origin_image";
	string higher50 = "higher50";
	string higher100 = "higher100";
	string lower50 = "lower50";
	string lower100 = "lower100";

	namedWindow(origin_image);
	namedWindow(higher50);
	namedWindow(higher100);
	namedWindow(lower50);
	namedWindow(lower100);

	imshow(origin_image, image);
	imshow(higher50, imageBrightnessenhance50);
	imshow(higher100, imageBrightnessenhance100);
	imshow(lower50, imageBrightnesslow50);
	imshow(lower100, imageBrightnesslow100);

	waitKey(0);

	destroyAllWindows();

	return 0;
}