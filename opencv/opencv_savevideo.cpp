#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){

	VideoCapture cap(0);
	if(cap.isOpened()==false){
		cout<<"Cannot open the video camera" << endl;
		cin.get();
		return -1;
	}

	//get the width of frames of the video
	int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
	//get the height of frames of the video
	int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));

	Size frame_size(frame_width, frame_height);
	int frame_per_second = 10;

	//Create and initialize the VideoWriter object 
	VideoWriter oVideoWriter("test.mov", VideoWriter::fourcc('M', 'J', 'P', 'G'), frame_per_second, frame_size, true);

	if(!oVideoWriter.isOpened()){
		cout<<"Cannot save the video to a file"<<endl;
		cin.get();
		return -1;
	}

	string window_name = "Saved video";
	namedWindow(window_name);

	while(1){
		Mat frame;
		bool isSuccess = cap.read(frame);

		if(!isSuccess){
			cout << "Video camera is disconnected" << endl;
            cin.get(); //Wait for any key press
            break;
		}

		/*
        Make changes to the frame as necessary
        e.g.  
         1. Change brightness/contrast of the image
         2. Smooth/Blur image
         3. Crop the image
         4. Rotate the image
         5. Draw shapes on the image
        */

        //write the video frame to the file
		oVideoWriter.write(frame); 

		//show the frame in the created window
		imshow(window_name, frame);

		//Wait for for 10 milliseconds until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If any other key is pressed, continue the loop 
        //If any key is not pressed within 10 milliseconds, continue the loop
		if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by the user. Stopping the video" << endl;
            break;
        }
	}
	//Flush and close the video file
    oVideoWriter.release();
	return 0;
}