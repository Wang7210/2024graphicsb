#include <opencv/highgui.h> ///Open的內建外掛
int main()
{
    IplImage * img = cvLoadImage("c:/micky.jpg");

    cvShowImage("img",img);
    cvWaitKey(0);/// 等任意鍵，再繼續
}
