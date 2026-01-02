//
// Created by shifat arman on 1/2/2026.
//

#ifndef MINI_FOOTBALL_FIELD_H
#define MINI_FOOTBALL_FIELD_H

class Field
{
public:
    Field();
    void draw();

private:
    float fieldWidth;
    float fieldHeight;
    
    void drawFieldBoundary() const;
    void drawCenterLine() const;
    
    void drawRectangle(float x, float y, float width, float height) ;
};
#endif