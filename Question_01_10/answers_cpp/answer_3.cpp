#include "../../common/mycv.hpp"

int main(int argc, const char* argv[]){
  // read image
  cv::Mat img = cv::imread("../imori.jpg", cv::IMREAD_COLOR);

  // BGR -> Gray
  cv::Mat gray = mycv::BGR2GRAY(img);

  // Gray -> Binary
  cv::Mat out = mycv::Binarize(gray, 128);

  cv::imwrite("answer_3.jpg", out);
  // cv::imshow("sample", out);
  // cv::waitKey(0);
  // cv::destroyAllWindows();

  return 0;
}
