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
		System.out.print("Type in a word or sentence: ");
		String userInput = keyboard.nextLine();
		userInput = userInput.toUpperCase();	// makes input uppercase
		System.out.print("You entered: " +userInput);
		
		
		// RANDOMIZE TRANSPOSITION NUMBER //
		
		// initialize randomNumberGenerator
        randomNumberGenerator = new Random();  
        
		// declare and initialize randomNumber
		int randomNumber = 0;
		
		// generate and display a random number
		for( int n=0; n < 1; n++) 
		{
			// generate a random number in range 1..25
			randomNumber = randomNumberGenerator.nextInt(25) + 1;
		}
		
		// initialize transpose with randomNumber
		int transpose = randomNumber;
		
		
		// declare and initialize randomDirection
		int randomDirection = 0;
		
		// generate and display a random number
		for( int d=0; d < 1; d++)
		{
			// generate a random number either 0 or 1
			randomDirection = randomNumberGenerator.nextInt(2);
			
			System.out.print("\nDirection goes: " +randomDirection);
		}
		
		// END RANDOMIZED TRANSPOSITION NUMBER //
		
		
		// TRANSPOSE EACH CHARACTER IN THE STRING //
		String newString = "";   // initialize to empty string
		char c = ' ';	// declare and initialize character
		
		// change each character in the string
		for( int i=0; i<userInput.length(); i++) 
		{
			// pull out a character
			c = userInput.charAt(i);
			
			// no change if it's a space
			if( c != ' ')	
			{
				// shift from range 'A'..'Z' (65..90) down to 0..25
				int value = c - 'A';	
				
				// transpose and wrap around
				value = (value + transpose) % 26;
				
				// shift back to 'A'..'Z' range
				c = (char)('A' + value);	
				
			}	// end no space change
			
			// append to the new string
			// forwards or backwards
			if (randomDirection == 0)
			{
				newString = newString + c;
			}
			else
			{
				newString = c + newString;
			}
		} // end character change
		
		// END TRANSPOSING CHARACTER IN STRING //
			
		
		// transpose forward and backwards 26 times
		String newString1 = newString;
		
			for (int x = 0; x <= 26; x++)
			{
				for( int i=0; i<userInput.length(); i++) 
				{
					// pull out a character
					c = userInput.charAt(i);
					
					// no change if it's a space
					if( c != ' ')	
					{
						// shift from range 'A'..'Z' (65..90) down to 0..25
						int value = c - 'A';	
						
						// transpose and wrap around
						value = (value + transpose) % 26;
						
						// shift back to 'A'..'Z' range
						c = (char)('A' + value);	
					}
					newString1 = newString + c;
				}
			} //end transpose fw and bw
		
		
		// Prompt menuOptions
		System.out.print("\n\nChoose one of the following: ");
		System.out.print("\n   1. Encode input line");
		System.out.print("\n   2. Decode input line");
		System.out.print("\n   3. Exit program");
		System.out.print("\nYour choice => ");
		
		
		// Create switch statement for menuOptions
		int mainOption = keyboard.nextInt();	// declare variables
		
		switch (mainOption)
		{
		case 1: 
			System.out.print("\nEncode chosen");
			System.out.print("\nEncoding using a transposition number of " +transpose+ " moving in ");
				
			 	// determine direction
					if (direction == randomDirection)
					{
						System.out.print("forward direction.");
					}
					else
					{
						System.out.print("backward direction.");
					}
			
			System.out.print("\nEncoded line is: " +newString);	// use the new appended string from character change
			break;
		case 2: 
			System.out.print("\nDecode chosen");
			System.out.println("\nShowing all possible results in forwards direction on the left and backwards direction on the right.");
			System.out.println("\n" +newString1);
			break;
		case 3:
			System.out.print("\nExiting program...");
			break;
		}
		
				
		System.out.println("\n\nDone with program.");
	}//end doIt()
	
}//end class Decrypt