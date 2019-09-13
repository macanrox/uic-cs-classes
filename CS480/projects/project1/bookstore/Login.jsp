<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>

<%! //this is a declaration tag
	static final String sFileName = "Login.jsp";
	static final String DBDriver  ="com.mysql.jdbc.Driver";
	static final String strConn   ="jdbc:mysql://localhost:3306/bookstore";
	static final String DBusername="root";
	static final String DBpassword="";
%>

<%
java.sql.Connection conn = null;
java.sql.Statement st = null;
String directUrl = "http://localhost:8080/bookstore/ShowBooks.jsp";
try {
	String user = request.getParameter("username");
	session.putValue("user", user);
	String pass = request.getParameter("password");
	Class.forName(DBDriver);
	conn = DriverManager.getConnection(strConn, DBusername, DBpassword);
	st = conn.createStatement();

	PreparedStatement pst = conn.prepareStatement("SELECT * FROM Users WHERE username=? AND password=?");
	pst.setString(1, user);
	pst.setString(2, pass);
	ResultSet rs = pst.executeQuery();

	if(rs.next()) {
		response.sendRedirect(directUrl);
	}
	else {
		out.println("Invalid login. Please try again.");
	}
}//end try
catch(Exception e) {
	out.println(e.toString());
	//out.println("</br></br><a href='http://localhost:8080/bookstore/Login.html'>Back</a>");
}
%>

<html> 
	<head> 
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"> 
		<title>Bookstore Login</title> 
	</head> 
	<body>
		<h1 align="center">Bookstore</h1> 
		<center> 
		<h2>Sign In</h2> 
		<form action="Login.jsp" method="post"> 
			<br/>Username: <input type="text" name="username"> 
			<br/>Password: <input type="password" name="password"> 
			<br/><input type="submit" value="Submit"> 
		</form> 
		</center> 
	</body> 
</html>