#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <ctime>
#include<iomanip>
#include "videosurv.h"
using namespace cv;
using namespace std;
string getime()
{
	string ar;
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[100];
	sprintf(buffer, "%d.%d.%d  %d:%d:%d", now->tm_mday, now->tm_mon, (1900 + now->tm_year), now->tm_hour, now->tm_min, now->tm_sec);
	return buffer;

}
string filname()
{
	string ar;
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[100];
	sprintf(buffer, "%d%d%d %d%d%d", now->tm_mday, now->tm_mon, (1900 + now->tm_year), now->tm_hour, now->tm_min, now->tm_sec);
	return buffer;

}

int vs()
{
	
	Mat frame;
	 Ptr<BackgroundSubtractor> Mog;
	Mog = createBackgroundSubtractorMOG2();
	int c = 0, started = 0;
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		return -1;
	}
	int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	string ar = "/home/prateek/Final/output/cctv/"+filname()+".avi";
	VideoWriter video(ar, CV_FOURCC('M', 'J', 'P', 'G'), 24, Size(frame_width, frame_height), true);

	cap >> frame;

	Mat frame1, frame2, frame3, result;
	frame.copyTo(frame1);
	Mog->apply(frame1, result);
	int i = 1;


	while (1)
	{
		cap >> frame;
		if (started == 0)
		{

			Mat cl = frame.clone();
			putText(cl, getime(), Point(10, 20), 1.1, 1.5, Scalar(0, 255, 0), 2.5);
			imshow("cam", cl);
		}
		c = waitKey(5);
		if (c == 's')
		{
			started = 1;
			//destroyWindow("cam");
			//waitKey(3000);


		}
		if (c == 'q')
		{
			started = 0;
			destroyWindow("cam");
			destroyWindow("Started");
			return -1;
			
		}
		if (started == 1)
		{
		
			Mat clone = frame.clone();
			putText(clone, getime(), Point(10, 20), 1.1, 1.5, Scalar(0, 0, 255), 2.5);

			imshow("Started", clone);
			Mog->apply(frame, result);
			frame1.copyTo(frame, result);
			frame1 = frame.clone();
			//cout <<"\n"<< countNonZero(result);
			//cout << "\n" << countNonZero(result);
			if (countNonZero(result) > 12000)
			{
				video.write(clone);

			}

		}


	}
	//destroyWindow("Started");
	waitKey(0);
	return 0;
}
