#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void print(Mat img, string name ) {
	for (int i = 0; i < 80 ; i++)
		cout << "*";

	cout << "\n파일 이름" << name<<endl;
	cout << "행의 수=  " << img.rows << endl;
	cout << "열의 수= " << img.cols << endl;
	cout << "행렬의 크기= " << img.size() << endl;
	cout << "전체 화소 개수= " << img.total() << endl;
	cout << "한 화소 크기= " << img.elemSize()<<endl;
	cout << "타입= " << img.type() << endl;
	cout << "채널= " << img.channels() << endl;
	imshow(name, img);
	waitKey(0);
	destroyWindow(name);
}
int main() {
	Mat color  = imread("./Lenna.png",IMREAD_COLOR);
	print(color, "color");
	Mat gray = imread("./Lenna.png", IMREAD_GRAYSCALE);
	print(gray, "gray");

	Mat color_ocean = imread("./ocean.jpg", IMREAD_COLOR);
	print(color_ocean, "color_ocean");
	Mat gray_ocean = imread("./ocean.jpg", IMREAD_GRAYSCALE);
	print(gray_ocean, "gray_ocean");


}