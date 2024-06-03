#include <opencv/highgui.h> ///‰ΩøÁî® OpenCV 2.1 ÊØîË?Á∞°ÂñÆ, ?™Ë???High GUI ?≥ÂèØ
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVËÆÄ??
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCVËΩâËâ≤ÂΩ?(?ÄË¶Åcv.h)
    glEnable(GL_TEXTURE_2D); ///1. ?ãÂ?Ë≤ºÂ??üËÉΩ
    GLuint id; ///Ê∫ñÂ?‰∏Ä??unsigned int ?¥Êï∏, ??Ë≤ºÂ?ID
    glGenTextures(1, &id); /// ?¢Á?Generate Ë≤ºÂ?ID
    glBindTexture(GL_TEXTURE_2D, id); ///Á∂ÅÂ?bind Ë≤ºÂ?ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// Ë≤ºÂ??ÉÊï∏, Ë∂ÖÈ??ÖË??ÑÁ??ñT, Â∞±È?Ë¶ÜË≤º??
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// Ë≤ºÂ??ÉÊï∏, Ë∂ÖÈ??ÖË??ÑÁ??ñS, Â∞±È?Ë¶ÜË≤º??
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// Ë≤ºÂ??ÉÊï∏, ?æÂ§ß?ÇÁ??ßÊ?, ?®Ê?ËøëÈ?
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// Ë≤ºÂ??ÉÊï∏, Á∏ÆÂ??ÇÁ??ßÊ?, ?®Ê?ËøëÈ?
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
int id1,id2;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D,id1);
    glBegin(GL_POLYGON);
        glTexCoord2f(0,0);glVertex2f(-1,+1);
        glTexCoord2f(0,1);glVertex2f(-1,-1);
        glTexCoord2f(0,1);glVertex2f(+1,-1);
        glTexCoord2f(1,0);glVertex2f(+1,+1);
        glEnd();
    glBindTexture(GL_TEXTURE_2D,id2);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week16-3_My_Texture");

    glutDisplayFunc(display);
    id1 = myTexture("c:/d5049597.jpg");
    id2 = myTexture("c:/earth.jpg");
    glutMainLoop();
}
