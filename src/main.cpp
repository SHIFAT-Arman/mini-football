#include <GL/freeglut.h>

#include "../include/entities/DBox.h"
#include "../include/entities/Field.h"
#include "../include/entities/Player.h"

Player player(400, 300, 80); // screen
Field field;
DBox dBox;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPointSize(10.0f);
    // Draw the field
    glPushMatrix();
    field.draw();
    glPopMatrix();
    
    // draw DBox
    glPushMatrix();
    dBox.draw();
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL 64-bit FreeGLUT Test");

    // Set black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Set up the projection (simple orthographic 2D)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000, 1000, -1000, 1000);
    // Register the display callback
    glutDisplayFunc(display);

    // Start the main event loop
    glutMainLoop();
    return 0;
}
