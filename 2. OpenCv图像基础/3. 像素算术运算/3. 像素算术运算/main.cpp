#include <iostream>
#include <opencv2/opencv.hpp>

class ImgOperation {
public:
	ImgOperation() :m1(cv::imread("dog.png")), m2(cv::imread("text.jpg")) {}
	void testAdd(std::string title="add") {
		cv::add(m1, m2, res);
		cv::imshow(title, res);
		cv::waitKey();
	}
	void testSub(std::string title = "subtract") {
		cv::subtract(m1, m2, res);
		cv::imshow(title, res);
		cv::waitKey();
	}
	void testMul(std::string title = "multiply") {
		cv::multiply(m1, m2, res);
		cv::imshow(title, res);
		cv::waitKey();
	}
	void testDivide(std::string title = "divide") {
		cv::divide(m1, m2, res);
		cv::imshow(title, res);
		cv::waitKey();
	}
	void testAddWeighted(std::string title="AddWeighted") {
		cv::addWeighted(m1, 0.1, m2, 0.9, 0, res);
		cv::imshow(title, res);
		cv::waitKey();
	}
	//BitWise
	void testBitWise() {
		cv::Mat _and, _or, _xor, _not;
		cv::bitwise_and(m1, m2, _and);
		cv::bitwise_or(m1, m2, _or);
		cv::bitwise_xor(m1, m2, _xor);
		cv::bitwise_not(m1, _not);

		cv::imshow("and", _and);
		cv::imshow("or", _or);
		cv::imshow("xor", _xor);
		cv::imshow("not", _not);
	}
private:
	cv::Mat m1;
	cv::Mat m2;
	cv::Mat res;
};

int main()
{
	ImgOperation opt;
	opt.testAdd();
	opt.testSub();
	opt.testMul();
	opt.testDivide();
	opt.testAddWeighted();	
	opt.testBitWise();

	cv::waitKey();
	return 0;
}