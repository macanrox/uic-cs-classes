import java.util.Scanner; // for user input

public class popOut {

	// declare Scanner
	Scanner keyboard = new Scanner(System.in);

	// make sure loop finishes
	boolean gameNotOver = true;

	/*
	 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
	 * 28 29 30 31 32 33 34 35 36 37 38 39 40 41
	 */

	// board variables //
	char p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15,
			p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28,
			p29, p30, p31, p32, p33, p34, p35, p36, p37, p38, p39, p40, p41;

	// -----------------------------------------------------------------------------------
	// //
	// MAIN //
	public static void main(String[] args) {
		popOut instance = new popOut();
		instance.doIt();

	} // end mains

	// ----------------------------------------------------------------------------------
	// //
	// METHODS //

	// doIt
	// Where the magic happens
	void doIt() {
		int turn = 1; // indicates player's turn
		char playerTurn = ' '; // blank until X or O piece is placed
		boolean exit = false; // stores return value from userInput. exits
								// program.

		// Print game instructions and identity
		gameInfo();

		// Initialize board values
		initializeBoard();

		// MAIN LOOP //
		do {
			// Print board
			displayBoard();

			// Call player's turn
			playerTurn = setPlayerToMove(turn);

			// Board must refresh each turn unless user prompts exit
			exit = boardUpdate(playerTurn, turn);

			if (exit) {
				System.out.println("\nExiting program...");
				break;
			}// end if(exit)

			// Check for win
			if (gameWin()) {
				System.out.println("Four in a row, " + playerTurn + " wins!");
				gameNotOver = false;
				break;
			}// end if(gamewin())

			// Increment number of turns
			turn++;

		} while (gameNotOver);
		// end do

		// If user prompts exit
		// or if a win occurs
		if (exit == false) {
			System.out.println("Last board: ");
			displayBoard();
		}

		System.out.println("\nThanks for playing!");

	}// end doIt()

	// -----------------------------------------------------------------------------------
	// //
	// gameInfo
	// Includes identifying info and game rules
	void gameInfo() {

		// Display identifying information
		System.out.println("Author: Bresia Prudente and Saleha Amreen ");
		System.out.println("TA: Sean Deitz, Wed 11-11:50 AM ");
		System.out.println("Program: #3, Pop Out \n");

		// Display game information System.out
		System.out
				.println("Welcome to the game of Pop Out."
						+ "\nChoose a column in which to move and"
						+ "\ntry to get four pieces in a row, either horizontally, diagonally, or"
						+ "\nvertically. At any point you may enter 'x' to exit the program. Your"
						+ "\nmoves will be marked by an 'X', and the computer's moves by an 'O'."
						+ "\nIf a player has a piece in the bottom row for a column, entering a"
						+ "\nletter 'A'..'G' removes that bottom piece, sliding the remaining"
						+ "\nin that column by one for a player.");

	}// end gameInfo

	// -----------------------------------------------------------------------------------
	// //
	// boardUpdate
	// Updates board information and prompts users to move pieces
	boolean boardUpdate(char playerToMove, int turn) {
		// !!! RECALL DECRYPT CHAR DEPOSITION !!! //
		// Declare the rows and columns as int since chars will be converted to
		// int
		int column = 0;
		int column1 = 0;
		String userInput = ""; // stores user input
		boolean exit = false; // determines if user wants to exit program

		// Create a loop for userInput
		while (true) {
			// Make userInput uppercase
			System.out.print("\n" + turn + ". Enter column for " + playerToMove
					+ " to play -> ");
			userInput = keyboard.next().toUpperCase().trim();

			// If user prompts 'x'
			if (userInput.contains("X")) {
				exit = true;
				break;
			}
			// If userInput prompts for position change...
			// Convert userInput values from column and row into int
			else {
				// Change numerical chars into int

				column = userInput.charAt(0) - '1'; // convert chars 1..7 into
													// value 0..6
				if (column < 0 || column >= 7) {
					System.out.println("Invalid move. Please retry");
				}
				// Change alphabetical chars into int
				column1 = userInput.charAt(0) - 'A'; // convert chars A..Z into
														// value 0..6
				if (column1 < 0 || column1 >= 7) {
					System.out.println("Invalid move. Please retry");
				}
				// Calculate where the piece needs to go
			//	int pieceTurn = (column * 7);

				// Store each character per turn
				if (turn == 1) {
					
					// column  
					
					if (getValue(35) == ' ') {
						setValue(playerToMove, 35);
					} else if (getValue(28) == ' ') {
						setValue(playerToMove, 28);
					} else if (getValue(21) == ' ') {
						setValue(playerToMove, 21);
					} else if (getValue(14) == ' ') {
						setValue(playerToMove, 14);
					} else if (getValue(7) == ' ') {
						setValue(playerToMove, 7);
					} else if (getValue(0) == ' ') {
						setValue(playerToMove, 0);
					}
					
					
					//column 2
					if (getValue(36) == ' ') {
						setValue(playerToMove, 36);
					} else if (getValue(29) == ' ') {
						setValue(playerToMove, 29);
					} else if (getValue(22) == ' ') {
						setValue(playerToMove, 22);
					} else if (getValue(15) == ' ') {
						setValue(playerToMove, 15);
					} else if (getValue(8) == ' ') {
						setValue(playerToMove, 8);
					} else if (getValue(1) == ' ') {
						setValue(playerToMove, 1);
					}
					
					//column 3
					if (getValue(37) == ' ') {
						setValue(playerToMove, 37);
					} else if (getValue(30) == ' ') {
						setValue(playerToMove, 30);
					} else if (getValue(23) == ' ') {
						setValue(playerToMove, 23);
					} else if (getValue(16) == ' ') {
						setValue(playerToMove, 16);
					} else if (getValue(9) == ' ') {
						setValue(playerToMove, 9);
					} else if (getValue(2) == ' ') {
						setValue(playerToMove, 2);
					}
					
					
					
					//column4 
					if (getValue(38) == ' ') {
						setValue(playerToMove, 38);
					} else if (getValue(29) == ' ') {
						setValue(playerToMove, 29);
					} else if (getValue(23) == ' ') {
						setValue(playerToMove, 23);
					} else if (getValue(16) == ' ') {
						setValue(playerToMove, 16);
					} else if (getValue(9) == ' ') {
						setValue(playerToMove, 9);
					} else if (getValue(3) == ' ') {
						setValue(playerToMove, 3);
					}
					//column 5
					if (getValue(39) == ' ') {
						setValue(playerToMove, 39);
					} else if (getValue(29) == ' ') {
						setValue(playerToMove, 29);
					} else if (getValue(23) == ' ') {
						setValue(playerToMove, 23);
					} else if (getValue(16) == ' ') {
						setValue(playerToMove, 16);
					} else if (getValue(9) == ' ') {
						setValue(playerToMove, 9);
					} else if (getValue(4) == ' ') {
						setValue(playerToMove, 4);
					}
					//column 6
					if (getValue(40) == ' ') {
						setValue(playerToMove, 40);
					} else if (getValue(33) == ' ') {
						setValue(playerToMove, 33);
					} else if (getValue(26) == ' ') {
						setValue(playerToMove, 26);
					} else if (getValue(19) == ' ') {
						setValue(playerToMove, 16);
					} else if (getValue(9) == ' ') {
						setValue(playerToMove, 9);
					} else if (getValue(5) == ' ') {
						setValue(playerToMove, 5);
					}
					//column7
					if (getValue(37) == ' ') {
						setValue(playerToMove, 41);
					} else if (getValue(34) == ' ') {
						setValue(playerToMove, 34);
					} else if (getValue(27) == ' ') {
						setValue(playerToMove, 27);
					} else if (getValue(20) == ' ') {
						setValue(playerToMove, 20);
					} else if (getValue(13) == ' ') {
						setValue(playerToMove, 13);
					} else if (getValue(6) == ' ') {
						setValue(playerToMove, 6);
					}
					
					
					
					break;

				}
			}
		}// end while(true)

		return exit;
	}// end boardUpdate

	// -----------------------------------------------------------------------------------
	// //
	// gameWin
	// Checks if there are pieces adjacent to each other
	boolean gameWin() {
		boolean value = false;

		// !!! MAKE FOR LOOPS FOR THESE? !!! //
		// Checks for adjacent pieces: row, column, and vertical
		// connect4(starting position, adds to starting position to find other 3
		// positions)

		// ROWS //
		if (connect4(0, 1)
				|| connect4(1, 1)
				|| connect4(2, 1)
				|| connect4(3, 1)
				|| // row 1
				connect4(7, 1)
				|| connect4(8, 1)
				|| connect4(9, 1)
				|| connect4(10, 1)
				|| // row 2
				connect4(14, 1)
				|| connect4(15, 1)
				|| connect4(16, 1)
				|| connect4(17, 1)
				|| // row 3
				connect4(21, 1)
				|| connect4(22, 1)
				|| connect4(23, 1)
				|| connect4(24, 1)
				|| // row 4
				connect4(28, 1)
				|| connect4(29, 1)
				|| connect4(30, 1)
				|| connect4(31, 1)
				|| // row 5
				connect4(35, 1)
				|| connect4(36, 1)
				|| connect4(37, 1)
				|| connect4(38, 1)
				|| // row 6

				// COLUMNS //
				connect4(0, 7)
				|| connect4(7, 7)
				|| connect4(14, 7)
				|| // column 1
				connect4(1, 7)
				|| connect4(8, 7)
				|| connect4(15, 7)
				|| // column 2
				connect4(2, 7)
				|| connect4(9, 7)
				|| connect4(16, 7)
				|| // column 3
				connect4(3, 7)
				|| connect4(10, 7)
				|| connect4(17, 7)
				|| // column 4
				connect4(4, 7)
				|| connect4(11, 7)
				|| connect4(18, 7)
				|| // column 5
				connect4(5, 7)
				|| connect4(12, 7)
				|| connect4(19, 7)
				|| // column 6
				connect4(6, 7)
				|| connect4(13, 7)
				|| connect4(20, 7)
				|| // column 7

				// LEFT-RIGHT VERTICAL
				connect4(14, 8) || connect4(7, 8) || connect4(7, 8)
				|| connect4(15, 8) || connect4(0, 8) || connect4(8, 8)
				|| connect4(16, 8) || connect4(1, 8) || connect4(9, 8)
				|| connect4(17, 8)
				|| connect4(2, 8)
				|| connect4(10, 8)
				|| connect4(3, 8)
				||

				// RIGHT-LEFT VERTICAL
				connect4(3, 6) || connect4(4, 6) || connect4(10, 6)
				|| connect4(5, 6) || connect4(11, 6) || connect4(17, 6)
				|| connect4(6, 6) || connect4(12, 6) || connect4(18, 6)
				|| connect4(13, 6) || connect4(19, 6) || connect4(20, 6)) {
			value = true;
		}// end RIGHT-LEFT VERTICAL

		return value;
	}// end gameWin

	// -----------------------------------------------------------------------------------
	// //
	// connect4
	// Checks if there are 4 in a row by determining other 3 positions from the
	// current position
	boolean connect4(int index, int position) {
		// Check 3 positions
		int position1 = index + position;
		int position2 = index + (position * 2);
		int position3 = index + (position * 3);

		// Return all positions at setValue (they must be equal to each other)
		return ((getValue(index) != ' ')
				&& (getValue(index) == getValue(position1))
				&& (getValue(position1) == getValue(position2)) && (getValue(position2) == getValue(position3)));

	}

	// -----------------------------------------------------------------------------------
	// //
	// setValue()
	// Stores value of character into location
	void setValue(char value, int index) {

		switch (index) {
		case 0:
			p0 = value;
			break;
		case 1:
			p1 = value;
			break;
		case 2:
			p2 = value;
			break;
		case 3:
			p3 = value;
			break;
		case 4:
			p4 = value;
			break;
		case 5:
			p5 = value;
			break;
		case 6:
			p6 = value;
			break;
		case 7:
			p7 = value;
			break;
		case 8:
			p8 = value;
			break;
		case 9:
			p9 = value;
			break;
		case 10:
			p10 = value;
			break;
		case 11:
			p11 = value;
			break;
		case 12:
			p12 = value;
			break;
		case 13:
			p13 = value;
			break;
		case 14:
			p14 = value;
			break;
		case 15:
			p15 = value;
			break;
		case 16:
			p16 = value;
			break;
		case 17:
			p17 = value;
			break;
		case 18:
			p18 = value;
			break;
		case 19:
			p19 = value;
			break;
		case 20:
			p20 = value;
			break;
		case 21:
			p21 = value;
			break;
		case 22:
			p22 = value;
			break;
		case 23:
			p23 = value;
			break;
		case 24:
			p24 = value;
			break;
		case 25:
			p25 = value;
			break;
		case 26:
			p26 = value;
			break;
		case 27:
			p27 = value;
			break;
		case 28:
			p28 = value;
			break;
		case 29:
			p29 = value;
			break;
		case 30:
			p30 = value;
			break;
		case 31:
			p31 = value;
			break;
		case 32:
			p32 = value;
			break;
		case 33:
			p33 = value;
			break;
		case 34:
			p34 = value;
			break;
		case 35:
			p35 = value;
			break;
		case 36:
			p36 = value;
			break;
		case 37:
			p37 = value;
			break;
		case 38:
			p38 = value;
			break;
		case 39:
			p39 = value;
			break;
		case 40:
			p40 = value;
			break;
		case 41:
			p41 = value;
			break;

		default:
			System.out.println(+value
					+ " is an invalid value. \nExiting program...");
			System.exit(-1);
			break;
		}// end switch(i)

	} // end setValue()

	// -----------------------------------------------------------------------------------
	// //
	// getValue()
	// Grabs info from location
	char getValue(int index) {

		char result = ' ';
		switch (index) {
		case 0:
			result = p0;
			break;
		case 1:
			result = p1;
			break;
		case 2:
			result = p2;
			break;
		case 3:
			result = p3;
			break;
		case 4:
			result = p4;
			break;
		case 5:
			result = p5;
			break;
		case 6:
			result = p6;
			break;
		case 7:
			result = p7;
			break;
		case 8:
			result = p8;
			break;
		case 9:
			result = p9;
			break;
		case 10:
			result = p10;
			break;
		case 11:
			result = p11;
			break;
		case 12:
			result = p12;
			break;
		case 13:
			result = p13;
			break;
		case 14:
			result = p14;
			break;
		case 15:
			result = p15;
			break;
		case 16:
			result = p16;
			break;
		case 17:
			result = p17;
			break;
		case 18:
			result = p18;
			break;
		case 19:
			result = p19;
			break;
		case 20:
			result = p20;
			break;
		case 21:
			result = p21;
			break;
		case 22:
			result = p22;
			break;
		case 23:
			result = p23;
			break;
		case 24:
			result = p24;
			break;
		case 25:
			result = p25;
			break;
		case 26:
			result = p26;
			break;
		case 27:
			result = p27;
			break;
		case 28:
			result = p28;
			break;
		case 29:
			result = p29;
			break;
		case 30:
			result = p30;
			break;
		case 31:
			result = p31;
			break;
		case 32:
			result = p32;
			break;
		case 33:
			result = p33;
			break;
		case 34:
			result = p34;
			break;
		case 35:
			result = p35;
			break;
		case 36:
			result = p36;
			break;
		case 37:
			result = p37;
			break;
		case 38:
			result = p38;
			break;
		case 39:
			result = p39;
			break;
		case 40:
			result = p40;
			break;
		case 41:
			result = p41;
			break;
		default:
			System.out.println("*** Invalid value of " + index
					+ " in method getPiece().  Exiting...");
			System.exit(-1);
			break;

		}

		// All characters have space as default

		return result;
	} // end getValue()

	// -----------------------------------------------------------------------------------
	// //
	// setPlayerTurn
	// Determines player's turn
	char setPlayerToMove(int turn) {
		// Odds -> player 1 = X
		// Evens -> player 2 = O
		if (turn % 2 == 1) {
			return 'X';

		} else {

			return 'O';
		}
	}// end setPlayerTurn

	// -----------------------------------------------------------------------------------
	// //
	// initializeBoard
	void initializeBoard() {
		p0 = p1 = p2 = p3 = p4 = p5 = p6 = ' ';
		p7 = p8 = p9 = p10 = p11 = p12 = p13 = ' ';
		p14 = p15 = p16 = p17 = p18 = p19 = p20 = ' ';
		p21 = p22 = p23 = p24 = p25 = p26 = p27 = ' ';
		p28 = p29 = p30 = p31 = p32 = p33 = p34 = ' ';
		p35 = p36 = p37 = p38 = p39 = p40 = p41 = ' ';

	}

	// -----------------------------------------------------------------------------------
	// //
	// displayBoard
	void displayBoard() {

		System.out.print("\n---------------\n");
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p0, p1, p2, p3, p4, p5,
				p6);
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p7, p8, p9, p10, p11,
				p12, p13);
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p14, p15, p16, p17, p18,
				p19, p20);
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p21, p22, p23, p24, p25,
				p26, p27);
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p28, p29, p30, p31, p32,
				p33, p34);
		System.out.printf("|%c|%c|%c|%c|%c|%c|%c| \n", p35, p36, p37, p38, p39,
				p40, p41);
		System.out.printf("---------------");
		System.out.println("\n 1 2 3 4 5 6 7 <- place piece");
		System.out.println(" A B C D E F G <- remove piece");

	}// end displayBoard

} // end popOut()