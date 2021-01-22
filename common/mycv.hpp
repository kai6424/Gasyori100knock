/**
 * @file mycv.hpp
 * @brief 画像処理
 * @date 2021/1/19
 * @details 画像処理を機能する関数の集合
 */

#ifndef MYCV_HPP
#define MYCV_HPP

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <math.h>

/**
 * @namespace mycv
 * @brief 画像処理の名前空間
 * @details 画像処理の名前空間
 */
namespace mycv
{
    void hello();

    /**
     * @brief Q1. 画像のRGBをBGRに入れ替える
     * @param img 3チャンネルの画像。
     * @return 3チャンネルの画像
     */
    cv::Mat channel_swap(cv::Mat img);

    /**
     * @brief Q2. 画像をグレースケールにする
     * @param img 3チャンネルの画像。
     * @return 1チャンネルの画像
     */
    cv::Mat BGR2GRAY(cv::Mat img);

    /**
     * @brief Q3. 画像を二値化にする
     * @param gray 1チャンネルの画像。
     * @param th しきい値。
     * @return 1チャンネルの画像
     */
    cv::Mat Binarize(cv::Mat gray, int th);

    /**
     * @brief Q4. 画像を二値化にする（大津）
     * @param gray 1チャンネルの画像。
     * @return 1チャンネルの画像
     */
    cv::Mat Binarize_Otsu(cv::Mat gray);

    /**
     * @brief Q5. BGR画像をHSV画像に変換する
     * @param img 3チャンネル8ビットの符号なしの画像。
     * @return 3チャンネル32ビットの浮動小数点数の画像。
     */
    cv::Mat BGR2HSV(cv::Mat img);

    /**
     * @brief Q5. HSV画像をBGR画像に変換する
     * @param hsv 3チャンネル32ビットの浮動小数点数の画像。
     * @return 3チャンネル8ビットの符号なしの画像。
     */
    cv::Mat HSV2BGR(cv::Mat hsv);

    /**
     * @brief Q5. HSV画像の色相を反転する
     * @param hsv 3チャンネル32ビットの浮動小数点数の画像。
     * @return 3チャンネル32ビットの浮動小数点数の画像。
     */
    cv::Mat inverse_hue(cv::Mat hsv);

    /**
     * @brief Q6. 画像を256色から4色に減色する
     * @param img 3チャンネル8ビットの符号なしの画像。
     * @return 3チャンネル8ビットの符号なしの画像。
     */
    cv::Mat decrease_color(cv::Mat img);

    /**
     * @brief Q7. 平均プーリング
     * @param img 3チャンネル8ビットの符号なしの画像。
     * @return 3チャンネル8ビットの符号なしの画像。
     */
    cv::Mat average_pooling(cv::Mat img);

    /**
     * @brief Q8. Maxプーリング
     * @param img 3チャンネル8ビットの符号なしの画像。
     * @return 3チャンネル8ビットの符号なしの画像。
     */
    cv::Mat max_pooling(cv::Mat img);

    /**
     * @brief Q9. ガウシアンフィルタ
     * @param img 3チャンネル8ビットの符号なしの画像。
     * @param sigma 標準偏差
     * @param kernel_size ガウシアンフィルタの一辺のサイズ
     * @return 3チャンネル8ビットの符号なしの画像。
     */
    cv::Mat gaussian_filter(cv::Mat img, double sigma, int kernel_size);

    /**
     * @brief Q10. メディアンフィルタ
     * @param img 3チャンネル8ビットの符号なしの画像。
     * @param kernel_size メディアンフィルタの一辺の長さ
     * @return 3チャンネル8ビットの符号なしの画像。
     */
    cv::Mat median_filter(cv::Mat img, int kernel_size);

    /**
     * @brief Q11. 平滑化フィルタ
     * @param img 3チャンネル8ビットの符号なしの画像。
     * @param kernel_size 平滑化フィルタの一辺の長さ。
     * @return 3チャンネル8ビットの符号なしの画像。
     */
    cv::Mat mean_filter(cv::Mat img, int kernel_size);

    /**
     * @brief Q12. モーションフィルタ
     * @param img 3チャンネル8ビットの符号なしの画像。
     * @param kernel_size モーションフィルタの一辺の長さ。
     * @return 3チャンネル8ビットの符号なしの画像。
     */
    cv::Mat motion_filter(cv::Mat img, int kernel_size);

    /**
     * @brief Q13. MAX-MINフィルタ
     * @param img 1チャンネル8ビットの符号なしの画像。
     * @param kernel_size MAX-MINフィルタの一辺の長さ。
     * @return 1チャンネル8ビットの符号なしの画像。
     */
    cv::Mat max_min_filter(cv::Mat img, int kernel_size);

    /**
     * @brief Q14. 微分フィルタ
     * @param img 1チャンネル8ビットの符号なしの画像。
     * @param kernel_size 微分フィルタの一辺の長さ。
     * @param horizontal true: 横方向にフィルタを適用する。false: 縦方向にフィルタを適用する。
     * @return 1チャンネル8ビットの符号なしの画像。
     */
    cv::Mat diff_filter(cv::Mat img, int kernel_size, bool horizontal);

    /**
     * @brief Q15. Prewittフィルタ
     * @param img 1チャンネル8ビットの符号なしの画像。
     * @param kernel_size Prewittフィルタの一辺の長さ。
     * @param horizontal true: 横方向にフィルタを適用する。false: 縦方向にフィルタを適用する。
     * @return 1チャンネル8ビットの符号なしの画像。
     */
    cv::Mat prewitt_filter(cv::Mat img, int kernel_size, bool horizontal);

    /**
     * @brief Q16. Sobelフィルタ
     * @param img 1チャンネル8ビットの符号なしの画像。
     * @param kernel_size フィルタの一辺の長さ。
     * @param horizontal true: 横方向にフィルタを適用する。false: 縦方向にフィルタを適用する。
     * @return 1チャンネル8ビットの符号なしの画像。
     */
    cv::Mat sobel_filter(cv::Mat img, int kernel_size, bool horizontal);

    /**
     * @brief Q17. Laplacianフィルタ
     * @param img 1チャンネル8ビットの符号なしの画像。
     * @param kernel_size フィルタの一辺の長さ。
     * @return 1チャンネル8ビットの符号なしの画像。
     */
    cv::Mat laplacian_filter(cv::Mat img, int kernel_size);

    /**
     * @brief Q18. Embossフィルタ
     * @param img 1チャンネル8ビットの符号なしの画像。
     * @param kernel_size フィルタの一辺の長さ。
     * @return 1チャンネル8ビットの符号なしの画像。
     */
    cv::Mat emboss_filter(cv::Mat img, int kernel_size);
} // namespace mycv

#endif
