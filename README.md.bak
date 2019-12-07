# NeOpencvStructure opencv环境搭建
## 一、VisualStudio新建CMake项目不能直接运行的解决方案
### 1.1 step1
文件-->打开-->CMake-->找到要打开项目根目录下的CMakeLists.txt文件->打开  
### 1.2 step2
项目-->生成缓存
### 1.3 setp2
右键项目cpp文件-->编译
### 1.4
切换到CMake视图-->右键项目-->全部生成
### 1.5
右键项目（可执行文件）-->调试-->实现项目运行（后面就可以直接点击“运行”来运行项目了）

## 二、实操
### 2.1 Module下的CMakeLists.txt文件
```cmake
cmake_minimum_required (VERSION 3.8)
include_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/include")
link_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/x64/vc15/lib")
# 将源代码添加到此项目的可执行文件。
add_executable (NeOpencvStructure "NeOpencvStructure.cpp" "NeOpencvStructure.h")
target_link_libraries(NeOpencvStructure opencv_world412d)
```
### 2.2 Module下的cpp文件
```cmake
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
```

## 三、采坑
### 3.1 找不到 opencv_world412.dll
运行报错如下图所示：  
![image](https://github.com/tianyalu/NeOpencvStructure/blob/master/show/error.png)  
解决方案：  
* 系统环境变量path添加路径: D:\CommonDev\opencv\opencv4.1.2\opencv\build\x64\vc15\bin, 未解决问题。  
* 将上述路径下的3个dll文件复制到 C:\Windows\System32 目录下，解决问题。  
**注意：** 将dll文件复制到 C:\Windows\SysWOW64 目录下**不解决问题**。


### 3.2 未经处理的异常
解决完上面的坑之后又出现了下面的异常：  
```bash
0x00007FFEA2F6A839 处(位于 NeOpencvStructure.exe 中)有未经处理的异常: Microsoft C++ 异常: cv::Exception，位于内存位置 0x000000CA2B2FF160 处。
```
原因：我没开电脑相机权限，打开就好了。