#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img;
int kernel = 1;
int kernel2 = 1;
int sigmax = 0;
void onChange(int value, void* userdata) {
	img = imread("./lenna.jpg");
	if (value % 2 == 0) {
		value += 1;
	}
	kernel = value;
	cout << "kernel :" << kernel << "\tkernel2 :" << kernel2 << "\tsigma: " << sigmax << endl;
	GaussianBlur(img, img, Size(value, kernel2), sigmax);
	
	imshow("Gaussian", img);
}
void onChange1(int value, void* userdata) {
	img = imread("./lenna.jpg");
	if (value % 2 == 0) {
		value += 1;
	}
	kernel2 = value;
	cout << "kernel :" << kernel <<"\tkernel2 :" <<kernel2 << "\tsigma: " << sigmax << endl;
	GaussianBlur(img, img, Size(kernel, value), sigmax);

	imshow("Gaussian", img);
}
void onChange2(int value, void* userdata) {
	img = imread("./lenna.jpg");
	sigmax = value;
	cout << "kernel :" << kernel << "\tkernel2 :" << kernel2 << "\tsigma: "<< sigmax << endl;
	GaussianBlur(img, img, Size(kernel, kernel2), value);

	imshow("Gaussian", img);
}

int main() {
	
	int w = 0,h=0;
	int count = 100;
	img = imread("./lenna.jpg");
	namedWindow("Gaussian", WINDOW_AUTOSIZE);
	createTrackbar("kernel_x", "Gaussian", &kernel, count, onChange);
	createTrackbar("kernel_y", "Gaussian", &kernel2, count, onChange1);
	createTrackbar("sigma", "Gaussian", &sigmax,10, onChange2);

	
	imshow("Gaussian", img);
	waitKey(0);
}