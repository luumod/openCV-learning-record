#include <iostream>
#include <opencv2/opencv.hpp>


/*
RGB 颜色模型
*/
struct XColor {
	unsigned int color : 15;
};
void getRGB555() {
	XColor col{};
	col.color = 0b110000010111100;
	std::cout << "R: " << (col.color >> 10) << '\n';
	std::cout << "G: " << ((col.color & 0x3F0) >> 5) << '\n';
	std::cout << "B: " << (col.color & 0x1F) << '\n';
}
void getRGB32() {
	int color = 0x0F0A2B0C;
	std::cout << "B: " << (color >> 24) << '\n';
	std::cout << "G: " << ((color & 0x00FF0000) >> 16) << '\n';
	std::cout << "R: " << ((color & 0x0000FF00) >> 8) << '\n';
	std::cout << "Alpha: " << (color & 0x000000FF) << '\n';
}

/*
HSV 颜色模型
*/
void test() {
	cv::Mat m1 = cv::imread("dog.png");
	cv::imshow("ori", m1);
	// HSV图像
	cv::Mat res;
	cv::cvtColor(m1, res, cv::ColorConversionCodes::COLOR_BGR2HSV);
	cv::imshow("hsv", res);
	// 单独显示HSV的图像
	std::vector<cv::Mat> vec;
	cv::split(m1, vec);
	cv::imshow("H", vec[0]);
	cv::imshow("S", vec[1]);
	cv::imshow("V", vec[2]);
	//HLS图像
	cv::cvtColor(m1, res, cv::ColorConversionCodes::COLOR_BGR2HLS);
	cv::imshow("hls", res);

	cv::cvtColor(m1, res, cv::ColorConversionCodes::COLOR_BGR2Lab);
	cv::imshow("Lab", res);

	cv::cvtColor(m1, res, cv::ColorConversionCodes::COLOR_BGR2YCrCb);
	cv::imshow("YCrCb", res);
	while (cv::waitKey() != 27) {}
}

// 封装颜色转换模型
class MColor {
public:
	MColor(std::string filename) :m(cv::imread(filename)) {}
	void show(std::string title) {
		cv::imshow(title, m);
	}
	void convert(std::string title, cv::ColorConversionCodes type) {
		cv::Mat res;
		cv::cvtColor(m, res, type);
		cv::imshow(title, res);
	}
private:
	cv::Mat m;
};
int main() {
	getRGB555();
	getRGB32();
	//test();

	MColor c("dog.png");
	c.show("origin");
	c.convert("hsv", cv::COLOR_BGR2HSV);
	c.convert("hls", cv::COLOR_BGR2HLS);
	c.convert("lab", cv::COLOR_BGR2Lab);
	c.convert("gray", cv::COLOR_BGR2GRAY);

	cv::waitKey(0);

	return 0;
}