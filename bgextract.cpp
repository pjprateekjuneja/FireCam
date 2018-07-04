#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "bgextract.h"
#include <ctime>
#include <string>
#include<fstream>
using namespace cv;
using namespace std;
string bgextractfilename()
{
	string ar;
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[100];
	sprintf(buffer, "bg_%d%d%d%d%d%d", now->tm_mday, now->tm_mon, (1900 + now->tm_year), now->tm_hour, now->tm_min, now->tm_sec);
	return buffer;

}
bool fex(const char *filename)
{
		ifstream ifile(filename);
		if (ifile.is_open())
			return true;
		else
			return false;
}


int main1(char* argc)
{


     int i = 0, j = 0, k = 0,div=0;
	double r,g, b;
	Mat inp;
	bool see=fex(argc);
	vector<Mat> frame;
	
	if (see==false)
	{   
		Mat error = imread("/home/prateek/Final/UI/img/Error.jpg");
		imshow("error", error);
		waitKey(2000);
		destroyWindow("error");
		return -1;
	}   
	   
	    string arg = string(argc);
	    VideoCapture cap(arg);
		int frcount = cap.get(CV_CAP_PROP_FRAME_COUNT);
		int fwidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
		int fheight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
		namedWindow("Video", CV_WINDOW_KEEPRATIO);

		for (int h = 0; h < frcount; h++)
		{
			frame.push_back(Mat());
			cap >> inp;
			inp.copyTo(frame.back());
			imshow("Video", frame[h]);
			waitKey(30);

		}
		destroyWindow("Video"); 
		 
		Mat finale(inp.size(), inp.type());
		finale = Scalar::all(0);
		for (i = 0; i <fheight; i++)
		{

			namedWindow("finale", CV_WINDOW_KEEPRATIO);
			imshow("finale", finale);
			waitKey(1);
			for (j = 0; j < fwidth; j++)
			{
				int mar=0,mag=0,mab=0; //mean 
				for (k = 0; k < frcount; k++)
				{

					mar+=frame[k].at<Vec3b>(i, j)[0];
					mag+=frame[k].at<Vec3b>(i, j)[1];
					mab+=frame[k].at<Vec3b>(i, j)[2];
				}

					mar/=frcount; mag/=frcount; mab/=frcount;


				finale.at<Vec3b>(i, j)[0] = mar;
				finale.at<Vec3b>(i, j)[1] = mag;
				finale.at<Vec3b>(i, j)[2] = mab;

			}

		}

		imshow("finale", finale);
		string ar = "/home/prateek/Final/output/background/" + bgextractfilename() + ".jpeg";
		imwrite(ar, finale);
		waitKey(0);
		destroyWindow("finale");
	waitKey(0);
	return 0;
		
}







