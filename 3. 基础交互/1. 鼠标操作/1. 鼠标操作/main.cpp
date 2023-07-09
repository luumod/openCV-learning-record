#include <iostream>
#include <opencv2/opencv.hpp>

class DrawShape {
public:
	DrawShape() :m1(cv::imread("dog.png")) {}
	void show(const std::string& title="mainWindow") {
		cv::imshow(title, m1);
	}
	void drawCircle(int x,int y,int r) {
		cv::circle(m1, cv::Point(x, y), r, cv::Scalar(128, 203, 196));
	}
	void drawRectangle(int x, int y, int w, int h) {
		cv::rectangle(m1, cv::Rect(x, y, w, h), cv::Scalar(255, 0, 0));
	}
	static void mouseEvent(int event, int x, int y, int flag, void* params) {
		DrawShape* obj = static_cast<DrawShape*>(params);
		if (event == cv::EVENT_FLAG_LBUTTON) {
			//左键画圆
			obj->drawCircle(x, y, 20);
		}
		else if (event == cv::EVENT_FLAG_RBUTTON) {
			obj->drawRectangle(x, y, 20, 20);
		}
	}
private:
	cv::Mat m1;
};

int main()
{
	DrawShape* p = new DrawShape();

	//鼠标处理过程
	cv::namedWindow("mainWindow");
	//typedef void (*MouseCallback)
	//			(int event, int x, int y, int flags, void* userdata);
	cv::setMouseCallback("mainWindow", &DrawShape::mouseEvent, p);

	while (true) {
		p->show();
		if (cv::waitKey(10) == 27) {
			break;
		}
	}
	delete p;
	p = nullptr;
	return 0;
}