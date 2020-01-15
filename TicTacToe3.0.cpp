#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

char gameTable[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'}; //setup tic tac toe board

char player = 'X'; //player X will go first

int n = 0; //number of turns passed variable

//function to draw the current state of the table
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
}
    return (a==b && b==c);

//function to check if a win condition is met
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

    return '/';   //if nothing
}

//function to take the input from the player and fill the chosen space
void Input()
{
    while (true)
    {
        int computerChoiceX = (rand()%3);
        int computerChoiceY = (rand()%3);

        if (gameTable[computerChoiceY][computerChoiceX] != 'O' && gameTable[computerChoiceY][computerChoiceX] != 'X')
        {
            gameTable[computerChoiceY][computerChoiceX] = player;
            break;
        }
    }
}

//switch the player to the other player
void TogglePlayer()
{
    if (player == 'X')  //if the player X went
        player = 'O';   //switch to player O
    else
        player = 'X';   //if O went, then switch to player X
}

int main()
{
    srand (time(NULL));
    Draw();
    while (1)
    {
        Input();
        Draw();
        n += 1;
        if (Win() != '/')
        {
            cout << Win() << " has won!!!\n";
            break;
        }
        else if (n == 9)
        {
            cout << "This game was a tie!\n";
            break;
        }
        TogglePlayer();
    }

    system("pause");

    return 0;
}
