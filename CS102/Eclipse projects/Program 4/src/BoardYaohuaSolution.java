/**
 * class Board
 * 		Implement the functionality for a puzzle where a pattern
 * of 9 color squares must be matched.  
 * The program displays a grid of 25 squares on the screen, along
 * with a target pattern of 9 squares.  The goal of the game
 * is to make the 9 central squares of the large grid match
 * the colors shown in the target set.
 *  
 * Selecting the "Redo" button starts over.  Selecting the 
 * "Exit" button exits the game.
 * 
 * Class: CS 102/107, Spring 2011
 * Lab: Billie Joe Armstrong, Wed. 6:00 AM
 * System: Eclipse 3.4.2, jsdk 1.6, Windows XP

 * @author Dale Reed 
 * @version February 7, 2011
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
    Square randomizeButton; 	// randomize board
    Square exitButton;			// users presses this to exit program
    Square gameMessagesLabel;	// Used to display messages
    Square goalLabel;			// Message shown above goal squares
    
    // declare some squares to be displayed on the screen
    Square[][] square;
    
    // declare constants to use throughout program
    final int SQUARE_SIZE = 44;
    final int OFFSET = 6;	
    int moveNumber = 0;
    
    // Create a Date object to keep track of time
    Date startTime = new Date();


    //----------------------------------------------------------------------------------------------
    // Constructor to create the board
    Board()
    {   
    	// display ID information and the instructions
    	displayIdInformation();

    	
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
		// create inner square boundary, to delineate middle 9 squares
	//	boardBackground = new Square (xPosition + OFFSET + SQUARE_SIZE + 2, yPosition + OFFSET + SQUARE_SIZE + 3,
		//							       152, "black", true, "");	
		// create lightGrey board center background
		boardBackground = new Square (xPosition + OFFSET + SQUARE_SIZE + 4, yPosition + OFFSET + SQUARE_SIZE + 5,
			                               148, "lightGray", true, "");		
		
		// adjust the x,y starting position
    	xPosition = xPosition - OFFSET/2 + 3;	   
    	yPosition = xPosition - OFFSET/4 + 2;	
    	xPosition += OFFSET;
    	yPosition += OFFSET;
    	
    	square = new Square[5][5];
    	
    	for (int x = 0; x < 5; x ++){
    		for (int y= 0; y < 5; y ++){
    			square[x][y] = new Square(xPosition + x*(SQUARE_SIZE+OFFSET), 
    					yPosition + y*(SQUARE_SIZE+OFFSET), SQUARE_SIZE, 
    					getRandomColor(), true, "");
    		}
    	}
				    
		// create the "Redo" and "Exit" squares near the bottom right of the board
		randomizeButton = new Square( 410, 330, 40, "lightGray", true, "Redo");
		exitButton = new Square( 460, 330, 40, "lightGray", true, "  Exit");
    }//end Board() constructor
    
    
    //----------------------------------------------------------------------------------------------
    public void displayIdInformation()
    {
        // Display identifying information
        System.out.println( "Author: Dale Reed \n" +
                            "Program #3: SquareUp \n" +
                            "February 7, 2011\n");
    }//end displayIdInformation()
       
    
    //----------------------------------------------------------------------------------------------
    // Generate a random number used to select one
    String getRandomColor()
    {
    	String theColor = "";	// will store the color, to be returned
    	
    	// generate a random number, which will be used to select a color among 8 colors
    	int randomNumber = randomNumberGenerator.nextInt( 8);
    	
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
    	
    	theSquare = exitButton;
        // Find out where the mouse click was, in some square 
        if( (mouseX >= theSquare.getX()) && (mouseX <= (theSquare.getX() + theSquare.getSize())) &&   
            (mouseY >= theSquare.getY()) && (mouseY <= (theSquare.getY() + theSquare.getSize()))
        ) {
             System.out.println("Clicked on the exit button.  Exiting program...");
             System.exit( 0);	// exit the program
        } 
        
        theSquare = randomizeButton;
        if( (mouseX >= theSquare.getX()) && (mouseX <= (theSquare.getX() + theSquare.getSize())) &&   
            (mouseY >= theSquare.getY()) && (mouseY <= (theSquare.getY() + theSquare.getSize()))
            ) {        	// Mouse click was inside the "Redo" button. Call the code corresponding to the "Redo" label
            randomizeBoard();
            return;     // go back and wait for another mouse click
        }
        
        for (int x = 0; x < 5; x ++){
        	for (int y = 0; y < 5; y ++){
        		theSquare = square[x][y];
        		if( (mouseX >= theSquare.getX()) && (mouseX <= (theSquare.getX() + theSquare.getSize())) &&   
        	            (mouseY >= theSquare.getY()) && (mouseY <= (theSquare.getY() + theSquare.getSize()))
        	            ){
        			theSquare.setColor("lightGray");
        			
        			String temp = square[x][4].getColor();
        			Square tempS = theSquare; 
        			for (int i = 4; i > 0; i --){
        				square[x][i].setColor(square[x][i-1].getColor());
        			}
        			square[x][0].setColor(temp);
        			
        			break;
        		}
        		
        		
        	}
        }
 
    	
       
    }//end handleMouseClick
    
    //----------------------------------------------------------------------------------------------
    // Handle the Redo button click by randomizing the board so that
    // each row and each column satisfies the desired parity
    void randomizeBoard()
    {	
    	// make a reference to a Square, which can point to any square (s0, s1, etc)
    	Square theSquare = null;
    	
    	// create a new set of random colors in the goal squares
    	for (int x = 0; x < 5; x ++){
    		for (int y = 0; y < 5; y ++){
    			square[x][y].setColor(getRandomColor());
    		}
    	}
       	    	    	
    	// reset the prompt message, starting time and move number
    	gameMessagesLabel.setLabel("Restarting...");
    	startTime = new Date();
    	moveNumber = 0;

    }//end Redo()
  
    
    //----------------------------------------------------------------------------------------------
    // return the square corresponding to the index
    // you may use it to return Square at row x and column y
    private Square getSquareNumber( int x, int y)
    {
    	Square returnValue = null;		// will be the reference of the Square to be returned
    	
    	// returnValue = Square at (x, y)
    	
    	return returnValue;
    }//end getSquareNumber()
    
    
}// end class Board()
