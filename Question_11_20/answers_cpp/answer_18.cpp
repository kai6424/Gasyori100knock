#include "../../common/mycv.hpp"

int main(int argc, const char* argv[]){
  // read image
  cv::Mat img = cv::imread("../imori.jpg", cv::IMREAD_COLOR);

  // BGR -> Gray
  cv::Mat gray = mycv::BGR2GRAY(img);

  // emboss filter
  cv::Mat out = mycv::emboss_filter(gray, 3);
  
  cv::imwrite("answer_18.jpg", out);
  // cv::imshow("answer", out);
  // cv::waitKey(0);
  // cv::destroyAllWindows();
 
  return 0;
}
