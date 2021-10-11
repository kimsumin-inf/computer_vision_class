#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int mx1, mx2, my1, my2;
void onMouse(int event, int x, int y, int flags, void* param) {
	Mat& src = *(Mat*)param;

	if (event == EVENT_LBUTTONDOWN) {
		mx1 = x;
		my1 = y;

	}

	else if (event == EVENT_LBUTTONUP) {
		mx2 = x;
		my2 = y;

		rectangle(src, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);
		Mat roi = src(Rect(mx1, my1, mx2 - mx1, my2 - my1));
		for (int i = 0; i < roi.cols; i++) {
			for (int j = 0; j < roi.rows; j++) {
				roi.at<Vec3b>(j, i)[0] += 15;
				roi.at<Vec3b>(j, i)[1] -= 20;
				roi.at<Vec3b>(j, i)[2] += 30;

			}
		}
		imshow("roi", roi);

	}



}
int main() {
	Mat img = imread("./Lenna.png");
	imshow("img", img);
	setMouseCallback("img", onMouse, &img);
	
	
	waitKey(0);
};