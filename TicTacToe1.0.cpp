#include <iostream>

using namespace std;

char gameTable[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'}; //setup tic tac toe board

char player = 'X'; //player X will go first

int n = 0; //number of

bool play = true;

void Draw()
{
    system("cls");  //clear the game board

    //iterate through the array in 2D
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << ' ' << gameTable [i][j] << ' ';   //output table state

            if (j < 2)  //formatting
                cout << '|';
        }
        if (i < 2)
            cout << endl << " --------- " << endl;
        else
            cout << endl;
    }
}

//function that will return a bool to find if all the inputted values are the same
bool equals(char a, char b, char c)
{
    return (a==b && b==c);
}

char Win()
{
    //check straight lines
    for (int i=0; i<3; i++)
    {
        if (equals(gameTable[i][0], gameTable[i][1], gameTable[i][2]))   //horizontal
            return gameTable[i][0];
        else if (equals(gameTable[0][i], gameTable[1][i], gameTable[2][i]))  //vertical
            return gameTable[0][i];
    }

    //check diagonals
    if(equals(gameTable[0][0], gameTable[1][1], gameTable[2][2]))   //diagonal down
        return gameTable[0][0];
    else if(equals(gameTable[0][2], gameTable[1][1], gameTable[2][0]))   //diagonal up
        return gameTable[0][2];

    return '/';
}

void Input()
{
    int space;
    bool free = false;
    cout << "It's player " << player << "'s turn. Press the number of the field: ";

    while (free == false)
    {
        cin >> space;
        switch (space)
        {
            case 1:
                if (gameTable[0][0] != 'O' && gameTable[0][0] != 'X')
                {
                    free = true;
                    gameTable[0][0] = player;
                }
                else
                    cout << "please input a spot that has not been chosen\n";
                break;
            case 2:
                if (gameTable[0][1] != 'O' && gameTable[0][1] != 'X')
                {
                    free = true;
                    gameTable[0][1] = player;
                }
                else
                    cout << "please input a spot that has not been chosen\n";
                break;
            case 3:
                if (gameTable[0][2] != 'O' && gameTable[0][2] != 'X')
                {
                    free = true;
                    gameTable[0][2] = player;
                }
                else
                    cout << "please input a spot that has not been chosen\n";
                break;
            case 4:
                if (gameTable[1][0] != 'O' && gameTable[1][0] != 'X')
                {
                    free = true;
                    gameTable[1][0] = player;
                }
                else
                    cout << "please input a spot that has not been chosen\n";
                break;
            case 5:
                if (gameTable[1][1] != 'O' && gameTable[1][1] != 'X')
                {
                    free = true;
                    gameTable[1][1] = player;
                }
                else
                    cout << "please input a spot that has not been chosen\n";
                break;
            case 6:
                if (gameTable[1][2] != 'O' && gameTable[1][2] != 'X')
                {
                    free = true;
                    gameTable[1][2] = player;
                }
                else
                    cout << "please input a spot that has not been chosen\n";
                break;
            case 7:
                if (gameTable[2][0] != 'O' && gameTable[2][0] != 'X')
                {
                    free = true;
                    gameTable[2][0] = player;
                }
                else
                    cout << "please input a spot that has not been chosen\n";
                break;
            case 8:
                if (gameTable[2][1] != 'O' && gameTable[2][1] != 'X')
                {
                    free = true;
                    gameTable[2][1] = player;
                }
                else
                    cout << "please input a spot that has not been chosen\n";
                break;
            case 9:
                if (gameTable[2][2] != 'O' && gameTable[2][2] != 'X')
                {
                    free = true;
                    gameTable[2][2] = player;
                }
                else
                    cout << "please input a spot that has not been chosen\n";
                break;
        }
    }
}

void TogglePlayer()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

int main()
{
    Draw();
    while (play)
    {
        Input();
        Draw();
        n += 1;
        if (Win() == 'X'||Win() == 'O')
        {
            cout << Win() << " has won!!!\n";
            break;
        }
        else if (n == 9)
        {
            cout << "This game was a tie!";
            break;
        }
        TogglePlayer();
    }
    return 0;
}
