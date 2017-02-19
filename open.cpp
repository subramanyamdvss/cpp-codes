#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main()
{
	Mat photo = imread("download.jpg", 1);
	Mat original;
	Mat phot(photo.rows,photo.cols,CV_8UC1,Scalar(0));
	int i, j;
	int b, g, r;
	int gray;
	int threshold = 200;
	namedWindow("trackbarwindow",1);
	createTrackbar("trackbar", "trackbarwindow", &threshold, 255);
	cvtColor(photo, photo, CV_RGB2GRAY);
	
	//namedWindow("original", WINDOW_AUTOSIZE);
	//imshow("original", photo);
	//waitKey(0);
	
	
	
	//namedWindow("grayscale", WINDOW_AUTOSIZE);
	//imshow("grayscale", photo);
	//waitKey(0);
	
	//original = photo;
	
	while (1)
	{
		for (i = 0; i < phot.rows; i++)
		{
			for (j = 0; j < phot.cols; j++)
			{

				if (photo.at<uchar>(i, j) < threshold)
				{
					phot.at<uchar>(i, j) = 0;
				}
				else
				{
					phot.at<uchar>(i, j) = 255;
				}
			}
		}

		namedWindow("tracking", WINDOW_AUTOSIZE);
		imshow("tracking", phot);
		waitKey(10);
	}
	
}


/*
int main()
{

	int i, j;
	Mat photo = imread("download.jpg", 1);
	int red =0 , blue =0, green=0, redT=255, blueT=255, greenT=255;
	int a, b, c;

	Mat phot(photo.rows, photo.cols, CV_8UC3, Scalar(0,0,0));
	namedWindow("Trackbar_Window", WINDOW_AUTOSIZE);
	createTrackbar("R", "Trackbar_Window", &red, 255);
	createTrackbar("B", "Trackbar_Window", &blue, 255);
	createTrackbar("G", "Trackbar_Window", &green, 255);
	createTrackbar("RT", "Trackbar_Window", &redT, 255);
	createTrackbar("BT", "Trackbar_Window", &blueT, 255);
	createTrackbar("GT", "Trackbar_Window", &greenT, 255);


	while(1)
	{
		for (i = 0; i < photo.rows; i++)
		{
			for (j = 0; j < photo.cols; j++)
			{
				a = photo.at<Vec3b>(i, j)[0];
				b = photo.at<Vec3b>(i, j)[1];
				c = photo.at<Vec3b>(i, j)[2];

				if ( a < blue + blueT && a> blue - blueT && b < green + greenT && b> green - greenT && c < red + redT && c > red - redT)
				{
					phot.at<Vec3b>(i, j)[0] = photo.at<Vec3b>(i, j)[0];
					phot.at<Vec3b>(i, j)[2] = photo.at<Vec3b>(i, j)[2];
					phot.at<Vec3b>(i, j)[1] = photo.at<Vec3b>(i, j)[1];
				}
				else
				{
					phot.at<Vec3b>(i, j)[0] = 0;
					phot.at<Vec3b>(i, j)[1] = 0;
					phot.at<Vec3b>(i, j)[2] = 0;
				}
	
			}
		}

		namedWindow("tracking", WINDOW_AUTOSIZE);
		imshow("tracking", phot);
		waitKey(10);

	}
}
*/
