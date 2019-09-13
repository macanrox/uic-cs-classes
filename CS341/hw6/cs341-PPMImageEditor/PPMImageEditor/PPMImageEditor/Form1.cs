using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.FSharp.Collections;

namespace PPMImageEditor
{
	public partial class Form1 : Form
	{
    //
    // Current image being displayed:
    //
    private PixelMap CurrentImage;

		public Form1()
		{
			InitializeComponent();
		}


    // 
    // Exit:
		private void cmdExit_Click(object sender, EventArgs e)
		{
			this.Close();
		}

    
    //
    // Open:
    //
		private void cmdOpen_Click(object sender, EventArgs e)
		{
			openFileDialog1.Filter = "PPM Files (*.ppm)|*.ppm|All files (*.*)|*.*";
			openFileDialog1.FileName = "";
			openFileDialog1.CheckFileExists = true;
			openFileDialog1.InitialDirectory = System.Environment.CurrentDirectory;

			DialogResult dr = openFileDialog1.ShowDialog();

			if (dr == System.Windows.Forms.DialogResult.OK)
			{
				string filepath = openFileDialog1.FileName;

        CurrentImage = new PixelMap(filepath);
        picImage.Image = CurrentImage.BitMap;

        // enable the other buttons so user can manipulate image:
        cmdFS1.Enabled = true;
        cmdSaveAs.Enabled = true;
			}
			else
			{
				MessageBox.Show("canceled...");
			}
		}//cmdOpen


    //
    // Test F#:
    //
    private void cmdFS1_Click(object sender, EventArgs e)
    {
      if (CurrentImage == null)  // sanity check: make sure we have an image to manipulate
        return;

      //
      // Example of calling library, which then dumps data about the given image
      // to Visual Studio's "Output" window.  Note you must run with debugging (F5)
      // in order to see the output.
      //
      //PPMImageLibrary.DebugOutput(
      //  CurrentImage.Header.Width,
      //  CurrentImage.Header.Height, 
      //  CurrentImage.Header.Depth,
      //  CurrentImage.ImageListData
      //);

      //
      // we have an image, perform transformation and display new result:
      //
      FSharpList<FSharpList<int>> newImageList;

      newImageList = PPMImageLibrary.TransformFirstRowWhite(
        CurrentImage.Header.Depth,
        CurrentImage.ImageListData
      );

      //
      // create a new PixelMap here on the client-side, which creates a new bitmap
      // we then display to the user:
      //
      CurrentImage = new PixelMap(newImageList);
      picImage.Image = CurrentImage.BitMap;
    }//cmdFS1


    //
    // Save as:
    //
    private void cmdSaveAs_Click(object sender, EventArgs e)
    {
      if (CurrentImage == null)  // sanity check: make sure we have an image to save
        return;

      saveFileDialog1.Filter = "PPM Files (*.ppm)|*.ppm";
      saveFileDialog1.DefaultExt = "ppm";
      saveFileDialog1.FileName = "";
      saveFileDialog1.InitialDirectory = System.Environment.CurrentDirectory;

      DialogResult dr = saveFileDialog1.ShowDialog();

      if (dr == System.Windows.Forms.DialogResult.OK)
      {
        string filepath = saveFileDialog1.FileName;

        bool written = PPMImageLibrary.WriteP3Image(
          filepath,
          CurrentImage.Header.Width,
          CurrentImage.Header.Height,
          CurrentImage.Header.Depth,
          CurrentImage.ImageListData
        );

        if (!written)
          MessageBox.Show("Write failed?!");
      }
      else
      {
        MessageBox.Show("canceled...");
      }
    }

    //
    // Write P3 
    //
    private void writeP3_Click(object sender, EventArgs e)
    {
        if (CurrentImage == null)  // sanity check: make sure we have an image to save
            return;

        saveFileDialog1.Filter = "PPM Files (*.ppm)|*.ppm";
        saveFileDialog1.DefaultExt = "ppm";
        saveFileDialog1.FileName = "";
        saveFileDialog1.InitialDirectory = System.Environment.CurrentDirectory;

        DialogResult dr = saveFileDialog1.ShowDialog();

        if (dr == System.Windows.Forms.DialogResult.OK)
        {
            string filepath = saveFileDialog1.FileName;

            bool written = PPMImageLibrary.WriteP3Image(
              filepath,
              CurrentImage.Header.Width,
              CurrentImage.Header.Height,
              CurrentImage.Header.Depth,
              CurrentImage.ImageListData
            );

            if (!written)
                MessageBox.Show("Write failed?!");
        }
        else
        {
            MessageBox.Show("canceled...");
        }
    }

    private void grayscale_Click(object sender, EventArgs e)
    {
      if (CurrentImage == null)  // sanity check: make sure we have an image to manipulate
        return;

      //
      // Example of calling library, which then dumps data about the given image
      // to Visual Studio's "Output" window.  Note you must run with debugging (F5)
      // in order to see the output.
      //
      //PPMImageLibrary.DebugOutput(
      //  CurrentImage.Header.Width,
      //  CurrentImage.Header.Height, 
      //  CurrentImage.Header.Depth,
      //  CurrentImage.ImageListData
      //);

      //
      // we have an image, perform transformation and display new result:
      //
      FSharpList<FSharpList<int>> newImageList;

      newImageList = PPMImageLibrary.TransformGrayscale(
        CurrentImage.ImageListData
      );

      //
      // create a new PixelMap here on the client-side, which creates a new bitmap
      // we then display to the user:
      //
      CurrentImage = new PixelMap(newImageList);
      picImage.Image = CurrentImage.BitMap;
    }//grayscale

    private void invert_Click(object sender, EventArgs e)
    {
      if (CurrentImage == null)  // sanity check: make sure we have an image to manipulate
        return;

      //
      // Example of calling library, which then dumps data about the given image
      // to Visual Studio's "Output" window.  Note you must run with debugging (F5)
      // in order to see the output.
      //
      //PPMImageLibrary.DebugOutput(
      //  CurrentImage.Header.Width,
      //  CurrentImage.Header.Height, 
      //  CurrentImage.Header.Depth,
      //  CurrentImage.ImageListData
      //);

      //
      // we have an image, perform transformation and display new result:
      //
      FSharpList<FSharpList<int>> newImageList;

      newImageList = PPMImageLibrary.TransformInvert(
        CurrentImage.Header.Depth,
        CurrentImage.ImageListData
      );

      //
      // create a new PixelMap here on the client-side, which creates a new bitmap
      // we then display to the user:
      //
      CurrentImage = new PixelMap(newImageList);
      picImage.Image = CurrentImage.BitMap;
    }//invert

    private void flipHorizontal_Click(object sender, EventArgs e)
    {
        if (CurrentImage == null)  // sanity check: make sure we have an image to manipulate
            return;

        //
        // Example of calling library, which then dumps data about the given image
        // to Visual Studio's "Output" window.  Note you must run with debugging (F5)
        // in order to see the output.
        //
        //PPMImageLibrary.DebugOutput(
        //  CurrentImage.Header.Width,
        //  CurrentImage.Header.Height, 
        //  CurrentImage.Header.Depth,
        //  CurrentImage.ImageListData
        //);

        //
        // we have an image, perform transformation and display new result:
        //
        FSharpList<FSharpList<int>> newImageList;

        newImageList = PPMImageLibrary.TransformFlipHorizontal(
          CurrentImage.ImageListData
        );

        //
        // create a new PixelMap here on the client-side, which creates a new bitmap
        // we then display to the user:
        //
        CurrentImage = new PixelMap(newImageList);
        picImage.Image = CurrentImage.BitMap;
    }//invert

    private void flipVertical_Click(object sender, EventArgs e)
    {
        if (CurrentImage == null)  // sanity check: make sure we have an image to manipulate
            return;

        //
        // Example of calling library, which then dumps data about the given image
        // to Visual Studio's "Output" window.  Note you must run with debugging (F5)
        // in order to see the output.
        //
        //PPMImageLibrary.DebugOutput(
        //  CurrentImage.Header.Width,
        //  CurrentImage.Header.Height, 
        //  CurrentImage.Header.Depth,
        //  CurrentImage.ImageListData
        //);

        //
        // we have an image, perform transformation and display new result:
        //
        FSharpList<FSharpList<int>> newImageList;

        newImageList = PPMImageLibrary.TransformFlipVertical(
          CurrentImage.ImageListData
        );

        //
        // create a new PixelMap here on the client-side, which creates a new bitmap
        // we then display to the user:
        //
        CurrentImage = new PixelMap(newImageList);
        picImage.Image = CurrentImage.BitMap;
    }//invert



	}//class
}//namespace
