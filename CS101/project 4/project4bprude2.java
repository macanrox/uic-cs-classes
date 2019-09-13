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
    
    // Have the sound files play by order
    String filename = FileChooser.pickAFile ();
    System.out.println (filename);
    int pos = filename.lastIndexOf (File.separatorChar);
    String temp1 = filename.substring(0, pos+1);
    System.out.println (temp1);
    
    String name1 = temp1 + "spaghetti1.jpg";
    String name2 = temp1 + "pisa1.jpg";
    String name3 = temp1 + "cake1.jpg";
    System.out.println (name1);
    System.out.println (name2);
    System.out.println (name3);
    
    
    // Access and open all sound files
    Sound s1 = new Sound (name1);
    
    Sound s2 = new Sound (name2);
    
    Sound s3 = new Sound (name3);
    
 

    
    
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