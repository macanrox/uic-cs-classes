/**
 * 
 * 
 * @author Bresia Prudente
 */

// Bresia Prudente
// bprude2
// Friday, 10:00 AM
// Draw cocentric shapes

public class lab5bprude2
{
  
  public static void main (String[] args) 
  {
    System.out.println("Begin Java Exection");
    System.out.println("");


    // put your Java Program here

    
    // Creating the world    
    
    Picture p;
    p = new Picture (680, 680);                        
    String filename = FileChooser.pickAFile ();
    Picture pict = new Picture (filename);
    
    
    // Save the picture to a file
    String outFileName;
    outFileName = FileChooser.pickAFile();
    p.write (outFileName );

    
    // Move turtle
    Turtle t;
    t = new Turtle (p);
    t.setPenWidth (2);
    
    drawSquare (t, 5);
    
    moveTurtle (t , 40, -40 );
    
    drawSquare (t, 15);
    
    moveTurtle (t, -80, 0 );
    
    
 
    // Show turtle's world
    p.show();
    

    System.out.println("");
    System.out.println("End Java Exection");
  } // end of method main
 
  
  // Method for creating a square
  public static void drawSquare (Turtle tParam, int length)
  {
    int count;
    int numSides;
    int degrees;
    numSides = 4;
    degrees = 360 / numSides;
    count = 0;
    while ( count < numSides)
    {
      tParam.forward ();
      tParam.turn (degrees);
      count = count + 1;
    }
    
  }
  
    
  // Method to move turtle  
  public static void moveTurtle (Turtle tParam, int xDelta, int yDelta)
  {
    tParam.penUp();
   
    int currentX = tParam.getXPos();
    int currentY = tParam.getYPos();
   
    int newX = currentX + xDelta;
    int newY = currentY + yDelta;
   
    tParam.moveTo (newX , newY);
   
    tParam.penDown();
  }
    
  
} // end of class