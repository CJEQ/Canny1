// Canny1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	IplImage *pimg = NULL;
	IplImage *pCannyimg = NULL;
	const char *img_name = "F:\\图片\\002.jpg";
	pimg = cvLoadImage(img_name, 1);
	//为Canny图像申请空间
	pCannyimg = cvCreateImage(cvGetSize(pimg), IPL_DEPTH_8U, 1);
	//Canny边缘检测
	cvCanny(pimg, pCannyimg, 50, 150, 3);
	//创建窗口
	cvNamedWindow("src", 1);
	cvNamedWindow("canny",1);

	cvShowImage("src", pimg);
	cvShowImage("canny", pCannyimg);

	cvWaitKey(0);

	//销毁窗口
	cvDestroyWindow("src");
	cvDestroyWindow("canny");

	//释放图像
	cvReleaseImage(&pimg);
	cvReleaseImage(&pCannyimg);
	return 0;
}

