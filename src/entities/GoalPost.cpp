//
// Created by shifat arman on 1/2/2026.
//

#include "../../include/entities/GoalPost.h"
#include <GL/glut.h>
GoalPost::GoalPost()
{
    goalPostWidth = 200.0f;
    goalPostHeight = 500.0f;
}
void GoalPost::draw()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    drawLeftGoalPost();
    drawRightGoalPost();
}
void GoalPost::drawLeftGoalPost()
{
    float goalPostX = -1100.0f;
    float goalPostY = -goalPostHeight / 2.0f;
    drawRectangle(goalPostX, goalPostY, goalPostWidth, goalPostHeight);
}
void GoalPost::drawRightGoalPost()
{
    float goalPostX = 900.0f;
    float goalPostY = -goalPostHeight / 2.0f;
    drawRectangle(goalPostX, goalPostY, goalPostWidth, goalPostHeight);
}
void GoalPost::drawRectangle(float x, float y, float width, float height) {
    int meshCols = 10;
    int meshRows = 10;
    
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);                    // Bottom-left
    glVertex2f(x + width, y);            // Bottom-right
    glVertex2f(x + width, y + height);   // Top-right
    glVertex2f(x, y + height);           // Top-left
    glEnd();
    
    glBegin(GL_LINES);
    
    glColor3f(0.7f, 0.7f, 0.7f);
    for (int i = 1; i < meshCols; i++)
    {
        float vx = x + i * (width / meshCols);
        glVertex2f(vx, y);
        glVertex2f(vx, y + height);
    }

    for (int i = 1; i < meshRows; i++)
    {
        float hy = y + i * (height / meshRows);
        glVertex2f(x, hy);
        glVertex2f(x + width, hy);
    }

    glEnd();
    
}
