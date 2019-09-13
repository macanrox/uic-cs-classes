#include <iostream>
#include <string>
using namespace std;

const int Rows = 8;
const int Columns = 10;


//displays the information
//includes program and author information
void displayInfo()
{
     cout << "Author: Bresia Prudente" << endl
          << "Date: 4/9/2012, CS 102 Spring '12" << endl
          << "System: C++" << endl;;
     
     cout << "\nPlay the game of Grid Match.  The object is to make as many squares "
             "as possible disappear from the board. On each move choose a particular "
             "square using the row,column coordinates.  That square and any adjacent "
             "similar squares will all be blanked out if there are 3 or more of them. "
             "Squares above the empty squares then slide down.  Empty columns slide "
             "to the left. Input of 'r' will restart the game and " 
             "re-randomize the board, and input of 'x' will exit the game." << endl;
     
     cout << "\n";
}

//show numbers
//will represent columns
void displayNumbers()
{
     cout << "    0 1 2 3 4 5 6 7 8 9\n";
}

//show lines
//separates numbers from board
void displayLine()
{
     cout << "    -------------------\n";     
}

//initialize board
//gives board their char values: '@', '#', '+', and '-'
void initializeBoard( char board[ Rows ][ Columns ])
{
     for( int row = 0; row < Rows; row++)
     {
          for( int col = 0; col < Columns; col++)
          {
               board[ row ][ col ] = rand() % 4 + 35;
          }//end column
     }// end row
     
}//end initializeBoard

//show the board
//helps user distinguish rows and columns
void displayBoard( char board[ Rows ][ Columns ] )
{
    //display numbers and line
    displayNumbers();
    displayLine();
    
    //make the board with "A | " and "| A"
    for( int row = 0; row < Rows; row++)
    {
          cout << (char)(row + 'A') << " | " ;
          
          for (int col = 0; col < Columns; col++)
          {                  
              cout << board[ row ][ col ] << " ";
          } // end column
          
          cout << "| " << (char)(row + 'A');
          cout << "\n";
          
     }// end row
     
    //display numbers and line
    displayLine();
    displayNumbers();
     
}// end displayBoard

//find the number of adjacent squares.
//create an array of all 0's, but adjacent squares that have the same
//as selected square has a value of 1 in the array to count and keep
//track of them. if the squares are in a group of 3 or more, they 
//become spaces and "disappear".
void charCluster( int x, int y )
{      
     //declare a char board
     char board[ Rows ][ Columns ];
     
     //create an alternate board
     int newBoard[ Rows ][ Columns ] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
     
    //create offsets to find neighbors left, up, right, and down
    //from selected square
    char neighborOffsets[] = {-1, -8, 1, 8};
    //have int length represent length of string
    int length = strlen( neighborOffsets );
    
    //mark original square's position
    newBoard[ x ][ y ] = 1;
    char userInput[ x ][ y ];
    
    while( true )
    {
           bool thereWasChange = false;
           
           //go through each square on the board
           //if square = 1, then check 4 neighbors
           //if neighbor is the same, set array value to 1
           for( int neighbor = 0; neighbor < length; neighbor++)
           {
                int neighborIndex = neighbor + neighborOffsets[ neighbor ];
                
                if( newBoard[ neighborIndex ][ neighborIndex ] != 1 &&
                    userInput[ neighborIndex ][ neighborIndex ])
                    {
                               newBoard[ neighborIndex ][ neighborIndex ] = 1;
                    }
           }
           
           //if we're done then break out of loop
           if( thereWasChange == false );
           {
               break;
           }
    }//end while(true)
    
    //accumulate the count of adjacent chars
    int numberOfSameChars = 0;
    for( int row = 0; row < 8; row++)
    {
         for( int col = 0; col < 10; col++)
         {
              if( newBoard[ row ][ col ] == 1 );
              {
                  numberOfSameChars++;
              }
         }
    }
     
     //if cluster size >= 3
     //then replace with ' '
     if( numberOfSameChars >= 3 )
     {
         for( int row = 0; row < 8 ; row++)
         {
              for (int column = 0; column < 10; column++)
              {
                  board[ Rows ][ Columns ] = ' ';
              }
         }
     }
     
     //slide down squares
     for( int row = 0; row < 8; row++)
     {
         for( int col = 0; col < 10; col++)
         { 
             if( board[ row ][ col ] == ' ' );
             {
                 
             }
         }
     }
     
     //if left column is blank
     //have current column slide to the left
     bool returnValue = true;
     int column;
     column--;
    
     for( int row = 8; row > 1; row--)
     {
        int charIndex = row * (Rows + 2) + column;
        if( board[ Rows ][ Columns ] = ' '); 
        {
            returnValue = false;
            break;
        }// end if(...)
     }// end for( int row)    
         
}        

int main()
{
    //get user input for row and column
    int moveNumber = 1;
    char userInput[81];       //C string for user input
    int row, col;   
    
    //display information
    displayInfo();
    
    //create board
    char board[ Rows ][ Columns ];
    
    //initialize board
    initializeBoard( board );
    
    //run this loop so that the player can play the
    //program until they win or exit
    while (true)
    {
        //display board
        displayBoard( board );
        
        //display move number and prompt
        cout << "\n" << moveNumber << ". " 
             << "Enter the row and column (e.g. c5) "
                "or 'r' to reset or 'x' to exit --> "; 
        //grab userInput info     
        cin >> userInput;
        cout << "\n";
        
        // pull out first character
        // and then convert to integer values
        char c = userInput[ 0 ];
        //convert lowercase to uppercase
        if( c >= 'a' && c <= 'z')
        {
            c = c - ('a' - 'A');
            row = c - 'A';
        }
        else
        {
            row = userInput[ 0 ] - 'A';
        }
        
        //check if first character is x or r
        //if user chooses 'x' then exit the program
        if( userInput[0] == 'X' || userInput[0] == 'x' )
        {
           cout << "Exiting program...\n" << endl;  
           break;             
        }
        //if user chooses 'r'
        //then randomize board, display reset message and reset move number
        else if( userInput[0] == 'R' || userInput[0] == 'r' )
        {
             //reset message and move number
             cout << "Restarting board...\n\n";
             int moveNumber = 1;
             initializeBoard( board );  
        }
        
        //pull out second character
        //and convert to integer values
        col = userInput[ 1 ] - '1';
        
        //increment move number
        moveNumber++;
        
    }
    
    cout << "\nDone. \n";
    system("pause");
    return 0;
    
}
