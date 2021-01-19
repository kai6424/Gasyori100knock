#include "../../common/mycv.hpp"

int main(int argc, const char* argv[]){
  // read image
  cv::Mat img = cv::imread("../imori.jpg", cv::IMREAD_COLOR);

  // BGR -> Gray
  cv::Mat out = mycv::BGR2GRAY(img);

  cv::imwrite("answer_2.jpg", out);
  // cv::imshow("sample", out);
  // cv::waitKey(0);
  // cv::destroyAllWindows();

  return 0;
}
