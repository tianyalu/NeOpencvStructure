// NeOpencvStructure.cpp: 定义应用程序的入口点。
//

#include "NeOpencvStructure.h"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main()
{
	//显示图片demo
	//Mat p = imread("F:\\图片\\meng\\meng1.jpeg");
	//imshow("img", p);
	//waitKey();

	//从摄像头读入视频，参数0就代表读入的是摄像头
	VideoCapture capture(0);
	Mat p;
	//循环显示每一帧
	while (1) {
		capture >> p; //读入并存储每一帧
		imshow("img", p); //显示当前帧
		waitKey(30); //等待30ms
	}
	cout << "Hello CMake." << endl;
	return 0;
}
