#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat f[3] = { imread("./Lenna.png") ,imread("./Lenna.png") ,imread("./Lenna.png") };
	int alpha, beta;
	cout << "alpha: ";
	cin >> alpha;
	cout << "\nBeta: ";
	cin >> beta;

	Mat g = (1 - alpha - beta) * f[0] + alpha * f[1] + beta * f[2];

	imshow("result", g);
	waitKey(0);
}