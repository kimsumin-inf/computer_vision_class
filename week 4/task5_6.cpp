#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
static int Count = 0;
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
		line(hist_img, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - hist_b[i]), Scalar(255, 0, 0));
		line(hist_img, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - hist_g[i]), Scalar(0, 255, 0));
		line(hist_img, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - hist_r[i]), Scalar(0, 0, 255));
	}
	if (Count == 0)
	{
		imshow("Histogram", hist_img);
		Count++;
	}
	else if (Count ==1)
		imshow("binary_hist",hist_img);

}
void draw_hist(int *hist) {
	int bin = 256;
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w/256);
	Mat hist_img(hist_h, hist_w, CV_8UC3, Scalar(255,255,255));
	int max= hist[0];

	for (int i = 1; i < bin; i++) {
		if (max < hist[i]) {
			max = hist[i];
		}
	}
	

	for (int i = 0; i < bin - 1; i++) {
		hist[i] = floor(((double)hist[i] / max) * hist_img.rows);
		
	}

	for (int i = 0; i < bin - 1; i++) {
		line(hist_img, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - hist[i]), Scalar(0));
		
	}

	imshow("binary_Histogram", hist_img);
		

}
int main() {
	Mat img = imread("./lenna.jpg");
	int th;
	cin >> th;
	vector<Mat> split_img;
	split(img, split_img);
	for (int i=0;i<3;i++){
		equalizeHist(split_img[i], split_img[i]);
	}
	imshow("origin_image", img);
	merge(split_img,  img);
	
	int* hist_r = new int[256] {};
	int* hist_g = new int[256] {};
	int* hist_b = new int[256] {};
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			hist_b[(int)img.at<Vec3b>(i, j)[0]]++;
			hist_g[(int)img.at<Vec3b>(i, j)[1]]++;
			hist_r[(int)img.at<Vec3b>(i, j)[2]]++;


		}
	}
	
	draw_hist(hist_b, hist_g, hist_r,256);
	imshow("equalize_hist_image", img);
	cvtColor(img, img, COLOR_BGR2GRAY);

	
	Mat binary_img,otsu;
	threshold(img, binary_img,th,255, THRESH_BINARY);
	threshold(img, otsu, th, 255, THRESH_BINARY|THRESH_OTSU);
	
	int hist[256] = {};
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			hist[(int)binary_img.at<uchar>(i, j)]++;
			
			
		}
	}

	draw_hist(hist);

	
	imshow("binary_img", binary_img);
	imshow("otsu", otsu);
	waitKey(0);
	
	delete[] hist_r;
	delete[] hist_g;
	delete[] hist_b;
	
}