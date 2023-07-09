#include <iostream>
#include <opencv2/opencv.hpp>


void testProerity(cv::VideoCapture vap) {
	std::cout << "宽度: " << vap.get(cv::CAP_PROP_FRAME_WIDTH) << '\n';
	std::cout << "高度: " << vap.get(cv::CAP_PROP_FRAME_HEIGHT) << '\n';
	std::cout << "帧数: " << vap.get(cv::CAP_PROP_FRAME_COUNT) << '\n';
	std::cout << "帧率: " << vap.get(cv::CAP_PROP_FPS) << '\n';
}
void CameraCapture() {
	cv::VideoCapture vap2(0);
	if (!vap2.isOpened()) {
		std::cout << "摄像头打开失败!\n";
		return;
	}
	cv::Mat image;
	while (true) {
		vap2 >> image;
		if (image.empty()) {
			break;
		}
		cv::imshow("camera", image);
		cv::waitKey(27);
	}
	vap2.release();
}
void CameraSave() {
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) {
		std::cout << "摄像头打开失败!\n";
		return;
	}
	//获取宽度和高度
	int width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
	cv::VideoWriter save{};
	save.open("save.avi", 
		cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
		30, cv::Size(width,height), true);
	cv::Mat image;
	while (true) {
		cap >> image;
		cv::imshow("摄像头", image);
		save << image; //往流中写入
		if (cv::waitKey(10) == 27) {
			break;
		}
	}
	cap.release();
	save.release();
}
void testCameraToImageShow(cv::VideoCapture vedio) {
	//显示视频
	cv::Mat image;
	while (true) {
		vedio >> image;
		if (image.empty() || cv::waitKey(10) == 27) {
			break;//为null则结束
		}
		cv::imshow("cat", image);
	}
	vedio.release();
}
void testCameraToPngImageSave(cv::VideoCapture vedio,std::string& prefilename) {
	cv::Mat image;
	int index = 1;
	while (true) {
		vedio >> image;
		if (image.empty() || cv::waitKey(10) == 27) {
			break;
		}
		std::string name = prefilename + std::to_string(index++) + ".png";
		cv::imwrite(name, image);
	}
	vedio.release();
}
int main()
{
	//打开视频
	cv::VideoCapture vap("cat.MP4");
	if (!vap.isOpened()) {
		std::cout << "视频打开失败!\n";
		return -1;
	}
	
	testCameraToImageShow(vap);
	return 0;
}