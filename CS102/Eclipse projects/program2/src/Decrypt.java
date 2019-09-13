/** --------------------------------------------- 
 * Decrypt.java
 * 
 *     Decrypt or encrypt a secret message using a
 * transposition cipher (1..25). Values wrap around
 * at the end of the alphabet. A transposition
 * of 1 changes "abcz" into "bcda", and a transposition
 * value of 2 changes "abcz" into "cdeb".  The input
 * might also need to be reversed to be decoded. A 
 * potential solution is identified by having a large 
 * number of common English words, taken from:
 *      http://www.duboislc.org/EducationWatch/First100Words.html
 * Encryption selects a transpostion value at random
 * as well as choosing a direction (forward or reverse)
 * at random.
 * 
 * Lab: Sean Deitz, Wed 5 AM
 * System: Java 6, using Eclipse, on Windows 7
 * Class: CS 102, Spring 2012
 * 
 * @version January 19, 2012
 * @author Dale Reed
 */

import java.util.Scanner;   // for user input
import java.util.Random;	// import random number generator

public class Decrypt {

	// declare Scanner for user input
	Scanner keyboard = new Scanner( System.in);
	
	// declare the random number generator
	Random randomNumberGenerator; 
	
	
	// Don't write code in main, rather chain off to another
	// method to avoid static errors.  This will make more
	// sense later in the semester.
	public static void main(String[] args)
	{
		Decrypt instance = new Decrypt();
		instance.doIt();
	}//end main()
	
	
	// Write your code in the method below
	void doIt()
	{
		// Display identifying information
		System.out.println("Author: Bresia Prudente ");
		System.out.println("TA: Sean Deitz, Wed 11:00 AM ");
		System.out.println("Program: #2, Decrypt \n");
		
		
		// Prompt for and read in input
		System.out.print("Type your text here: ");
		String userInput = keyboard.nextLine();
		userInput = userInput.toUpperCase();	// Makes input uppercase
		System.out.print("You entered: " +userInput);
		
		
		// RANDOMIZE TRANSPOSITION NUMBER //
		
		// Initialize randomNumberGenerator as a new Random()
		// Also declare and initialize randomNumber
        randomNumberGenerator = new Random();  
		int randomNumber = 0;
		
		// Generate and display a random number between 1..25 
		// for transposition number in encrypt option
		for( int n=0; n < 1; n++) 
		{
			// generate a random number in range 1..25
			randomNumber = randomNumberGenerator.nextInt(25) + 1;
		}
		
		// Initialize transposition with randomNumber
		// Also declare and initialize randomDirection to determine
		// forward and backward direction for encrypt option
		int transpose = randomNumber;
		int randomDirection = 0;
		
		// Randomly generate and display either 0 or 1 for
		// forward or backward direction
		for( int d=0; d < 1; d++)
		{
			randomDirection = randomNumberGenerator.nextInt(2);
		}
		// END RANDOMIZED TRANSPOSITION NUMBER //
		
		
		// TRANSPOSE EACH CHARACTER IN THE STRING //
		// Declare and initialize variables
		String newString = "";
		// Initialize c so that it applies to any letter
		char c = ' ';	
		
		// Pulls out each character in the string
		// and changes it accordingly to transposition number
		for( int i=0; i<userInput.length(); i++) 
		{
			// Pulls out the character
			c = userInput.charAt(i);
			
			// Don't change if there's a space
			if( c != ' ')	
			{
				// Shift from range 'A'..'Z' (65..90) down to 0..25
				int value = c - 'A';	
				
				// Transpose and wrap around
				value = (value + transpose) % 26;
				
				// Shift back to 'A'..'Z' range
				c = (char)('A' + value);	
				
			}	// End space change
			
			// Append to the new string forwards
			// or backwards depending if randomDirection
			// value is 0 or 1
			if (randomDirection == 0)
			{
				newString = newString + c;
			}
			else
			{
				newString = c + newString;
			}
		} // End character change
		// END TRANSPOSING CHARACTER IN STRING //
					

		// Prompt menu with options
		System.out.print("\n\nChoose one of the following: ");
			// Give three options:
			// Encode, decode and exit
			System.out.print("\n   1. Encode input line");
			System.out.print("\n   2. Decode input line");
			System.out.print("\n   3. Exit program");
			// User inputs choice in this line
			System.out.print("\nYour choice => ");
		
		
		// Create switch statement for menuOptions
		// Declare and initialize variables
		int mainOption = keyboard.nextInt();
		int direction = 0;
		
		// SWITCH MAINOPTION //
		switch (mainOption)
		{
			// Encode option
			case 1: 
				System.out.print("\nEncode chosen");
				// Print transposition number value
				System.out.print("\nEncoding using a transposition number of " +transpose+ " moving in ");
					
				 	// Print forward or backward direction
						if (direction == randomDirection)
						{
							System.out.print("forward direction.");
						}
						else
						{
							System.out.print("backward direction.");
						}
				
				// Use the new appended string from the character change 
				System.out.println("\nEncoded line is: " +newString);	
				break;
			
			// Decode option
			case 2: 
				System.out.print("\nDecode chosen");
				System.out.println("\nShowing all possible results in forwards direction on the left and backwards direction on the right.");
				
				
					// Make transposition within 0..25 range
					for (int transpose1 = 1; transpose1 < 25; transpose1++)
					{
						// Declare and initialize new strings
						String forward = "";
						String backward = "";
						
							// Nested encrypt code
							for (int i = 0; i < userInput.length(); i++)
							{
								c = userInput.charAt(i);
								
								if (c != ' ')
								{
									int value1 = c - 'A';
									value1 = (value1 + transpose1) % 26;
									c = (char)(value1 + 'A');
								}// End of no space change
							
								// Use new strings to append new character
								forward = forward + c;
								backward = c + backward;
		
							}// End nested encrypt code
							
							// Prints two columns in forward and backward directions
							System.out.println("" +forward +"	" +backward);
							
						} // End transposition range
						break;
	
			// Exit program
			case 3:
				System.out.println("\nExiting program.");
				break;
		}
		// END SWITCH MENUOPTION //
		
				
		System.out.println("\nDone with program.");
	}//end doIt()
	
}//end class Decrypt