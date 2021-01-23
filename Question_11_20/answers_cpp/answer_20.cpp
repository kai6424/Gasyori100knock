#include "../../common/mycv.hpp"

int main(int argc, const char *argv[])
{
    // read image
    cv::Mat img = cv::imread("../imori_dark.jpg", cv::IMREAD_COLOR);

    // prepare
    std::vector<uchar> v;
    img = img.reshape(1, 1);
    img.copyTo(v);
    plt::xlim(0, 255);

    // make histgram
    plt::hist(v, 256);

    plt::save("answer_20.png");
    // plt::show();

    return 0;
}
