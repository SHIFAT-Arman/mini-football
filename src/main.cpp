#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,1);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        for (float x=-1.0f; x< 1.0f; x+=0.01f)
        {
            glVertex2f(x,0.0f);
        }
    glEnd();

    glFlush();
    
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 360);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL 64-bit FreeGLUT Test");

    // Set black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Set up the projection (simple orthographic 2D)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);

    // Register the display callback
    glutDisplayFunc(display);

    // Start the main event loop
    glutMainLoop();
    return 0;
}
