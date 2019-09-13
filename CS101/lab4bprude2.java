/**
 * 
 * 
 * @author Bresia Prudente
 */

// Bresia Prudente
// bprude2
// Friday, 10:00 AM
// 
public class lab4bprude2 
{
  
  public static void main (String[] args) 
  {
    System.out.println("Begin Java Exection");
    System.out.println("");


    // put your Java Program here
    
    //Create world
    Picture p;
    p = new Picture (680, 680);                         //double black slashes for pictures in directory
    String filename = FileChooser.pickAFile ();
    Picture pict = new Picture (filename);
    
    
    //Create turtle
    Turtle t;
    t = new Turtle (400, 250, p);
    
    
    //Moving turtle
    t.setPenWidth (2);
    
    
    //Draw a triangle
    drawTriangle (t);
    
    
    //Showing turtle's world
    p.show ();
    
    
    


    System.out.println("");
    System.out.println("End Java Exection");
  } //end of method main
 
  
  //Implement method into "Moving turtle"
  public static void drawTriangle (Turtle tParam)
  {
    int count;
    int numSides;
    int degrees;
    numSides = 3;
    degrees = 720 / numSides;
    count = 0;
    while ( count < numSides )
    {
      tParam.forward (100);
      tParam.turn (degrees);
      count = count + 1;      
    }
  }
  
  
} // end of Template class