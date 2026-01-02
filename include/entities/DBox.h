//
// Created by shifat arman on 1/2/2026.
//

#ifndef MINI_FOOTBALL_DBOX_H
#define MINI_FOOTBALL_DBOX_H
class DBox
{
public:
    DBox();
    void draw() const;
private:
    float Dbox_width;
    float Dbox_height;
    
    void drawLeftDBox() const;
    void drawRightDBox() const;
    void drawRectangle(float x, float y, float width, float height) const;
};
#endif // MINI_FOOTBALL_DBOX_H
