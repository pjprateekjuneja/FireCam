#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "frameconv.h"
#include <ctime>
using namespace cv;
using namespace std;
string staticfilename1()
{
		string ar;
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[100];
	sprintf(buffer, "%d.%d.%d  %d:%d:%d", now->tm_mday, now->tm_mon, (1900 + now->tm_year), now->tm_hour, now->tm_min, now->tm_sec);
	return buffer;

}
int vconv()
{
	Mat frame;
        //Ptr<BackgroundSubtractor> Mog;
	//Mog= createBackgroundSubtractorMOG2();
	int c = waitKey(5), started = 0;
		VideoCapture cap(0);
		if (!cap.isOpened())
			cout << "error";
		cap >> frame;
string loc;

		//Mat frame1,finale, result;
		//frame.copyTo(frame1);
		//Mog->apply(frame, result);
		int i = 1;
		
		while (1)
		{
			cap >> frame;
		//	finale= frame.clone();
			
			c = waitKey(5);
			if (c == 's')
			{
				started = 1;waitKey(1000);
				
			}
			else
			{
				imshow("Cam", frame);
			}
			if (c == 'q')
			{
				started = 0;
				destroyWindow("Cam");
					destroyWindow("result");
					return -1;
					
			}
			if (started == 1)
			{
				
				
				//Mat clone = frame.clone();
				//putText(frame, "Camera On:", Point(40, 40), 3, 1.0, Scalar(0, 0, 255), 1.5);

				imshow("Cam",frame);
				
				//Mog->apply(frame, result);
				
				//frame1.copyTo(frame, result);
				//frame1 = frame.clone();
				
				//waitKey(1); 
				//cout << countNonZero(result) << "\n";
				
				{
					//waitKey(1000);
					//frame1 = finale.clone();
					loc = "/home/prateek/Final/output/frames/" + staticfilename1() + ".jpg";
					imwrite(loc, frame);
					//destroyWindow("Cam");
					//cap.release();
				//	break;
				}
			}
		

		}
		imshow("result", frame);
		
	
	waitKey(0);
	//destroyWindow("result");
	

	return -1;
}
