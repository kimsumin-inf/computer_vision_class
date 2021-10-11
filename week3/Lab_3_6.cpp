#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;



int main() {
	Mat src = imread("C:\\Users\\sumin\\Desktop\\2021-2 ¼ö¾÷\\computer vision\\class\\week3\\ocean.jpg");
	

	Mat shallow_copy = src;
	Mat deep_copy = src.clone();

	Mat copyTocopy;
	src.copyTo(copyTocopy);

	flip(src, src, 0);

	imshow("src", src);
	imshow("shallow_copy", shallow_copy);
	imshow("deep_copy", deep_copy);
	imshow("copyTocopy", copyTocopy);

	waitKey(0);
}
