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

    // Gray -> Binary
    cv::Mat Binarize_Otsu(cv::Mat gray)
    {
        int width = gray.cols;
        int height = gray.rows;

        // determine threshold
        double w0 = 0, w1 = 0;
        double m0 = 0, m1 = 0;
        double max_sb = 0, sb = 0;
        int th = 0;
        int val;

        // Get threshold
        for (int t = 0; t < 255; t++)
        {
            w0 = 0;
            w1 = 0;
            m0 = 0;
            m1 = 0;
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    val = (int)(gray.at<uchar>(y, x));

                    if (val < t)
                    {
                        w0++;
                        m0 += val;
                    }
                    else
                    {
                        w1++;
                        m1 += val;
                    }
                }
            }

            m0 /= w0;
            m1 /= w1;
            w0 /= (height * width);
            w1 /= (height * width);
            sb = w0 * w1 * pow((m0 - m1), 2);

            if (sb > max_sb)
            {
                max_sb = sb;
                th = t;
            }
        }

        std::cout << "threshold:" << th << std::endl;

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

        // each y, x
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                // Binarize
                if (gray.at<uchar>(y, x) >= th)
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

    // BGR -> HSV
    cv::Mat BGR2HSV(cv::Mat img)
    {
        // get height and width
        int width = img.cols;
        int height = img.rows;

        float r, g, b;
        float h, s, v;
        float _max, _min;

        // prepare output
        cv::Mat hsv = cv::Mat::zeros(height, width, CV_32FC3);

        // each y, x
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                // BGR -> HSV
                r = (float)img.at<cv::Vec3b>(y, x)[2] / 255;
                g = (float)img.at<cv::Vec3b>(y, x)[1] / 255;
                b = (float)img.at<cv::Vec3b>(y, x)[0] / 255;

                _max = fmax(r, fmax(g, b));
                _min = fmin(r, fmin(g, b));

                // get Hue
                if (_max == _min)
                {
                    h = 0;
                }
                else if (_min == b)
                {
                    h = 60 * (g - r) / (_max - _min) + 60;
                }
                else if (_min == r)
                {
                    h = 60 * (b - g) / (_max - _min) + 180;
                }
                else if (_min == g)
                {
                    h = 60 * (r - b) / (_max - _min) + 300;
                }

                // get Saturation
                s = _max - _min;

                // get Value
                v = _max;

                hsv.at<cv::Vec3f>(y, x)[0] = h;
                hsv.at<cv::Vec3f>(y, x)[1] = s;
                hsv.at<cv::Vec3f>(y, x)[2] = v;
            }
        }
        return hsv;
    }

    // HSV -> BGR
    cv::Mat HSV2BGR(cv::Mat hsv)
    {
        // get height and width
        int width = hsv.cols;
        int height = hsv.rows;

        float h, s, v;
        double c, _h, _x;
        double r, g, b;

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

        // each y, x
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {

                h = hsv.at<cv::Vec3f>(y, x)[0];
                s = hsv.at<cv::Vec3f>(y, x)[1];
                v = hsv.at<cv::Vec3f>(y, x)[2];

                c = s;
                _h = h / 60;
                _x = c * (1 - abs(fmod(_h, 2) - 1));

                r = g = b = v - c;

                if (_h < 1)
                {
                    r += c;
                    g += _x;
                }
                else if (_h < 2)
                {
                    r += _x;
                    g += c;
                }
                else if (_h < 3)
                {
                    g += c;
                    b += _x;
                }
                else if (_h < 4)
                {
                    g += _x;
                    b += c;
                }
                else if (_h < 5)
                {
                    r += _x;
                    b += c;
                }
                else if (_h < 6)
                {
                    r += c;
                    b += _x;
                }

                out.at<cv::Vec3b>(y, x)[0] = (uchar)(b * 255);
                out.at<cv::Vec3b>(y, x)[1] = (uchar)(g * 255);
                out.at<cv::Vec3b>(y, x)[2] = (uchar)(r * 255);
            }
        }

        return out;
    }

    // inverse Hue
    cv::Mat inverse_hue(cv::Mat hsv)
    {
        int height = hsv.rows;
        int width = hsv.cols;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                hsv.at<cv::Vec3f>(y, x)[0] = fmod(hsv.at<cv::Vec3f>(y, x)[0] + 180, 360);
            }
        }

        return hsv;
    }

    // Dedcrease color
    cv::Mat decrease_color(cv::Mat img)
    {
        int height = img.cols;
        int width = img.rows;
        int channel = img.channels();

        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                for (int c = 0; c < channel; c++)
                {
                    out.at<cv::Vec3b>(y, x)[c] = (uchar)(floor((double)img.at<cv::Vec3b>(y, x)[c] / 64) * 64 + 32);
                }
            }
        }
        return out;
    }

    // average pooling
    cv::Mat average_pooling(cv::Mat img)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

        int r = 8;
        double v = 0;

        for (int y = 0; y < height; y += r)
        {
            for (int x = 0; x < width; x += r)
            {
                for (int c = 0; c < channel; c++)
                {
                    v = 0;
                    for (int dy = 0; dy < r; dy++)
                    {
                        for (int dx = 0; dx < r; dx++)
                        {
                            v += (double)img.at<cv::Vec3b>(y + dy, x + dx)[c];
                        }
                    }
                    v /= (r * r);
                    for (int dy = 0; dy < r; dy++)
                    {
                        for (int dx = 0; dx < r; dx++)
                        {
                            out.at<cv::Vec3b>(y + dy, x + dx)[c] = (uchar)v;
                        }
                    }
                }
            }
        }
        return out;
    }

    // max pooling
    cv::Mat max_pooling(cv::Mat img)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

        int r = 8;
        double v = 0;

        for (int y = 0; y < height; y += r)
        {
            for (int x = 0; x < width; x += r)
            {
                for (int c = 0; c < channel; c++)
                {
                    v = 0;
                    for (int dy = 0; dy < r; dy++)
                    {
                        for (int dx = 0; dx < r; dx++)
                        {
                            v = fmax(img.at<cv::Vec3b>(y + dy, x + dx)[c], v);
                        }
                    }

                    for (int dy = 0; dy < r; dy++)
                    {
                        for (int dx = 0; dx < r; dx++)
                        {
                            out.at<cv::Vec3b>(y + dy, x + dx)[c] = (uchar)v;
                        }
                    }
                }
            }
        }
        return out;
    }

    // gaussian filter
    cv::Mat gaussian_filter(cv::Mat img, double sigma, int kernel_size)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

        // prepare kernel
        int pad = floor(kernel_size / 2);
        int _x = 0, _y = 0;
        double kernel_sum = 0;

        // get gaussian kernel
        float kernel[kernel_size][kernel_size];

        for (int y = 0; y < kernel_size; y++)
        {
            for (int x = 0; x < kernel_size; x++)
            {
                _y = y - pad;
                _x = x - pad;
                kernel[y][x] = 1 / (2 * M_PI * sigma * sigma) * exp(-(_x * _x + _y * _y) / (2 * sigma * sigma));
                kernel_sum += kernel[y][x];
            }
        }

        for (int y = 0; y < kernel_size; y++)
        {
            for (int x = 0; x < kernel_size; x++)
            {
                kernel[y][x] /= kernel_sum;
            }
        }

        // filtering
        double v = 0;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                for (int c = 0; c < channel; c++)
                {

                    v = 0;

                    for (int dy = -pad; dy < pad + 1; dy++)
                    {
                        for (int dx = -pad; dx < pad + 1; dx++)
                        {
                            if (((x + dx) >= 0) && ((y + dy) >= 0))
                            {
                                v += (double)img.at<cv::Vec3b>(y + dy, x + dx)[c] * kernel[dy + pad][dx + pad];
                            }
                        }
                    }
                    out.at<cv::Vec3b>(y, x)[c] = v;
                }
            }
        }
        return out;
    }

    // median filter
    cv::Mat median_filter(cv::Mat img, int kernel_size)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

        // prepare kernel
        int pad = floor(kernel_size / 2);

        // filtering
        double v = 0;
        int vs[kernel_size * kernel_size];
        int count = 0;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                for (int c = 0; c < channel; c++)
                {
                    v = 0;
                    count = 0;

                    for (int i = 0; i < kernel_size * kernel_size; i++)
                    {
                        vs[i] = 999;
                    }

                    // get neighbor pixels
                    for (int dy = -pad; dy < pad + 1; dy++)
                    {
                        for (int dx = -pad; dx < pad + 1; dx++)
                        {
                            if (((y + dy) >= 0) && ((x + dx) >= 0))
                            {
                                vs[count++] = (int)img.at<cv::Vec3b>(y + dy, x + dx)[c];
                            }
                        }
                    }

                    // get and assign median
                    std::sort(vs, vs + (kernel_size * kernel_size));
                    out.at<cv::Vec3b>(y, x)[c] = (uchar)vs[int(floor(count / 2)) + 1];
                }
            }
        }
        return out;
    }

    // mean filter
    cv::Mat mean_filter(cv::Mat img, int kernel_size)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

        // prepare kernel
        int pad = floor(kernel_size / 2);

        // filtering
        double v = 0;
        int vs[kernel_size * kernel_size];
        int count = 0;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                for (int c = 0; c < channel; c++)
                {
                    v = 0;

                    // get pixel sum
                    for (int dy = -pad; dy < pad + 1; dy++)
                    {
                        for (int dx = -pad; dx < pad + 1; dx++)
                        {
                            if (((y + dy) >= 0) && ((x + dx) >= 0))
                            {
                                v += (int)img.at<cv::Vec3b>(y + dy, x + dx)[c];
                            }
                        }
                    }

                    // assign mean value
                    v /= (kernel_size * kernel_size);
                    out.at<cv::Vec3b>(y, x)[c] = (uchar)v;
                }
            }
        }
        return out;
    }

    // motion filter
    cv::Mat motion_filter(cv::Mat img, int kernel_size)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

        // prepare kernel
        int pad = floor(kernel_size / 2);

        double kernel[kernel_size][kernel_size]; //{{1./3, 0, 0}, {0, 1./3, 0}, {0, 0, 1./3}};

        for (int y = 0; y < kernel_size; y++)
        {
            for (int x = 0; x < kernel_size; x++)
            {
                if (y == x)
                {
                    kernel[y][x] = 1. / kernel_size;
                }
                else
                {
                    kernel[y][x] = 0;
                }
            }
        }

        // filtering
        double v = 0;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                for (int c = 0; c < channel; c++)
                {

                    v = 0;

                    for (int dy = -pad; dy < pad + 1; dy++)
                    {
                        for (int dx = -pad; dx < pad + 1; dx++)
                        {
                            if (((y + dy) >= 0) && ((x + dx) >= 0) && ((y + dy) < height) && ((x + dx) < width))
                            {
                                v += (double)img.at<cv::Vec3b>(y + dy, x + dx)[c] * kernel[dy + pad][dx + pad];
                            }
                        }
                    }
                    out.at<cv::Vec3b>(y, x)[c] = (uchar)v;
                }
            }
        }
        return out;
    }

    // max min filter
    cv::Mat max_min_filter(cv::Mat img, int kernel_size)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

        int pad = floor(kernel_size / 2);

        double vmax = 0, vmin = 999, v = 0;

        // filtering
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                vmax = 0;
                vmin = 999;
                for (int dy = -pad; dy < pad + 1; dy++)
                {
                    for (int dx = -pad; dx < pad + 1; dx++)
                    {
                        if (((y + dy) >= 0) && ((x + dx) >= 0) && ((y + dy) < height) && ((x + dx) < width))
                        {
                            v = (double)img.at<uchar>(y + dy, x + dx);
                            if (v > vmax)
                            {
                                vmax = v;
                            }
                            if (v < vmin)
                            {
                                vmin = v;
                            }
                        }
                    }
                }
                out.at<uchar>(y, x) = (uchar)(vmax - vmin);
            }
        }
        return out;
    }

    // max min filter
    cv::Mat diff_filter(cv::Mat img, int kernel_size, bool horizontal)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

        // prepare kernel
        double kernel[kernel_size][kernel_size] = {{0, -1, 0}, {0, 1, 0}, {0, 0, 0}};

        if (horizontal)
        {
            kernel[0][1] = 0;
            kernel[1][0] = -1;
        }

        int pad = floor(kernel_size / 2);

        double v = 0;

        // filtering
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                v = 0;
                for (int dy = -pad; dy < pad + 1; dy++)
                {
                    for (int dx = -pad; dx < pad + 1; dx++)
                    {
                        if (((y + dy) >= 0) && ((x + dx) >= 0) && ((y + dy) < height) && ((x + dx) < width))
                        {
                            v += img.at<uchar>(y + dy, x + dx) * kernel[dy + pad][dx + pad];
                        }
                    }
                }
                v = fmax(v, 0);
                v = fmin(v, 255);
                out.at<uchar>(y, x) = (uchar)v;
            }
        }
        return out;
    }

    // prewitt filter
    cv::Mat prewitt_filter(cv::Mat img, int kernel_size, bool horizontal)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

        // prepare kernel
        double kernel[kernel_size][kernel_size] = {{-1, -1, -1}, {0, 0, 0}, {1, 1, 1}};

        if (horizontal)
        {
            kernel[0][1] = 0;
            kernel[0][2] = 1;
            kernel[1][0] = -1;
            kernel[1][2] = 1;
            kernel[2][0] = -1;
            kernel[2][1] = 0;
        }

        int pad = floor(kernel_size / 2);

        double v = 0;

        // filtering
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                v = 0;
                for (int dy = -pad; dy < pad + 1; dy++)
                {
                    for (int dx = -pad; dx < pad + 1; dx++)
                    {
                        if (((y + dy) >= 0) && ((x + dx) >= 0) && ((y + dy) < height) && ((x + dx) < width))
                        {
                            v += img.at<uchar>(y + dy, x + dx) * kernel[dy + pad][dx + pad];
                        }
                    }
                }
                v = fmax(v, 0);
                v = fmin(v, 255);
                out.at<uchar>(y, x) = (uchar)v;
            }
        }
        return out;
    }

    // Sobel filter
    cv::Mat sobel_filter(cv::Mat img, int kernel_size, bool horizontal)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

        // prepare kernel
        double kernel[kernel_size][kernel_size] = {{1, 2, 1}, {0, 0, 0}, {-1, -2, -1}};

        if (horizontal)
        {
            kernel[0][1] = 0;
            kernel[2][1] = 0;
            kernel[1][0] = 2;
            kernel[1][2] = -2;
        }

        int pad = floor(kernel_size / 2);

        double v = 0;

        // filtering
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                v = 0;
                for (int dy = -pad; dy < pad + 1; dy++)
                {
                    for (int dx = -pad; dx < pad + 1; dx++)
                    {
                        if (((y + dy) >= 0) && ((x + dx) >= 0) && ((y + dy) < height) && ((x + dx) < width))
                        {
                            v += img.at<uchar>(y + dy, x + dx) * kernel[dy + pad][dx + pad];
                        }
                    }
                }
                v = fmax(v, 0);
                v = fmin(v, 255);
                out.at<uchar>(y, x) = (uchar)v;
            }
        }
        return out;
    }

    // laplacian filter
    cv::Mat laplacian_filter(cv::Mat img, int kernel_size)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

        // prepare kernel
        double kernel[kernel_size][kernel_size] = {{0, 1, 0}, {1, -4, 1}, {0, 1, 0}};

        int pad = floor(kernel_size / 2);

        double v = 0;

        // filtering
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                v = 0;
                for (int dy = -pad; dy < pad + 1; dy++)
                {
                    for (int dx = -pad; dx < pad + 1; dx++)
                    {
                        if (((y + dy) >= 0) && ((x + dx) >= 0) && ((y + dy) < height) && ((x + dx) < width))
                        {
                            v += img.at<uchar>(y + dy, x + dx) * kernel[dy + pad][dx + pad];
                        }
                    }
                }
                v = fmax(v, 0);
                v = fmin(v, 255);
                out.at<uchar>(y, x) = (uchar)v;
            }
        }
        return out;
    }

    // emboss filter
    cv::Mat emboss_filter(cv::Mat img, int kernel_size)
    {
        int height = img.rows;
        int width = img.cols;
        int channel = img.channels();

        // prepare output
        cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

        // prepare kernel
        double kernel[kernel_size][kernel_size] = {{-2, -1, 0}, {-1, 1, 1}, {0, 1, 2}};

        int pad = floor(kernel_size / 2);

        double v = 0;

        // filtering
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                v = 0;
                for (int dy = -pad; dy < pad + 1; dy++)
                {
                    for (int dx = -pad; dx < pad + 1; dx++)
                    {
                        if (((y + dy) >= 0) && ((x + dx) >= 0) && ((y + dy) < height) && ((x + dx) < width))
                        {
                            v += img.at<uchar>(y + dy, x + dx) * kernel[dy + pad][dx + pad];
                        }
                    }
                }
                v = fmax(v, 0);
                v = fmin(v, 255);
                out.at<uchar>(y, x) = (uchar)v;
            }
        }
        return out;
    }
} // namespace mycv
