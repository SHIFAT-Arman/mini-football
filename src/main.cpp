#include <GL/freeglut.h>
#include <cmath>
#include <cstdio>

#include "../include/entities/Ball.h"
#include "../include/entities/DBox.h"
#include "../include/entities/Field.h"
#include "../include/entities/GoalPost.h"
#include "../include/entities/Player.h"
#include "../include/entities/ScoreManager.h"

Field field;
DBox dBox;
GoalPost goalPost;
Ball ball;
Player* players[8];
ScoreManager scoreManager;

int controlledPlayerIndex = 0; // Index of the currently controlled player

// Time tracking
int lastTime = 0;

// Keyboard state
bool keyW = false;
bool keyA = false;
bool keyS = false;
bool keyD = false;

void initPlayers()
{
    // Left team (purple) - 4 players
    players[0] = new Player(-700, 0, 0);      // Forward
    players[1] = new Player(-500, 300, 0);    // Midfielder top
    players[2] = new Player(-500, -300, 0);   // Midfielder bottom
    players[3] = new Player(-800, 0, 0);      // Goalkeeper (controlled)
    
    // Right team (red) - 4 players
    players[4] = new Player(700, 0, 1);       // Forward
    players[5] = new Player(500, 300, 1);     // Midfielder top
    players[6] = new Player(500, -300, 1);    // Midfielder bottom
    players[7] = new Player(800, 0, 1);       // Goalkeeper
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPointSize(10.0f);
    // Draw the field
    glPushMatrix();
    field.draw();
    glPopMatrix();
    
    // draw DBox
    glPushMatrix();
    dBox.draw();
    glPopMatrix();
    
    //goal posts
    glPushMatrix();
    goalPost.draw();
    glPopMatrix();
    
    //players
    for (int i = 0; i < 8; i++) {
        glPushMatrix();
        players[i]->draw();
        glPopMatrix();
    }
    glPushMatrix();
    glColor3f(1, 1, 0);
    glLineWidth(2.0f);
    float px = players[controlledPlayerIndex]->x;
    float py = players[controlledPlayerIndex]->y;
    float pr = players[controlledPlayerIndex]->radius + 10;
    
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 20; i++) {
        float angle = 2.0f * 3.14159f * i / 20;
        float cx = px + pr * cos(angle);
        float cy = py + pr * sin(angle);
        glVertex2f(cx, cy);
    }
    glEnd();

    scoreManager.draw();
    glutSwapBuffers();

    glPopMatrix();
    //ball
    glPushMatrix();
    ball.draw();
    glPopMatrix();
    glFlush();
}

void update(int value) {
    // Calculate delta time (time since last update)
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    float deltaTime = (currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;
    
    // Limit delta time to prevent large jumps
    if (deltaTime > 0.05f) deltaTime = 0.05f;
    
    // Move controlled player based on keys
    float speed = 300.0f * deltaTime;
    if (keyW) players[controlledPlayerIndex]->move(0, speed);
    if (keyS) players[controlledPlayerIndex]->move(0, -speed);
    if (keyA) players[controlledPlayerIndex]->move(-speed, 0);
    if (keyD) players[controlledPlayerIndex]->move(speed, 0);
    // Update ball physics
    ball.update(deltaTime);

    if (ball.x < -900 && ball.y > -200 && ball.y < 200) {
        scoreManager.incrementTeam2Score();
        ball.reset();  // Reset ball to center after goal
    }

    // Check if ball scored in right goal (Team 1 scores)
    if (ball.x > 900 && ball.y > -200 && ball.y < 200) {
        scoreManager.incrementTeam1Score();
        ball.reset();  // Reset ball to center after goal
    }

    // Request redraw
    glutPostRedisplay();
    
    // Schedule next update (16ms = ~60 FPS)
    glutTimerFunc(16, update, 0);
}
void mouse(int button, int state, int x, int y) {
    // Convert mouse coordinates to OpenGL coordinates
    // Window is 1000x1000, coordinates are -1000 to +1000
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float glX = (x - 500) * 2.0f;
        float glY = (500 - y) * 2.0f;
        
        // Calculate kick direction from ball to click position
        float dx = glX - 0.0f;  // Assuming ball starts at center
        float dy = glY - 0.0f;
        
        // Normalize and scale for kick power
        float length = sqrt(dx * dx + dy * dy);
        if (length > 0) {
            dx = (dx / length) * 500.0f;
            dy = (dy / length) * 500.0f;
            ball.kick(dx, dy);
            printf("Ball kicked towards (%.1f, %.1f)\n", glX, glY);
        }
    }
}

void keyboardInput(const unsigned char key, int x, int y)
{
    switch(key) {
    case 'w':
    case 'W':
        keyW = true;
        break;
    case 's':
    case 'S':
        keyS = true;
        break;
    case 'a':
    case 'A':
        keyA = true;
        break;
    case 'd':
    case 'D':
        keyD = true;
        break;
    case 9:  // TAB key
        controlledPlayerIndex = (controlledPlayerIndex + 1) % 4;  // Cycle through team
        printf("Controlling player %d\n", controlledPlayerIndex);
        break;
    case 'r':
    case 'R':
        // Reset ball to center
        ball.reset();
        printf("Ball reset to center\n");
        break;
            
    case ' ':
        // Kick ball (for testing)
        ball.kick(300.0f, 200.0f);
        printf("Ball kicked!\n");
        break;

    case 'x':
    case 'X':
        scoreManager.resetScores();
        break;

    case 27:  // ESC key
        exit(0);
        break;
    }
    
    glutPostRedisplay();
}
void keyboardUp(unsigned char key, int x, int y) {
    switch(key) {
    case 'w':
    case 'W':
        keyW = false;
        break;
    case 's':
    case 'S':
        keyS = false;
        break;
    case 'a':
    case 'A':
        keyA = false;
        break;
    case 'd':
    case 'D':
        keyD = false;
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL 64-bit FreeGLUT Test");

    // Set black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Set up the projection (simple orthographic 2D)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1500, 1500, -1500, 1500);
    
    // Initialize players
    initPlayers();
    
    // Initialize time
    lastTime = glutGet(GLUT_ELAPSED_TIME);
    
    // Give the ball an initial kick for demonstration
    ball.kick(400.0f, 300.0f);
    
    
    // Register the display callback
    glutDisplayFunc(display);
    // keyboard func
    glutKeyboardFunc(keyboardInput);
    glutKeyboardUpFunc(keyboardUp);
    // mouse func
    glutMouseFunc(mouse);
    // Timer for updates
    glutTimerFunc(0, update, 0);
    // Start the main event loop
    glutMainLoop();
    return 0;
}
