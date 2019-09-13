import java.util.Scanner; // for user input

public class popOut {
	
	

	// declare Scanner
	Scanner keyboard = new Scanner(System.in);

	// make sure loop finishes
	boolean gameNotOver = true;
	
	/*
	 *   0  1  2  3  4  5  6
	 *   7  8  9 10 11 12 13
	 *  14 15 16 17 18 19 20
	 *  21 22 23 24 25 26 27
	 *  28 29 30 31 32 33 34
	 *  35 36 37 38 39 40 41
	 */
	
	// board variables //
	char p0,  p1,  p2,  p3,  p4,  p5,  p6,
		 p7,  p8,  p9,  p10, p11, p12, p13,
		 p14, p15, p16, p17, p18, p19, p20,
		 p21, p22, p23, p24, p25, p26, p27,
		 p28, p29, p30, p31, p32, p33, p34,
		 p35, p36, p37, p38, p39, p40, p41;

	
	// ----------------------------------------------------------------------------------- //
	// MAIN //
	public static void main(String[] args) {
		popOut instance = new popOut();
		instance.doIt();

	} // end mains

	
	// ---------------------------------------------------------------------------------- //
	// METHODS //

	
	// doIt
	// Where the magic happens
	void doIt()
	{
		int turn = 1;				// indicates player's turn
		char playerTurn = ' ';		// blank until X or O piece is placed
		boolean exit = false;		// stores return value from userInput. exits program.
		
		// Print game instructions and identity
		gameInfo();
		
		// Initialize board values
		initializeBoard();
		
		// MAIN LOOP // 
		do
		{
			// Print board
			displayBoard();
			System.out.println("\n 1 2 3 4 5 6 7 <- place piece");
			System.out.println(" A B C D E F G <- remove piece");
			
			// Call player's turn
			playerTurn = setPlayerTurn(turn);
			
			// Board must refresh each turn unless user prompts exit
			exit = boardUpdate (playerTurn, turn);
			
			if (exit)
			{
				System.out.println("\nExiting program...");
				break;
			}// end if(exit)

			// Check for win
			if (gameWin())
			{
				System.out.println("Four in a row, " +playerTurn +" wins!");
				gameNotOver = false;
				break;
			}// end if(gamewin())
			
			// Increment number of turns
			turn++;
			
		} while (gameNotOver);
		// end do
		
		// If user prompts exit
		// or if a win occurs
		if (exit == false)
		{
			System.out.println("Last board: ");
			displayBoard();
		}

		System.out.println("\nThanks for playing!");
		
	}// end doIt()
		
	
	// ----------------------------------------------------------------------------------- //
	// gameInfo
	// Includes identifying info and game rules
	void gameInfo()
	{

		  // Display identifying information
		  System.out.println("Author: Bresia Prudente and Saleha Amreen ");
		  System.out.println("TA: Sean Deitz, Wed 11-11:50 AM ");
		  System.out.println("Program: #3, Pop Out \n");
		  
		  // Display game information System.out
		  System.out.println("Welcome to the game of Pop Out." 
		  +"\nChoose a column in which to move and" 
		  +"\ntry to get four pieces in a row, either horizontally, diagonally, or"
		  +"\nvertically. At any point you may enter 'x' to exit the program. Your"
		  +"\nmoves will be marked by an 'X', and the computer's moves by an 'O'."
		  +"\nIf a player has a piece in the bottom row for a column, entering a"
		  + "\nletter 'A'..'G' removes that bottom piece, sliding the remaining"
		  + "\nin that column by one for a player.");
		 
		
	}// end gameInfo

	
	// ----------------------------------------------------------------------------------- //
	// boardUpdate
	// Updates board information and prompts users to move pieces
	boolean boardUpdate (char playerTurn, int turn)
	{
		// !!! RECALL DECRYPT CHAR DEPOSITION !!! //
		// Declare the rows and columns as int since chars will be converted to int
		int column = 0;
		int column1 = 0;
		boolean exit = false;		// determines if user wants to exit program
		
		// Create a loop for userInput
		while (true)
		{
			// Make userInput uppercase
			System.out.print("\n" +turn +". Enter column for " +playerTurn +" to play -> ");
			String userInput = keyboard.next().toUpperCase();
			
			// If user prompts 'x'
			if (userInput.contains("X"))
			{
				exit = true;
				break;
			}
			// If userInput prompts for position change...
			// Convert userInput values from column and row into int
			else
			{
				// Change numerical chars into int
				column = userInput.charAt(0) - '1';		// convert chars 1..7 into value 0..6 
				
				// Change alphabetical chars into int
				column1 = userInput.charAt(0) - 'A'; 	// convert chars A..Z into value 0..6
				
				// Calculate where the piece needs to go
				int pieceTurn = (column * 7);
				
				// Store each character per turn
				for (turn = 1; turn >= pieceTurn; turn++)
				{					
					setValue(playerTurn, pieceTurn);
				}// end 
				break;
				
			}// end else
								
	}// end while(true)
		
		return exit;
}// end boardUpdate
	
	
	// ----------------------------------------------------------------------------------- //
	// gameWin
	// Checks if there are pieces adjacent to each other
	boolean gameWin()
	{
		boolean value = false;
		
		// !!! MAKE FOR LOOPS FOR THESE? !!! //
		// Checks for adjacent pieces: row, column, and vertical
		// connect4(starting position, adds to starting position to find other 3 positions)
		
		// ROWS // 
		if ( connect4(0, 1) || connect4(1, 1) ||  connect4(2, 1) ||  connect4(3, 1) || 			// row 1
			 connect4(7, 1) || connect4(8, 1) ||  connect4(9, 1) ||  connect4(10, 1) ||			// row 2
			 connect4(14, 1) || connect4(15, 1) ||  connect4(16, 1) ||  connect4(17, 1) ||		// row 3
			 connect4(21, 1) || connect4(22, 1) ||  connect4(23, 1) ||  connect4(24, 1) ||		// row 4
			 connect4(28, 1) || connect4(29, 1) ||  connect4(30, 1) ||  connect4(31, 1) ||		// row 5
			 connect4(35, 1) || connect4(36, 1) ||  connect4(37, 1) ||  connect4(38, 1) ||		// row 6
		
		// COLUMNS // 
			  connect4(0, 7) || connect4(7, 7) ||  connect4(14, 7) ||		// column 1
			  connect4(1, 7) || connect4(8, 7) ||  connect4(15, 7) ||		// column 2
			  connect4(2, 7) || connect4(9, 7) ||  connect4(16, 7) ||		// column 3
			  connect4(3, 7) || connect4(10, 7) ||  connect4(17, 7) ||		// column 4
			  connect4(4, 7) || connect4(11, 7) ||  connect4(18, 7) ||		// column 5
			  connect4(5, 7) || connect4(12, 7) ||  connect4(19, 7) ||		// column 6
			  connect4(6, 7) || connect4(13, 7) ||  connect4(20, 7) ||		// column 7

		
		// LEFT-RIGHT VERTICAL
			 connect4(14, 8) || 				
			 connect4(7, 8) ||  connect4(7, 8) || connect4(15, 8) ||
			 connect4(0, 8) ||  connect4(8, 8) || connect4(16, 8) ||
			 connect4(1, 8) ||  connect4(9, 8) || connect4(17, 8) ||
			 connect4(2, 8) ||  connect4(10, 8) ||
			 connect4(3, 8) ||
		
		// RIGHT-LEFT VERTICAL
			 connect4(3, 6) || 				
			 connect4(4, 6) ||  connect4(10, 6) ||
			 connect4(5, 6) ||  connect4(11, 6) || connect4(17, 6) ||
			 connect4(6, 6) ||  connect4(12, 6) || connect4(18, 6) ||
			 connect4(13, 6) ||  connect4(19, 6) ||
			 connect4(20, 6)
			)
		{
			value = true;
		}// end RIGHT-LEFT VERTICAL
	
		return value;
	}// end gameWin
	
	
	// ----------------------------------------------------------------------------------- //
	// connect4
	// Checks if there are 4 in a row by determining other 3 positions from the current position
	boolean connect4 (int index, int position)
	{
		// Check 3 positions
		int position1 = index + position;
		int position2 = index + (position * 2);
		int position3 = index + (position * 3);
		
		// Return all positions at setValue (they must be equal to each other)
		return ( (getValue(index) != ' ') &&
				 (getValue(index) == getValue(position1)) &&
				 (getValue(position1) == getValue(position2)) &&
				 (getValue(position2) == getValue(position3))
			   );
		
	}
	
	
	// ----------------------------------------------------------------------------------- //
	// setValue()
	// Stores value of character into location
	void setValue( char piece, int pLocation) 
	{  
		// column 1 (35, 28, 21, 14, 7, 0)
		if( getValue(35) == ' ') 
		{
			   setValue( piece, 1);   
		}
		else if( getValue(28) == ' ') 
		{
			   setValue( piece, 1);   
		}
		else if( getValue(21) == ' ') 
		{
			   setValue( piece, 1);   
		}
		else if( getValue(14) == ' ') 
		{
			   setValue( piece, 1);   
		}
		else if( getValue(7) == ' ') 
		{
			   setValue( piece, 1);   
		}
		else if( getValue(0) == ' ') 
		{
			   setValue( piece, 1);   
		}
		else
		{
			System.out.println("Error: Column is already full.");
		}
		
		// column 2 (36, 29, 22, 15, 8, 1)
		if( getValue(36) == ' ') 
		{
			   setValue( piece, 2);   
		}
		else if( getValue(29) == ' ') 
		{
			   setValue( piece, 2);   
		}
		else if( getValue(22) == ' ') 
		{
			   setValue( piece, 2);   
		}
		else if( getValue(15) == ' ') 
		{
			   setValue( piece, 2);   
		}
		else if( getValue(8) == ' ') 
		{
			   setValue( piece, 2);   
		}
		else if( getValue(1) == ' ') 
		{
			   setValue( piece, 2);   
		}
		else
		{
			System.out.println("Error: Column is already full.");
		}
		
		// column 3 (37, 30, 23, 16, 9, 2)
		if( getValue(37) == ' ') 
		{
			   setValue( piece, 3);   
		}
		else if( getValue(30) == ' ') 
		{
			   setValue( piece, 3);   
		}
		else if( getValue(23) == ' ') 
		{
			   setValue( piece, 3);   
		}
		else if( getValue(16) == ' ') 
		{
			   setValue( piece, 3);   
		}
		else if( getValue(9) == ' ') 
		{
			   setValue( piece, 3);   
		}
		else if( getValue(2) == ' ') 
		{
			   setValue( piece, 3);   
		}
		else
		{
			System.out.println("Error: Column is already full.");
		}
		
		// column 4 (38, 31, 24, 17, 10, 3)
		if( getValue(38) == ' ') 
		{
			   setValue( piece, 4);   
		}
		else if( getValue(31) == ' ') 
		{
			   setValue( piece, 4);   
		}
		else if( getValue(24) == ' ') 
		{
			   setValue( piece, 4);   
		}
		else if( getValue(17) == ' ') 
		{
			   setValue( piece, 4);   
		}
		else if( getValue(10) == ' ') 
		{
			   setValue( piece, 4);   
		}
		else if( getValue(3) == ' ') 
		{
			   setValue( piece, 4);   
		}
		else
		{
			System.out.println("Error: Column is already full.");
		}
		
		// column 5 (39, 32, 25, 18, 11, 4)
		if( getValue(39) == ' ') 
		{
			   setValue( piece, 5);   
		}
		else if( getValue(32) == ' ') 
		{
			   setValue( piece, 5);   
		}
		else if( getValue(25) == ' ') 
		{
			   setValue( piece, 5);   
		}
		else if( getValue(18) == ' ') 
		{
			   setValue( piece, 5);   
		}
		else if( getValue(11) == ' ') 
		{
			   setValue( piece, 5);   
		}
		else if( getValue(4) == ' ') 
		{
			   setValue( piece, 5);   
		}
		else
		{
			System.out.println("Error: Column is already full.");
		}
		
		// column 6 (40, 33, 26, 19, 12, 5)
		if( getValue(40) == ' ') 
		{
			   setValue( piece, 6);   
		}
		else if( getValue(33) == ' ') 
		{
			   setValue( piece, 6);   
		}
		else if( getValue(26) == ' ') 
		{
			   setValue( piece, 6);   
		}
		else if( getValue(19) == ' ') 
		{
			   setValue( piece, 6);   
		}
		else if( getValue(12) == ' ') 
		{
			   setValue( piece, 6);   
		}
		else if( getValue(5) == ' ') 
		{
			   setValue( piece, 6);   
		}
		else
		{
			System.out.println("Error: Column is already full.");
		}
		
		// column 7 (41, 34, 27, 20, 13, 6)
		if( getValue(41) == ' ') 
		{
			   setValue( piece, 7);   
		}
		else if( getValue(34) == ' ') 
		{
			   setValue( piece, 7);   
		}
		else if( getValue(27) == ' ') 
		{
			   setValue( piece, 7);   
		}
		else if( getValue(20) == ' ') 
		{
			   setValue( piece, 7);   
		}
		else if( getValue(13) == ' ') 
		{
			   setValue( piece, 7);   
		}
		else if( getValue(6) == ' ') 
		{
			   setValue( piece, 7);   
		}
		else
		{
			System.out.println("Error: Column is already full.");
		}
		

	} // end setValue()
	
	
	// ----------------------------------------------------------------------------------- //
	// getValue()
	// Grabs info from location
	char getValue(int pLocation) 
	{
		// All characters have space as default
		char valueGet = ' ';
		
		switch (pLocation)
		{
			case 1:
				p35 = valueGet;
				p28 = valueGet;
				p21 = valueGet;
				p14 = valueGet;
				p7 = valueGet;
				p0 = valueGet;
				break;
			case 2:
				p36 = valueGet;
				p29 = valueGet;
				p22 = valueGet;
				p15 = valueGet;
				p8 = valueGet;
				p1 = valueGet;
				break;
			case 3:
				p37 = valueGet;
				p30 = valueGet;
				p23 = valueGet;
				p16 = valueGet;
				p9 = valueGet;
				p2 = valueGet;
				break;
			case 4:
				p38 = valueGet;
				p31 = valueGet;
				p24 = valueGet;
				p17 = valueGet;
				p10 = valueGet;
				p3 = valueGet;
				break;
			case 5:
				p39 = valueGet;
				p32 = valueGet;
				p25 = valueGet;
				p18 = valueGet;
				p11 = valueGet;
				p4 = valueGet;
				break;
			case 6:
				p40 = valueGet;
				p33 = valueGet;
				p26 = valueGet;
				p19 = valueGet;
				p12 = valueGet;
				p4 = valueGet;
				break;
			case 7:
				p41 = valueGet;
				p34 = valueGet;
				p27 = valueGet;
				p20 = valueGet;
				p13 = valueGet;
				p5 = valueGet;
				break;

			default: System.out.println(+pLocation +" is an invalid value. \nExiting program...");
					 System.exit(-1);
					 break;
		}// end switch(i)
		
		return valueGet;
	} // end getValue()

	
	// ----------------------------------------------------------------------------------- //
	// setPlayerTurn
	// Determines player's turn
	char setPlayerTurn(int turn)
	{
		// Odds  -> player 1 = X
		// Evens -> player 2 = O
		if (turn % 2 == 1)
		{
			char piece = 'X';
			return piece;
		}
		else
		{
			char piece = 'O';
			return piece;
		}
	}// end setPlayerTurn
	
	
	// ----------------------------------------------------------------------------------- //
	// initializeBoard
	void initializeBoard()
	{
		p0= p1= p2= p3= p4= p5= p6=' ';
		p7= p8= p9= p10= p11= p12= p13=' ';
		p14= p15= p16= p17= p18= p19= p20=' ';
		p21= p22= p23= p24= p25= p26= p27=' ';
		p28= p29= p30= p31= p32= p33= p34=' ';
		p35= p36= p37= p38= p39= p40= p41=' ';
		
	}
	
	
	// ----------------------------------------------------------------------------------- //
	// displayBoard
	void displayBoard()
	{

		System.out.print("\n---------------\n");
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p0, p1, p2, p3, p4, p5, p6);
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p7, p8, p9, p10, p11, p12, p13);
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p14, p15, p16, p17, p18, p19, p20);
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p21, p22, p23, p24, p25, p26, p27);
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p28, p29, p30, p31, p32, p33, p34);
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p35, p36, p37, p38, p39, p40, p41);
		System.out.printf("---------------");

		
	}// end displayBoard

} // end popOut()