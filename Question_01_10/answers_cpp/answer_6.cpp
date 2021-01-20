#include "../../common/mycv.hpp"

int main(int argc, const char* argv[]){
  // read image
  cv::Mat img = cv::imread("../imori.jpg", cv::IMREAD_COLOR);

  // decrease color
  cv::Mat out = mycv::decrease_color(img);
  
  cv::imwrite("answer_6.jpg", out);
  // cv::imshow("answer", out);
  // cv::waitKey(0);
  // cv::destroyAllWindows();

  return 0;
}
