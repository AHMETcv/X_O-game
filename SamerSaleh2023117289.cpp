#include <iostream>
using namespace std;
int row,column, choice;
char Winner = 'x',currentPlayer = 'x';
char board[3][3] = { {'1','2','3'},
                 {'4','5','6' },
                 {'7','8','9' } };
void print() {
    cout << "----------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << ": ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << " :";
        cout << endl;
    }

    cout << "----------\n";
}
bool coondition()
{
    if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
    {
        Winner = board[0][0];
        return false;
    }
    else if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
    {
        Winner = board[1][0];
        return false;
    }
    else if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
    {
        Winner = board[2][0];
        return false;
    }
    else if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
    {
        Winner = board[0][0];
        return false;
    }
    else if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
    {
        Winner = board[0][1];
        return false;
    }
    else if (board[2][2] == board[1][2] && board[2][2] == board[0][2])
    {
        Winner = board[0][2];
        return false;
    }
    else if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {

        Winner = board[0][0];
        return false;
    }
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        Winner = board[2][0];
        return false;
    }
    return true;
}
bool Player() {
    cout << "("<< currentPlayer << " player)\n";
    cin >> choice;
    if (choice < 1 || choice > 10)
    {
        cout << "invali value! please try again: \n";
        Player();
    }
    int row = (choice - 1) / 3;
    int clmn = (choice - 1) % 3;
    board[row][clmn] = currentPlayer;
    system("cls");
    print();
    currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';
    return !coondition();
}
void play() {
    int a = 0;
    print();
    while (a == 0)
    {
        if (Player())
        {
            cout << Winner << " player is winner!";
            a++;
        }
    }
}
int main() {
    play();
}
