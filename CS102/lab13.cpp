/**
 * A simple TicTacToe game demonstrating basic usage of structs
 * @author Bresia Prudente (bprude2) and Karl Consing (consing2)
 * @datesubmitted 4/12/12
 */

#include <iostream>

using namespace std;

const int Size = 10;     //size of board

//define your struct here
struct Turn
{
    int turnNumber;      //determines if it's player 'X' or 'O'
    char board[Size];    //array of characters on board
};

/**
 * This is a method I thought you might find useful.
 * much like strncpy, copies n elements from a source array to a new array.
 * Don't use arr1=arr2, that's wrong.
 */
void copynArray(char sourceArray[], char destinationArray[], int numberOfItemsToCopy)
{
    int i = 0;
    for(;i<numberOfItemsToCopy;++i)
    {
       destinationArray[i]=sourceArray[i];
    }
}

/**
 * Modify this to actually print the board stored in t.  Turn number is a plus.
 */
void printBoard(Turn &t)
{
    t.board[Size] = ' ';         //grab information from board stored in t
    
    cout<<"+-----+"<< endl
        <<"|"<<' '<<"|"<<' '<<"|"<<' '<<"|"<<endl
        <<"|-----|"<< endl
        <<"|"<<' '<<"|"<<' '<<"|"<<' '<<"|"<<endl
        <<"|-----|"<< endl
        <<"|"<<' '<<"|"<<' '<<"|"<<' '<<"|"<<endl
        <<"+-----+"<< endl;
    
    cout << endl << "This is turn " << -1 << "." << endl;
}

/**
 * Creates a new turn object from the current turn t.
 * input is the cell the user wants to play in.
 * turn number should be one greater than the turn number in t.
 *  You shouldn't need to modify the current turn object.
 */
 
Turn makeMove(Turn &t, int input)
{
    Turn nextTurn;
    
    nextTurn.board[input];
    
    return nextTurn;
}

void storeCurrentGameInfo(Turn t, Turn history[])
{
//find the first "enpty" point in the array of turns, and put the turn passed in there.
}

void printEntireGame(Turn history[])
{    
     // print the turn number and board for every move taken

}

// All functions done, commence main
int main()
{
    char currentBoard[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int i;
    int turnNumber = 0;
    int userEntry;
    Turn currentTurn;
    // For the third point, you'll need to make an array of structs, one for each turn of the game;
    
    
    
    cout<<"Welcome to Tic Tac Toe."<<endl<<endl
    <<"In each turn, you will enter a single digit"<<endl
    <<" associated with the position on the board "<<endl
    <<"you would like to play as follows."<<endl<<endl;
    
    // You can use any inputs you like.  0 for the upper left hand corner might be easiest
    // What I have here syncs up with the num pad, so I like it a bit more.
    cout<<"+-----+"<<endl
        <<"|"<<'7'<<"|"<<'8'<<"|"<<'9'<<"|"<<endl
        <<"|-----|"<<endl
        <<"|"<<'4'<<"|"<<'5'<<"|"<<'6'<<"|"<<endl
        <<"|-----|"<<endl
        <<"|"<<'1'<<"|"<<'2'<<"|"<<'3'<<"|"<<endl
        <<"+-----+"<<endl;
    
    cout<<endl<<"This is turn "<<"X"<<"."<<endl;
    cout<<endl<<"X goes first, and play ends in 9 turns.  "<<endl
    <<"There are no losers or winners, and pieces can be overwritten."<<endl
    <<"  Have fun."<<endl<<endl;
    
    while(turnNumber < 9)
    {
        printBoard(currentTurn);
        cout<<"Enter the number of the position you would like to play.  "<<endl;
        cin >> userEntry;
        //No error checking performed
        currentTurn = makeMove(currentTurn, userEntry);
    
        // this is for part 3
        //storeCurrentGameInfo(currentTurn, history); //Saves the move at the next open position in the array
        turnNumber++;
    }

    cout<<endl<<"The game has ended with the following board configuration."<<endl;
    //printBoard(currentTurn);
    cout<<"Thanks for playing."<<endl<<endl;
    cout<<"Press r for recap."<<endl;
    char pause;
    cin>>pause;
    if(pause=='r')
    {
        // printEntireGame(gameSnapshots);
    }
}//end main
