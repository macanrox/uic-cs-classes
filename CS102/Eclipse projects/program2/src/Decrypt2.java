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

public class Decrypt2 {

	// declare Scanner for user input
	Scanner keyboard = new Scanner( System.in);
	
	
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
		System.out.print("Enter input string: ");
		String inputLine = keyboard.nextLine();
		inputLine = inputLine.toUpperCase();	// converts lowercase to uppercase
		System.out.print("You entered: " +inputLine);
		
		// Store characters into a new string
	    String store = inputLine;	    	    
		
		// Pull out each character one at a time	    
	    // Declare variables
	    char chars;
		char stores;
		char newChar;
	    
		// Create for loop to pull out each character
	    for (chars = 0; chars < store.length(); ++chars)
		{
			stores = store.charAt(chars);
			newChar = (char) (stores + 1);
		}
		
		// Apply transposition value per character
	    char a = 'A';
			int A = a-65;
			int valueA = ((A+1) % 26) + 65;
			char a1 = (char) valueA;
						
		char b = 'B';
			int B = b-65;
			int valueB = ((B+1) % 26) + 65;
			char b1 = (char) valueB;
							
		char c = 'C';
			int C = c-65;
			int valueC = ((C+1) % 26) + 65;
			char c1 = (char) valueC;
						
		char d = 'D';
			int D = d-65;
			int valueD = ((D+1) % 26) + 65;
			char d1 = (char) valueD;
							
		char e = 'E';
			int E = e-65;
			int valueE = ((E+1) % 26) + 65;
			char e1 = (char) valueE;
							
		char f = 'F';
			int F = f-65;
			int valueF = ((F+1) % 26) + 65;
			char f1 = (char) valueF;
							
		char g = 'G';
			int G = g-65;
			int valueG = ((G+1) % 26) + 65;
			char g1 = (char) valueG;
							
		char h = 'H';
			int H = h-65;
			int valueH = ((H+1) % 26) + 65;
			char h1 = (char) valueH;
						
		char i = 'I';
			int I = i-65;
			int valueI = ((I+1) % 26) + 65;
			char i1 = (char) valueI;
							
		char j = 'J';
			int J = j-65;
			int valueJ = (J+1) % 26 + 65;
			char j1 = (char) valueJ;
							
		char k = 'K';
			int K = k-65;
			int valueK = ((K+1) % 26) + 65;
			char k1 = (char) valueK;
							
		char l = 'L';
			int L = l-65;
			int valueL = ((L+1) % 26) + 65;
			char l1 = (char) valueL;
							
		char m = 'M';
			int M = m-65;
			int valueM = ((M+1) % 26) + 65;
			char m1 = (char) valueM;
							
		char n = 'N';
			int N = n-65;
			int valueN = ((N+1) % 26) + 65;
			char n1 = (char) valueN;
							
		char o = 'O';
			int O = o-65;
			int valueO = ((O+1) % 26) + 65;
			char o1 = (char) valueO;
							
		char p = 'P';
			int P = p-65;
			int valueP = ((P+1) % 26) + 65;
			char p1 = (char) valueP;
							
		char q = 'Q';
			int Q = q-65;
			int valueQ = ((Q+1) % 26) + 65;
			char q1 = (char) valueQ;
							
		char r = 'R';
			int R = r-65;
			int valueR = ((R+1) % 26) + 65;
			char r1 = (char) valueR;
							
		char s = 'S';
			int S = s-65;
			int valueS = ((S+1) % 26) + 65;
			char s1 = (char) valueS;
							
		char t = 'T';
			int T = t-65;
			int valueT = ((T+1) % 26) + 65;
			char t1 = (char) valueT;
							
		char u = 'U';
			int U = u-65;
			int valueU = ((U+1) % 26) + 65;
			char u1 = (char) valueU;
							
		char v = 'V';
			int V = v-65;
			int valueV = ((V+1) % 26) + 65;
			char v1 = (char) valueV;
							
		char w = 'W';
			int W = w-65;
			int valueW = ((W+1) % 26) + 65;
			char w1 = (char) valueW;
						
		char x = 'X';
			int X = x-65;
			int valueX = ((X+1) % 26) + 65;
			char x1 = (char) valueX;
						
		char y = 'Y';
			int Y = y-65;
			int valueY = ((Y+1) % 26) + 65;
			char y1 = (char) valueY;
			
		char z = 'Z';
			int Z = z-65;
			int valueZ = ((Z+1) % 26) + 65;
			char z1 = (char) valueZ;
				
		// Prompt menuOptions
		System.out.print("\n\nChoose one of the following: ");
		System.out.print("\n   1. Encode input line");
		System.out.print("\n   2. Decode input line");
		System.out.print("\n   3. Exit program");
		System.out.print("\nYour choice => ");
		
		
		// Create switch statement for menuOptions
		int mainOption = keyboard.nextInt();	// declare variables
		String inputLine2 = keyboard.next();
		
		switch (mainOption)
		{
		case 1: 
			System.out.print("\nEncode chosen");
			System.out.print("\nEncoded line is: ");
			System.out.println("\n" +store);
			break;
		case 2: 
			System.out.print("\nDecode chosen");
			break;
		case 3:
			System.out.print("\nExiting program...");
			break;
		}
		
				
		System.out.println("\n\nDone with program.");
	}//end doIt()
	
}//end class Decrypt