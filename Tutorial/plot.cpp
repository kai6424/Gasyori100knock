#include <matplotlib-cpp/matplotlibcpp.h>

namespace plt = matplotlibcpp;

int main()
{
    plt::plot({1, 3, 2, 4});

    // output（jpgでエラーになる）
    plt::save("plot.png");

    return 0;
}
