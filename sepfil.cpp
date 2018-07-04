#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "sepfil.h"
#include <ctime>
using namespace cv;
using namespace std;
string sepfilename()
{
	string ar;
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[100];
	sprintf(buffer, "sep_%d%d%d%d%d%d", now->tm_mday, now->tm_mon, (1900 + now->tm_year), now->tm_hour, now->tm_min, now->tm_sec);
	return buffer;

}
Mat tosepia(Mat frame)
{
	Mat kern = (cv::Mat_<float>(4, 4) << 0.272, 0.534, 0.131, 0,
		0.349, 0.686, 0.168, 0,
		0.393, 0.769, 0.189, 0,
		0, 0, 0, 1);

	transform(frame, frame, kern);

	return frame;
}
int sfi()
{
	namedWindow("Cam", CV_WINDOW_KEEPRATIO);
	Mat frame,captured;
	int c = 0, started = 0;
	VideoCapture cap(0);
	if (!cap.isOpened())
		cout << "error";
	while (1)
	{
		c = waitKey(5);
		cap >> frame;
		frame = tosepia(frame);
		frame.copyTo(captured);
		if (c == 's')
		{
			namedWindow("Captured", CV_WINDOW_AUTOSIZE);
			imshow("Captured", frame);
			string loc = "/home/prateek/Final/output/filter/"+sepfilename() + ".jpg";
			imwrite(loc, frame);
			waitKey(500);
			destroyWindow("Captured");
		}
		if (c == 'q')
		{
			destroyWindow("Cam");
			destroyWindow("Captured");
			return -1;
		}
	
		imshow("Cam", captured);
		
	}
	/*namedWindow("Captured", CV_WINDOW_KEEPRATIO);
	imshow("Captured", captured);
	destroyWindow("Cam");
	cap.release();
	waitKey(3000);
	destroyWindow("Captured");*/


	return 0;
}
