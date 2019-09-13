//
// N-tier Netflix database application.
//
// Bresia Prudente (bprude2), Saleha Amreen (samree2)
// U. of Illinois, Chicago
// CS341, Spring 2014
// Homework 8
//

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DatabaseApp
{
    public partial class Form1 : Form
    {
        //
        // Class members:
        //
        private Random RandomNumberGenerator;
        private BusinessTier.Business businesstier;
        private BusinessTier.Review reviewtier;
        //
        // Constructor:
        //
        public Form1()
        {
            InitializeComponent();

            RandomNumberGenerator = new Random();

            //Create instance of business tier
            businesstier = new BusinessTier.Business(txtFileName.Text);
        }

        //
        // This event is triggered when app starts and window is loaded for first time:
        //
        private void Form1_Load(object sender, EventArgs e)
        {
        }

        //
        // Test Connection:
        //
        private void cmdConnect_Click(object sender, EventArgs e)
        {
            businesstier = new BusinessTier.Business(txtFileName.Text);

            if (businesstier.TestConnection())
                MessageBox.Show("Connection is good!");
            else
                MessageBox.Show("Connection is not good?!?!");
        }

        //
        // Get Movie Name:  from id...
        //
        private void cmdGetMovieName_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            int id = Convert.ToInt32(txtMovieID.Text);  //converts string to integer
            BusinessTier.Movie m = businesstier.GetMovie(id);

            if (m == null)
                listBox1.Items.Add("Movie not found...");
            else
                listBox1.Items.Add(m.MovieName);
        }

        //
        // Get Movie Reviews: from id...
        //
        private void cmdGetMovieReviews_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            int id = Convert.ToInt32(txtMovieID.Text);  //converts string to integer
            BusinessTier.Reviews review = businesstier.GetReviews(id);

            foreach (BusinessTier.Review row in review)
            {

                listBox1.Items.Add(row.UserID + ":" + row.Rating);
            }
        }

        //
        // Average Rating:
        //
        private void cmdAvgRating_Click(object sender, EventArgs e)
        {

            listBox1.Items.Clear();
            double a, b, average;
            a = 0.0;
            b = 0.0;
            average = 0.0;

            BusinessTier.Reviews review = businesstier.GetReviews(txtRatingsMovieName.Text);
            //BsuinessTier.Review
            foreach (BusinessTier.Review row in review)
            {
                a++; // length  of db
                b += row.Rating;
            }
            average = b / a;
            listBox1.Items.Add("Average rating: " + average);

        }

        //
        // Each Rating:
        //
        private void cmdEachRating_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            int r5 = 0;
            int r4 = 0;
            int r3 = 0;
            int r2 = 0;
            int r1 = 0;
            int total = 0;

            BusinessTier.Reviews review = businesstier.GetReviews(txtRatingsMovieName.Text);

            foreach (BusinessTier.Review row in review)
            {
                if (row.Rating == 5) { r5++; }
                if (row.Rating == 4) { r4++; }
                if (row.Rating == 3) { r3++; }
                if (row.Rating == 2) { r2++; }
                if (row.Rating == 1) { r1++; }

            }
            total = r5 + r4 + r3 + r2 + r1;
            listBox1.Items.Add("5: " + r5);
            listBox1.Items.Add("4: " + r4);
            listBox1.Items.Add("3: " + r3);
            listBox1.Items.Add("2: " + r2);
            listBox1.Items.Add("1: " + r1);
            listBox1.Items.Add("Total:" + total);

        }

        //
        // Add movie:
        //
        private void cmdInsertMovie_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            Boolean newMovie = businesstier.AddMovie(this.txtInsertMovieName.Text);
            listBox1.Items.Add("New Movie Added!");

        }

        private void tbarRating_Scroll(object sender, EventArgs e)
        {
            lblRating.Text = tbarRating.Value.ToString();
        }

        //
        // Add Review:
        //
        private void cmdInsertReview_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            int userid = RandomNumberGenerator.Next(100000, 999999);  // 6-digit user ids:
            int rating = Convert.ToInt32(lblRating.Text);  // 1..5:s

            Boolean m = businesstier.AddReview(txtInsertMovieName.Text, userid, rating);

            listBox1.Items.Add("Review Added!");
        }


        //
        // Top N Movies by Average Rating:
        //
        private void cmdTopMoviesByAvgRating_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            //
            // TODO:
            //
            //string N = txtTopN.Text;
        }

        //
        // Top N Movies by # of reviews:
        //
        private void cmdTopMoviesByNumReviews_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            //
            // TODO:
            //
        }

        //
        // Top N Users by # of reviews:
        //
        private void cmdTopUsers_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            //
            // TODO:
            //
        }

    }//class
}//namespace
