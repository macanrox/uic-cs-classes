// 
// Netflix database application. 
// 
// Bresia Prudente
// U. of Illinois, Chicago 
// CS341, Spring 2014 
// Homework 7 
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
using System.Data.SqlServerCe;

namespace NetflixApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        //
        //Form window
        //
        private void Form1_Load(object sender, EventArgs e)
        {
             
        }

        //
        //openDB opens and closes connection to database
        //
        private void openDB_Click(object sender, EventArgs e)
        {
            string connectionInfo;
            SqlCeConnection db;

            connectionInfo = "Data Source = Netflix-65k.sdf";
            db = new SqlCeConnection(connectionInfo);

            db.Open();

            //Begin debugging
            string msg = db.State.ToString();
            MessageBox.Show(msg);
            //End debugging            

            db.Close();
        }//end openDB

        //
        //User adds new movie to database
        //
        private void addMovie_Click(object sender, EventArgs e)
        {

            resultBox.Clear();

            //Open the connection
            string connectionInfo = "Data Source = Netflix-65k.sdf";
            SqlCeConnection db = new SqlCeConnection(connectionInfo);
            db.Open();

            SqlCeCommand cmd = new SqlCeCommand();
            SqlCeCommand cmd1 = new SqlCeCommand();
            cmd.Connection = db;

            object value = cmd.ExecuteScalar();
            string val = value.ToString();
            int valID = Convert.ToInt32(val);
            valID = valID + 1;

            MessageBox.Show(valID.ToString);
            string x = valID.ToString();
            string y = addMovie.Text;
            cmd.CommandText = "INSERT INTO MOVIES Values ('" + x + ',' + y + ')";

            resultBox.Clear();

            int id = Convert.ToInt32(addMovieBox.Text);

            var query = from r in NetflixApp.Reviews
                        where r.MovieID = id 
                        //orderby r.Rating descending, r.UserID ascending
                        select new { r.UserID, r.Rating}; 
           
            //Close connection
            db.Close();

        }//end addMovie

        //
        //Allow users to add a review
        //
        private void addReview_Click(object sender, EventArgs e)
        {

            //User can only input integer values of 1-5
            //UserID is optional (if not given, randomize)
            //Report success or failure

            resultBox.Clear();

            //Open the connection
            string connectionInfo = "Data Source = Netflix-65k.sdf";
            SqlCeConnection db = new;
            SqlCeConnection(connectionInfo);
            db.Open();

            SqlCeCommand cmd = new SqlCeCommand();
            SqlCeCommand cmd1 = new SqlCeCommand();
            cmd.Connection = db;
            
            cmd.CommandText = "SELECT MovieID FROM Movies WHERE MovieName = '" +
                reviewRatingBox.Text.ToString() + "';'";

            object exec = cmd.ExecuteScalar();
            int result = Convert.ToInt32(exec);
            cmd.CommandText = "INSERT INTO REVIEWS (MovieID, UserID, Rating)Values(" +result.ToString()+ ","
                + 1499 +"," + resultBox.Text + "')";
            object start = cmd.ExecuteNonQuery();

            MessageBox.Show(cmd.CommandText);   //debugging
            db.Close();

        }

        //
        //Gets an average rating for a movie by user input
        //
        private void avgRating_Click(object sender, EventArgs e)
        {

            resultBox.Clear();

            //Open the connection
            string connectionInfo = "Data Source = Netflix-65k.sdf";
            SqlCeConnection db = new SqlCeConnection(connectionInfo);
            db.Open();

            SqlCeCommand cmd = new SqlCeCommand();
            object exec = cmd.ExecuteScalar();
            SqlCeDataAdapter adapter = new SqlCeDataAdapter(cmd);
            DataSet data = new DataSet();
            string movie = avgRatingBox.Text;

            cmd.CommandText = "SELECT MovieID FROM Movies WHERE MovieName = " +movie + "';'";
            int result = Convert.ToInt32(exec);
            cmd.CommandText = "SELECT ROUND(AVG(CAST(Rating AS Float), 2) FROM Reviews WHERE MovieID = "+result+ "';'";
            
            int rows = cmd.ExecuteNonQuery();
            adapter.Fill(data);
            DataTable dataTable = data.Tables["TABLE"];
            
            if(rows > 0)
                MessageBox("Operation successful!");
            else
                MessageBox("Movie not found!");

            //Close connection
            db.Close();

             foreach (DataRow row in dt.Rows)
                 MessageBox.Show(row["MovieID"] + ":" + row["AvgRating"]);
        }

        //
        //User enters movie name and displays the # of reviews along
        //with the total number of reviews
        //
        private void groupRating_Click(object sender, EventArgs e)
        {
            
            resultBox.Clear();

            //Open the connection
            string connectionInfo = "Data Source = Netflix-65k.sdf";
            SqlCeConnection db = new SqlCeConnection(connectionInfo);
            db.Open();

            SqlCeCommand cmd = new SqlCeCommand();
            SqlCeCommand cmd1 = new SqlCeCommand();
            cmd.Connection = db;

            //Close connection
            db.Close();

        }

        //
        //Displays top N movies by rating
        //
        private void topMovies_Click(object sender, EventArgs e)
        {

            resultBox.Clear();

            //Open the connection
            string connectionInfo = "Data Source = Netflix-65k.sdf";
            SqlCeConnection db = new SqlCeConnection(connectionInfo);
            db.Open();

            SqlCeCommand cmd = new SqlCeCommand();
            SqlCeCommand cmd1 = new SqlCeCommand();
            cmd.Connection = db;

            String SQLGetResults = "SELECT MovieID FROM Movies WHERE MovieName = " + title + "';";

            var query = from r in NetflixApp.Reviews
                        group r by r.MovieID into g
                        select new { MovieID = g.key, avgRating, g.Average( (grp) => grp.Rating) };

            var ordered = from tuple in query
                          join m in NetflixApp.Movies
                          on tuple.MovieID equals m.MovieID
                          orderby tuple.avgRating descending, m.MovieName ascending
                          select new { m.MovieName, tuple.avgRating };

            var top10 = ordered.Take(10);

            foreach (var tuple in top10)
                resultBox.Items.Add(tuple.MovieID + ":" + tuple.avgRating);

            //Close connection
            db.Close();
        }

        //
        //Displays top N users based on # of reviews submitted
        private void topUsrs_Click(object sender, EventArgs e)
        {

            resultBox.Clear();

            //Open the connection
            string connectionInfo = "Data Source = Netflix-65k.sdf";
            SqlCeConnection db = new SqlCeConnection(connectionInfo);
            db.Open();

            SqlCeCommand cmd = new SqlCeCommand();
            SqlCeCommand cmd1 = new SqlCeCommand();
            cmd.Connection = db;

            int id = Convert.ToInt32(topUsersBox.Text);

            var query = from r in NetflixApp.Reviews
                        where r.MovieID = id
                        orderby r.UserID descending, r.Rating
                        select new { r.UserID, r.Rating };

            foreach (var tuple in query)
                resultBox.Items.Add(tuple.UserID + ":" + tuple.Rating);

            //Close connection
            db.Close();
        }

        //
        //Displays top N reviewed movies
        private void topRevMovies_Click(object sender, EventArgs e)
        {
            
            resultBox.Clear();

            //Open the connection
            string connectionInfo = "Data Source = Netflix-65k.sdf";
            SqlCeConnection db = new SqlCeConnection(connectionInfo);
            db.Open();

            SqlCeCommand cmd = new SqlCeCommand();
            SqlCeCommand cmd1 = new SqlCeCommand();
            cmd.Connection = db;

            //Close connection
            db.Close();

        }

        private void listBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void userMovie_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
