#include "../../common/mycv.hpp"

int main(int argc, const char* argv[]){
  // read image
  cv::Mat img = cv::imread("../imori.jpg", cv::IMREAD_COLOR);

  // BGR -> HSV
  cv::Mat hsv = mycv::BGR2HSV(img);

  // Inverse Hue
  hsv = mycv::inverse_hue(hsv);

  // Gray -> Binary
  cv::Mat out = mycv::HSV2BGR(hsv);

  cv::imwrite("answer_5.jpg", out);
  // cv::imshow("sample", out);
  // cv::waitKey(0);
  // cv::destroyAllWindows();

  return 0;
}
