// Canny1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	IplImage *pimg = NULL;
	IplImage *pCannyimg = NULL;
	const char *img_name = "F:\\ͼƬ\\002.jpg";
	pimg = cvLoadImage(img_name, 1);
	//ΪCannyͼ������ռ�
	pCannyimg = cvCreateImage(cvGetSize(pimg), IPL_DEPTH_8U, 1);
	//Canny��Ե���
	cvCanny(pimg, pCannyimg, 50, 150, 3);
	//��������
	cvNamedWindow("src", 1);
	cvNamedWindow("canny",1);

	cvShowImage("src", pimg);
	cvShowImage("canny", pCannyimg);

	cvWaitKey(0);

	//���ٴ���
	cvDestroyWindow("src");
	cvDestroyWindow("canny");

	//�ͷ�ͼ��
	cvReleaseImage(&pimg);
	cvReleaseImage(&pCannyimg);
	return 0;
}

