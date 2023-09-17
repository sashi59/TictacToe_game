#include <iostream>
using namespace std;
#define BOARD_SIZE 3

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWinLoose(char board[BOARD_SIZE][BOARD_SIZE], char sign)
{
    for (int i = 0; i < 3; i++)
    {
        // row win
        if (board[i][0] == sign && board[i][1] == sign && board[i][2] == sign)
        {
            return true;
        }
        // column win
        if (board[0][i] == sign && board[1][i] == sign && board[2][i] == sign)
        {
            return true;
        }
    }
    // diagonal win
    if (board[0][0] == sign && board[1][1] == sign && board[2][2] == sign)
    {
        return true;
    }
    // mirror diagonal win
    if (board[0][2] == sign && board[1][1] == sign && board[2][0] == sign)
    {
        return true;
    }

    return false;
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '}, 
                                          {' ', ' ', ' '},
                                          {' ', ' ', ' '}};
    int r, c;
    char currPlayer = 'X';
    int attempts = 0;

    cout << "*********** TIC TAC TOE GAME ***********" << endl;
    displayBoard(board);

    while (attempts < BOARD_SIZE * BOARD_SIZE)
    {
        cout << "Player " << currPlayer << " turn, Enter the row and column(0 to 2 range)" << endl;
        cin >> r >> c;
        // checking constraints
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == ' ')
        {
            board[r][c] = currPlayer;
            displayBoard(board);
            if (checkWinLoose(board, currPlayer))
            {
                cout << "Player " << currPlayer << " Wins!" << endl;
                break;
            }
            if (currPlayer == 'X')
            {
                currPlayer = 'O';
            }
            else
            {
                currPlayer = 'X';
            }
            attempts++;
        }
        else
        {
            cout << "Invalid move! Try again...\n";
        }
    }
    if (attempts == BOARD_SIZE * BOARD_SIZE)
    {
        cout << "Match is draw!" << endl;
    }
    return 0;
}