#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int mx1, mx2, my1, my2;
void onMouse(int event, int x, int y, int flags, void* param) {
	Mat& img = *(Mat*)param;

	if (event == EVENT_LBUTTONDOWN) {
		mx1 = x;
		my1 = y;
		
	}

	else if (event == EVENT_LBUTTONUP) {
		mx2 = x;
		my2 = y;

		
		rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);

		imshow("img", img);

	}

	

}
int main() {

}