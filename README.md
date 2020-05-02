# NeOpencvStructure opencv�����

[TOC]

## һ�������
�ο���[Visual Studio OpenCV ��������](https://www.jianshu.com/p/2c64a4a89a15)  
### 1.1 Visual Studio����׼��
���� [Visual Studio](https://visualstudio.microsoft.com/zh-hans/vs/community/) , ������������`Visual Studio Community 2019` ������Ѱ漴�ɡ����а�װ���򣬹�ѡ ** ʹ��`C++`��`Linux`����**��  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/visualStudio1.webp)  

��������� **`SDK`����Ϳ��** �¹�ѡ **`Windows 10 SDK`** �� **`Windows` ͨ��`C`����ʱ**��  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/visualStudio2.webp)  

**�����������ɹ��ߺ�����ʱ**�¹�ѡ**����`Windows`��`C++ CMake`����** ��  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/visualStudio3.webp)  
�ȴ���װ��ɡ�  

### 1.2 OpenCV SDK ����׼��
���� [OpenCV](https://opencv.org/releases/)�������������ڵ���`Release`��`4.1.2`�汾������`Windows`�˺�`Android`�ˣ�  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/opencv_download.png)  
��װ����ѹ��  
> `Mac`����ֱ��ʹ��`brew install opencv` ����װ��  

### 1.3 Visual Studio ���� OpenCV �� Cmake ����  
`CMakeLists.txt`�����`opencv`ͷ�ļ��Ϳ�·���������ӿ⣺  
```bash
include_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/include")

link_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/x64/vc15/lib")

target_link_libraries(NeOpencvStructure opencv_world412d)
```
��`opencv`�е�`open_world412d.dll`��̬����ӵ����ɵĿ�ִ���ļ�ͬĿ¼�¡�  
`opencv`��`open_world412d.dll`��̬��λ�ã�  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/dll_path.png)   

�л�`CMake`ѡ�  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/cmake_option.webp)   

�ҵ�����Ŀ¼��  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/work_space.webp)   

������  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/copy_dll.png)   

## ����ʵ��
### 2.1 Module�µ�CMakeLists.txt�ļ�
```cmake
cmake_minimum_required (VERSION 3.8)
# ����opencvͷ�ļ�
include_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/include")
# ����opencv��̬��·��
link_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/x64/vc15/lib")
# ��Դ������ӵ�����Ŀ�Ŀ�ִ���ļ���
add_executable (NeOpencvStructure "NeOpencvStructure.cpp" "NeOpencvStructure.h")
# ������Ϊ��opencv_world412d���Ķ�̬��Ԥ���뵽��NeOpencvStructure����ִ���ļ�
target_link_libraries(NeOpencvStructure opencv_world412d)
```
### 2.2 Module�µ�cpp�ļ�
```c++
#include "NeOpencvStructure.h"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main()
{
	//��ʾͼƬdemo
	//Mat p = imread("F:\\ͼƬ\\meng\\meng1.jpeg");
	//imshow("img", p);
	//cvtColor(p, p, COLOR_BGR2GRAY);
	//imshow("img2", p);
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

### 3.1 VisualStudio�½�CMake��Ŀ����ֱ�����еĽ������

* step1�� �ļ�-->��-->CMake-->�ҵ�Ҫ����Ŀ��Ŀ¼�µ�CMakeLists.txt�ļ�->��  

* step2�� ��Ŀ-->���ɻ���

* setp3�� �Ҽ���Ŀcpp�ļ�-->����

* setp4�� �л���CMake��ͼ-->�Ҽ���Ŀ-->ȫ������

* setp5�� �Ҽ���Ŀ����ִ���ļ���-->����-->ʵ����Ŀ���У�����Ϳ���ֱ�ӵ�������С���������Ŀ�ˣ�

### 3.2  �Ҳ��� opencv_world412.dll
���б�������ͼ��ʾ��  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/error.png)  

~~�������1��~~  
~~* ϵͳ��������path���·��: D:\CommonDev\opencv\opencv4.1.2\opencv\build\x64\vc15\bin, **δ�������**��  ~~
~~* ������·���µ�3��dll�ļ����Ƶ� C:\Windows\System32 Ŀ¼�£�**�������**��~~  
~~**ע�⣺** ��dll�ļ����Ƶ� C:\Windows\SysWOW64 Ŀ¼��**���������**��~~

�������2���Ƽ�����  
ֱ�ӽ�`D:\CommonDev\opencv\opencv4.1.2\opencv\build\x64\vc15\bin\opencv_world412.dll` ���Ƶ���Ŀ����Ŀ¼�� `E:\AndroidWangYiCloud\CPlusWorkspace\NeOpencvStructure\out\build\x64-Debug\NeOpencvStructure` ���ɡ�  


### 3.3 δ��������쳣
���������Ŀ�֮���ֳ�����������쳣��  
```bash
0x00007FFEA2F6A839 ��(λ�� NeOpencvStructure.exe ��)��δ��������쳣: Microsoft C++ �쳣: cv::Exception��λ���ڴ�λ�� 0x000000CA2B2FF160 ����
```
ԭ����û���������Ȩ�ޣ��򿪾ͺ��ˡ�