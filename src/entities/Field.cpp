//
// Created by shifat arman on 1/2/2026.
//

#include "../../include/entities/Field.h"
#include <GL/glut.h>

Field::Field()
{
    fieldWidth = 900.0f;
    fieldHeight = 600.0f;
}
void Field::draw()
{
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
