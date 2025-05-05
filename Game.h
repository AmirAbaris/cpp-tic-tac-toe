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
    char currentPlayer;

    void Init();
    void DrawBoard();
    void MakeMove(int row, int col);
    bool IsValidMove(int row, int col);
    void SwitchPlayer();
    bool CheckWin();
    bool CheckDraw();
    void Play();
};

#endif