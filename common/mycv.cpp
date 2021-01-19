#include "mycv.hpp"

namespace mycv
{
    void hello()
    {
        std::cout << "hello" << std::endl;
    }

    // Channel swap
    cv::Mat channel_swap(cv::Mat img)
    {
        // get height and width
        int width = img.cols;
        int height = img.rows;

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

        // each y, x
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                // R -> B
                out.at<cv::Vec3b>(y, x)[0] = img.at<cv::Vec3b>(y, x)[2];
                // B -> R
                out.at<cv::Vec3b>(y, x)[2] = img.at<cv::Vec3b>(y, x)[0];
                // G -> G
                out.at<cv::Vec3b>(y, x)[1] = img.at<cv::Vec3b>(y, x)[1];
            }
        }

        return out;
    }

    // BGR -> Gray
    cv::Mat BGR2GRAY(cv::Mat img)
    {
        // get height and width
        int width = img.cols;
        int height = img.rows;

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

        // each y, x
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                // BGR -> Gray
                out.at<uchar>(y, x) = 0.2126 * (float)img.at<cv::Vec3b>(y, x)[2] + 0.7152 * (float)img.at<cv::Vec3b>(y, x)[1] + 0.0722 * (float)img.at<cv::Vec3b>(y, x)[0];
            }
        }

        return out;
    }

    // Gray -> Binary
    cv::Mat Binarize(cv::Mat gray, int th)
    {
        int width = gray.cols;
        int height = gray.rows;

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

        // each y, x
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                // Binarize
                if (gray.at<uchar>(y, x) > th)
                {
                    out.at<uchar>(y, x) = 255;
                }
                else
                {
                    out.at<uchar>(y, x) = 0;
                }
            }
        }

        return out;
    }
} // namespace mycv
