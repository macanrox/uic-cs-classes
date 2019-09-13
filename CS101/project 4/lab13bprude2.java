/**
 * Bresia Prudente
 * bprude2
 * CSC 101
 * Project 4
 * Friday at 10:00
 * Description: Modify the sound file volume so that the first half increases from silence to 100% and the other 
 * half decreases from 100% to silence.
 */

public class project4bprude2
{
  
  public static void main (String[] args) 
  {
    System.out.println("Begin Java Exection");
    System.out.println("");

    
    

    // MAIN PROGRAM //
    
    
    // Open sound files
    
    // Prompt user to open the a sound file
    SimpleOutput.showInformation ("Open a sound file.");
    String filename = FileChooser.pickAFile();
    Sound s = new Sound (filename);

    
    // Get information from the sound files
    System.out.println ("S Length: " +  s.getLength());
    System.out.println ("S Sampling Rate: " +  s.getSamplingRate());
    
    
    
    
    // Create a new cropSound file
    Sound s1 = cropSound (s, 0, (s.getLength()/2));
    Sound s2 = cropSound (s, (s.getLength()/2), s.getLength());
    
    // Get information from new cropSound file
    System.out.println ("S1 length: " + s1.getLength());
    System.out.println ("S2 length: " + s1.getLength());
    
    
    // Create a new increaseSound file
    Sound s3 = increaseSound (s1);
    
    // Get information from increaseSound file
    System.out.println ("S3 length: " + s3.getLength());
    
    
    // Create a new decreaseSound file
    Sound s4 = decreaseSound (s2);
    
    // Get information from decreaseSound file
    System.out.println ("S4 length: " + s4.getLength());
    
      
    // Create a new joinSounds file
    Sound s5 = joinSounds (s3, s4);
    
    // Get information from joinSounds file
    System.out.println ("S5 length: " + s5.getLength());
    
    
    
    
    // Play the final, modified sound file
    s5.explore();
    
    
    // Save the final sound
    SimpleOutput.showInformation ("Save the modified file.");
    String saveSoundFile = FileChooser.pickAFile();
    s.write (saveSoundFile);
    


    System.out.println("");
    System.out.println("End Java Exection");
  } // End main
  
  
  
  // METHODS GO HERE //
  
  
 public static Sound cropSound (Sound s1, int startIndex, int endIndex)
  {    
    int l3 = endIndex - startIndex;
    
    Sound s3;
    s3 = new Sound (l3);
    
    SoundSample ssarray1[];
    SoundSample ssarray3[];
    int largest;
    int value1;
    int  i;
    
    ssarray1 = s1.getSamples();
    ssarray3 = s3.getSamples();
 
    
    for ( i = startIndex ; i < endIndex ; ++i )
    {
      value1 = ssarray1[i].getValue();
      
      ssarray3[i - startIndex].setValue(value1);
    }
    
    return s3;
  }
  
  public static Sound joinSounds (Sound s1, Sound s2)
  {
    int l1 = s1.getLength();
    int l2 = s2.getLength();
    int l3 = l1 + l2;   
    
    Sound s3;
    s3 = new Sound (l3);
    
    SoundSample ssarray1[];
    SoundSample ssarray2[];
    SoundSample ssarray3[];
    int largest;
    int value1;
    int value2;
    int value3;
    int  i;
    double mult;
    
    ssarray1 = s1.getSamples();
    ssarray2 = s2.getSamples();
    ssarray3 = s3.getSamples(); 
    
    for ( i = 0 ; i < l1 ; ++i )
    {
      value1 = ssarray1[i].getValue();      
      ssarray3[i].setValue(value1);
    }
    
    for ( i = 0 ; i < l2 ; ++i )
    {
      value2 = ssarray2[i].getValue();      
      ssarray3[i + l1].setValue(value2);
    }
    
    return s3;
  }
} // end of Template class