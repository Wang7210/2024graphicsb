#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * Hand1 = NULL;
GLMmodel * Hand2 = NULL;
GLMmodel * upper = NULL;
GLMmodel * lower = NULL;
void drawmodel(void)
{
    if (!pmodel) {
        pmodel = glmReadOBJ("Hand2.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}
void drawHand1(void)
{
    if (!Hand1) {
        Hand1 = glmReadOBJ("Hand1.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!Hand1) exit(0);
        glmUnitize(Hand1);
        glmFacetNormals(Hand1);
        glmVertexNormals(Hand1, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}
void drawHand2(void)
{
    if (!Hand2) {
        Hand2 = glmReadOBJ("Hand2.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!Hand2) exit(0);
        glmUnitize(Hand2);
        glmFacetNormals(Hand2);
        glmVertexNormals(Hand2, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}
void drawUpper(void)
{
    if (!upper) {
        upper = glmReadOBJ("upper.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!upper) exit(0);
        glmUnitize(upper);
        glmFacetNormals(upper);
        glmVertexNormals(upper, 90.0);
    }
    glmDraw(upper, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLower(void)
{
    if (!lower) {
        lower = glmReadOBJ("lower.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!lower) exit(0);
        glmUnitize(lower);
        glmFacetNormals(lower);
        glmVertexNormals(lower, 90.0);
    }
    glmDraw(lower, GLM_SMOOTH | GLM_TEXTURE);
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutWireCube(0.6);
    glutSolidSphere(0.2,30,30);

    glPushMatrix();
        drawUpper();
        glTranslatef(0,0,0);
        glPushMatrix();
            glTranslatef(0,-0.3,0);
            glRotatef(angle++,1,0,0);
            glTranslatef(0,-1,0);
            drawLower(); ///glutSolidTeapot( 0.3 );
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();

}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week12-2 obj gundam upper lower");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    myTexture("Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

   glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutMainLoop();
}
