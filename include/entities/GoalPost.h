//
// Created by shifat arman on 1/2/2026.
//

#ifndef MINI_FOOTBALL_GOALPOST_H
#define MINI_FOOTBALL_GOALPOST_H
class GoalPost
{
public:
    GoalPost();
    void draw();
private:
    float goalPostWidth, goalPostHeight;
    
    void drawLeftGoalPost();
    void drawRightGoalPost();
    void drawRectangle(float x, float y, float width, float height);
};
#endif // MINI_FOOTBALL_GOALPOST_H
