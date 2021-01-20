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
} // namespace mycv

#endif
