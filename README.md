# NeOpencvStructure opencv�����
## һ��VisualStudio�½�CMake��Ŀ����ֱ�����еĽ������
### 1.1 step1
�ļ�-->��-->CMake-->�ҵ�Ҫ����Ŀ��Ŀ¼�µ�CMakeLists.txt�ļ�->��  
### 1.2 step2
��Ŀ-->���ɻ���
### 1.3 setp2
�Ҽ���Ŀcpp�ļ�-->����
### 1.4
�л���CMake��ͼ-->�Ҽ���Ŀ-->ȫ������
### 1.5
�Ҽ���Ŀ����ִ���ļ���-->����-->ʵ����Ŀ���У�����Ϳ���ֱ�ӵ�������С���������Ŀ�ˣ�

## ����ʵ��
### 2.1 Module�µ�CMakeLists.txt�ļ�
```cmake
cmake_minimum_required (VERSION 3.8)
include_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/include")
link_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/x64/vc15/lib")
# ��Դ������ӵ�����Ŀ�Ŀ�ִ���ļ���
add_executable (NeOpencvStructure "NeOpencvStructure.cpp" "NeOpencvStructure.h")
target_link_libraries(NeOpencvStructure opencv_world412d)
```
### 2.2 Module�µ�cpp�ļ�
```cmake
#include "NeOpencvStructure.h"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main()
{
	//��ʾͼƬdemo
	//Mat p = imread("F:\\ͼƬ\\meng\\meng1.jpeg");
	//imshow("img", p);
	//waitKey();

	//������ͷ������Ƶ������0�ʹ�������������ͷ
	VideoCapture capture(0);
	Mat p;
	//ѭ����ʾÿһ֡
	while (1) {
		capture >> p; //���벢�洢ÿһ֡
		imshow("img", p); //��ʾ��ǰ֡
		waitKey(30); //�ȴ�30ms
	}
	cout << "Hello CMake." << endl;
	return 0;
}
```

## �����ɿ�
### 3.1 �Ҳ��� opencv_world412.dll
���б�������ͼ��ʾ��  
![image](https://github.com/tianyalu/NeOpencvStructure/blob/master/show/error.png)  
���������  
* ϵͳ��������path���·��: D:\CommonDev\opencv\opencv4.1.2\opencv\build\x64\vc15\bin, δ������⡣  
* ������·���µ�3��dll�ļ����Ƶ� C:\Windows\System32 Ŀ¼�£�������⡣  
**ע�⣺** ��dll�ļ����Ƶ� C:\Windows\SysWOW64 Ŀ¼��**���������**��


### 3.2 δ��������쳣
���������Ŀ�֮���ֳ�����������쳣��  
```bash
0x00007FFEA2F6A839 ��(λ�� NeOpencvStructure.exe ��)��δ��������쳣: Microsoft C++ �쳣: cv::Exception��λ���ڴ�λ�� 0x000000CA2B2FF160 ����
```
ԭ����û���������Ȩ�ޣ��򿪾ͺ��ˡ�