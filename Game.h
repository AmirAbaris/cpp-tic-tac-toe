#ifndef GAME_H
#define GAME_H

class Game
{
public:
    static const int rows = 3;
    static const int cols = 3;
    char board[rows][cols];
    char playerX = 'X';
    char playerO = 'O';

    void Init();
    void DrawBoard();
};

#endif