/* gridmatch.cpp - Play a gridmatch game
		
	Author: Bresia Prudente
	Date: 	4/23/2012
	Class: 	CS 102 Assignment 6
	System:  g++ Compiler: DEVC++
	Description:
		Choose characters from groups of 3 or more in a grid.  Those grouped 
		characters disappear, with the squares above sliding down.
 */
#include <iostream>
using namespace std;

// global constants
const int NUMBER_OF_ROWS = 8;
const int NUMBER_OF_COLUMNS = 10;

// struct for linked list
struct Node
{
       char boardDisplay[ NUMBER_OF_ROWS ][ NUMBER_OF_COLUMNS ];
       int moveNumber;
       Node *pNext;
};

void displayIDinfo()
{
   cout << "Author: Bresia Prudente \n"
        << "Da;te: 4/23/12, CS 102 Spring '12 \n"
        << "System: C++ \n"
        << endl;
}

void displayInstructions()
{
   cout << "Play the game of Grid Match.  The object is to make as many squares \n"
        << "as possible disappear from the board. On each move choose a particular \n"
        << "square using the row,column coordinates.  That square and any adjacent \n"
        << "similar squares will all be blanked out if there are 3 or more of them. \n"
        << "Squares above the empty squares then slide down.  Empty columns slide \n"
        << "to the left. Input of 'r' will restart the game and re-randomize the \n"
        << "board, and input of 'x' will exit the game. \n"
        << endl;
}

//--------------------------------------------------------------------------
// Called from several places to pause the output
int pause()
{
	char c;	// a temporary character
	
	// Read and discard input to the end of the line.
	do {
		scanf( "%c", &c);
	} while ( c != '\n');

   // Prompt for "enter" to be pressed by the user	
	printf("Press the enter key to continue...");
	scanf("%c", &c);
	printf("\n");
}//end pause()


//--------------------------------------------------------------------------
// Randomly choose one of: @ # - +
char getRandomChar()
{
   // get a random number 0..3
   int x = rand() % 4;  
   
   // choose the character corresponding to the random number 
   char c = ' ';
   switch (x) {
      case 0: c='@'; break;
      case 1: c='#'; break;
      case 2: c='-'; break;
      case 3: c='+'; break;
   }
   
   return c;
}// end getRandomChar()


//--------------------------------------------------------------------------
// Store the given board and move number on a new Node, and connect that
// Node to the linked list.
void storeNode( Node* &pHead,                // pointer to head of list
                char boardDisplay[ NUMBER_OF_ROWS ][ NUMBER_OF_COLUMNS],  // the 2D board
                int moveNumber)              // move number
{
   Node *pTemp = new Node();
   
   // copy the board into the new node
   for( int i=0; i<NUMBER_OF_ROWS; i++) 
   {
       for( int j=0; j<NUMBER_OF_COLUMNS; j++) 
       {
            pTemp->boardDisplay[ i][ j] = boardDisplay[ i][ j];
       }   
   }   
   // copy the move number into the new node
   pTemp->moveNumber = moveNumber;
   
   // Connect the node into the list and update the head of the list
   pTemp->pNext = pHead;
   pHead = pTemp;          
}//end storeNode()


//--------------------------------------------------------------------------
// Retrieve information from the linked list and store it into the boardDisplay
// and moveNumber.
void retrieveNode( Node *&pHead,                // pointer to head of list
                   char boardDisplay[ NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS],  // the 2D board
                   int &moveNumber )              // move number
{
   // Ensure we also have at least the original Node on the list
   // containing the starting board configuration.
   if( pHead->pNext == NULL) 
   {
       printf("Can't undo past the beginning of the game.  Enter 'c' to continue: ");
       char c;
       scanf(" %c", &c);   // now pause the output
       return;    
   }
   
   // The current node has the current board.  Delete this one and go back to the
   // one before that.
   Node *pTemp = pHead;
   pHead = pHead -> pNext; 
   
   // copy the board from the previous Node into the current display
   for( int i=0; i<NUMBER_OF_ROWS; i++) 
   {
       for( int j=0; j<NUMBER_OF_COLUMNS; j++) 
       {
            boardDisplay[ i][ j] = pHead->boardDisplay[ i][ j];
       }   
   }   
   // retrieve the move number and number guessed from the Node
   moveNumber = pHead->moveNumber;
     
}//end retrieveNode()


//--------------------------------------------------------------------------
// Go through all board positions and randomly assign one of 4 characters
void initializeBoard( char board[NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS], int &moveNumber, Node* &pHead)
{
   for( int row = 0; row < NUMBER_OF_ROWS; row++) {
      for( int col = 0; col < NUMBER_OF_COLUMNS; col++) {
         // Randomly choose one of: @ # - +  and store in this board position
         board[ row][ col] = getRandomChar();
      }
   }
   
   // reset the move number
   moveNumber = 1;
}//end initializeBoard()


//--------------------------------------------------------------------------
// Draw top or bottom board border.
// Used as part of displayBoard()
void drawBorder()
{
      // display board top or bottom border
   cout << "    ";
   for( int col = 0; col < NUMBER_OF_COLUMNS; col++) {
      cout << "--";
   }
   cout << "-\n";
}

//--------------------------------------------------------------------------
// Display numbers, which will appear at the top or bottom of the board
// Used as part of displayBoard()
void displayNumbers()
{
   cout << "     ";
   for( int col = 0; col < NUMBER_OF_COLUMNS; col++) {
      cout << col << " ";
   }
   cout << endl;
}

//--------------------------------------------------------------------------
// Display the board
void displayBoard( char board[NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS])
{
   cout << "\n\n";   // leave a blank row
   displayNumbers(); // display row of column numbers
   drawBorder();     // top border
   
   // display all board rows
   for( int row = 0; row < NUMBER_OF_ROWS; row++) {
      cout << " " << (char)(row + 'A') << " | ";
      for( int col = 0; col < NUMBER_OF_COLUMNS; col++) {
         cout << board[ row][ col] << " ";
      }
      cout << "| " << (char)(row + 'A') << endl;
   }
   
   drawBorder();   // bottom border
   displayNumbers(); // display row of column numbers
   cout << endl;
}//end displayBoard()


//--------------------------------------------------------------------------
char convertToUpper( char c)
{
   // if alphabetic lower case, convert to upper case
   if( c>= 'a' && c<='z') {
      c = c - ('a'-'A');    
   }
   return c;
}//end convertToUpper()


//--------------------------------------------------------------------------
void setArrayToZeros( int adjacentSimilarPieces[ NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS])
{
   for( int i=0; i<NUMBER_OF_ROWS; i++) 
   {
      for( int j = 0; j<NUMBER_OF_COLUMNS; j++) 
      {
         adjacentSimilarPieces[ i][ j] = 0;
      }    
   }   
}


//--------------------------------------------------------------------------
// Counts number of 1's in the array, representing the number of adjacent
// pieces of the same type.
int countNumberAdjacent( int adjacentSimilarPieces[ NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS])
{
    int numberAdjacent = 0;
    for( int i=0; i<NUMBER_OF_ROWS; i++) 
    {
       for( int j = 0; j<NUMBER_OF_COLUMNS; j++) 
       {
          if( adjacentSimilarPieces[ i][ j] == 1) 
          {
              numberAdjacent++;
          }
       }//end for( int j...    
    }// end for( int i...
    
    return numberAdjacent;
}//end countNumberAdjacent()


//--------------------------------------------------------------------------
// See if the row, column indices are in bounds.  If so see if the piece at
// that position matches thePiece the user selected.  If so, place a 1 in
// the adjacentSimilarPieces array and set the changesWereMade boolean variable
// to true.
void handlePosition( char board[][NUMBER_OF_COLUMNS],
                     int row,
                     int column, 
                     char thePiece, 
                     int adjacentSimilarPieces[][NUMBER_OF_COLUMNS],
                     bool &changesWereMade)
{
   // Ensure table indices are in bounds.  If not return.
   if( row<0 || row >= NUMBER_OF_ROWS || column < 0 || column >= NUMBER_OF_COLUMNS) {
      return;
   }
   
   // See if the piece at that position matches thePiece the user selected
   // and it hasn't already been explored, which would be indicated by
   // a 1 in the adjacentSimilarPieces array.
   // If it is a new matching piece place a 1 in the adjacentSimilarPieces array  
   // and set the changesWereMade boolean variable to true. 
   if( board[ row][ column] == thePiece && adjacentSimilarPieces[ row][ column] != 1) {
      adjacentSimilarPieces[ row][ column] = 1;
      changesWereMade = true;  
   } 
}//end handlePosition


//--------------------------------------------------------------------------
// Go through the board, finding all adjacent pieces with the same character
// as the character where the user made a move.  For all those found adjacent
// pieces that are the same put a 1 in that position in the adjacentSimilarPieces
// array.
void findAdjacentSimilarPieces( char board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], 
                                char thePiece, 
                                int adjacentSimilarPieces[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS])
{
   // Iteratively loop through board.  When a 1 is found, check adjacent
   // neighbors.  If they are not already a 1, see if the board square at
   // that position has the same value as the original move.  If so,
   // set it to a 1 as well.  Continue this process until a pass is made
   // through the board and no changes are made.
   bool changesWereMade;
   while( true) {
      changesWereMade = false;
      for( int i=0; i<NUMBER_OF_ROWS; i++) {
       for( int j = 0; j<NUMBER_OF_COLUMNS; j++) {
          if( adjacentSimilarPieces[ i][ j] == 1) {
              // Check all 4 neighbors to see if they match the piece and 
              // haven't already been explored.  Check left, up, right, down.
              // If a change is made, set changesWereMade to true
              handlePosition( board, i, j-1, thePiece, adjacentSimilarPieces, changesWereMade);  // left
              handlePosition( board, i-1, j, thePiece, adjacentSimilarPieces, changesWereMade);  // up
              handlePosition( board, i, j+1, thePiece, adjacentSimilarPieces, changesWereMade);  // right
              handlePosition( board, i+1, j, thePiece, adjacentSimilarPieces, changesWereMade);  // down
          }
       }//end for( int j...    
      }// end for( int i...
      
      // If no changes were made, we're done and can stop the neighbor checking
      if( changesWereMade == false) {
         break;
      }
   }//end while( true)
     
}//end findAdjacentSimilarPieces()
   

//--------------------------------------------------------------------------   
// Clear board spots for adjacent pieces.
// Go through the adjacentSimilarPieces array.  Everywhere there is a 1,
// clear out the corresponding spot in the board.    
void clearBoardSpotsOfAdjacentPieces( 
                  char board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], 
                  int adjacentSimilarPieces[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS])
{
    for( int i=0; i<NUMBER_OF_ROWS; i++) {
       for( int j = 0; j<NUMBER_OF_COLUMNS; j++) {
          if( adjacentSimilarPieces[ i][ j] == 1) {
              board[ i][ j] = ' ';
          }
       }//end for( int j...    
    }// end for( int i...
}//end clearBoardSpotsOfAdjacentPieces


//--------------------------------------------------------------------------
// For debugging display adjacency array
void displayAdjacencyArray( int adjacentSimilarPieces[NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS])
{
   // display all adjacency array values
   for( int row = 0; row < NUMBER_OF_ROWS; row++) {
      cout << " " << (char)(row + 'A') << " | ";
      for( int col = 0; col < NUMBER_OF_COLUMNS; col++) {
         cout << adjacentSimilarPieces[ row][ col] << " ";
      }
      cout << "| " << (char)(row + 'A') << endl;
   }
}//end displayAdjacencyArray

     
//--------------------------------------------------------------------------     
// After blanking out adjacent matching squares, slide down any pieces
// above the now empty squares.
void slideDownPieces( char board[][NUMBER_OF_COLUMNS])
{
   // Iterate through the board to slide squares down when
   // there is empty space below them.  Start at the bottom displayed row 
   // and move up so that squares slide all the way down.
   for( int row = NUMBER_OF_ROWS - 2; row >= 0; row--) {
      for( int column = 0; column < NUMBER_OF_COLUMNS; column++) {
         
      	// if a square is occupied and the square below it is blank then
      	// slide it down as far as possible.
      	int currentRow = row;  // make a temporary row indicator
      	while( (board[ currentRow][column] != ' ') && (board[ currentRow+1][column] == ' ') ){
      		// slide square down one spot
      		board[ currentRow+1][ column] = board[ currentRow][ column];
      		board[ currentRow][ column] = ' ';
      		// advance the currentRow if it is still in bounds
      		if( currentRow < NUMBER_OF_ROWS - 1) {
               currentRow++;
            }
            else {
               // we're at the bottom, so break out of this loop
               break;
            }
      	}//end while( board[ ...
      	
      }//end for( int column
   }//end for( int row 
   
}//end slideDownPieces 
    	

//--------------------------------------------------------------------------
// If a column is blank, shift the columns to the left
bool columnIsEmpty( char board[][NUMBER_OF_COLUMNS], int column )
{           
            
    bool returnValue = true;
    column--;        //sets column to the left
    
    for( int row = NUMBER_OF_ROWS; row > 1; row--)
    {
         
              if( board[row][column] == ' ' &&
                  board[row - 1][column] == ' ' &&
                  board[row - 2][column] == ' ' &&
                  board[row - 3][column] == ' ' &&
                  board[row - 4][column] == ' ' &&
                  board[row - 5][column] == ' ' &&
                  board[row - 6][column] == ' ' &&
                  board[row - 7][column] == ' ' &&
                  board[row - 8][column] == ' ' )
                  {
                        returnValue = true;
                  } 
              else
                  {
                        returnValue = false;
                        break;
                  }
                     
             
    }
    return returnValue;
    
           
}// end bool columnIsEmpty(int...


//--------------------------------------------------------------------------
// If a column is blank, shift the columns to the left
void shiftColumnLeft( char board[][NUMBER_OF_COLUMNS] )
{

     for(int x = 0; x < NUMBER_OF_COLUMNS ; x++) 
     {
             if( columnIsEmpty( board, x) ) 
             {
                  for(int y = 0; y < NUMBER_OF_ROWS; y++) 
                  {
                          if( (x + 1) != NUMBER_OF_COLUMNS ) 
                          {
                                 char temp;
                                 temp = board[y][x];
                                 board[y][x] = board[y][x+1];
                                 board[y][x+1] = temp;
                          }
                  }
              }
     }
}
    	
    	
//--------------------------------------------------------------------------
// Make a move.  If a valid move is found and made, return true, else return false.
bool makeMove(char board[NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS],
              char theRowChar, 
              char theColumnChar,
              int &moveNumber,
              Node* &pHead)
{
   // fold input characters into upper case
   theRowChar = convertToUpper( theRowChar);
   int row = theRowChar - 'A';
   int column = theColumnChar - '0';
   
   // Ensure move is not in a blank spot on the board
   if( board[ row][column] == ' ') {
      return false;
   }

   // Find adjacent positions that are the same character.  
   // Create an array of 0 and 1 to mark and subsequently
   // count the number of adjacent squares of the same type.
   int adjacentSimilarPieces[ NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS];
   // initialize values in this array to all zeros
   setArrayToZeros( adjacentSimilarPieces);
   // place a 1 in the selected move
   adjacentSimilarPieces[ row][ column] = 1;
   // Go through and set a 1 for all similar pieces adjacent to the users move
   findAdjacentSimilarPieces( board, board[ row][column], adjacentSimilarPieces);

   // displayAdjacencyArray( adjacentSimilarPieces);     // for debugging 
   
   // See if there were at least 3 adjacent pieces
   int numberAdjacent = countNumberAdjacent( adjacentSimilarPieces);
   if( numberAdjacent >= 3) {
       // clear board spots for adjacent pieces
       clearBoardSpotsOfAdjacentPieces( board, adjacentSimilarPieces);
       
   // Increment moveNumber
   moveNumber++;
   
   // slide down characters above deleted characters
   slideDownPieces( board);

   
   // store new board and moveNumber
   storeNode(pHead, board, moveNumber);
   
   }
   else 
   {
      return false;
   }
   
      // shift columns to the left
   shiftColumnLeft( board );
   
   return true;
}//end makeMove()
  
  
//--------------------------------------------------------------------------
// See if there are moves remaining.  We operate on a copy of the board so
// we can reuse existing code to try all possible moves to see if one is valid.
bool thereAreMovesRemaining( char board[NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS], Node *pHead)  
{
   // Make a copy of the board.  
   char boardCopy[ NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS];
   for( int row = 0; row < NUMBER_OF_ROWS; row++) 
   {
      for( int col = 0; col < NUMBER_OF_COLUMNS; col++) 
      {
         boardCopy[ row][ col] = board[ row][ col];
      }//end for( int col...
   }//end for( int row...
   
   // Go through each spot on the board and see
   // if a valid move could be found at that position.  If so then there are
   // moves remaining and return true;
   int moveNumber;   // placeHolder to allow calling makeMove
   for( char row = 'A'; row <= 'H'; row++) 
   {
      for( char col = '0'; col <= '9'; col++) 
      {
         if( makeMove( boardCopy, row, col, moveNumber, pHead)) {
            return true;
         }
      }//end for( int col...
   }//end for( int row...
   
   return false;
}//end thereAreMovesRemaining()
          

//--------------------------------------------------------------------------
// Used for debugging
void displayList( Node *pHead )
{
     cout << "List: ";
     while( pHead != NULL )
     {
            cout << " " << pHead->moveNumber;
            pHead = pHead -> pNext;
     }
     cout << "\n";
}
               
//--------------------------------------------------------------------------
// Starting point for program
int main()
{
   Node *pHead = NULL;
   
   // declare the board
   char board[ NUMBER_OF_ROWS][ NUMBER_OF_COLUMNS];
   int moveNumber = 1;  // keeps track of move numbers
   
   // display identifying information and instructions
   displayIDinfo();
   displayInstructions();
   
   // initialize the board
   initializeBoard( board, moveNumber, pHead);
   
   // create first Node on linked list
   storeNode( pHead, board, moveNumber );
   
   // main loop
   while( thereAreMovesRemaining( board, pHead)) {
      displayBoard( board );
      
      //displayList( pHead ); //debugging
      
      // Prompt for user input and handle input
      char row, column;
      cout << moveNumber << ". Enter the row and column (e.g. c5) \n"
           << "   or 'r' to reset or 'x' to exit --> ";
      cin >> row;
      // check to see if 'x' to exit, 'r' to restart
      // or 'u' to undo were chosen
      if( row == 'x') {
         cout << "Exiting program..." << endl;
         break;   // break out of enclosing loop  
      }
      if( row == 'r') {
         cout << "Resetting board..." << endl;
         initializeBoard( board, moveNumber, pHead);
         continue;   // continue on up to top of main loop to restart game
      }
      if( row == 'u') 
      {
         cout << "Undoing board..." << endl;
         retrieveNode( pHead, board, moveNumber);   
         continue;     // continue with board undo
      }
      // Neither 'x' to exit, 'r' to reset or 'u' to undo were chosen, 
      //so first character must be the row.  Now read in the column.
      cin >> column;
      
      // make the move and increment moveNumber if it is a valid move
      if( makeMove( board, row, column, moveNumber, pHead) == false) {
            cout << "Must be group of 3 or more.  Please retry." << endl;
      
      }
      
   }//end while( true)
   
   cout << "Done with game. Thanks for playing. Exiting..." << endl;

   pause();    // pause the output.  Works in DevC++ and others as well
   return 0;
}
