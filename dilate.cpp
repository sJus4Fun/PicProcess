
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main(int argc, char** argv) {
	Mat src = imread("D:/images/smarties.png"); //读取图片
	if (src.empty()) {                     //判断是否找到图片
		printf("没有找到图片 ");           //输出文字
	}
	else
	{
		namedWindow("原图", WINDOW_AUTOSIZE);// 显示窗口命名为input ；WINDOW_AUTOSIZE显示大小为图片自定义大小，且不可以更改大小
		imshow("原图", src); //显示
 
		Mat str1= getStructuringElement(MORPH_RECT,Size(50, 50));
		Mat fsImg;
		erode(src,fsImg,str1);
		imshow("腐蚀图像",fsImg);
 
 
		Mat str2 = getStructuringElement(MORPH_RECT, Size(20, 20));
		Mat pzImg;
		dilate(src, pzImg, str2);
		imshow("膨胀图像", pzImg);
 
		waitKey(0);//显示的毫秒时间，如果函数参数<=0表示一直显示。>0表示显示的时间
		destroyAllWindows();
		return 0;
 
	}
