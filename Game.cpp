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
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << board[i][j];
            if (j < cols - 1)
                std::cout << " | ";
        }
        std::cout << "\n";
        if (i < rows - 1)
            std::cout << "--+---+--\n";
    }
}

bool Game::IsValidMove(int row, int col)
{
    return row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == ' ';
}

void Game::MakeMove(int row, int col)
{
    board[row][col] = currentPlayer;
}

void Game::SwitchPlayer()
{
    currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
}

bool Game::CheckWin()
{
    for (int i = 0; i < cols; ++i)
    {
        if (
            board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

        if (
            board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    return false;
}

bool Game::CheckDraw()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }

    return true;
}

void Game::Play()
{
    Init();
    currentPlayer = playerX;
    bool isGameDone = false;

    while (!isGameDone)
    {
        int row, col;
        DrawBoard();
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (!IsValidMove(row, col))
        {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        MakeMove(row, col);

        if (CheckWin())
        {
            DrawBoard();
            std::cout << "Player " << currentPlayer << " wins!\n";
            isGameDone = true;
        }
        else if (CheckDraw())
        {
            DrawBoard();
            std::cout << "It's a draw!\n";
            isGameDone = true;
        }
        else
        {
            SwitchPlayer();
        }
    }
}
