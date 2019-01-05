#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(){
	VideoCapture cap("test.mov");

	if(cap.isOpened()==false){
		cout<<"Can't open the video "<<endl;
		cin.get();
		return -1;
	}

	//Uncomment the following line if you want to start the video in the middle
 	//cap.set(CAP_PROP_POS_MSEC, 300); 

	double fps = cap.get(CAP_PROP_FPS);
	cout<<"FPS : "<<fps<<endl;
	string window_name = "first time video opencv";
	namedWindow(window_name, WINDOW_NORMAL);

	while(1){
		Mat frame;
		bool bSuccess = cap.read(frame); // read a new frame from video

		if(bSuccess==false){
			cout<<"Found the end of video"<<endl;
			break;
		}

		imshow(window_name, frame);
		//This function should be followed by waitKey(int) function in order to provide sufficient time 
		//to paint and display the frame in the window for the specified time duration in milliseconds. 
		//If you do not call waitKey(int) function, the frame will not be displayed in the window.
		if(waitKey(10)==27){
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
   			break;
		}
	}

	return 0;
}