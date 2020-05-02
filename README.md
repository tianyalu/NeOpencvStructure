# NeOpencvStructure opencv环境搭建

[TOC]

## 一、环境搭建
参考：[Visual Studio OpenCV 环境配置](https://www.jianshu.com/p/2c64a4a89a15)  
### 1.1 Visual Studio环境准备
下载 [Visual Studio](https://visualstudio.microsoft.com/zh-hans/vs/community/) , 这里我们下载`Visual Studio Community 2019` 社区免费版即可。运行安装程序，勾选 ** 使用`C++`的`Linux`开发**：  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/visualStudio1.webp)  

单个组件中 **`SDK`、库和框架** 下勾选 **`Windows 10 SDK`** 和 **`Windows` 通用`C`运行时**：  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/visualStudio2.webp)  

**编译器、生成工具和运行时**下勾选**用于`Windows`的`C++ CMake`工具** ：  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/visualStudio3.webp)  
等待安装完成。  

### 1.2 OpenCV SDK 环境准备
下载 [OpenCV](https://opencv.org/releases/)，这里我们现在的是`Release`的`4.1.2`版本，下载`Windows`端和`Android`端：  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/opencv_download.png)  
安装及解压。  
> `Mac`可以直接使用`brew install opencv` 来安装。  

### 1.3 Visual Studio 创建 OpenCV 的 Cmake 工程  
`CMakeLists.txt`中添加`opencv`头文件和库路径，并链接库：  
```bash
include_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/include")

link_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/x64/vc15/lib")

target_link_libraries(NeOpencvStructure opencv_world412d)
```
将`opencv`中的`open_world412d.dll`动态库添加到生成的可执行文件同目录下。  
`opencv`中`open_world412d.dll`动态库位置：  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/dll_path.png)   

切换`CMake`选项：  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/cmake_option.webp)   

找到工作目录：  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/work_space.webp)   

拷贝：  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/copy_dll.png)   

## 二、实操
### 2.1 Module下的CMakeLists.txt文件
```cmake
cmake_minimum_required (VERSION 3.8)
# 导入opencv头文件
include_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/include")
# 导入opencv动态库路径
link_directories("D:/CommonDev/opencv/opencv4.1.2/opencv/build/x64/vc15/lib")
# 将源代码添加到此项目的可执行文件。
add_executable (NeOpencvStructure "NeOpencvStructure.cpp" "NeOpencvStructure.h")
# 将名字为“opencv_world412d”的动态库预编译到“NeOpencvStructure”可执行文件
target_link_libraries(NeOpencvStructure opencv_world412d)
```
### 2.2 Module下的cpp文件
```c++
#include "NeOpencvStructure.h"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main()
{
	//显示图片demo
	//Mat p = imread("F:\\图片\\meng\\meng1.jpeg");
	//imshow("img", p);
	//cvtColor(p, p, COLOR_BGR2GRAY);
	//imshow("img2", p);
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

### 3.1 VisualStudio新建CMake项目不能直接运行的解决方案

* step1： 文件-->打开-->CMake-->找到要打开项目根目录下的CMakeLists.txt文件->打开  

* step2： 项目-->生成缓存

* setp3： 右键项目cpp文件-->编译

* setp4： 切换到CMake视图-->右键项目-->全部生成

* setp5： 右键项目（可执行文件）-->调试-->实现项目运行（后面就可以直接点击“运行”来运行项目了）

### 3.2  找不到 opencv_world412.dll
运行报错如下图所示：  
![image](https://github.com/tianyalu/NeOpencvStructure/raw/master/show/error.png)  

~~解决方案1：~~  
~~* 系统环境变量path添加路径: D:\CommonDev\opencv\opencv4.1.2\opencv\build\x64\vc15\bin, **未解决问题**。  ~~
~~* 将上述路径下的3个dll文件复制到 C:\Windows\System32 目录下，**解决问题**。~~  
~~**注意：** 将dll文件复制到 C:\Windows\SysWOW64 目录下**不解决问题**。~~

解决方案2（推荐）：  
直接将`D:\CommonDev\opencv\opencv4.1.2\opencv\build\x64\vc15\bin\opencv_world412.dll` 复制到项目生成目录下 `E:\AndroidWangYiCloud\CPlusWorkspace\NeOpencvStructure\out\build\x64-Debug\NeOpencvStructure` 即可。  


### 3.3 未经处理的异常
解决完上面的坑之后又出现了下面的异常：  
```bash
0x00007FFEA2F6A839 处(位于 NeOpencvStructure.exe 中)有未经处理的异常: Microsoft C++ 异常: cv::Exception，位于内存位置 0x000000CA2B2FF160 处。
```
原因：我没开电脑相机权限，打开就好了。