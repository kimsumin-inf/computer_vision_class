#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat img = Mat(Size(1080, 720), CV_8UC3, Scalar(0, 0, 0));
	line(img, Point(100, 100), Point(400, 400), Scalar(0, 0, 255), 5, LINE_AA); // �� �߱�
	rectangle(img, Rect(Point(250, 30), Point(450, 200)), Scalar(0, 255, 0), 5); // �簢�� �׸���
	circle(img, Point(100, 300), 60, Scalar(255, 0, 0), 3); // �� �׸���
	ellipse(img, Point(300, 350), Point(100, 60), 45, 130, 270, Scalar(255, 255, 255), 5); // Ÿ�� �׸���

	imshow("img_drawing",img );
	imwrite(".//img_drawing.jpg", img);// ���� ����
	waitKey(0); // 1/1000 ��
	return 0;
}