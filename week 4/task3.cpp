#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

void draw_hist(int* hist_b, int* hist_g, int* hist_r, int bin) {
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / bin);
	Mat hist_img(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));
	int max[3] = { hist_b[0],hist_g[0],hist_r[0] };

	for (int i = 1; i < bin; i++) {
		if (max[0] < hist_b[i]) {
			max[0] = hist_b[i];
		}
	}
	for (int i = 1; i < bin; i++) {
		if (max[1] < hist_g[i]) {
			max[1] = hist_g[i];
		}
	}
	for (int i = 1; i < bin; i++) {
		if (max[2] < hist_r[i]) {
			max[2] = hist_r[i];
		}
	}

	for (int i = 0; i < bin - 1; i++) {
		hist_b[i] = floor(((double)hist_b[i] / max[0]) * hist_img.rows);
		hist_g[i] = floor(((double)hist_g[i] / max[1]) * hist_img.rows);
		hist_r[i] = floor(((double)hist_r[i] / max[2]) * hist_img.rows);
	}

	for (int i = 0; i < bin - 1; i++) {
		line(hist_img, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - hist_b[i]),Scalar(255,0,0));
		line(hist_img, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - hist_g[i]), Scalar(0,255, 0));
		line(hist_img, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - hist_r[i]), Scalar(0,0,255));
	}
	imshow("Histogram", hist_img);
	waitKey(0);

}
int main() {
	Mat src = imread("./lenna.jpg");
	int bin;
	cout << "bin : 32, 64, 128, 256 중에 하나를 선택하시오." << endl;
	cin >> bin;
	
	int* hist_r = new int[bin] {};
	int* hist_g = new int[bin] {};
	int* hist_b = new int[bin] {};
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			hist_b[(int)src.at<Vec3b>(i, j)[0] % bin]++;
			hist_g[(int)src.at<Vec3b>(i, j)[1] % bin]++;
			hist_r[(int)src.at<Vec3b>(i, j)[2] % bin]++;


		}
	}

	draw_hist(hist_b, hist_g, hist_r, bin);
	imshow("src", src);
	waitKey(0);
	delete[] hist_r;
	delete[] hist_g;
	delete[] hist_b;
	
}