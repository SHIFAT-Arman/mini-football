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
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);                    // Bottom-left
    glVertex2f(x + width, y);            // Bottom-right
    glVertex2f(x + width, y + height);   // Top-right
    glVertex2f(x, y + height);           // Top-left
    glEnd();
}
