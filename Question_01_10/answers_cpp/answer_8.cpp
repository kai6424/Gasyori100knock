#include "../../common/mycv.hpp"

int main(int argc, const char* argv[]){
  // read image
  cv::Mat img = cv::imread("../imori.jpg", cv::IMREAD_COLOR);

  // max pooling
  cv::Mat out = mycv::max_pooling(img);
  
  cv::imwrite("answer_8.jpg", out);
  // cv::imshow("answer", out);
  // cv::waitKey(0);
  // cv::destroyAllWindows();

  return 0;
}
