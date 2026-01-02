//
// Created by shifat arman on 1/2/2026.
//

#ifndef MINI_FOOTBALL_PLAYER_H
#define MINI_FOOTBALL_PLAYER_H

#endif // MINI_FOOTBALL_PLAYER_H

#pragma once

class Player
{
public:
    Player(int x, int y, int r);

    void draw() const;

private:
    int x;
    int y;
    int radius;
    
    void plotCirclePoints(int xc, int yc, int x, int y) const;
};