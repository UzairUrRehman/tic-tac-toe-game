#include <iostream>
#include <string>
using namespace std;

char space[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
string p1, p2;
int row, column;
char token = 'x';
bool tie = false;

void Board()
{
    cout << "    |     |  \n";
    cout << " " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "\n";
    cout << "____|_____|____\n";
    cout << "    |     |  \n";
    cout << " " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "\n";
    cout << "____|_____|____\n";
    cout << "    |     |  \n";
    cout << " " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "\n";
    cout << "    |     |  \n";
}

void playerMove()
{
    int digit;
    bool validMove = false;

    while (!validMove)
    {
        if (token == 'x')
            cout << p1 << " please enter: ";
        else
            cout << p2 << " please enter: ";

        cin >> digit;

        if (digit < 1 || digit > 9)
        {
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (digit == 1) { row = 0; column = 0; }
        else if (digit == 2) { row = 0; column = 1; }
        else if (digit == 3) { row = 0; column = 2; }
        else if (digit == 4) { row = 1; column = 0; }
        else if (digit == 5) { row = 1; column = 1; }
        else if (digit == 6) { row = 1; column = 2; }
        else if (digit == 7) { row = 2; column = 0; }
        else if (digit == 8) { row = 2; column = 1; }
        else if (digit == 9) { row = 2; column = 2; }

        if (token == 'x' && space[row][column] != 'x' && space[row][column] != '0')
        {
            space[row][column] = 'x';
            token = '0';
            validMove = true;
        }
        else if (token == '0' && space[row][column] != 'x' && space[row][column] != '0')
        {
            space[row][column] = '0';
            token = 'x';
            validMove = true;
        }
        else
        {
            cout << "Space already occupied! Try again.\n";
        }
    }
}

bool checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
        {
            return true;
        }
    }

    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

bool playAgain()
{
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    cin.ignore();
    return (choice == 'y' || choice == 'Y');
}

void resetBoard()
{
    char count = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            space[i][j] = count++;
    token = 'x';
    tie = false;
}

int main()
{
    do
    {
        cout << "Enter the name of first player: ";
        getline(cin, p1);
        cout << "Enter the name of second player: ";
        getline(cin, p2);

        cout << p1 << " is Player 01. He/She will play first.\n";
        cout << p2 << " is Player 02. He/She will play second.\n";

        while (!checkWin())
        {
            Board();
            playerMove();
        }

        Board();

        if (token == 'x' && tie == false)
            cout << p2 << " Wins!\n";
        else if (token == '0' && tie == false)
            cout << p1 << " Wins!\n";
        else
            cout << "It's a draw!!\n";

        resetBoard();

    } while (playAgain());
}