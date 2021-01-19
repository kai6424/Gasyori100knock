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
} // namespace mycv

#endif
