#include <iostream>
#include <opencv2/opencv.hpp>

class Draw {
public:
	Draw() :m(cv::imread("dog.png")) {}
	void testDrawLine() {
		//绘制线
		cv::line(m, cv::Point(0, 0), cv::Point(300, 300), cv::Scalar(0,255,0), 3, cv::LineTypes::LINE_AA);
	}
	void testDrawCircle() {
		cv::circle(m, cv::Point(150, 150), 50, cv::Scalar(0, 255, 0),-1); //填充圆
		cv::circle(m, cv::Point(150, 150), 52, cv::Scalar(0, 0, 255), 2, cv::LineTypes::LINE_AA); //空心圆
	}
	void testDrawRectangle() {
		cv::rectangle(m, cv::Rect(0, 0, 50, 50), cv::Scalar(100, 45, 20),-1);
	}
	void testDrawEllipse() {
		cv::ellipse(m, cv::Point(100, 100),cv::Size(20,80),180,0,360, cv::Scalar(54, 54, 43));
		cv::ellipse(m, cv::Point(100, 100), cv::Size(20, 80), 90, 0, 360, cv::Scalar(54, 54, 43),-1);
	}
	void testDrawText(const std::string& name) {
		cv::putText(m,
			name,
			cv::Point(10, 200),
			cv::HersheyFonts::FONT_HERSHEY_COMPLEX,
			1.0,
			cv::Scalar(50,50,255),
			2,
			cv::LineTypes::LINE_AA,
			false); //翻转
	}
	void show(const std::string& title = "origin") {
		cv::imshow(title, m);
	}
protected:
	cv::Mat m;
};

int main()
{
	Draw img;
	//img.testDrawLine();
	//img.testDrawCircle();
	//img.testDrawRectangle();
	//img.testDrawEllipse();
	img.testDrawText("Hello openCV");
	img.show();
	cv::waitKey();
	return 0;
}