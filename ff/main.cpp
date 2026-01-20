//
// Created by shifat arman on 1/2/2026.
//

#include "Field.h"
#include <GL/freeglut.h>
#include <cmath>
Field::Field()
{
    fieldWidth = 900.0f;
    fieldHeight = 600.0f;
}



void Field::draw()
{
    drawStadium();
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFieldBoundary();
    drawCenterLine();
}
void Field::drawFieldBoundary() const
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(-fieldWidth, -fieldHeight);
    glVertex2f(fieldWidth, -fieldHeight);
    glVertex2f(fieldWidth, fieldHeight);
    glVertex2f(-fieldWidth, fieldHeight);
    glEnd();
}
void Field::drawCenterLine() const
{
    glBegin(GL_LINES);
    glVertex2f(0.0f, -fieldHeight);
    glVertex2f(0.0f,  fieldHeight);
    glEnd();
}
void Field::drawRectangle(float x, float y, float width, float height)
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y); // Bottom-left
    glVertex2f(x + width, y); // Bottom-right
    glVertex2f(x + width, y + height); // Top-right
    glVertex2f(x, y + height); // Top-left
    glEnd();
}

void Field::drawStadium() const
{
    float marginX = 260.0f;
    float stadiumHeight = 240.0f;
    float baseY = fieldHeight;
    float topY  = baseY + stadiumHeight;

    // ================= OUTER WALL =================
    glColor3f(0.35f, 0.35f, 0.35f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-fieldWidth - marginX, baseY);
    glVertex2f( fieldWidth + marginX, baseY);
    glVertex2f( fieldWidth + marginX, topY);
    glVertex2f(-fieldWidth - marginX, topY);
    glEnd();

    // ================= SEATING STEPS =================
    int rows = 10;
    float rowHeight = stadiumHeight / rows;
    for (int r = 0; r <= rows; r++)
    {
        float y = baseY + r * rowHeight;
        float inset = marginX * (0.25f + 0.55f * ((float)r / rows));
        glColor3f(0.45f, 0.45f, 0.45f);
        glBegin(GL_LINES);
        glVertex2f(-fieldWidth - inset, y);
        glVertex2f( fieldWidth + inset, y);
        glEnd();
    }

    // ================= AISLES =================
    glColor3f(0.55f, 0.55f, 0.55f);
    int aisles = 6;
    for (int i = 1; i < aisles; i++)
    {
        float x = -fieldWidth - marginX +
                  (2.0f * (fieldWidth + marginX) * i / aisles);
        glBegin(GL_LINES);
        glVertex2f(x, baseY);
        glVertex2f(x, topY);
        glEnd();
    }

    // ================= PEOPLE (STRICT SEATS) =================
    float headR = 20.0f;  // Increased from 14.0f to 20.0f
    int peopleRows[] = {2, 4, 6};   // only these rows have people
    int rowCount = 3;
    int peoplePerRow = 8;          // reduced count

    for (int i = 0; i < rowCount; i++)
    {
        int r = peopleRows[i];
        float y = baseY + r * rowHeight + headR * 0.9f;
        float inset = marginX * (0.25f + 0.55f * ((float)r / rows));
        float leftX  = -fieldWidth - inset + headR * 2.0f;
        float rightX =  fieldWidth + inset - headR * 2.0f;
        float spacing = (rightX - leftX) / (peoplePerRow - 1);

        for (int p = 0; p < peoplePerRow; p++)
        {
            float x = leftX + p * spacing;
            // stagger formation
            if (i % 2 == 1) x += spacing * 0.35f;
            // safety clamp (absolute guarantee)
            if (x < leftX || x > rightX) continue;

            // Choose color based on side - Team Purple on left, Team Red on right
            if (x < 0)
                glColor3f(0.7f, 0.1f, 0.9f);  // Purple team color
            else
                glColor3f(1.0f, 0.1f, 0.1f);  // Red team color

            // Draw larger person (head)
            glBegin(GL_POLYGON);
            for (int k = 0; k < 16; k++)
            {
                float a = 2.0f * 3.14159f * k / 16;
                glVertex2f(x + cos(a) * headR,
                           y + sin(a) * headR);
            }
            glEnd();

            // Draw body below the head
            glBegin(GL_POLYGON);
            glVertex2f(x - headR * 0.4f, y - headR * 0.9f);
            glVertex2f(x + headR * 0.4f, y - headR * 0.9f);
            glVertex2f(x + headR * 0.3f, y - headR * 1.8f);
            glVertex2f(x - headR * 0.3f, y - headR * 1.8f);
            glEnd();

            // Draw arms
            glColor3f(0.9f, 0.7f, 0.5f);  // Skin color for arms
            glBegin(GL_POLYGON);
            // Left arm
            glVertex2f(x - headR * 0.4f, y - headR * 1.0f);
            glVertex2f(x - headR * 0.5f, y - headR * 1.0f);
            glVertex2f(x - headR * 0.9f, y - headR * 1.5f);
            glVertex2f(x - headR * 0.8f, y - headR * 1.6f);
            glEnd();

            glBegin(GL_POLYGON);
            // Right arm
            glVertex2f(x + headR * 0.4f, y - headR * 1.0f);
            glVertex2f(x + headR * 0.5f, y - headR * 1.0f);
            glVertex2f(x + headR * 0.9f, y - headR * 1.5f);
            glVertex2f(x + headR * 0.8f, y - headR * 1.6f);
            glEnd();
        }
    }

    // ================= FRONT RAIL =================
    glColor3f(0.7f, 0.7f, 0.7f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(-fieldWidth - marginX * 0.25f, baseY + rowHeight);
    glVertex2f( fieldWidth + marginX * 0.25f, baseY + rowHeight);
    glEnd();
    glLineWidth(1.0f);
}










Field field;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    field.draw();

    glFlush();   // since you're using GLUT_SINGLE
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL 64-bit FreeGLUT Test");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1500, 1500, -1500, 1500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
