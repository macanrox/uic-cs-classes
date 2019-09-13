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
	
	String username = request.getParameter("username");
	String password = request.getParameter("password");
	String name = request.getParameter("name");
	String address = request.getParameter("address");
	long credit_card = Long.parseLong(request.getParameter("credit_card"));
	
	PreparedStatement pst = conn.prepareStatement("INSERT INTO users(type, username, password, name, address, credit_card) VALUES(?, ?, ?, ?, ?, ?)");
	pst.setInt(1, 0);
	pst.setString(2, username);
	pst.setString(3, password);
	pst.setString(4, name);
	pst.setString(5, address);
	pst.setLong(6, credit_card);
	
	int count = pst.executeUpdate();
	
	if(count > 0) {
		response.sendRedirect("http://localhost:8080/bookstore/Login.jsp");
	}
	else {
		out.println("Missing or invalid fields, please try again.");
	}
}//end try
catch(Exception e) {
	out.println(e.toString());
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
		<form action="Registration.jsp" method="post"> 
			<br/>Username: <input type="text" name="username"> 
			<br/>Password: <input type="password" name="password"> 
			<br/>Name: <input type="text" name="name"> 
			<br/>Address: <input type="text" name="address"> 
			<br/>Credit Card: <input type="text" name="cc"> 
			<br/><input type="submit" value="Register"> 
		</form>
		</center> 
	</body> 
</html>