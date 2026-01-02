//
// Created by shifat arman on 1/2/2026.
//

#include "../../include/entities/Player.h"
#include <GL/freeglut.h>

Player::Player(int x, int y, int r)
    : x(x), y(y), radius(r)
{}

void Player::plotCirclePoints(int xc, int yc, int x, int y) const
{
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);

    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}

void Player::draw() const
{
    int x0 = 0;
    int y0 = radius;
    int d = 3 - 2 * radius;

    glBegin(GL_POINTS);

    while (x0 <= y0)
    {
        plotCirclePoints(x, y, x0, y0);

        if (d < 0)
        {
            d = d + 4 * x0 + 6;
        }
        else
        {
            d = d + 4 * (x0 - y0) + 10;
            y0--;
        }
        x0++;
    }

    glEnd();
}