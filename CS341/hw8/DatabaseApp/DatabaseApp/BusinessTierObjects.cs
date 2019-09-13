//
// BusinessTier:  business objects, acting as data transfer objects between UI and business tier.
//

using System;
using System.Collections.Generic;


namespace BusinessTier
{

  //
  // Movie:
  //
  class Movie
  {
    //
    // Fields:
    //
    private int _MovieID;
    private string _MovieName;
    private Reviews _MovieReviews;

    //
    // Properties:
    //
    public int MovieID
    {
      get
      {
        return _MovieID;
      }
      private set
      {
        _MovieID = value;
      }
    }

    public String MovieName
    {
      get
      {
        return _MovieName;
      }
      private set
      {
        _MovieName = value;
      }
    }

    public Reviews MovieReviews
    {
      get
      {
        return _MovieReviews;
      }
      private set
      {
        _MovieReviews = value;
      }
    }

    public double AvgRating
    {
      get
      {
        return MovieReviews.AvgRating;
      }
    }

    public int NumReviews
    {
      get
      {
        return MovieReviews.NumReviews;
      }
    }

    //
    // constructor:
    //
    public Movie(int movieid, string moviename, Reviews reviews)
    {
      MovieID = movieid;
      MovieName = moviename;
      MovieReviews = reviews;
    }

  }//class


  //
  // Review:
  //
  class Review
  {
    //
    // Fields:
    //
    private int _ReviewID;
    private int _MovieID;
    private int _UserID;
    private int _Rating;

    //
    // Properties:
    //
    public int ReviewID
    {
      get
      {
        return _ReviewID;
      }
      private set
      {
        _ReviewID = value;
      }
    }


    public int MovieID
    {
      get
      {
        return _MovieID;
      }
      private set
      {
        _MovieID = value;
      }
    }

    public int UserID
    {
      get
      {
        return _UserID;
      }
      private set
      {
        _UserID = value;
      }
    }

    public int Rating
    {
      get
      {
        return _Rating;
      }
      private set
      {
        _Rating = value;
      }
    }

    //
    // constructor:
    //
    public Review(int reviewid, int movieid, int userid, int rating)
    {
      ReviewID = reviewid;
      MovieID = movieid;
      UserID = userid;
      Rating = rating;
    }

  }//class


  //
  // User:
  //
  class User
  {
    //
    // Fields:
    //
    private int _UserID;
    private int _NumReviews;

    //
    // Properties:
    //
    public int UserID
    {
      get
      {
        return _UserID;
      }
      private set
      {
        _UserID = value;
      }
    }

    public int NumReviews
    {
      get
      {
        return _NumReviews;
      }
      private set
      {
        _NumReviews = value;
      }
    }

    //
    // constructor:
    //
    public User(int userid, int numreviews)
    {
      UserID = userid;
      NumReviews = numreviews;
    }

  }//class


  //
  // Movies:
  //
  class Movies : List<Movie>  // inherits from or "is-a" list of Movie objects
  {
  }


  //
  // Reviews:
  //
  class Reviews : List<Review>  // inherits from or "is-a" list of Review objects
  {

    //
    // Properties:
    //
    public int NumReviews
    {
      get
      {
        return this.Count;
      }
    }

    public double AvgRating
    {
      get
      {
        if (this.Count == 0)
        {
          return 0.0;
        }
        else  // compute from set of reviews in *this* list:
        {
          double sum = 0;

          foreach (Review r in this)
            sum = sum + r.Rating;

          return sum / this.Count;
        }
      }
    }

  }//class


  //
  // Users:
  //
  class Users : List<User>  // inherits from or "is-a" list of User objects
  {
  }

}//namespace
