/** --------------------------------------------- 
 * MouseAndKeys.java
 *      Handle on-screen mouse clicks using mouse events 
 *  as well as key presses. The main functionality of 
 *  this program is in class Board.
 *          
 * Class: CS 102/107, Spring 2011
 * Lab: Billie Joe Armstrong, Wed. 6:00 AM
 * System: Eclipse 3.4.2, jsdk 1.6, Windows XP
 *
 * @author  Dale Reed
 * ----------------------------------------------
 */

import java.io.*;                 // used for reading from a file
import java.awt.event.*;

public class MouseAndKeys implements MouseListener
{   
    // Instance variables 
	Board theBoard;					// create the board
    
    // After x,y values found, add these differences to compensate for screen offsets caused by
    // title bar on top and screen border on the left
    final int deltaY = -30;     
    final int deltaX = -4;
    

    //----------------------------------------------------------------------------------------
    // main() - startup main loop.    
    //           "throws IOException" is needed to implement reading from a file
    public static void main(String[] args) throws IOException
    {
    	// create an instance of this class
    	MouseAndKeys MouseKeysInstance = new MouseAndKeys();
        
        // Register this instance with Canvas as the MouseListener so mouse events get handled 
        // with the mouse code shown below.  Similarly register it as the key listener to
    	// handle key press events.
        Canvas.getCanvas().setMouseListener( MouseKeysInstance);
       
        // Run the non-static doIt() method which creates the board, which will be referenced
        // when button clicks are handled.
        MouseKeysInstance.doIt();
    }
    
    // Implementing MouseListener means we must declare the 5 mouse methods:
    //     mouseClicked, mouseEntered, mouseExited, mousePressed, and mouseReleased
    // We can leave the body empty for methods whose behaviors we do not need to define.
   
    // use this to detect mouse "clicks", which is a press (for some milliseconds) & release
    public void mouseClicked(MouseEvent e) {}
    
    // detect mouse position when it enters the drawing frame
    public void mouseEntered(MouseEvent e) {}
    
    // detect mouse position when it exits the drawing frame
    public void mouseExited(MouseEvent e)  {}

    // detect mouse position when mouse button is pressed
    public void mousePressed(MouseEvent e) 
    {
        int x = e.getX() + deltaX;  // compensate for offset of frame left border 
        int y = e.getY() + deltaY;  // compensate for frame title bar on the tip
        
        // pass the mouse click coordinates to the board class to be handled
        theBoard.handleMouseClick( x,y);
    }

    // detect mouse position when mouse button is released    
    public void mouseReleased(MouseEvent e) {}

  
    //----------------------------------------------------------------------------------------
    // doIt() - display identifying information and run main part of program
    //      
    void doIt() 
    {                      
        // Create board.  This cannot be done within main because we want the board to be created
    	// (which could be done in main) but then we also want the mouse listener methods to 
    	// also be able to reference the same board to call the mouse handling method within the board 
    	// class.  Doing this within main would prevent the board from being shared between where
    	// it is created and where it is used in the mousePressed() method.
        theBoard = new Board();    
    }//end method doIt()

    
}//end class MouseAndKeys
