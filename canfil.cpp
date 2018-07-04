#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "canfil.h"
#include <ctime>
using namespace cv;
using namespace std;
string canfilename()
{
	string ar;
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[100];
	sprintf(buffer, "can_%d%d%d%d%d%d", now->tm_mday, now->tm_mon, (1900 + now->tm_year), now->tm_hour, now->tm_min, now->tm_sec);
    return buffer;

}
int cfi()
{

	Mat captured;
	int c = 0;
	VideoCapture cap(0);
	namedWindow("Cam", CV_WINDOW_KEEPRATIO);
	if (!cap.isOpened())
	{
		return -1;
	}
	while (1)
	{
		c = waitKey(5);
		cap >> captured;
		cvtColor(captured, captured, CV_BGR2GRAY);
		GaussianBlur(captured, captured, Size(7, 7), 1.5, 1.5);
		Canny(captured, captured, 0, 30, 3);
		if (c == 's')
		{
			namedWindow("Captured", CV_WINDOW_AUTOSIZE);
			imshow("Captured",captured);
			string loc = "/home/prateek/Final/output/filter/"+canfilename() + ".jpg";
			cout << loc;
			imwrite(loc, captured);
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
	namedWindow("Captured", CV_WINDOW_KEEPRATIO);
	imshow("Captured", captured);
	destroyWindow("Cam");
	cap.release();
	waitKey(3000);
	destroyWindow("Captured");
	return 0;
}
