namespace PPMImageEditor
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            this.picImage = new System.Windows.Forms.PictureBox();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.cmdOpen = new System.Windows.Forms.Button();
            this.cmdSaveAs = new System.Windows.Forms.Button();
            this.cmdExit = new System.Windows.Forms.Button();
            this.cmdFS1 = new System.Windows.Forms.Button();
            this.writeP3 = new System.Windows.Forms.Button();
            this.grayscale = new System.Windows.Forms.Button();
            this.invert = new System.Windows.Forms.Button();
            this.flipHorizontal = new System.Windows.Forms.Button();
            this.flipVertical = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.picImage)).BeginInit();
            this.SuspendLayout();
            // 
            // picImage
            // 
            this.picImage.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.picImage.BackColor = System.Drawing.Color.Aqua;
            this.picImage.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.picImage.Location = new System.Drawing.Point(170, 15);
            this.picImage.Margin = new System.Windows.Forms.Padding(6);
            this.picImage.Name = "picImage";
            this.picImage.Size = new System.Drawing.Size(400, 394);
            this.picImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picImage.TabIndex = 0;
            this.picImage.TabStop = false;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // cmdOpen
            // 
            this.cmdOpen.Location = new System.Drawing.Point(15, 15);
            this.cmdOpen.Margin = new System.Windows.Forms.Padding(6);
            this.cmdOpen.Name = "cmdOpen";
            this.cmdOpen.Size = new System.Drawing.Size(129, 35);
            this.cmdOpen.TabIndex = 1;
            this.cmdOpen.Text = "Open...";
            this.cmdOpen.UseVisualStyleBackColor = true;
            this.cmdOpen.Click += new System.EventHandler(this.cmdOpen_Click);
            // 
            // cmdSaveAs
            // 
            this.cmdSaveAs.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.cmdSaveAs.Enabled = false;
            this.cmdSaveAs.Location = new System.Drawing.Point(15, 327);
            this.cmdSaveAs.Margin = new System.Windows.Forms.Padding(6);
            this.cmdSaveAs.Name = "cmdSaveAs";
            this.cmdSaveAs.Size = new System.Drawing.Size(129, 35);
            this.cmdSaveAs.TabIndex = 2;
            this.cmdSaveAs.Text = "Save as...";
            this.cmdSaveAs.UseVisualStyleBackColor = true;
            this.cmdSaveAs.Click += new System.EventHandler(this.cmdSaveAs_Click);
            // 
            // cmdExit
            // 
            this.cmdExit.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.cmdExit.Location = new System.Drawing.Point(15, 374);
            this.cmdExit.Margin = new System.Windows.Forms.Padding(6);
            this.cmdExit.Name = "cmdExit";
            this.cmdExit.Size = new System.Drawing.Size(129, 35);
            this.cmdExit.TabIndex = 3;
            this.cmdExit.Text = "Exit";
            this.cmdExit.UseVisualStyleBackColor = true;
            this.cmdExit.Click += new System.EventHandler(this.cmdExit_Click);
            // 
            // cmdFS1
            // 
            this.cmdFS1.Enabled = false;
            this.cmdFS1.Location = new System.Drawing.Point(15, 62);
            this.cmdFS1.Margin = new System.Windows.Forms.Padding(6);
            this.cmdFS1.Name = "cmdFS1";
            this.cmdFS1.Size = new System.Drawing.Size(129, 35);
            this.cmdFS1.TabIndex = 4;
            this.cmdFS1.Text = "Test F#";
            this.cmdFS1.UseVisualStyleBackColor = true;
            this.cmdFS1.Click += new System.EventHandler(this.cmdFS1_Click);
            // 
            // writeP3
            // 
            this.writeP3.Location = new System.Drawing.Point(15, 98);
            this.writeP3.Margin = new System.Windows.Forms.Padding(6);
            this.writeP3.Name = "writeP3";
            this.writeP3.Size = new System.Drawing.Size(129, 35);
            this.writeP3.TabIndex = 10;
            this.writeP3.Text = "Write P3";
            this.writeP3.UseVisualStyleBackColor = true;
            this.writeP3.Click += new System.EventHandler(this.writeP3_Click);
            // 
            // grayscale
            // 
            this.grayscale.Location = new System.Drawing.Point(15, 135);
            this.grayscale.Margin = new System.Windows.Forms.Padding(6);
            this.grayscale.Name = "grayscale";
            this.grayscale.Size = new System.Drawing.Size(129, 35);
            this.grayscale.TabIndex = 12;
            this.grayscale.Text = "Grayscale";
            this.grayscale.UseVisualStyleBackColor = true;
            this.grayscale.Click += new System.EventHandler(this.grayscale_Click);
            // 
            // invert
            // 
            this.invert.Location = new System.Drawing.Point(15, 173);
            this.invert.Margin = new System.Windows.Forms.Padding(6);
            this.invert.Name = "invert";
            this.invert.Size = new System.Drawing.Size(129, 35);
            this.invert.TabIndex = 13;
            this.invert.Text = "Invert";
            this.invert.UseVisualStyleBackColor = true;
            this.invert.Click += new System.EventHandler(this.invert_Click);
            // 
            // flipHorizontal
            // 
            this.flipHorizontal.Location = new System.Drawing.Point(15, 210);
            this.flipHorizontal.Margin = new System.Windows.Forms.Padding(6);
            this.flipHorizontal.Name = "flipHorizontal";
            this.flipHorizontal.Size = new System.Drawing.Size(129, 66);
            this.flipHorizontal.TabIndex = 14;
            this.flipHorizontal.Text = "Flip Horizontally";
            this.flipHorizontal.UseVisualStyleBackColor = true;
            this.flipHorizontal.Click += new System.EventHandler(this.flipHorizontal_Click);
            // 
            // flipVertical
            // 
            this.flipVertical.Location = new System.Drawing.Point(15, 278);
            this.flipVertical.Margin = new System.Windows.Forms.Padding(6);
            this.flipVertical.Name = "flipVertical";
            this.flipVertical.Size = new System.Drawing.Size(129, 37);
            this.flipVertical.TabIndex = 15;
            this.flipVertical.Text = "Flip Vertically";
            this.flipVertical.UseVisualStyleBackColor = true;
            this.flipVertical.Click += new System.EventHandler(this.flipVertical_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(11F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Yellow;
            this.ClientSize = new System.Drawing.Size(592, 426);
            this.Controls.Add(this.flipVertical);
            this.Controls.Add(this.flipHorizontal);
            this.Controls.Add(this.invert);
            this.Controls.Add(this.grayscale);
            this.Controls.Add(this.writeP3);
            this.Controls.Add(this.cmdFS1);
            this.Controls.Add(this.cmdExit);
            this.Controls.Add(this.cmdSaveAs);
            this.Controls.Add(this.cmdOpen);
            this.Controls.Add(this.picImage);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(6);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "PPM Image Editor";
            ((System.ComponentModel.ISupportInitialize)(this.picImage)).EndInit();
            this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.PictureBox picImage;
		private System.Windows.Forms.OpenFileDialog openFileDialog1;
		private System.Windows.Forms.SaveFileDialog saveFileDialog1;
		private System.Windows.Forms.Button cmdOpen;
		private System.Windows.Forms.Button cmdSaveAs;
		private System.Windows.Forms.Button cmdExit;
        private System.Windows.Forms.Button cmdFS1;
    private System.Windows.Forms.Button writeP3;
    private System.Windows.Forms.Button grayscale;
    private System.Windows.Forms.Button invert;
    private System.Windows.Forms.Button flipHorizontal;
    private System.Windows.Forms.Button flipVertical;
	}
}

