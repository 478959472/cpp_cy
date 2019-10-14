#include <iostream>
//下面两个是opencv的目录，注意一下
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using  namespace std;
using  namespace cv;


int main() {
    std::cout << "Hello, World!" << std::endl;
    Mat img = imread("C:\\Users\\montnets\\vsworkspace\\repos\\cpp_cy\\opencv_clion_test\\1.png");
    imshow("Lena", img);
    waitKey(0);
    return 0;
}