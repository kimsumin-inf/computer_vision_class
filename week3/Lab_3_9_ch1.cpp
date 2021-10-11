#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img, roi;
int mx1, mx2, my1, my2;
int exp_x,exp_y;
bool cropping = false;

void onMouse(int event, int x, int y, int flags, void* param) {
	

	if (event == EVENT_LBUTTONDOWN) {
		mx1 = x;
		my1 = y;
		cropping = true;
	}
	
	else if (event == EVENT_LBUTTONUP) {
		mx2 = x;
		my2 = y;
		
		cropping = false;
		rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);

		imshow("img", img);

	}
	
	if (cropping == true) {
		rectangle(img, Rect(mx1, my1, x - mx1, y - my1), Scalar(0, 255, 0), 2);
		imshow("img", img);
	}

}

int main() {
	img = imread("./Lenna.png");
	imshow("img", img);

	
	setMouseCallback("img", onMouse);

	while (1) {
		int key = waitKey(1);
		
		if (key == 'q') break;
		else if (key == 'w') {
			exp_y -= 10;
		}
		else if (key == 'a') {
			exp_x -= 10;
		}
		else if (key == 's') {
			exp_y += 10;
		}
		else if (key == 'd') {
			exp_x += 10;
		}
		Mat src = imread("./Lenna.png");
		rectangle(src, Rect(mx1+exp_x, my1+exp_y, mx2 - mx1+exp_x, my2 - my1+exp_y), Scalar(0, 255, 0), 2);
		imshow("img", src);
		

	}
}