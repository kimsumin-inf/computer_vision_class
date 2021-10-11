#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace cv;

int main() {
	srand(time(NULL));
	Mat img = imread("C:\\Users\\sumin\\Desktop\\2021-2 ����\\computer vision\\class\\week3\\ocean.jpg");
	int row = (rand() % (img.rows-20));
	int col = (rand() % (img.cols-20));
	int width = 1+(rand() % 19), height = 1+(rand() % 19);
	
	Rect bounds(0, 0, img.cols, img.rows);
	Rect r(col,row, width, height);
	Mat roi = img(r & bounds);
	
	
	//imshow("roi", roi);
	roi = (0, 0, 0);

	cout << "\nroi�� ��ġ" << endl << 
		"x: " << row <<endl<<
		"y: "<<col <<endl<<
		"����: "<<height<<endl<<
		"����: "<<width;

	imshow("img", img);
	
	cout << "\nroi = " << endl << roi << endl;
	waitKey(0);
}