/**
 * Class for creating a template for a simple Java program
 * 
 * @author Bresia Prudente
 */

// Bresia Prudente
// bprude2
// Friday at 10:00 AM
// Use a turtle to spell out my initials.
public class Lab3bprude2
{
  
  public static void main (String[] args) 
  {
    System.out.println("Begin Java Exection");
    System.out.println("");


    // put your Java Program here
       World w;
       w = new World ();
       
       
       Turtle t;
       t=new Turtle (50, 150, w);
       
       
       t.setPenWidth (5);   
       
       t.forward ();        //for B
       t.turnRight ();
       t.forward (50);
       t.turnRight ();
       t.forward (50);
       t.turnRight ();
       t.forward (50);
       t.turn (180);
       t.penUp ();         //leaves no mark
       t.forward (50);
       t.turnRight ();
       t.penDown ();
       t.forward (50);
       
       

       
       w.show();
           
       

    System.out.println("");
    System.out.println("End Java Exection");
  }
} // end of Template class