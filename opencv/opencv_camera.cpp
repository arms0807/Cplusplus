#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
	// on mac you can only use the terminal from mac to access the camera.
	// can't use iterm
	VideoCapture cap(0); // 0 means use the camera of the computer

	if(cap.isOpened()==false){
		cout<<"The camera can't be used"<<endl;
		cin.get();
		return -1;
	}

	double width = cap.get(CAP_PROP_FRAME_WIDTH);
	double height = cap.get(CAP_PROP_FRAME_HEIGHT);

	cout<<"Resolution is "<<width<<"* "<<height<<endl;

	string window_name = "Camera opencv";

	namedWindow(window_name);

	while(1){
		Mat frame;
		bool bSuccess = cap.read(frame);

		if(bSuccess == false){
			cout<<"Video camera is disconnected"<<endl;
			cin.get();
			break;
		}

		imshow(window_name, frame);
		if(waitKey(10)==27){
			cout<<"The esc had been pressed"<<endl;
			break;
		}
	}
	return 0;
}