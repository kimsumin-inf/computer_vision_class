#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void print(Mat img, string name ) {
	for (int i = 0; i < 80 ; i++)
		cout << "*";

	cout << "\n���� �̸�" << name<<endl;
	cout << "���� ��=  " << img.rows << endl;
	cout << "���� ��= " << img.cols << endl;
	cout << "����� ũ��= " << img.size() << endl;
	cout << "��ü ȭ�� ����= " << img.total() << endl;
	cout << "�� ȭ�� ũ��= " << img.elemSize()<<endl;
	cout << "Ÿ��= " << img.type() << endl;
	cout << "ä��= " << img.channels() << endl;
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