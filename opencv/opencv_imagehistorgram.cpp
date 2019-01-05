#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//histogram equalize for constrasting grayscale image.
int main(){
	Mat image = imread("test.jpg");

	if(image.empty()){
		cout<<"can't open the image"<<endl;
		cin.get();
		return -1;
	}

	//change color into grayscale
	cvtColor(image, image, COLOR_BGR2GRAY);

	//equalize the histogram
	Mat hist_equalized_image;
	equalizeHist(image, hist_equalized_image);

	String windowNameOfOriginalImage = "Original Image"; 
    String windowNameOfHistogramEqualized = "Histogram Equalized Image";

    namedWindow(windowNameOfOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameOfHistogramEqualized, WINDOW_NORMAL);

    // Show images inside created windows.
    imshow(windowNameOfOriginalImage, image);
    imshow(windowNameOfHistogramEqualized, hist_equalized_image);

    waitKey(0); // Wait for any keystroke in one of the windows

    destroyAllWindows(); //Destroy all open windows

	return 0;
}