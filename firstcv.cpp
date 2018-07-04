#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "bgextract.h"
#include "static_pic.h"
#include "videosurv.h"
#include "videocap.h"
//#include "frameconv.h"
#include "negfil.h"
#include "sepfil.h"
#include "canfil.h"
#include "grafil.h"
#include "help.h"
using namespace cv;
using namespace std;
Mat src;
int curchoice = 0, cur = 0;  int textflag = 1;
char i[1000];
string ar;

void mouse_caller(int event, int x, int y, int flags, void* userdata)
{

	if (event == EVENT_MOUSEMOVE){

		/*{
		cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
		}*/

		if (x > 118 && x<305 && y>80 && y < 265)
		{
			if ((curchoice != 1) && cur == 0)

			{
				src = imread("/home/home/Final/UI/img/Selected_BGExtrac.jpg");
				imshow("FireCam", src);
				curchoice = 1;
				textflag = 1;

			}

		}
		else if (x > 119 && x<310 && y>353 && y < 538)
		{
			if ((curchoice != 2) && cur == 0)

			{
				src = imread("/home/prateek/Final/UI/img/Selected_SC.jpg");
				imshow("FireCam", src);
				curchoice = 2;
				textflag = 0;
			}

		}
		else if (x > 456 && x<579 && y>368 && y < 520)
		{
			if ((curchoice != 3) && cur == 0)

			{
				src = imread("/home/prateek/Final/UI/img/Selected_filter.jpg");
				imshow("FireCam", src);
				curchoice = 3;
				textflag = 0;
			}

		}
		else if (x > 424 && x<612 && y>76 && y < 263)
		{
			if ((curchoice != 4) && cur == 0)

			{
				src = imread("/home/prateek/Final/UI/img/Selected_vs.jpg");
				imshow("FireCam", src);
				curchoice = 4;
				textflag = 0;
			}

		}

		else if (x >76 && x<133 && y>0 && y < 68)
		{
			if ((curchoice != 5) && cur == 0)

			{
				//src = imread("/home/home/Final/UI/img/Selected_vs.jpg");
				//imshow("motioCam", src);
				curchoice = 5;
				textflag = 0;
			}

		}


		else if (cur == 0)
		{
		label2:
			cur = 0;

			src = imread("/home/prateek/Final/UI/img/Home.jpg");
			imshow("FireCam", src);
			curchoice = 0; 
		 	setMouseCallback("FireCam", mouse_caller, NULL);
			
		}


	}

	if ((event == EVENT_LBUTTONDOWN))
	{
		if (x >9 && x<66 && y>8 && y < 60)
		{
			helper();
		}

		if (curchoice == 1)
		{
		//label1:
			
			src = imread("/home/prateek/Final/UI/img/Video_Dir.jpg");
			imshow("FireCam", src);
		
			int c = 0; int end = 0; i[0] = '\0'; int re = 0;
			
			if (event == EVENT_LBUTTONDOWN)
			{
				if (x > 322 && x<471 && y>265 && y < 471)
				{
					if (cur == 1)
					{
						textflag = 0;
						cur = 0;
						goto label2;
					}
				}
			}
		
				cur = 1;
				
				while (textflag == 1)
				{
				   label1:
					re = 0;
					textflag = 1;
						
						imshow("FireCam", src);
						c = waitKey(5);

						if ((textflag == 1) && (c != -1))
						{
						
							
							src = imread("/home/prateek/Final/UI/img/Video_Dir.jpg");
							src = src.clone();
							if (c == 8)
							{
								if (end)
								{

									end--;
									i[end] = '\0';

								}
							}
							else if (c == 13)
							{
								textflag = 0;
								re = 1;

							}
							else
							{
								i[end] = c;
								end++;
								i[end] = '\0';
							}
							
							ar = string(i);
							putText(src, ar, Point(118, 330), 3, 1.0, Scalar(130, 130,130 ), 1.5);

						}

					}
					if (re == 1)
					{
						int ret = main1(i);
						if (ret == -1)
						goto label1;
						if (ret == 0)
							goto label2;
					}
				
		}
		else if (curchoice == 2)
		{
			cur = 2;
			//destroyWindow("motioCam");
			int ret = static_pic();
			if (ret == -1)
				goto label2;
		}
		else if (curchoice == 3)
		{
		label3:
		
			src = imread("/home/prateek/Final/UI/img/filter.jpg");
			imshow("FireCam", src);
			setMouseCallback("FireCam", mouse_caller, NULL);
			if ((x > 125 && x<293 && y>76 && y < 245) && (cur == 3))
			{
				//destroyWindow("motioCam");
				int ret = gfi();
				if (ret == -1)
				{
					cur = 0;
					goto label3;

				}
			}
			else if ((x > 460 && x<652 && y>76 && y < 245) && (cur == 3))
			{
				//destroyWindow("motioCam");
				int ret = nfi();
				if (ret == -1)
				{
					cur = 0;
					goto label3;
				}
			}
			else if ((x > 125 && x<312 && y>334 && y < 501) && (cur == 3))
			{
				//destroyWindow("motioCam");
				int ret = cfi();
				if (ret == -1)
				{
					cur = 0;
					goto label3;
				}
			}
			else if ((x > 462 && x<651 && y>334 && y < 502) && (cur == 3))
			{
				//destroyWindow("motioCam");
				int ret = sfi();
				if (ret == -1)
				{
					cur = 0;
					goto label3;
				}
			}

			else if (x > 15 && x<124 && y>270 && y < 368)
			{
				goto label2;
			}

			cur = 3;

		}
		else if (curchoice == 4)
		{
			cur = 4;
			//destroyWindow("motioCam");

			int ret = vs();
			if (ret == -1)
			goto label2;
		}

		else if (curchoice == 5)
		{
			cur = 5;
			//destroyWindow("motioCam");

			int ret = vc();
			if (ret == -1)
			goto label2;
		}

	}

}




int main(int argc, char* argv[])
{
	
	src = imread("/home/prateek/Final/UI/img/start.jpg");
	imshow("FireCam", src);
	cvWaitKey(3000);
	curchoice = 0; cur = 0;
	src = imread("/home/prateek/Final/UI/img/Home.jpg");
	imshow("FireCam", src);
	setMouseCallback("FireCam", mouse_caller, NULL);
	waitKey(0);
	return 0;
}
