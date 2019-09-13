<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@ include file="index.jsp" %>

<%
java.sql.Connection conn = null;
java.sql.Statement st = null;
try {
	Class.forName(DBDriver);
	conn = DriverManager.getConnection(strConn, DBusername, DBpassword);
	st = conn.createStatement();

	

}//end try
catch(Exception e) {
	out.println(e.toString());
	//out.println("</br></br><a href='http://localhost:8080/bookstore/Login.html'>Back</a>");
}
%>

<html>
	<body>
		<h1>HTTP Error 401</h1>
		<p>You do not have permission to access this page</p>
		<a href="http://localhost:8080/bookstore/ShowBooks.jsp">Back</a>
	</body>
</html>