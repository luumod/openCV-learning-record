#include <iostream>
#include <opencv2/opencv.hpp>

class ImgPixel {
public:
	ImgPixel(std::string filename):m(cv::imread(filename)){}
	void show(std::string title) {
		cv::imshow(title, m);
	}
	void Visit_By_Array() {
		auto dims = m.channels(); //获取通道数
		for (int i = 0; i < m.rows; i++) {
			for (int j = 0; j < m.cols; j++) {
				if (dims == 1) {
					//如果是一通道，则直接操作
					uchar rets = m.at<uchar>(i, j);
					rets = 255 - rets;
				}
				if (dims == 3) {
					cv::Vec3b rets = m.at<cv::Vec3b>(i, j);
#if 0
					m.at<cv::Vec3b>(i, j)[0] = 255 - rets[0];
					m.at<cv::Vec3b>(i, j)[1] = 255 - rets[1];
					m.at<cv::Vec3b>(i, j)[2] = 255 - rets[2];
#else 
					//安全类型转换： 超过255的赋值为 255 小于0的赋值为 0
					m.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(rets[0] + 100);
					m.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(rets[1] + 100);
					m.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(rets[2] + 100);
#endif
				}
			}
		}
	}
private:
	cv::Mat m;
};
int main(){
	ImgPixel img("dog.png");
	img.show("origin");
	img.Visit_By_Array();
	img.show("convert1");

	cv::waitKey(0);
	return 0;
}