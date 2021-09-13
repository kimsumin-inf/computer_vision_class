#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#ifdef _DEBUG
#pragma comment(lib, "opencv_world3415d.lib")
#else 
#pragma comment(lib, "opencv_world3415.lib")
#endif 

int main() {
	Mat img;
	img = imread("C:\\opencv\\sources\\samples\\data\\lena.jpg", IMREAD_COLOR);
	if (img.empty()) {
		cout << "영상을 출력할 수 없음" << endl;
	}

	Mat gray, output;
	cvtColor(img, gray, CV_BGR2GRAY);

	imwrite(".//gray_lena.jpg", gray);

	imshow("img", img);
	imshow("gray", gray);
	waitKey(0);
	return 0;
}