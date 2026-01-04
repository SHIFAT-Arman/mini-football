//
// Created by shifat arman on 1/2/2026.
//

#include "../../include/entities/Player.h"
#include <GL/glut.h>

Player::Player(float startX, float startY, int teamNumber) {
    x = startX;
    y = startY;
    team = teamNumber;
    radius = 25.0f;
}

void Player::draw() {
    // Set color based on team
    if (team == 0) {
        // Left team - Purple
        glColor3f(0.6f, 0.2f, 0.8f);
    } else {
        // Right team - Red
        glColor3f(0.8f, 0.2f, 0.2f);
    }
    
    // Draw filled circle
    drawCircleBresenham((int)x, (int)y, (int)radius);
}

void Player::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void Player::drawCircleBresenham(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;
    
    plotCirclePoints(xc, yc, x, y);
    
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        plotCirclePoints(xc, yc, x, y);
    }
}

void Player::plotCirclePoints(int xc, int yc, int x, int y) {
    glBegin(GL_LINES);
    glVertex2f(xc - x, yc + y);
    glVertex2f(xc + x, yc + y);
        
    glVertex2f(xc - x, yc - y);
    glVertex2f(xc + x, yc - y);
        
    glVertex2f(xc - y, yc + x);
    glVertex2f(xc + y, yc + x);
        
    glVertex2f(xc - y, yc - x);
    glVertex2f(xc + y, yc - x);
    glEnd();
}