#include "../../common/mycv.hpp"

int main(int argc, const char* argv[]){
  // read image
  cv::Mat img = cv::imread("../imori_noise.jpg", cv::IMREAD_COLOR);

  // median filter
  cv::Mat out = mycv::median_filter(img, 3);
  
  cv::imwrite("answer_10.jpg", out);
  // cv::imshow("answer", out);
  // cv::waitKey(0);
  // cv::destroyAllWindows();

  return 0;
}
