#include <opencv/highgui.h> ///Open�����إ~��
int main()
{
    IplImage * img = cvLoadImage("c:/micky.jpg");

    cvShowImage("img",img);
    cvWaitKey(0);/// �����N��A�A�~��
}
