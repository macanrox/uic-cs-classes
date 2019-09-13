//
// Data Access Tier:  interface between business tier and database.
//

using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlServerCe;

using System.Windows.Forms; //for debugging

namespace DataAccessTier
{

    class Data
    {
        //
        // Fields:
        //
        private string _DBFile;

        //
        // constructor:
        //
        public Data(string DatabaseFilename)
        {
            _DBFile = DatabaseFilename;
        }

        //
        // TestConnection:  returns true if the database can be successfully opened and closed,
        // false if not.
        //
        public bool TestConnection()
        {
            string connectionInfo = "Data Source = " + _DBFile + "";
            using (SqlCeConnection db = new SqlCeConnection(connectionInfo))
            {
                try
                {
                    db.Open();
                    return true;
                }
                catch (SqlCeException)
                {
                    return false;
                }
            }
        }

        //
        // ExecuteScalarQuery:  executes a scalar Select query, returning the single result 
        // as an object.  
        //
        public object ExecuteScalarQuery(string sql)
        {
            string connectionInfo = "Data Source = " + _DBFile + "";
            SqlCeConnection db = new SqlCeConnection(connectionInfo);

            db.Open();    //open connection

            SqlCeCommand cmd = new SqlCeCommand();
            cmd.Connection = db;
            cmd.CommandText = sql;
            object result = cmd.ExecuteScalar();

            //MessageBox.Show("DataAccessTier sql: " +sql); //debugging

            db.Close();   //close connection

            return result;
        }

        // 
        // ExecuteNonScalarQuery:  executes a Select query that generates a temporary table,
        // returning this table in the form of a Dataset.
        //
        public DataSet ExecuteNonScalarQuery(string sql)
        {
            DataSet ds = new DataSet();
  
            string connectionInfo = "Data Source = " + _DBFile + "";
            SqlCeConnection db = new SqlCeConnection(connectionInfo);
            db.Open();

            SqlCeCommand cmd = new SqlCeCommand();
            cmd.Connection = db;
            SqlCeDataAdapter adapter = new SqlCeDataAdapter(cmd);
            cmd.CommandText = sql;
            adapter.Fill(ds);

            db.Close();

            return ds;
        }

        //
        // ExecutionActionQuery:  executes an Insert, Update or Delete query, and returns
        // the number of records modified.
        //
        public int ExecuteActionQuery(string sql)
        {
            int rowsModified = 0;

            //
            // TODO:
            //

            return rowsModified;
        }

    }//class

}//namespace
