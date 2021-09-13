#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int exp_x,exp_y;
void onMouse(int event, int x, int y, int flags, void* param) {
	if (event == EVENT_LBUTTONDOWN) {
		Mat& img = *(Mat*)(param);
		circle(img, Point(x, y), 200, Scalar(0, 255, 0), 10);


		circle(img, Point(x, y), 200, Scalar(0, 255, 0), 10);
		exp_x = x;
		exp_y = y;
		imshow("dog", img);

	}
	
	
}
int main() {

	

	Mat src = imread("C:\\opencv\\sources\\samples\\data\\chicky_512.png");
	imshow("dog", src);
	setMouseCallback("dog", onMouse, &src);


	while (1) {
		int key = waitKey(1);
		
		if (key == 'a') {
			exp_x -= 10;
		}
		else if (key == 'w') {
			exp_y -= 10;

		}
		else if (key == 'd') {
			exp_x += 10;
		}
		else if (key == 's') {
			exp_y += 10;
		}
		Mat img = imread("C:\\opencv\\sources\\samples\\data\\chicky_512.png");
		circle(img, Point(exp_x, exp_y), 200, Scalar(0, 255, 0), 10);
		putText(img, "I found a dog!", Point(exp_x, exp_y + 200), FONT_HERSHEY_PLAIN, 2.0, 255, 2);
		imshow("dog", img);
		if (key == 'q') {
			imwrite(".//dog_catch.jpg", img);
		}
	}
	waitKey(0);
	


}