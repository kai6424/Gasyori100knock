#include "../../common/mycv.hpp"

int main(int argc, const char* argv[]){
  // read image
  cv::Mat img = cv::imread("../imori.jpg", cv::IMREAD_COLOR);

  // BGR -> Gray
  cv::Mat gray = mycv::BGR2GRAY(img);

  // laplacian filter
  cv::Mat out = mycv::laplacian_filter(gray, 3);
  
  cv::imwrite("answer_17.jpg", out);
  // cv::imshow("answer", out);
  // cv::waitKey(0);
  // cv::destroyAllWindows();
 
  return 0;
}
