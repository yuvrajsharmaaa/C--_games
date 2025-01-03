#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

#define SCREEN_WIDTH 52
#define SCREEN_HEIGHT 20
#define PADDLE_WIDTH 7

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

// Ball and paddle position
int ballX = 26, ballY = 18;
int ballDirX = 1, ballDirY = -1;
int paddleX = 22;
vector<vector<int>> bricks;

void setCursorPosition(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void clearScreen() {
    system("cls");
}

void drawBorder() {
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        setCursorPosition(i, 0);
        cout << "#";
        setCursorPosition(i, SCREEN_HEIGHT - 1);
        cout << "#";
    }
    for (int i = 1; i < SCREEN_HEIGHT - 1; i++) {
        setCursorPosition(0, i);
        cout << "#";
        setCursorPosition(SCREEN_WIDTH - 1, i);
        cout << "#";
    }
}

void initializeBricks() {
    for (int i = 2; i < 10; i++) {
        for (int j = 5; j < SCREEN_WIDTH - 5; j += 4) {
            bricks.push_back({j, i});
        }
    }
}

void drawBricks() {
    for (auto &brick : bricks) {
        setCursorPosition(brick[0], brick[1]);
        cout << "[]";
    }
}

void drawPaddle() {
    for (int i = 0; i < PADDLE_WIDTH; i++) {
        setCursorPosition(paddleX + i, SCREEN_HEIGHT - 2);
        cout << "=";
    }
}

void drawBall() {
    setCursorPosition(ballX, ballY);
    cout << "O";
}

void eraseBall() {
    setCursorPosition(ballX, ballY);
    cout << " ";
}

void erasePaddle() {
    for (int i = 0; i < PADDLE_WIDTH; i++) {
        setCursorPosition(paddleX + i, SCREEN_HEIGHT - 2);
        cout << " ";
    }
}

void movePaddle(char direction) {
    if (direction == 'a' && paddleX > 1) {
        erasePaddle();
        paddleX--;
    } else if (direction == 'd' && paddleX + PADDLE_WIDTH < SCREEN_WIDTH - 1) {
        erasePaddle();
        paddleX++;
    }
}

void moveBall() {
    eraseBall();
    ballX += ballDirX;
    ballY += ballDirY;

    // Ball collision with walls
    if (ballX <= 1 || ballX >= SCREEN_WIDTH - 2) {
        ballDirX *= -1;
    }
    if (ballY <= 1) {
        ballDirY *= -1;
    }

    // Ball collision with paddle
    if (ballY == SCREEN_HEIGHT - 3 && ballX >= paddleX && ballX < paddleX + PADDLE_WIDTH) {
        ballDirY *= -1;
    }

    // Ball collision with bricks
    for (auto it = bricks.begin(); it != bricks.end();) {
        if (ballX >= it->at(0) && ballX <= it->at(0) + 1 && ballY == it->at(1)) {
            ballDirY *= -1;
            it = bricks.erase(it);
        } else {
            ++it;
        }
    }

    // Game over condition
    if (ballY >= SCREEN_HEIGHT - 1) {
        clearScreen();
        setCursorPosition(SCREEN_WIDTH / 2 - 5, SCREEN_HEIGHT / 2);
        cout << "GAME OVER!";
        exit(0);
    }
}

int main() {
    clearScreen();
    initializeBricks();
    drawBorder();
    
    while (true) {
        drawBricks();
        drawPaddle();
        drawBall();
        
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' || ch == 'd') {
                movePaddle(ch);
            }
        }
        
        moveBall();
        Sleep(50);
    }
    return 0;
}
