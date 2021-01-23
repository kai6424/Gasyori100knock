#include "../../common/mycv.hpp"

int main(int argc, const char* argv[]){
  // read image
  cv::Mat img = cv::imread("../imori_dark.jpg", cv::IMREAD_COLOR);

  // histogram normalization
  cv::Mat out = mycv::histogram_normalization(img, 0, 255);
  
  cv::imwrite("answer_21.jpg", out);
  // cv::imshow("answer", out);
  // cv::waitKey(0);
  // cv::destroyAllWindows();
 
  return 0;
}
