#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	VideoCapture cap("C:\\Users\\sumin\\Desktop\\2021-2 ����\\computer vision\\class\\week2\\KakaoTalk_20210913_174308198.mp4"); // ����
	//VideoCapture cap(0); // ī�޶� ����
	if (!cap.isOpened()) cout << "�ش� ��ο� ������ �����ϴ�" << endl;
	Mat video,gray;
	while (true) {
		cap >> video;

		imshow("video", video);
		cvtColor(video, gray, CV_BGR2GRAY);
		imshow("gray_video", gray);
		
		if (waitKey(10) == 'q') {
			break;
		}
	}

}