#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	VideoCapture cap("C:\\Users\\sumin\\Desktop\\2021-2 수업\\computer vision\\class\\week2\\KakaoTalk_20210913_174308198.mp4"); // 비디오
	//VideoCapture cap(0); // 카메라 영상
	if (!cap.isOpened()) cout << "해당 경로에 영상이 없습니다" << endl;
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