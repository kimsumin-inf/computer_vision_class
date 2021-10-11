#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int stretch(int x, int r1, int s1, int r2, int s2) {
	float result;
	if (0 <= x && x <= r1) {
		result = s1 / r1 * x;
	}
	else if (r1 < x && x <= r2) {
		result = ((s2 - s1) / (r2 - r1)) * (x - r1) + s1;
	}
	else if (r2 < x && x <=255) {
		result = ((255 - s2) / (255 - r2)) * (x - r2) + s2;
	}
	return (int)result;
}
int main() {
	Mat img = imread("./lenna.jpg");
	Mat new_img = img.clone();
	int r1, s1, r2, s2;
	cout << "r1을 입력하시오: "; cin >> r1;
	cout << "s1을 입력하시오: "; cin >> s1;
	cout << "r2을 입력하시오: "; cin >> r2;
	cout << "s2을 입력하시오: "; cin >> s2;

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			for (int c = 0; c < 3; c++){
				int output = stretch(img.at<Vec3b>(i, j)[c], r1, s1, r2, s2);
				new_img.at<Vec3b>(i, j)[c] = saturate_cast<uchar>(output);
			}
		}
	}
	imshow("img", img);
	imshow("stretch img", new_img);
	waitKey(0);

}