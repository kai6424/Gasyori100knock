#include "../../common/mycv.hpp"

int main(int argc, const char* argv[]){
  // read image
  cv::Mat img = cv::imread("../imori.jpg", cv::IMREAD_COLOR);

  // BGR -> Gray
  cv::Mat gray = mycv::BGR2GRAY(img);

  // prewitt filter (vertical)
  cv::Mat out_v = mycv::prewitt_filter(gray, 3, false);

  // prewitt filter (horizontal)
  cv::Mat out_h = mycv::prewitt_filter(gray, 3, true);
  
  cv::imwrite("answer_15_v.jpg", out_v);
  cv::imwrite("answer_15_h.jpg", out_h);
  // cv::imshow("answer (vertical)", out_v);
  // cv::imshow("answer (horizontal)", out_h);
  // cv::waitKey(0);
  // cv::destroyAllWindows();
 
  return 0;
}
