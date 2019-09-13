/* TicTacMore.java
 * 
 * Program #3 for UIC CS 107, Fall 2011
 * Author: Dale Reed 
 * CS 107, program #3.  Written in Java using Eclipse. 
 * Lab: Wed 7am with Edmund Hilary 
 *  
 * The object of the game is to get either 4 in a row or 
 * 3 in a row on any edge.  Player X starts and play alternates 
 * until someone wins or the board is full.  You may only move 
 * in a square adjacent to a piece already played.  
 */

import java.util.Scanner;

public class TicTacMore {
	
	// instance variables shared throughout the program
	Scanner keyboard = new Scanner( System.in);
	boolean notDone = true;		// flag variable used to signal when main loop is done
	
	// Board variables.  The board itself is the inner rectangle.  The extra border
	// of squares around the edges is used to simplify the writing of code used 
	// in adjacency checking.
	//
	// Board positions are:
	//      1  2  3  4  5
	// 
	//  A   8  9 10 11 12 
	//  B  15 16 17 18 19 
	//  C  22 23 24 25 26 
	//  D  29 30 31 32 33 
	//  E  36 37 38 39 40
	//
	char   p0,    p1,  p2,  p3,  p4,  p5,    p6,
	
	       p7,    p8,  p9, p10, p11, p12,   p13, 
	      p14,   p15, p16, p17, p18, p19,   p20, 
	      p21,   p22, p23, p24, p25, p26,   p27, 
	      p28,   p29, p30, p31, p32, p33,   p34, 
	      p35,   p36, p37, p38, p39, p40,   p41, 
	      
	      p42,   p43, p44, p45, p46, p47,   p48;
	
	
	/*
	 *   0  1  2  3  4  5  6
	 *   7  8  9 10 11 12 13
	 *  14 15 16 17 18 19 20
	 *  21 22 23 24 25 26 27
	 *  28 29 30 31 32 33 34
	 *  35 36 37 38 39 40 41
	 */
	
	
    //-------------------------------------------------------------------------
	// main loop chains off to another method to avoid static errors
	public static void main(String[] args)
	{
		TicTacMore instance = new TicTacMore();
		instance.runIt();
	}//end main 
	
	
    //-------------------------------------------------------------------------	
	// Main part of the code
	void runIt()
	{
		int moveNumber = 1;   // track move number.  Even/Odd tells if 'X' or 'O' to move
		char playerToMove = ' ';	// on odd moves will be 'X', on even moves will be 'O'
		boolean wantsToExit = false;	// stores return value from user input method.  Used to exit program
		
		// display ID and instructions
		displayIDandInstructions();
		
		// Initialize board values
		initializeValues();
		
		// main loop
		do {
			// display the board
			displayBoard();
			
			// set player to move ('X' or 'O') based on even/odd move number
			playerToMove = setPlayerToMove( moveNumber);
			
			// prompt for move and update board.  Method returns true normally, false if user input was 'x' to exit
			wantsToExit = promptForMoveAndUpdateBoard( playerToMove, moveNumber);
			// see if user wanted to exit
			if( wantsToExit) {
				System.out.println("Exiting program...");
				break;
			}
			
			// check for a win
			if( thereWasAWin() ) {
				// there was a win, so break out of main loop to exit the game
				System.out.println("You won!");
				notDone = false;
				break;
			}
			
			// increment the move number
			moveNumber++;
		} while( notDone);
		
		// display the final board if the main loop resulted in a win.
		// If user selected 'x' to exit, then the "wantsToExit" variable will have been set to true
		if( wantsToExit == false) {
			System.out.println("Final board: ");
			displayBoard();
		}
		
		System.out.println("Thanks for playing.  Exiting...");
	}//end runIt()
	
	
    //-------------------------------------------------------------------------	
	void displayIDandInstructions()
	{
		System.out.println(
				   "Welcome to TicTacMore \n"
				 + " \n"
			     + "Author: Dale Reed \n"
				 + "CS 107, program #3.  Written in Java using Eclipse. \n"
			     + "Lab: Wed 7am with Edmund Hilary \n"
		         + " \n"
				 + "The object of the game is to get either 4 in a row or \n"
				 + "3 in a row on any edge.  Player X starts and play alternates \n"
				 + "until someone wins or the board is full.  You may only move \n"
				 + "in a square adjacent to a piece already played.  \n" 
				 + " \n");	
	}
	
	
    //-------------------------------------------------------------------------	
	// Prompt for move, validate adjacency, and make move.
	boolean promptForMoveAndUpdateBoard( char playerToMove, int moveNumber)
	{
		// declare the row and column, which will be extracted from the user input
		int row = 0;
		int column = 0;	// entered as character, but converted to number
		String userInput = "";	// stores user input
		boolean userWantsToExitProgram = false;		// default under normal circumstances.  Set to true if 
												    // user chooses 'x' to exit
		
		// Infinite loop used to prompt for and make move.  Invalid input cycles back up to retry.
		// Valid input breaks out of this loop
		while( true) {
			// get user input and convert to upper case
			System.out.print( moveNumber + ". Enter row and column for move (e.g. b3) -> ");
			userInput = keyboard.next().toUpperCase().trim();   // for good measure trim leading/trailing spaces
			
			// see if user selected 'x' to exit program
			if( userInput.contains("X")) {
				userWantsToExitProgram = true;	// return value signals that user wants to exit
				break;
			}
			else {
				// User input was not 'x' to exit program, but rather was move position information.
				// Extract user input values for row and column and convert to numerical values
				// Board positions are:
				//      1  2  3  4  5
				// 
				//  A   8  9 10 11 12 
				//  B  15 16 17 18 19 
				//  C  22 23 24 25 26 
				//  D  29 30 31 32 33 
				//  E  36 37 38 39 40
				
				row = userInput.charAt(0) - 'A';  // convert character 'A'..'E' to value 0..4
				// ensure user input for row is within range (not required in your program)
				if( row<0 || row > 4) {
					System.out.println("Invalid row value.  Please retry.");
					continue;
				}
				column = userInput.charAt(1) - '1';	  // convert character '1'..'5' to value 0..4
				// ensure user input for column is within range (not required in your program)
				if( column<0 || column > 4) {
					System.out.println("Invalid column value.  Please retry.");
					continue;
				}
			
				// calculate the piece index based on the row and column.
				// Compensate for extra row at top, and extra column at the left of each row
				int pieceIndex = (row+1)*7 + 1 + column;
				
				// Check to ensure that move being made is adjacent to some existing piece.
				// Don't need to do the check when moveNumber is 1 (first move)
				if( moveNumber == 1 || thereIsAnAdjacentPiece( pieceIndex)) { 
					// store the playerToMove character in the appropriate piece
					setPieceAt( playerToMove, pieceIndex);
					
					// break out of the loop used to prompt for and make a move
					break;
					
				}//end if( pieceIsAdjacent(...)
				else {
					// No adjacent piece, so give message and allow retry
					System.out.println("Sorry, that move is not adjacent to an existing piece.  Please retry.");
					continue;	// branch back up to try again
				}
			}//end else
		}//end while( moveIsInvalid)
		
		// return true if user indicated exiting program, false otherwise
		return userWantsToExitProgram;
	}//end promptForMoveAndUpdateBoard()
	
	
	
    //-------------------------------------------------------------------------	
	// Check to see if the piece at the desired index location has an adjacent square that is occupied.
	// Adjacency is the left, right, above, below, and 4 diagonal locations.  These locations are 
	// computed as offsets from the existing location index as follows:
	//    index-8  index-7  index-6                       7  8  9
	//    index-1  index    index+1     for example:     14 15 16
	//    index+6  index+7  index+8                      21 22 23
	// Creating an extra border around the actual board greatly simplifies this code.
	// Board positions are:
	//      1  2  3  4  5
	// 
	//  A   8  9 10 11 12 
	//  B  15 16 17 18 19 
	//  C  22 23 24 25 26 
	//  D  29 30 31 32 33 
	//  E  36 37 38 39 40 
	boolean thereIsAnAdjacentPiece( int index)
	{
		boolean returnValue = false;   // the return value
		
		// Check all adjacent pieces.  If any is not '.', then return true
		// since there IS an adjacent piece.
		if( getPiece(index-8) != '.' || getPiece(index-7) != '.' || getPiece(index-6) != '.' ||
			getPiece(index-1) != '.' ||                             getPiece(index+1) != '.' ||
			getPiece(index+6) != '.' || getPiece(index+7) != '.' || getPiece(index+8) != '.' 
		  ) {
			returnValue = true;
		}
		
		return returnValue;
	}//end thereIsAnAdjacentPiece(...)
	
	
    //-------------------------------------------------------------------------	
	// See if there was a win.  If so, return true, else return false.
	// If there are 3 pieces in a row all on an edge, that is a win.  Also if there are 4 pieces in a row
	// anywhere else (row, column, diagonal), that is a win.
	// Board positions are:
	//       1  2  3  4  5
	//  
	//   A   8  9 10 11 12 
	//   B  15 16 17 18 19 
	//   C  22 23 24 25 26 
	//   D  29 30 31 32 33 
	//   E  36 37 38 39 40
	//
	// The above index values are for reference in the code below
	boolean thereWasAWin()
	{
		boolean returnValue = false;	
		
		// First check edges for patterns of 3 in a row.  The first number given is the
		// index of the starting position.  The second number given is the offset used
		// to add to the starting position to get the indices of the other 2 positions
		if( allThreeSame( 8,1) || allThreeSame( 9,1) || allThreeSame( 10,1) ||    // top row
			allThreeSame( 8,7) || allThreeSame( 15,7) || allThreeSame( 22,7) ||   // left column
			allThreeSame( 36,1) || allThreeSame( 37,1) || allThreeSame( 38,1) ||  // bottom row
			allThreeSame( 12,7) || allThreeSame( 19,7) || allThreeSame( 26,7)     // right column
		   ) {
			// There was a pattern of 3 in a row
			returnValue = true;
		}

		// Check for patterns of 4 in a row.  The first number given is the
		// index of the starting position.  The second number given is the offset used
		// to add to the starting position to get the indices of the other 3 positions
		if( allFourSame( 15,1) || allFourSame(  16,1) ||   // 2nd row
			allFourSame( 22,1) || allFourSame(  23,1) ||   // 3rd row
			allFourSame( 29,1) || allFourSame(  30,1) ||   // 4th row
			allFourSame(  9,7) || allFourSame( 16,7) ||   // 2nd column
			allFourSame( 10,7) || allFourSame(  17,7) ||   // 3rd column
			allFourSame( 11,7) || allFourSame(  18,7) ||   // 4th column
			// upper left to lower right diagonals
			allFourSame( 15,8) || allFourSame( 8,8) || allFourSame( 16,8) || allFourSame(9,8) || 
			// upper right to lower left diagonals
			allFourSame( 11,6) || allFourSame( 12,6) || allFourSame( 18,6) || allFourSame(19,6)
		  ) {
			// There was a pattern of 4 in a row
			returnValue = true;
		}
		
		return returnValue;
	}//end thereWasAWin()
	
	
    //-------------------------------------------------------------------------	
	// See if 3 in a row ware all the same.  The index of the starting point is given, as well
	// as the offset to calculate the other two index positions.
	boolean allThreeSame( int i, int offset)
	{
		// given the starting index, calculate the index values of the other positions
		int j = i + offset;
		int k = i + (offset * 2);
		
		// compare all the pieces, which results in true or false
		return ( (getPiece(i) != '.') && 
				 (getPiece(i) == getPiece(j)) &&
				 (getPiece(j)) == getPiece(k)
			   );
	}//end allThreeSame
	
	
    //-------------------------------------------------------------------------	
	// See if 4 in a row are all the same.  The index of the starting point is given, as well
	// as the offset to calculate the other three index positions.
	boolean allFourSame( int i, int offset)
	{
		// given the starting index, calculate the index values of the other positions
		int j = i + offset;
		int k = i + (offset * 2);
		int m = i + (offset * 3);

		// compare all the pieces, which results in true or false
		return ( (getPiece(i) != '.') && 
				 (getPiece(i) == getPiece(j)) &&
				 (getPiece(j) == getPiece(k)) &&
				 (getPiece(k)) == getPiece(m)
			   );
	}//end allFourSame
	
	
	
    //-------------------------------------------------------------------------	
	// Set the value into the piece at the index
	void setPieceAt( char value, int index)
	{
		switch( index) { 
		   case 0: p0 = value; break;
		   case 1: p1 = value; break;
		   case 2: p2 = value; break;
		   case 3: p3 = value; break;
		   case 4: p4 = value; break;
		   case 5: p5 = value; break;
		   case 6: p6 = value; break;
		   case 7: p7 = value; break;
		   case 8: p8 = value; break;
		   case 9: p9 = value; break;
		   case 10: p10 = value; break;
		   case 11: p11 = value; break;
		   case 12: p12 = value; break;
		   case 13: p13 = value; break;
		   case 14: p14 = value; break;
		   case 15: p15 = value; break;
		   case 16: p16 = value; break;
		   case 17: p17 = value; break;
		   case 18: p18 = value; break;
		   case 19: p19 = value; break;
		   case 20: p20 = value; break;
		   case 21: p21 = value; break;
		   case 22: p22 = value; break;
		   case 23: p23 = value; break;
		   case 24: p24 = value; break;
		   case 25: p25 = value; break;
		   case 26: p26 = value; break;
		   case 27: p27 = value; break;
		   case 28: p28 = value; break;
		   case 29: p29 = value; break;
		   case 30: p30 = value; break;
		   case 31: p31 = value; break;
		   case 32: p32 = value; break;
		   case 33: p33 = value; break;
		   case 34: p34 = value; break;
		   case 35: p35 = value; break;
		   case 36: p36 = value; break;
		   case 37: p37 = value; break;
		   case 38: p38 = value; break;
		   case 39: p39 = value; break;
		   case 40: p40 = value; break;
		   case 41: p41 = value; break;
		   case 42: p42 = value; break;
		   case 43: p43 = value; break;
		   case 44: p44 = value; break;
		   case 45: p45 = value; break;
		   case 46: p46 = value; break;
		   case 47: p47 = value; break;
		   case 48: p48 = value; break;
		   // add the default as a sanity check
		   default: System.out.println("*** Invalid value of " + value + " in method setPiece().  Exiting...");
		   	        System.exit( -1);
		   	        break;
		} 		
	}//end setPiece()
	
	
    //-------------------------------------------------------------------------	
	// Get the char stored in some piece
	char getPiece( int index)
	{
		char result = ' ';
		switch( index) { 
		   case 0: result = p0; break;
		   case 1: result = p1; break;
		   case 2: result = p2; break;
		   case 3: result = p3; break;
		   case 4: result = p4; break;
		   case 5: result = p5; break;
		   case 6: result = p6; break;
		   case 7: result = p7; break;
		   case 8: result = p8; break;
		   case 9: result = p9; break;
		   case 10: result = p10; break;
		   case 11: result = p11; break;
		   case 12: result = p12; break;
		   case 13: result = p13; break;
		   case 14: result = p14; break;
		   case 15: result = p15; break;
		   case 16: result = p16; break;
		   case 17: result = p17; break;
		   case 18: result = p18; break;
		   case 19: result = p19; break;
		   case 20: result = p20; break;
		   case 21: result = p21; break;
		   case 22: result = p22; break;
		   case 23: result = p23; break;
		   case 24: result = p24; break;
		   case 25: result = p25; break;
		   case 26: result = p26; break;
		   case 27: result = p27; break;
		   case 28: result = p28; break;
		   case 29: result = p29; break;
		   case 30: result = p30; break;
		   case 31: result = p31; break;
		   case 32: result = p32; break;
		   case 33: result = p33; break;
		   case 34: result = p34; break;
		   case 35: result = p35; break;
		   case 36: result = p36; break;
		   case 37: result = p37; break;
		   case 38: result = p38; break;
		   case 39: result = p39; break;
		   case 40: result = p40; break;
		   case 41: result = p41; break;
		   case 42: result = p42; break;
		   case 43: result = p43; break;
		   case 44: result = p44; break;
		   case 45: result = p45; break;
		   case 46: result = p46; break;
		   case 47: result = p47; break;
		   case 48: result = p48; break;
		   // add the default as a sanity check
		   default: System.out.println("*** Invalid value of " + index + " in method getPiece().  Exiting...");
		   	        System.exit( -1);
		   	        break;
		} 
		
		return result;
	}//end getPiece()
	
	
    //-------------------------------------------------------------------------	
	// Set playerToMove, alternating between 'X' and 'O'
	char setPlayerToMove( int moveNumber)
	{
		if( moveNumber % 2 == 1) {
			// odd numbered move, so it should be 'X'
			return 'X';
		}
		else {
			// even numbered move, so it should be 'O'
			return 'O';
		}		
	}//end setPlayerToMove
	
	
    //-------------------------------------------------------------------------	
	// Initialize board values.  Note that the "inner" set of variables forming the actual
	// board are initialized to '.', while the "outer" set of rows used only to simplify
	// coding are initialized to blanks ' '.
	void initializeValues()
	{
		p0= p1= p2= p3= p4= p5=   p6='.';
		p7=                       p13='.';
		   p8=p9=p10=p11=p12='.';
		p14=                      p20='.';
			p15=p16=p17=p18=p19='.';
		p21=                      p27='.';
			p22=p23=p24=p25=p26='.';
		p28=                      p34='.';
			p29=p30=p31=p32=p33='.';
		p35=                      p41='.';
			p36=p37=p38=p39=p40='.';
		p42=                      p48='.';
			p43=p44=p45=p46=p47='.';
	}//end initializeValues()
	
	
    //-------------------------------------------------------------------------	
	// Display the board represented in the playing pieces
	void displayBoard()
	{
	    	System.out.println("");
	    	System.out.printf( "  1 2 3 4 5      \n"); 
	    	System.out.printf( "A %c %c %c %c %c A \n", p8, p9, p10, p11, p12 );
	    	System.out.printf( "B %c %c %c %c %c B \n", p15, p16, p17, p18, p19 );
	    	System.out.printf( "C %c %c %c %c %c C \n",p22,p23,p24,p25,p26 );
	    	System.out.printf( "D %c %c %c %c %c D \n",p29,p30,p31,p32,p33 );
	    	System.out.printf( "E %c %c %c %c %c E \n",p36,p37,p38,p39,p40  );
	    	System.out.printf( "  1 2 3 4 5      \n"); 
	}//end displayBoard()
	
}//end class
