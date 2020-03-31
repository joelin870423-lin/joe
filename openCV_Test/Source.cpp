#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::setUseOptimized(false);
	Mat src,src_gray,src_bin,open,close;
	double start, end, time;
	src = imread("C:/Users/user/Desktop/ironman.jpg");
	if (!src.data)
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	imwrite("gray_image.jpg", src_gray);
	threshold(src_gray, src_bin, 128, 255, THRESH_BINARY);
	for (int j = 3; j < 10; j++) {
		start = static_cast<double>(getTickCount());
		Mat kernel = getStructuringElement(MORPH_RECT, Size(j, j), Point(-1, -1));
		for (int i = 0; i < 100; i++) {
			morphologyEx(src_bin, open, 2, kernel);
		}
		end = static_cast<double>(getTickCount());
		time = (double)((end - start) / getTickFrequency());
		cout << "runtume(open)"<<j<<"x"<< j<<" : " << time << "s" << endl;
	}

	for (int j = 3; j < 10; j++) {
		start = static_cast<double>(getTickCount());
		Mat kernel = getStructuringElement(MORPH_RECT, Size(j, j), Point(-1, -1));
		for (int i = 0; i < 100; i++) {
			morphologyEx(src_bin, close, 3, kernel);
		}
		end = static_cast<double>(getTickCount());
		time = (double)((end - start) / getTickFrequency());
		cout << "runtume(close)" << j << "x" << j << " : " << time << "s" << endl;
	}


	namedWindow("Display");
	namedWindow("Display_gray");
	namedWindow("Display_bin");
	namedWindow("Display_open");
	namedWindow("Display_close");

	imshow("Display", src);
	imshow("Display_gray", src_gray);
	imshow("Display_bin", src_bin);
	imshow("Display_open", open);
	imshow("Display_close", close);



	waitKey(0);

	return 0;

}