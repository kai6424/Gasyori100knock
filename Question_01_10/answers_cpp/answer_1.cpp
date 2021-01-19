#include "../../common/mycv.hpp"

int main(int argc, const char *argv[])
{
  // read image
  cv::Mat img = cv::imread("../imori.jpg", cv::IMREAD_COLOR);

  // channel swap
  cv::Mat out = mycv::channel_swap(img);

  cv::imwrite("answer_1.jpg", out);
  // cv::imshow("sample", out);
  // cv::waitKey(0);
  // cv::destroyAllWindows();

  return 0;
}
