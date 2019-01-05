#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
	VideoCapture cap("test.mov");

	if(!cap.isOpened()){
		cout<<"can't open the video"<<endl;
		cin.get();
		return -1;
	}

	string origin_video = "origin_video";
	string higher50 = "higher50";
	string higher100 = "higher100";
	string lower50 = "lower50";
	string lower100 = "lower100";

	namedWindow(origin_video);
	namedWindow(higher50);
	namedWindow(higher100);
	namedWindow(lower50);
	namedWindow(lower100);

	while(true){
		Mat frame;
		bool bSuccess = cap.read(frame);

		if(bSuccess==false){
			cout<<"The end of the video"<<endl;
			break;
		}

		Mat imageBrightnessenhance50;
		frame.convertTo(imageBrightnessenhance50, -1, 1, 50);

		Mat imageBrightnessenhance100;
		frame.convertTo(imageBrightnessenhance100, -1, 1, 100);

		Mat imageBrightnesslow50;
		frame.convertTo(imageBrightnesslow50, -1, 1, -50);

		Mat imageBrightnesslow100;
		frame.convertTo(imageBrightnesslow100, -1, 1, -100);

		imshow(origin_video, frame);
		imshow(higher50, imageBrightnessenhance50);
		imshow(higher100, imageBrightnessenhance100);
		imshow(lower50, imageBrightnesslow50);
		imshow(lower100, imageBrightnesslow100);

		if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
	}

	return 0;
}