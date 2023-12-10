#include <iostream>
#include <vector>

void displayBoard(const std::vector<std::vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool updateBoard(std::vector<std::vector<char>> &board, char currentPlayer, int box)
{
    int row = (box - 1) / 3;
    int col = (box - 1) % 3;

    if (board[row][col] == ' ')
    {
        board[row][col] = currentPlayer;
        return true;
    }
    else
    {
        std::cout << "\nInvalid move. The box is already filled. Choose another.\n";
        return false;
    }
}

bool checkWinner(const std::vector<std::vector<char>> &board, char currentPlayer)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
        {
            return true; // Check rows
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
        {
            return true; // Check columns
        }
    }

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
    {
        return true; // Check main diagonal
    }

    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
    {
        return true; // Check secondary diagonal
    }

    return false;
}

bool isBoardFull(const std::vector<std::vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
            {
                return false; // Board is not full
            }
        }
    }
    return true; // Board is full
}

char switchPlayer(char currentPlayer)
{
    return (currentPlayer == 'X') ? 'O' : 'X';
}

int main()
{
    using namespace std;
    cout << "--------- Tic Tac Toe ----------\n\n";

    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    int box;
    bool validMove;

    while (true)
    {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter a box number (1-9): ";
        cin >> box;

        if (box == -1)
        {
            cout << "\n\tGame Terminated\n";
            return 0;
        }

        if (box >= 1 && box <= 9)
        {
            validMove = updateBoard(board, currentPlayer, box);
            if (validMove)
            {
                if (checkWinner(board, currentPlayer))
                {
                    cout << "\t *** Player " << currentPlayer << " Won!! ***\n";
                    break;
                }
                else if (isBoardFull(board))
                {
                    cout << "\n\t *** Draw...  ***\n";
                    break;
                }
                else
                {
                    currentPlayer = switchPlayer(currentPlayer);
                }
            }
        }
        else
        {
            cout << "\nPlease Enter a valid box value\n";
        }
    }

    cout << "\n :: Thanks for playing Tic Tac Toe game!! :: \n";
    return 0;
}
