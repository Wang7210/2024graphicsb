#include <GL/glut.h>

void myBody()
{
    glColor3f(1,0,0);
    glutSolidCube(0.3);
}

void myArm()
{
    glColor3f(0,1,0);
    glScalef(1.5,0.5,0.5);
    glutSolidCube(0.3);
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///²M­I´º

    glPushMatrix();
    glTranslatef(-0.6,+0.3,0);
    myBody();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(+0.0,+0.3,0);
    glRotatef(angle++,0,0,1);
    glColor3f(0,1,0);///ºñ
    myArm();
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

