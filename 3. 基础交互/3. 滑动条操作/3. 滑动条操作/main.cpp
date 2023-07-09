#include <iostream>
#include <opencv2/opencv.hpp>

class TrackBar {
public:
	TrackBar() :mt(cv::imread("dog.png")),current(6),maxValue(30) {}
	int* getData() {
		return &current; //传递給trackbar需要是一个指针
	}
	int getMaxValue() {
		return maxValue;
	}
	//滑动条回调函数
	static void OnTrack(int pos,void* params){
		TrackBar* obj = static_cast<TrackBar*>(params);
		cv::Mat copyMat = cv::Mat::zeros(obj->mt.size(), obj->mt.type());
		int dims = obj->mt.channels();
		float beta = 30, alpha = 0.1 + (float)pos / 10.0;
		for (int i = 0; i < obj->mt.rows; i++) {
			for (int j = 0; j < obj->mt.cols; j++) {
				if (dims == 1) {
					uchar pix = obj->mt.at<uchar>(i, j);
					copyMat.at<uchar>(i,j) = cv::saturate_cast<uchar>(pix * alpha + beta);
				}
				else if (dims == 3) {
					cv::Vec3b vec = obj->mt.at<cv::Vec3b>(i, j);
					float b = vec[0], g = vec[1], r = vec[2];
					copyMat.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(b * alpha + beta);
					copyMat.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(g * alpha + beta);
					copyMat.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(r * alpha + beta);
				}
				else {
					return;
				}
			}		
		}
		cv::imshow("trackBarWindow", copyMat); //显示操作后的图像
	}
private:
	cv::Mat mt;
	int current;
	int maxValue;
};

int main()
{
	TrackBar* tbar = new TrackBar();

	//创建窗口
	cv::namedWindow("trackBarWindow");
	cv::createTrackbar("调整亮度", "trackBarWindow",
		tbar->getData(), tbar->getMaxValue(), &TrackBar::OnTrack, tbar);
	cv::waitKey(0);
	delete tbar;
	tbar = nullptr;
	return 0;
}