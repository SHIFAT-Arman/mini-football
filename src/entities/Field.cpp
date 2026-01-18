//
// Created by shifat arman on 1/2/2026.
//

#include "../../include/entities/Field.h"
#include <GL/freeglut.h>
#include <cmath>
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
    drawCenterCircle();
    drawPenaltyBoxes();
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
void Field::drawCenterCircle() const
{
    float radius = 150.0f;
    int segments = 50;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; i++)
    {
        float theta = 2.0f * 3.14159f * float(i) / float(segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}
void Field::drawPenaltyBoxes() const
{
    float penaltyWidth = 250.0f;
    float penaltyHeight = 400.0f;

    // Left penalty box
    glBegin(GL_LINE_LOOP);
    glVertex2f(-fieldWidth, -penaltyHeight / 2);
    glVertex2f(-fieldWidth + penaltyWidth, -penaltyHeight / 2);
    glVertex2f(-fieldWidth + penaltyWidth, penaltyHeight / 2);
    glVertex2f(-fieldWidth, penaltyHeight / 2);
    glEnd();

    // Right penalty box
    glBegin(GL_LINE_LOOP);
    glVertex2f(fieldWidth, -penaltyHeight / 2);
    glVertex2f(fieldWidth - penaltyWidth, -penaltyHeight / 2);
    glVertex2f(fieldWidth - penaltyWidth, penaltyHeight / 2);
    glVertex2f(fieldWidth, penaltyHeight / 2);
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