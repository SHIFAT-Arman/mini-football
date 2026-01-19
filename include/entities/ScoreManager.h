//
// Manages scoring and score display for the football game
//

#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <GL/glut.h>

class ScoreManager
{
private:
    int team1Score;
    int team2Score;
    int winningScore;
    bool gameOver;
    int winningTeam; // 0 = no winner, 1 = team1, 2 = team2

    // Helper function to render text on screen
    void renderText(float x, float y, const char* text);

    // Helper function to render a number
    void renderNumber(float x, float y, int number);

public:
    ScoreManager();

    // Score management
    void incrementTeam1Score();
    void incrementTeam2Score();
    void resetScores();

    // Getters
    int getTeam1Score() const;
    int getTeam2Score() const;
    bool isGameOver() const;
    int getWinningTeam() const;

    // Display score on screen
    void draw();
};

#endif // SCOREMANAGER_H