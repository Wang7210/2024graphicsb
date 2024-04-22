#include <GL/glut.h>

void myBody()
{
    glColor3f(1,0,0);///¬õ
    glutWireCube(0.6);
}

void myArm()
{
    glColor3f(0,1,0);///ºñ
    glScalef(1.5,0.5,0.5);
    glutWireCube(0.3);
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///²M­I´º

    glPushMatrix();
    myBody();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3,0.3,0);
    glRotatef(angle++,0,0,1);
    glTranslatef(0.225,0,0);
    myArm();///¥kÁu

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3,0.3,0);
    glRotatef(angle++,0,0,-1);
    glTranslatef(0.225,0,0);
    myArm();///¥ªÁu
    glPopMatrix();

    glutSwapBuffers();

}

int main(int argc, char *argv[])
{
 	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("week10");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}

