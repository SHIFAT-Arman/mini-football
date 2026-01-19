//
// ScoreManager.cpp
// Implementation of score management and display
//

#include "../../include/entities/ScoreManager.h"
#include <string>

ScoreManager::ScoreManager()
{
    team1Score = 0;
    team2Score = 0;
    winningScore = 5;
    gameOver = false;
    winningTeam = 0;
}

void ScoreManager::incrementTeam1Score()
{
    if (!gameOver)
    {
        team1Score++;
        if (team1Score >= winningScore)
        {
            gameOver = true;
            winningTeam = 1;
        }
    }
}

void ScoreManager::incrementTeam2Score()
{
    if (!gameOver)
    {
        team2Score++;
        if (team2Score >= winningScore)
        {
            gameOver = true;
            winningTeam = 2;
        }
    }
}

void ScoreManager::resetScores()
{
    team1Score = 0;
    team2Score = 0;
    gameOver = false;
    winningTeam = 0;
}

int ScoreManager::getTeam1Score() const
{
    return team1Score;
}

int ScoreManager::getTeam2Score() const
{
    return team2Score;
}

bool ScoreManager::isGameOver() const
{
    return gameOver;
}

int ScoreManager::getWinningTeam() const
{
    return winningTeam;
}

void ScoreManager::renderText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    while (*text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}

void ScoreManager::renderNumber(float x, float y, int number)
{
    std::string numStr = std::to_string(number);
    renderText(x, y, numStr.c_str());
}

void ScoreManager::draw()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    // Display "Team 1" label
    renderText(-200.0f, 550.0f, "Team 1");

    // Display Team 1 score
    renderNumber(-100.0f, 520.0f, team1Score);

    // Display separator
    renderText(-10.0f, 520.0f, "-");

    // Display Team 2 score
    renderNumber(50.0f, 520.0f, team2Score);

    // Display "Team 2" label
    renderText(100.0f, 550.0f, "Team 2");

    // Display game over message if game is finished
    if (gameOver)
    {
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for winner message

        if (winningTeam == 1)
        {
            renderText(-150.0f, 0.0f, "TEAM 1 WINS!");
        }
        else if (winningTeam == 2)
        {
            renderText(-150.0f, 0.0f, "TEAM 2 WINS!");
        }

        glColor3f(1.0f, 1.0f, 1.0f);
        renderText(-200.0f, -50.0f, "Press 'R' to restart");
    }
}