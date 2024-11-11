#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat output = cv::Mat::zeros(new_rows, new_cols, input.type());

    for (int y = 0; y < new_rows; ++y) {
        for (int x = 0; x < new_cols; ++x) {
            // 计算新图像中点 (x, y) 对应原始图像中的点
            int x0 = static_cast<int>(x / scale);
            int y0 = static_cast<int>(y / scale);

            // 确保坐标在原始图像范围内
            x0 = std::max(0, std::min(x0, input.cols - 1));
            y0 = std::max(0, std::min(y0, input.rows - 1));

            // 将原始图像中的像素值复制到新图像中
            output.at<cv::Vec3b>(y, x) = input.at<cv::Vec3b>(y0, x0);
        }
    }

    return output;//cv::Mat::zeros(new_rows, new_cols, input.type());
}