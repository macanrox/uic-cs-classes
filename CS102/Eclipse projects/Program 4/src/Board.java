/**
 * GridMatch program
 * 
 * 		Implement the functionality for a game where the user
 * tries to clear the board by clicking on groups of adjacent
 * squares of the same color, where there are 3 or more in a 
 * group.
 *  
 * Selecting the "Redo" button starts over.  Selecting the 
 * "Exit" button exits the game.
 * 
 * Class: CS 102, Spring 2012
 * Lab: Billie Joe Armstrong, Wed. 6:00 AM
 * System: Eclipse 3.4.2, jsdk 1.6, Windows 7

 * @author Dale Reed 
 * @version March 31, 2012
 * 
 */

import java.util.Scanner;		  // allows user input from the keyboard
import java.util.Random;          // allows getting a random number
import java.util.Date;			  // allow creating a Date object to keep track of time


public class Board
{      	
    // Create the random number generator.  "Seed" this with the value 1.
    // Removing the value from the parenthesis will give a different result every
    // time, which isn't what we want when we are debugging.
    Random randomNumberGenerator = new Random(1);  
	
	// declare squares to be displayed
    Square resetBoard; 	        // reset board
    Square exitButton;			// users presses this to exit program
    Square gameMessagesLabel;	// Used to display messages
    Square goalLabel;			// Message shown above goal squares
    Square boardCenterBackground; // used to "erase" the board between rounds
    
    // declare some squares to be displayed on the screen
    Square[] theSquares;
    
    // declare constants to use throughout program
    final int OFFSET = 6;	
    final int HOW_MANY_COLORS = 4;	  // how many different square colors are used
    final int BACKGROUND_SIZE = 258;  // size of the background
    int SquaresPerSide = 5;	  // how many squares per side
    // should be 44 when 5 squares per side
    int SquareSize = ((BACKGROUND_SIZE - OFFSET) / SquaresPerSide) - OFFSET;	
    // should be 44 when 5 squares per side
    int TotalSquares = (SquaresPerSide+2) * (SquaresPerSide+2);
    int moveNumber = 0;
    // keep track of upper-left of squares drawing area, used to reset the board
    int squaresStartDrawingXPosition;   
    int squaresStartDrawingYPosition;   
    boolean noMovesLeftOnBoard = false;		// used to reset board after all possible moves made
    
    // Create a Date object to keep track of time
    Date startTime = new Date();


    //----------------------------------------------------------------------------------------------
    // Constructor to create the board
    Board()
    {   
    	// display ID information and the instructions
    	displayIdInformation();
    	displayInstructions();
    	
    	// Set variables used to indicate upper-left position of object to be drawn.
    	// This way the entire board can be moved by simply changing these values.
    	int xPosition = 40; 
    	int yPosition = 40;
    	
		// make the board background squares
    	Square boardBackground = null;		// make a Square reference that we can reuse
    	// background large black outline
    	boardBackground = new Square (xPosition, yPosition, 270, "black", true, "");  
    	xPosition += OFFSET;		// same as xPosition = xPosition + OFFSET;    // add OFFSET to x
    	yPosition += OFFSET;		// same as yPosition = yPosition + OFFSET;    // add OFFSET to y
    	// lightGray board background
		boardBackground = new Square (xPosition, yPosition, 258, "lightGray", true, "");	
		
		// adjust the x,y starting position
    	xPosition = xPosition + OFFSET;	 
    	yPosition = xPosition - OFFSET/4 + 2;	
    	// keep track of the upper-left position of squares drawing area, used
    	// to reset the board when redrawing squares.
    	squaresStartDrawingXPosition = xPosition;  
        squaresStartDrawingYPosition = yPosition;
    	
    	// Create and Initialize each of the squares
    	createAndInitializeSquareColors();
				    
		// create the "Redo" and "Exit" squares near the bottom right of the board
		gameMessagesLabel = new Square( 160, 330, 40, "white", true, "Welcome to the Grid Match game.");
		goalLabel = new Square( 420, 50, 40, "white", true, "Click on groups of 3 or more.");
		resetBoard = new Square( 410, 330, 40, "lightGray", true, "Reset");
		exitButton = new Square( 460, 330, 40, "lightGray", true, "  Exit");
    }//end Board() constructor
    
    
    void createAndInitializeSquareColors()
    {
    	// See if previous board was done
    	if( noMovesLeftOnBoard) {
    		// previous board was done, so reset boolean variable and increment number of squares per side
    		noMovesLeftOnBoard = false;		// reset
    		SquaresPerSide += 2;
    	}
    	
    	// Recalculate TotalSquares and SquareSize, in case the SquaresPerSide has changed
        SquareSize = ((BACKGROUND_SIZE - OFFSET) / SquaresPerSide) - OFFSET;	
        // should be 44 when 5 squares per side
        TotalSquares = (SquaresPerSide+2) * (SquaresPerSide+2);
    	
    	int xPosition = squaresStartDrawingXPosition;
    	int yPosition = squaresStartDrawingYPosition;
    		
		// create lightGrey board center background
		boardCenterBackground = new Square (xPosition-OFFSET, yPosition-OFFSET, 258, "lightGray", true, "");
		
    	// declare the array of Squares.  Add an extra square all the way around the sides to simplify
        // the code that checks for adjacent squares of similar colors.  This "extra" row will never 
        // match color, since they will be set to "white" and additionally will never be displayed.
    	theSquares = new Square[ (SquaresPerSide+2) * (SquaresPerSide+2)];
    	
		// initialize each of the squares
		for( int i=0; i< TotalSquares; i++) {
			// if it is a border square, then make the color white and don't display it
			if( isABorderSquare( i, (SquaresPerSide+ 2)) ) {
				theSquares[ i] = new Square( 0,0, 1, "white", false, "");
			}
			else {
				// else give it a random color and display it
		    	theSquares[ i] = new Square( xPosition, yPosition, SquareSize, getRandomColor(), true, "");
				xPosition += SquareSize + OFFSET;
			}
			// if we are at the end of a row (but not the first row) then reset both x and y positions
			if( ((i+1) % (SquaresPerSide+2) == 0) && (i >= (SquaresPerSide+2))) {
				xPosition = squaresStartDrawingXPosition;
				yPosition += SquareSize + OFFSET;
			}
		}
    }// initialize the colors of each square
	
	
    //----------------------------------------------------------------------------------------------
    // See if square at index position i is one of the edge squares
    // values for a 5 x 5 board:
    //     0  1  2  3  4 
    //     5  6  7  8  9 
    //    10 11 12 13 14
    //    15 16 17 18 19 
    //    20 21 22 23 24
    // Values for a 5 x 5 board with an extra border around all sides:
    //     0  1  2  3  4  5  6
    //     7  8  9 10 11 12 13
    //    14 15 16 17 18 19 20
    //    21 22 23 24 25 26 27
    //    28 29 30 31 32 33 34
    //    35 36 37 38 39 40 41
    //    42 43 44 45 46 47 48 
    // The "size" parameter is a value that reflects the extra border,
    // so in the case of a 5 x 5 board it would be 7
    private boolean isABorderSquare( int i, int size)
    {
    	// see if it is one one of the borders
    	if( ( i % size == 0) ||	      // it is on the left column
			( i < size) ||	          // it is on the top row
			( (i+1) % size == 0) ||	  // it is on the right column
			( i >=  (size*size - size) ) // it is on the bottom row
		   ) {
    		return true;
    	}
    	else {
    		return false;
    	}
    }
    
    
    //----------------------------------------------------------------------------------------------
    public void displayIdInformation()
    {
        // Display identifying information
        System.out.println( "Author: Dale Reed \n" +
                            "Program #4: GridMatch \n" +
                            "March 3, 2012\n");
    }//end displayIdInformation()
    
    
    //----------------------------------------------------------------------------------------------
    public void displayInstructions()
    {
        // Display Instructions
        System.out.println( "Welcome to the Grid Match game. \n" +
        					"\n" +
        					"Try to eliminate all squares on the board.  To make squares \n" +
        					"disappear click on any group of 3 or more, making the squares  \n" +
        					"above slide down. \n");
    }//end displayInstructions()
    
    
    //----------------------------------------------------------------------------------------------
    // Generate a random number used to select one
    String getRandomColor()
    {
    	String theColor = "";	// will store the color, to be returned
    	
    	// generate a random number, which will be used to select a color among 8 colors
    	int randomNumber = randomNumberGenerator.nextInt( HOW_MANY_COLORS);
    	
    	switch (randomNumber) {
    		case 0: theColor = "darkGray"; break;
    		case 1: theColor = "red"; break;
    		case 2: theColor = "blue"; break;
    		case 3: theColor = "yellow"; break;
    		case 4: theColor = "green"; break;
    		case 5: theColor = "magenta"; break;
    		case 6: theColor = "cyan"; break;
    		case 7: theColor = "orange"; break;
    		case 8: theColor = "pink"; break;
    		default: System.out.println("Random number value for color out of range.  Exiting...");
    				System.exit( -1);
    				break;
    	}//end switch
    	
    	return theColor;
    }//end getRandomColor()
    
    
    //----------------------------------------------------------------------------------------------
    // Handle each mouse click
    void handleMouseClick(int mouseX, int mouseY)
    {   
    	Square theSquare = null;     // make a reference that can point to any square
    	
        // Find out where the mouse click was, in some square 
    	
    	// First check the exit button
        if( mouseClickedInSquare( mouseX, mouseY, exitButton)) {
             System.out.println("Clicked on the exit button.  Exiting program...");
             System.exit( 0);	// exit the program
        } 
        
        // see if the reset button was selected
        if( mouseClickedInSquare( mouseX, mouseY, resetBoard)) { 
        	randomizeBoard();
            return;     // go back and wait for another mouse click
        }
        
        // Now iterate through the board squares, until the one that was clicked is found.
        for( int i=0; i< TotalSquares; i++) {
        	theSquare = theSquares[ i];
        	if( mouseClickedInSquare( mouseX, mouseY, theSquare)) { 
        		handleCluster( i);
            }
        }
   	
        // See if there are any remaining moves to be made.  Do this by stepping through
        // the board and simulating clicking on each color (non-gray) square as if it were
        // chosen for a move.  Call the method that counts how many adjacent same-color
        // square there are for each of these simulated moves.  If this value is >= 3 for
        // any square, then we know that we're not done yet. At this point in the program 
        // we don't care about *which* squares are identical, just the fact that there is
        // still some group of 3 or more adjacent squares of the same color.
        boolean thereAreRemainingMoves = false;
        
    	// Check each valid board position, but don't check the border squares
        for( int row = 1; row <= SquaresPerSide; row++) {
        	for( int column = 1; column <= SquaresPerSide; column++) {
    			// check if square is part of a playable group.
        		// First calculate the index from the row and column value
    			int squareIndex = row * (SquaresPerSide+ 2) + column;
    			String theColor = theSquares[ squareIndex].getColor();

    	        // Make a dummy array of ints to satisfy the recursiveCount method.  For each
    			// square we only want to know if it is part of a group of 3 or more.
    	        int[] dummyArray = new int[ TotalSquares];
            	if( !theColor.equals("lightGray") && countAdjacentSameColorSquares( squareIndex, dummyArray) >= 3) {
            		thereAreRemainingMoves = true;
            		break;
            	}
    		}//end for( int column...
        	if( thereAreRemainingMoves) {
        		// we found a valid move, so break out of the moves check loops
        		break;
        	}
    	}//end for( int row...

        // handle the case when there are no more remaining moves
        if( thereAreRemainingMoves == false) {
        	// display message and pause
        	gameMessagesLabel.setLabel("         No moves left on this board. Press the Reset button.");
        	// variable set below causes grows board size once Reset button is pressed
        	noMovesLeftOnBoard = true;
        	return;
        }
        
        // increment move counter
        moveNumber++;
        
        // display move number and time elapsed
        Date rightNow = new Date();
    	long elapsed = (rightNow.getTime() - startTime.getTime()) / 1000;
        gameMessagesLabel.setLabel("Move # " + moveNumber + ", with " + elapsed + " seconds elapsed.");
    }//end handleMouseClick

    
    boolean mouseClickedInSquare( int mouseX, int mouseY, Square theSquare) 
    {
	    // Find out where the mouse click was, in some square 
	    if( (mouseX >= theSquare.getX()) && (mouseX <= (theSquare.getX() + theSquare.getSize())) &&   
	        (mouseY >= theSquare.getY()) && (mouseY <= (theSquare.getY() + theSquare.getSize()))
	    ) {
	         return true;
	    } 
	    
	    return false;
    }//end mouseClickedInSquare()
    
    
    // Find the number of adjacent like-colored squares.
    // First create an array of all 0's, except squares adjacent
    // to the selected square that are the same color as the selected
    // square have a 1 set in this array to count and keep track 
    // of them.  If the count is >= 3, then set all those squares
    // to "lightGray", making them essentially disappear.
    // values for a 5 x 5 board:
    //     0  1  2  3  4 
    //     5  6  7  8  9 
    //    10 11 12 13 14
    //    15 16 17 18 19 
    //    20 21 22 23 24
    // Values for a 5 x 5 board with an extra border around all sides:
    //     0  1  2  3  4  5  6
    //     7  8  9 10 11 12 13
    //    14 15 16 17 18 19 20
    //    21 22 23 24 25 26 27
    //    28 29 30 31 32 33 34
    //    35 36 37 38 39 40 41
    //    42 43 44 45 46 47 48 
    // The "size" parameter is a value that reflects the extra border,
    // so in the case of a 5 x 5 board it would be 7
    void handleCluster( int index)
    {   	
    	// array to mark adjacent squares of same color
    	int[] squaresTags = new int[ TotalSquares];   // marks which squares are same color
    	int numberOfSameColorSquares = 0;			   // tells how many adjacent squares match the current one
    	
    	// Find how many adjacent squares are similar, and mark them in the squaresTags array
    	numberOfSameColorSquares = countAdjacentSameColorSquares( index, squaresTags);
    	    	
    	// if the cluster size was >=3, then go through and
    	// set all those squares to lightGray, essentially
    	// making them disappear.
    	if( numberOfSameColorSquares >= 3) {
	    	for( int i=0; i<squaresTags.length; i++) {
	    		if( squaresTags[ i] == 1) {
	    			theSquares[ i].setColor("lightGray");
	    		}
	    	}//end for( int i...
    	}//end if
    	
    	// Slide Down:
    	//        Iterate through the board to slide squares down when
    	// there is empty space ("lightGray") below them.  We have a playing
    	// space of size SquaresPerSideon a side, but have added an extra
    	// border on both sides (and top and bottom) which is why to find the 
    	// index of the square below we must add an extra 2.
    	// Start at the bottom displayed row and move up so that squares slide all the way down
    	for( int i=TotalSquares - (SquaresPerSide+3); i>(SquaresPerSide+2); i--) {
    		// if a square has a color and the square below it is blank
    		if( ! theSquares[i].getColor().equals("lightGray") && 
    			theSquares[i+(SquaresPerSide+2)].getColor().equals("lightGray") ) {
    			// slide down
    			slideSquare( i, (SquaresPerSide+2));
    		}
    	}//end for( int i...
    	
    	// Eliminate any blank columns, sliding squares to the left.  Start in the second
    	// displayed column then repeat successively with columns to the right.
    	for( int column = 2; column <= SquaresPerSide; column++) {
    		
    		// First find out *how many* columns to the left are blank so we know how far
    		// to slide the column over.
    		int numberOfBlankColumnsToTheLeft = 0;	// used to count number of positions to slide over
    		int columnCopy = column;	 		    // make copy so we keep track of original column we are dealing with
    		// loop through to count how many column positions we need to slide over
    		while( columnToTheLeftIsBlank( columnCopy)){
				numberOfBlankColumnsToTheLeft++;
				columnCopy--;
    		}
    		
    		// shift current column left if there are blank columns to the left of it
    		if( numberOfBlankColumnsToTheLeft >= 1) {	
    			// column to the left is blank, so slide this column left  
	    		for( int row = SquaresPerSide; row > 1; row--) {
	    			// handle the particular square, sliding it to the left
	    			int squareIndex = row * (SquaresPerSide+ 2) + column;
	            	slideSquare( squareIndex, -numberOfBlankColumnsToTheLeft);   // -1 means slide left
	    		}//end for( int row...
    		}
    	}//end for( int column...
    	
    }//end handleCluster
 
    
    // Set up the count of the number of squares that are the same color as the one
    // at the "index" position.  Mark those similar squares with a 1 in the squaresTags array.
    int countAdjacentSameColorSquares( int index, int[] squaresTags)
    {   	
    	// Create an array of offsets used to add to an index position to find
    	// the neighbors to the left, above, right and below.  Each value
    	// will be used in turn.  For a 5x5 array the offsets would simply be
    	// -1, -5, 1, +5, but we have to use formulas below since the size of
    	// the board changes over time.
    	int[] neighborOffsets = {-1, -(SquaresPerSide+2), 1, (SquaresPerSide+2)};

    	// Mark the original clicked-upon square's position in the squaresTags array
    	// and get the color of the clicked-upon square.
    	squaresTags[ index] = 1;
    	String theColor = theSquares[ index].getColor();
    	
    	// Iteratively go through the board, setting a value of 1 in the squaresTags
    	// array for each adjacent square that is the same color.  Keep doing this
    	// until we make a complete pass through the board and there is no change,
    	// at which point we know we're done.
    	while( true) {
    		boolean thereWasAChange = false;
    		
    		// Go through each square on the board.  For each square if it is a 1
    		// then check its 4 neighbors to see if the neighbor is the same color.
    		// If neighbor is the same color, set its squareTag array value to 1.
    		for( int i=0; i<theSquares.length; i++) {
    			
    			// if it is not one of the extra border squares and its squaresTag is 1
    			if( isABorderSquare( i, (SquaresPerSide + 2)) == false && 
    			    (squaresTags[ i]==1) ) {
    				
    				// Check its neighbors on all 4 sides.
    		    	for( int whichNeighbor=0; whichNeighbor < neighborOffsets.length; whichNeighbor++) {
    			    	int neighborIndex = i + neighborOffsets[ whichNeighbor];
    			    	// If adjacent neighbor has not already been set to 1 and it is
    			    	// the correct color then set it to 1
    		    		if( squaresTags[ neighborIndex] != 1  && 
    		    		    theSquares[ neighborIndex].getColor().equals( theColor) ) {
    		    				squaresTags[ neighborIndex] = 1;  // set the tag for this new square
    		    				// set the boolean variable to keep track of the fact that a change was made
    		    				thereWasAChange = true;
    		    		}//end if( squaresTags...
    		    	}//end for( int whichNeighbor = 0...
    		    	
    			}//end if( ! isABorderSquare(...)
    			
    		}//end for( int i...
    		
    		// If we went through the entire board and no neighbor was changed, then we're done
    		if( thereWasAChange == false) {
    			break;	// break out of the enclosing loop
    		}
    	}//end while( true)
    	
    	// go through the squares Tags and accumulate the count of how many adjacent squares are similar
    	int numberOfSameColorSquares = 0;	// counter, used as the return value
    	for( int i=0; i<squaresTags.length; i++) {
    		if( squaresTags[ i] == 1) {
    			numberOfSameColorSquares++;
    		}
    	}
   	
    	return numberOfSameColorSquares;
    }//end countAdjacentSameColorSquares()
    
    
    // return true if column to the left is blank, allowing current column to slide left
    boolean columnToTheLeftIsBlank( int column) 
    {
    	boolean returnValue = true;
    	// Go through column to the left.  If any square is not "lightGray" then column isn't blank.
    	column--;	// set to the column to the left
    	
		for( int row = SquaresPerSide; row > 1; row--) {
			int squareIndex = row * (SquaresPerSide+ 2) + column;
    		if( ! theSquares[ squareIndex].getColor().equals("lightGray") ) {
    			// square is not blank, so column is not blank
    			returnValue = false;
    			break;
        	}
		}//end for( int row...   	
    	
    	return returnValue;
    }
    
    
    // Slide squares into adjacent blank squares.  When parameter "offset" is sent the value
    // SquaresPerSide+2 then sliding is downward.  When parameter "offset" is sent the
    // value -1, then sliding goes to the left, to eliminate blank columns.
    // Note that we don't really slide a square down, but simply exchange it's color with
    // that in the adjacent square.
    void slideSquare( int i, int offset)
    {
    	while( ! theSquares[i].getColor().equals("lightGray") && 
    			theSquares[i+offset].getColor().equals("lightGray") ) {
    		// "slide" the color down
    		swapColor( i, offset);
	    	// now set i to be the square below so that the color successively moves downward
	    	i += SquaresPerSide+2;
    	}
    }//end slideDownSquare()
    
    
    // swap color at position i with color at position i+offset
    void swapColor( int i, int offset)
    {
    	int indexOfOtherSquare = i + offset;   
    	String colorOfOtherSquare = theSquares[ indexOfOtherSquare].getColor();
    	theSquares[ indexOfOtherSquare].setColor( theSquares[ i].getColor());  // set color of other square
    	theSquares[ i].setColor( colorOfOtherSquare);                          // set color of square i
    }
    
    
    //----------------------------------------------------------------------------------------------
    // Handle each key press, in case you want to use this instead of mouse clicks
    void handleKeyPress( char c)
    {  
    	System.out.println("You pressed " + c);
    }//end handleKeyPress()

    
    //----------------------------------------------------------------------------------------------
    // Handle the Redo button click by randomizing the board so that
    // each row and each column satisfies the desired parity
    void randomizeBoard()
    {	
    	createAndInitializeSquareColors();
    	    	
    	// reset the prompt message, starting time and move number
    	gameMessagesLabel.setLabel("Restarting...");
    	startTime = new Date();
    	moveNumber = 0;

    }//end Redo()
  
    
    //----------------------------------------------------------------------------------------------
    // return the square corresponding to the index
    private Square getSquareNumber( int index)
    {
    	Square returnValue = null;		// will be the reference of the Square to be returned
    	
    	switch ( index) {
    		case 0: returnValue = theSquares[ 0]; break;
    		case 1: returnValue = theSquares[ 1]; break;    	
    		case 2: returnValue = theSquares[ 2]; break;
    		case 3: returnValue = theSquares[ 3]; break;
    		default: // Sanity check, should never execute this code
    			System.out.println("*** Error: invalid square number " + index + ". Exiting...");
    			System.exit( -1);
    			break;
    	}//end switch( index)
    	
    	return returnValue;
    }//end getSquareNumber()
    
    
}// end class Board()
