import java.util.Scanner;

public class program2 {

	public static void main( String[] args)
	{
		Scanner keyboard = new Scanner( System.in);
		
		System.out.println("Starting program...");
		System.out.print("Enter a string: ");
		String userInput= keyboard.nextLine();  // read entire line, with spaces
		//convert it to all upper case
		userInput = userInput.toUpperCase();
		
		// Transpose each letter in the string
		String newString = "";   // initialize to empty string
		char c = ' ';
		
		// you need to make transposition a variable in a for loop
		// if you want to use the code shown below to try all possible
		// decryptions.
		int transposition = 1;
		
		// go through each letter in the string. 
		//                         01234
		// Input string could be: "BASIC"
		for( int i=0; i<userInput.length(); i++) {
			// pull off the ith character
			c = userInput.charAt( i);
			// don't change it if it is a space
			if( c != ' ') {
				// shift from range 'A'..'Z' (65..90) down to 0..25
				int value = c - 'A';
				// add the transposition, wrapping around
				value = (value + transposition) % 26;
				// shift back into 'A'..'Z' range
				c = (char)('A' + value);
			}
			// append it to the new string
			// do the opposite to make a new string in reverse order:
			//    newString = c + newString
			newString = newString + c;
		}
		System.out.println( newString);
		
		// See if the new string contains the word "BCMF"
		if( newString.contains("FMCB")) {
			System.out.println("Napoleon was here.");
		}
		
		System.out.println();
		System.out.println("Done.");
	}
}

