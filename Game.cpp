#include <iostream>
#include "Game.h"

void Game::Init()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void Game::DrawBoard()
{
    int rows = Game::rows;
    int cols = Game::cols;
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            std::cout << Game::board[i][j] << "*";
        }
        std::cout << "\n";
    }
}