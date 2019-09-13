
public class Board 
{
	
	// declare and initialize variables
	private int board;
	private int numRows;		// 6 rows
	private int numColumns;		// 7 columns
	private int connect4 = 4;	// player needs 4 pieces to win
	
	
	// METHODS //
	
	// getNumRows()
	public int getNumRows()
	{
		for (numRows = 1; numRows < 6; numRows++ )
		{
			System.out.print ("");
		}	// end for (numRows...)
		
		return numRows;
	}	// end getNumRows()
	
	// getNumColumns
	public int getNumColumns()
	{
		for (numColumns = 1; numColumns < 7; numColumns++)
		{
			System.out.println("|	|");
		}	// end for(numColumns...)
		return numColumns;
	}	// end getNumColumns()

	
}	// end class Board
