//
// BusinessTier:  business logic, acting as interface between UI and data store.
//

using System;
using System.Collections.Generic;
using System.Data;

using System.Windows.Forms; //for debugging

namespace BusinessTier
{

    //
    // Business:
    //
    class Business
    {
        //
        // Fields:
        //
        private string _DBFile;
        private DataAccessTier.Data datatier;

        //
        // Constructor:
        //
        public Business(string DatabaseFilename)
        {
            _DBFile = DatabaseFilename;

            datatier = new DataAccessTier.Data(_DBFile); //call new instance
            bool test = datatier.TestConnection();    //test connection

        }

        //
        // Methods:
        //
        public bool TestConnection()
        {
            return datatier.TestConnection();
        }

        public bool AddMovie(string MovieName)
        {
            string sql = "SELECT COUNT(*) FROM Movies";
            object result = datatier.ExecuteScalarQuery(sql);
            int temp = Convert.ToInt32(result) + 1; //take the max and add 1

            sql = "INSERT INTO Movies(MovieID, MovieName) Values(" + temp.ToString() + ",'" + MovieName + "')";
            datatier.ExecuteNonScalarQuery(sql);

            return true;
        }//end AddMovie

        public bool AddReview(int MovieID, int UserID, int Rating)
        {
            string sql = "SELECT MovieID FROM Movies WHERE MovieName =" + MovieID;
            object result = datatier.ExecuteNonScalarQuery(sql);


            sql = "INSERT INTO REVIEWS(MovieID, UserID, Rating) Values(" + Convert.ToInt32(result.ToString()) + ", '" + UserID + "','" + Rating + "')";
            datatier.ExecuteNonScalarQuery(sql);
            return true;
        }//end AddReview

        public bool AddReview(string MovieName, int UserID, int Rating)
        {
            string sql = "SELECT MovieID FROM Movies WHERE MovieName ='" + MovieName + "'";
            object result = datatier.ExecuteScalarQuery(sql);

            sql = "INSERT INTO REVIEWS(MovieID, UserID, Rating) Values(" + result.ToString() + ", '" + UserID + "','" + Rating + "')";
            datatier.ExecuteNonScalarQuery(sql);
            return true;
        }//end AddReview

        public Movie GetMovie(int MovieID)
        {
            Movie m;

            string sql = string.Format("SELECT MovieName FROM Movies WHERE MovieID = {0};", MovieID);    //grab entry
            object result = datatier.ExecuteScalarQuery(sql); //get the result of string
            string movieName = result.ToString(); //get string from object

            m = new Movie(MovieID, movieName, GetReviews(MovieID));

            return m;
        }//end GetMovie

        public Movie GetMovie(string MovieName)
        {
            Movie m;

            string sql = string.Format("SELECT MovieName FROM Movies;", MovieName);    //grab entry
            object result = datatier.ExecuteScalarQuery(sql); //get the result of string
            int movieID = int.Parse(result.ToString()); //get integer from object

            m = new Movie(movieID, MovieName, GetReviews(MovieName));

            return m;
        }//end GetMovie

        public Reviews GetReviews(int MovieID)
        {
            Reviews reviews = new Reviews();
            datatier = new DataAccessTier.Data(_DBFile);

            //read user input
            string sql = string.Format(@"SELECT UserID, Rating, ReviewID
            FROM Reviews
            WHERE MovieID={0}
            ORDER BY Rating Desc, UserID ASC;", MovieID);    //grab query
            DataSet result = datatier.ExecuteNonScalarQuery(sql);  //get result of string

            //grab dataset
            DataTable dt = result.Tables["TABLE"];    //temp table

            foreach (DataRow row in dt.Rows)
            {
                int userID = Convert.ToInt32(row["UserID"]);
                int ratings = Convert.ToInt32(row["Rating"]);
                int reviewID = Convert.ToInt32(row["ReviewID"]);
                reviewID++;

                reviews.Add(new Review(reviewID, MovieID, userID, ratings));
            }

            return reviews;
        }//end GetReviews

        public Reviews GetReviews(string MovieName)
        {
            Reviews reviews = new Reviews();
            datatier = new DataAccessTier.Data(_DBFile);

            string sql1 = "SELECT MovieID FROM Movies WHERE MovieName = '" + MovieName + "'";
            object mid = datatier.ExecuteScalarQuery(sql1);
            int MovieID = Convert.ToInt32(mid);

            //read user input
            string sql = string.Format(@"SELECT UserID, Rating, ReviewID
            FROM Reviews
            WHERE MovieID={0}
            ORDER BY Rating Desc, UserID ASC;", MovieID);    //grab query
            DataSet result = datatier.ExecuteNonScalarQuery(sql);  //get result of string

            //grab dataset
            DataTable dt = result.Tables["TABLE"];    //temp table

            foreach (DataRow row in dt.Rows)
            {
                int userID = Convert.ToInt32(row["UserID"]);
                int ratings = Convert.ToInt32(row["Rating"]);
                int reviewID = Convert.ToInt32(row["ReviewID"]);
                reviewID++;

                reviews.Add(new Review(reviewID, MovieID, userID, ratings));
            }

            return reviews;
        }//end GetReviews

        //
        // Get Top Movies By Average Rating:
        // Group all the reviews for each movie, compute averages, and take top N (user input)
        //
        public Movies GetTopMoviesByAvgRating(int N)
        {
            Movies movies = new Movies();

            //
            // TODO:
            //

            //parameter Movie( int MovieID, stringMovieName, getReviews(int Movie ID))
            movies.Add(new Movie(124, "The Seventh Seal", GetReviews(124)));

            return movies;
        }//end GetTopMoviesByAvgRating

        public Movies GetTopMoviesByNumReviews(int N)
        {
            Movies movies = new Movies();

            //
            // TODO:
            //        
            //Debugging
            movies.Add(new Movie(124, "The Seventh Seal", GetReviews(124)));

            return movies;
        }

        public Users GetTopUsersByNumReviews(int N)
        {
            Users users = new Users();

            //
            // TODO:
            //
            users.Add(new User(-1, -1));

            return users;
        }

    }//class

}//namespace
