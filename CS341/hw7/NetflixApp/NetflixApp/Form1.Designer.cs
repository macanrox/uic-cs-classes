namespace NetflixApp
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
            this.openDB = new System.Windows.Forms.Button();
            this.addMovie = new System.Windows.Forms.Button();
            this.addReview = new System.Windows.Forms.Button();
            this.avgRating = new System.Windows.Forms.Button();
            this.groupRating = new System.Windows.Forms.Button();
            this.topRateMovies = new System.Windows.Forms.Button();
            this.topUsrs = new System.Windows.Forms.Button();
            this.topRevMovies = new System.Windows.Forms.Button();
            this.addMovieBox = new System.Windows.Forms.TextBox();
            this.reviewRatingBox = new System.Windows.Forms.TextBox();
            this.grpRateBox = new System.Windows.Forms.TextBox();
            this.avgRatingBox = new System.Windows.Forms.TextBox();
            this.topUsersBox = new System.Windows.Forms.TextBox();
            this.resultBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // openDB
            // 
            this.openDB.Location = new System.Drawing.Point(280, 12);
            this.openDB.Name = "openDB";
            this.openDB.Size = new System.Drawing.Size(93, 23);
            this.openDB.TabIndex = 0;
            this.openDB.Text = "Test Connection";
            this.openDB.UseVisualStyleBackColor = true;
            this.openDB.Click += new System.EventHandler(this.openDB_Click);
            // 
            // addMovie
            // 
            this.addMovie.Location = new System.Drawing.Point(280, 58);
            this.addMovie.Name = "addMovie";
            this.addMovie.Size = new System.Drawing.Size(75, 23);
            this.addMovie.TabIndex = 1;
            this.addMovie.Text = "Add Movie";
            this.addMovie.UseVisualStyleBackColor = true;
            this.addMovie.Click += new System.EventHandler(this.addMovie_Click);
            // 
            // addReview
            // 
            this.addReview.Location = new System.Drawing.Point(280, 87);
            this.addReview.Name = "addReview";
            this.addReview.Size = new System.Drawing.Size(75, 23);
            this.addReview.TabIndex = 2;
            this.addReview.Text = "Add Review";
            this.addReview.UseVisualStyleBackColor = true;
            this.addReview.Click += new System.EventHandler(this.addReview_Click);
            // 
            // avgRating
            // 
            this.avgRating.Location = new System.Drawing.Point(280, 150);
            this.avgRating.Name = "avgRating";
            this.avgRating.Size = new System.Drawing.Size(93, 23);
            this.avgRating.TabIndex = 3;
            this.avgRating.Text = "Average Rating";
            this.avgRating.UseVisualStyleBackColor = true;
            this.avgRating.Click += new System.EventHandler(this.avgRating_Click);
            // 
            // groupRating
            // 
            this.groupRating.Location = new System.Drawing.Point(280, 179);
            this.groupRating.Name = "groupRating";
            this.groupRating.Size = new System.Drawing.Size(93, 23);
            this.groupRating.TabIndex = 4;
            this.groupRating.Text = "Group by Rating";
            this.groupRating.UseVisualStyleBackColor = true;
            this.groupRating.Click += new System.EventHandler(this.groupRating_Click);
            // 
            // topRateMovies
            // 
            this.topRateMovies.Location = new System.Drawing.Point(280, 256);
            this.topRateMovies.Name = "topRateMovies";
            this.topRateMovies.Size = new System.Drawing.Size(126, 23);
            this.topRateMovies.TabIndex = 5;
            this.topRateMovies.Text = "Top Movies by Rating";
            this.topRateMovies.UseVisualStyleBackColor = true;
            this.topRateMovies.Click += new System.EventHandler(this.topMovies_Click);
            // 
            // topUsrs
            // 
            this.topUsrs.Location = new System.Drawing.Point(280, 227);
            this.topUsrs.Name = "topUsrs";
            this.topUsrs.Size = new System.Drawing.Size(75, 23);
            this.topUsrs.TabIndex = 6;
            this.topUsrs.Text = "Top Users";
            this.topUsrs.UseVisualStyleBackColor = true;
            this.topUsrs.Click += new System.EventHandler(this.topUsrs_Click);
            // 
            // topRevMovies
            // 
            this.topRevMovies.Location = new System.Drawing.Point(280, 285);
            this.topRevMovies.Name = "topRevMovies";
            this.topRevMovies.Size = new System.Drawing.Size(126, 23);
            this.topRevMovies.TabIndex = 7;
            this.topRevMovies.Text = "Top Reviewed Movies";
            this.topRevMovies.UseVisualStyleBackColor = true;
            this.topRevMovies.Click += new System.EventHandler(this.topRevMovies_Click);
            // 
            // addMovieBox
            // 
            this.addMovieBox.Location = new System.Drawing.Point(417, 63);
            this.addMovieBox.Name = "addMovieBox";
            this.addMovieBox.Size = new System.Drawing.Size(172, 20);
            this.addMovieBox.TabIndex = 8;
            this.addMovieBox.TextChanged += new System.EventHandler(this.userMovie_TextChanged);
            // 
            // reviewRatingBox
            // 
            this.reviewRatingBox.Location = new System.Drawing.Point(417, 89);
            this.reviewRatingBox.Name = "reviewRatingBox";
            this.reviewRatingBox.Size = new System.Drawing.Size(66, 20);
            this.reviewRatingBox.TabIndex = 9;
            // 
            // grpRateBox
            // 
            this.grpRateBox.Location = new System.Drawing.Point(417, 184);
            this.grpRateBox.Name = "grpRateBox";
            this.grpRateBox.Size = new System.Drawing.Size(172, 20);
            this.grpRateBox.TabIndex = 11;
            // 
            // avgRatingBox
            // 
            this.avgRatingBox.Location = new System.Drawing.Point(417, 152);
            this.avgRatingBox.Name = "avgRatingBox";
            this.avgRatingBox.Size = new System.Drawing.Size(172, 20);
            this.avgRatingBox.TabIndex = 12;
            // 
            // topUsersBox
            // 
            this.topUsersBox.Location = new System.Drawing.Point(417, 227);
            this.topUsersBox.Name = "topUsersBox";
            this.topUsersBox.Size = new System.Drawing.Size(66, 20);
            this.topUsersBox.TabIndex = 13;
            // 
            // resultBox
            // 
            this.resultBox.Location = new System.Drawing.Point(12, 12);
            this.resultBox.Multiline = true;
            this.resultBox.Name = "resultBox";
            this.resultBox.Size = new System.Drawing.Size(231, 296);
            this.resultBox.TabIndex = 10;
            this.resultBox.TextChanged += new System.EventHandler(this.listBox_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(601, 320);
            this.Controls.Add(this.topUsersBox);
            this.Controls.Add(this.avgRatingBox);
            this.Controls.Add(this.grpRateBox);
            this.Controls.Add(this.resultBox);
            this.Controls.Add(this.reviewRatingBox);
            this.Controls.Add(this.addMovieBox);
            this.Controls.Add(this.topRevMovies);
            this.Controls.Add(this.topUsrs);
            this.Controls.Add(this.topRateMovies);
            this.Controls.Add(this.groupRating);
            this.Controls.Add(this.avgRating);
            this.Controls.Add(this.addReview);
            this.Controls.Add(this.addMovie);
            this.Controls.Add(this.openDB);
            this.Name = "Form1";
            this.Text = "Netflix";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button openDB;
        private System.Windows.Forms.Button addMovie;
        private System.Windows.Forms.Button addReview;
        private System.Windows.Forms.Button avgRating;
        private System.Windows.Forms.Button groupRating;
        private System.Windows.Forms.Button topRateMovies;
        private System.Windows.Forms.Button topUsrs;
        private System.Windows.Forms.Button topRevMovies;
        private System.Windows.Forms.TextBox addMovieBox;
        private System.Windows.Forms.TextBox reviewRatingBox;
        private System.Windows.Forms.TextBox grpRateBox;
        private System.Windows.Forms.TextBox avgRatingBox;
        private System.Windows.Forms.TextBox topUsersBox;
        private System.Windows.Forms.TextBox resultBox;
    }
}

