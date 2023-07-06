#include <iostream>
#include <opencv2/opencv.hpp>

void testShow() {
	cv::Mat	m1(200, 200, CV_8UC1);
	cv::imshow("1", m1);
	//std::cout << m << '\n';
	cv::Mat m2(200, 200, CV_8UC3, cv::Scalar(255, 0, 255));
	cv::imshow("2", m2);

	cv::Mat m3 = m2.clone();
	cv::imshow("3", m3);

	cv::Mat m4;
	m3.copyTo(m4);	
	cv::imshow("4", m4);

	//imread
	cv::Mat m5 = cv::imread("images/mm.png", cv::ImreadModes::IMREAD_GRAYSCALE);
	cv::imshow("5", m5);
}
void testPrint() {
	cv::Mat m(10, 10, CV_8UC1);
	std::cout << "Mat: \n"<<m << '\n';
	//格式化
	std::cout << "C: \n" << cv::format(m, cv::Formatter::FMT_C);
	std::cout << "numpy: \n" << cv::format(m, cv::Formatter::FMT_NUMPY);
}
void testSaveFile(cv::String filename) {
	auto m = cv::imread("./images/dog.png" ,cv::ImreadModes::IMREAD_GRAYSCALE);	
	cv::imshow("dog", m);
	cv::imwrite(filename, m);
}
int main() {
	testSaveFile("./images/reduced_dog.png");
	cv::waitKey();
	return 0;
}