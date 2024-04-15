#include<GL/glut.h>
#include <stdio.h>
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(-0.6,+0.3,0);
            glutSolidTeapot(0.3);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(+0.0,+0.3,0);
            glutSolidCube(0.3);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(+0.6,+0.3,0);
            glutSolidSphere(0.3,30,30);
        glPopMatrix();

     glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///140
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///143

     glutCreateWindow("week04 keyboard mouse motion");///145
    glutDisplayFunc(display);

     glutMainLoop();///174
}
