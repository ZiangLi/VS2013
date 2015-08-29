#include <iostream>
#include <string>
#include <queue>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\features2d\features2d.hpp>
#include <opencv2\nonfree\nonfree.hpp>
#include <opencv2\legacy\legacy.hpp>
#include <opencv2\flann\flann.hpp>
#include <opencv2\contrib\contrib.hpp>

using namespace std;
using namespace cv;

#define USE_BRISK
//#define USE_SIFT
const int test = 1;
int main()
{
	// 读入一张图片（原画）  
	Mat img = imread("2.jpg");
	// 创建一个名为 "原画"窗口  
	cvNamedWindow("原画");
	imshow("原画", img);
	//// 在窗口中显示游戏原画
	//////////////////////////////////////////////////////////////////////////
	////像素提取
	//Vec3f intensity = img.at<Vec3f>(90, 90);
	//float r = intensity.val[0];
	//float g = intensity.val[1];
	//float b = intensity.val[2];
	//cout << r << g << b << endl;
	//////////////////////////////////////////////////////////////////////////
	////图像腐蚀
	//Mat element = getStructuringElement(MORPH_RECT, Size(25, 25));
	//Mat dstImage;
	//erode(img, dstImage, element);
	//imshow("腐蚀图", dstImage);
	//////////////////////////////////////////////////////////////////////////
	////均值滤波
	//Mat dstImage;
	//blur(img, dstImage, Size(70, 70));
	//imshow("均值滤波图", dstImage);
	//////////////////////////////////////////////////////////////////////////
	////边缘检测
	//Mat dstImage, edge, grayImage;//参数定义
	//dstImage.create(img.size(), img.type());//与img同大小的矩阵dst
	//cvtColor(img, grayImage, CV_BGR2GRAY);//转化为灰度图
	//blur(img, edge, Size(3, 3));//降噪
	//Canny(edge, edge, 3, 9, 3);//运行canny边缘检测
	//imshow("边缘检测图", edge);
	//////////////////////////////////////////////////////////////////////////
	////读取视频
	//VideoCapture capture;
	//capture.open("3.mp4");
	//while (1)
	//{
	//	Mat frame;
	//	capture >> frame;
	//	imshow("读取视频", frame);
	//	waitKey(100);
	//}
	//////////////////////////////////////////////////////////////////////////
	////读取摄像头
	//VideoCapture capture;
	//capture.open(0);
	//while (1)
	//{
	//	Mat frame;
	//	capture >> frame;
	//	imshow("读取视频", frame);
	//	waitKey(300);
	//}
	//////////////////////////////////////////////////////////////////////////
	////读取摄像头并滤波，腐蚀，边缘检测
	//VideoCapture capture;
	//capture.open(0);
	//while (1)
	//{
	//	Mat frame;
	//	capture >> frame;
	//	imshow("捕获图像", frame);

	//	Mat frame_blur, frame_erode, frame_canndy;//声明三个图像矩阵（滤波，腐蚀，边缘）

	//	medianBlur(frame, frame_blur, 5);
	//	imshow("中值滤波", frame_blur);//中值滤波效果

	//	Canny(frame_blur, frame_canndy, 1, 50, 3);
	//	imshow("边缘检测", frame_canndy);//边缘检测效果

	//	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	//	erode(frame, frame_erode, element);
	//	imshow("腐蚀效果", frame_erode);//腐蚀效果

	//	Rect ccomp;
	//	floodFill(frame, Point(20, 20), Scalar(155, 255, 55), &ccomp, Scalar(20, 20, 20), Scalar(20, 20, 20));
	//	imshow("漫水填充", frame);

	//	waitKey(30);
	//}
	//////////////////////////////////////////////////////////////////////////
	//string filename = "I.xml";
	//FileStorage fs(filename, FileStorage::WRITE);
	//fs << "iterationNr" << 100;
	//Mat R = Mat_<uchar >::eye(3, 3),
	//	T = Mat_<double>::zeros(3, 1);
	//fs << "R" << R; // Write cv::Mat  
	//fs << "T" << T;
	//fs << "strings" << "["; // text - string sequence
	//fs << "image1.jpg" << "Awesomeness" << "baboon.jpg";
	//fs << "]"; // close sequence
	//fs << "Mapping"; // text - mapping  
	//fs << "{" << "One" << 1;
	//fs << "Two" << 2 << "}";
	//fs.release();

	//FileStorage fs2;
	//fs2.open(filename, FileStorage::READ);
	//Mat R2, T2;
	//fs2["R"] >> R2;
	//fs2["T"] >> T2;

	//FileNode n = fs2["strings"];
	//if (n.type() != FileNode::SEQ)
	//{
	//	cerr << "Not a squence!" << endl;
	//	return 1;
	//}
	//FileNodeIterator it=n.begin(), it_end = n.end();
	//for (; it != it_end; it++)
	//	std::cout << string(*it) << endl;

////////////////////////////////////////////////////////////////
vector<Point2f> list;
float inf = 10000000.0;
vector<bool>used;
for (int i = 0; i < 2 * list.size(); i++)
{
	used.push_back(false);
}
vector<vector<float>> dist;
for (int j = 0; j < list.size(); j++)
{
	vector<float>line;
	for (int i = 0; i < list.size(); i++)
	{
		if (i == j)
			line.push_back(inf);
		else
		{
			Point2f p;
			p = list[j] - list[i];
			line.push_back(sqrt(p.dot(p)));
		}
	}
	for (int i = 0; i < list.size(); i++)
		line.push_back(inf);
	dist.push_back(line);
}
for (int i = 0; i < list.size(); i++)
{
	vector<float>line;
	for (int j = 0; j < 2 * list.size(); j++)
		line.push_back(inf);
	dist.push_back(line);
}
	return 0;
}
