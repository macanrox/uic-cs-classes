import java.awt.*;

/**
 * A square that can be manipulated and that draws itself on a canvas.
 * 
 * @author Barnes & Kolling 
 * @author reed
 * @version (9/1/2003)
 */
public class Square
{
    private int size;
    private int xPosition;
    private int yPosition;
    private String color;
    private boolean isVisible;
    private String label;
    private int id;		// used to identify squares without using their label

    /**
     * Create a new Square at default position with default color.
     */
    public Square()
    {
        size = 30;
        xPosition = 60;
        yPosition = 50;
        color = "red";
        isVisible = false;
        label = "";
        id = 0;
    }
    
   /**
     * Create a new Square with supplied position, size, color, and visibility
     */
    public Square( int x, int y, int theSize, String theColor, 
                   boolean visibility)
    {
        xPosition = x;
        yPosition = y;
        size = theSize;
        color = theColor;
        isVisible = visibility;
        label = "";
        id = 0;
        draw();     // Now actually draw it
    }
    
    /**
     * Create a new Square with supplied position, size, color, and visibility
     */
    public Square( int x, int y, int theSize, String theColor, 
                   boolean visibility, String theLabel)
    {
        xPosition = x;
        yPosition = y;
        size = theSize;
        color = theColor;
        isVisible = visibility;
        label = theLabel;
        id = 0;
        draw();     // Now actually draw it
    }
    
    // Square copy constructor, making a new Square based on an existing Square
    public Square( Square otherSquare)
    {
        xPosition = otherSquare.xPosition;
        yPosition = otherSquare.yPosition;
        size = otherSquare.size;
        color = otherSquare.color;
        isVisible = otherSquare.isVisible;
        label = otherSquare.label;
        id = otherSquare.id;
        draw();     // Now actually draw it
    }

    /**
     * Get the color for this square
     */
    public String getColor()
    {
        return color;
    }
    
    /**
     * Get the xPosition for this square
     */
    public int getX()
    {
        return xPosition;
    }
    
    /**
     * Get the yPosition for this square
     */
    public int getY()
    {
        return yPosition;
    }
    
    
    /**
     * Get the size for this square
     */
    public int getSize()
    {
        return size;
    }
    
    /**
     * Get the label for this square
     */
    public String getLabel()
    {
        return label;   
    }
    
    /**
     * Get the id for this square
     */
    public int getID()
    {
        return id;   
    }

    /**
     * Get the visibility for this square
     */
    public boolean getVisibility()
    {
        return isVisible;   
    }
    
    /**
     * Make this Square visible. If it was already visible, do nothing.
     */
    public void makeVisible()
    {
        isVisible = true;
        draw();
    }
    
    /**
     * Make this Square invisible. If it was already invisible, do nothing.
     */
    public void makeInvisible()
    {
        erase();
        isVisible = false;
    }
    
    
    /**
     * Slowly move the Square horizontally by 'distance' pixels.
     */
    public void slowMoveHorizontal(int distance)
    {
        int delta;

        if(distance < 0) 
        {
            delta = -1;
            distance = -distance;
        }
        else 
        {
            delta = 1;
        }

        for(int i = 0; i < distance; i++)
        {
            xPosition += delta;
            draw();
        }
    }

    /**
     * Slowly move the Square vertically by 'distance' pixels.
     */
    public void slowMoveVertical(int distance)
    {
        int delta;

        if(distance < 0) 
        {
            delta = -1;
            distance = -distance;
        }
        else 
        {
            delta = 1;
        }

        for(int i = 0; i < distance; i++)
        {
            yPosition += delta;
            draw();
        }
    }

    /**
     * Change the size to the new size (in pixels). Size must be >= 0.
     */
    public void changeSize(int newSize)
    {
        erase();
        size = newSize;
        draw();
    }

    /**
     * Change the position of the square on the canvas.
     */
    public void setPosition(int newX, int newY)
    {
        erase();
        xPosition = newX;
        yPosition = newY;
        draw();
    }
    
    
    /**
     * Change the color. Valid colors are "red", "yellow", "blue", "green",
     * "magenta", "black", "cyan", "darkGray", "gray", "lightGray", "orange",
     * "pink", "white"
     */
    public void setColor(String newColor)
    {
        color = newColor;
        draw();
    }

    /*
     * Set the label
     */
    public void setLabel( String theLabel)
    {
        label = theLabel;
        draw();
    }
    
    
    /*
     * Set the id
     */
    public void setID( int theID)
    {
        id = theID;
        draw();
    }
    
    
    /*
     * Set the size
     */
    public void setSize( int theSize)
    {
        size = theSize;
        draw();
    }
    
    
    /*
     * Draw the Square with current specifications on screen.
     */
    private void draw()
    {
        if(isVisible) {
            Canvas canvas = Canvas.getCanvas();
            canvas.draw(this, color,
                        new Rectangle(xPosition, yPosition, size, size),
                        label);
            canvas.wait(1);
        }
    }

    /*
     * Erase the Square on screen.
     */
    private void erase()
    {       
        if(isVisible) {
            Canvas canvas = Canvas.getCanvas();
            canvas.erase(this);
        }
    }
}

