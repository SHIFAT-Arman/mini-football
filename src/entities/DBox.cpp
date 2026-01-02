//
// Created by shifat arman on 1/2/2026.
//

#include "../../include/entities/DBox.h"
#include <GL/glut.h>

DBox::DBox()
{
    Dbox_width = 300.0f;
    Dbox_height = 400.0f;
}
void DBox::draw() const
{
    glColor3f(1.0f, 1.0f, 1.0f);
    drawLeftDBox();
    drawRightDBox();
}
void DBox::drawLeftDBox() const
{
    float dBoxX = -900.0f; // Left DBox X position
    float dBoxY = -Dbox_height; // Centered vertically
    drawRectangle(dBoxX, dBoxY, Dbox_width, Dbox_height * 2.0f);
}
void DBox::drawRightDBox() const
{
    float dBoxX = 900.0f - Dbox_width; // Right DBox X position
    float dBoxY = -Dbox_height; // Centered vertically
    drawRectangle(dBoxX, dBoxY, Dbox_width, Dbox_height * 2.0f);
    
}
void DBox::drawRectangle(float x, float y, float width, float height) const
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);                    // Bottom-left
    glVertex2f(x + width, y);            // Bottom-right
    glVertex2f(x + width, y + height);   // Top-right
    glVertex2f(x, y + height);           // Top-left
    glEnd();
}