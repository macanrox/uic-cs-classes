<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@page import ="java.util.regex.*" %>
<%@page import ="java.security.MessageDigest" %>
<%@ include file="index.jsp" %>

<%
java.sql.Connection conn = null;
java.sql.Statement st = null;
try {
	String username = request.getParameter("username");
	String password = request.getParameter("password");
	String name = request.getParameter("name");
	String address = request.getParameter("address");
	long credit_card = Long.parseLong(request.getParameter("cc"));
	int countCheck = 0;
	String regex = "(?=^.*[a-z0-9].{8,}$)[^,./'!@#$%&*]+$";
	
	//make sure the password contains letters and numbers
	Pattern pattern = Pattern.compile(regex);
	Matcher m = pattern.matcher(password);
	
	//hashing password to put into the database
	String tempPass = password;	//store in a different variable to hash
	MessageDigest md = MessageDigest.getInstance("MD5");
	md.update(tempPass.getBytes());
	byte passToByte[] = md.digest();
	StringBuffer hashPass = new StringBuffer();	//we're using stringbuffer because its faster
	int x;
	for(x=0; x < passToByte.length; x++){
		hashPass.append(Integer.toString((passToByte[x] & 0xff) + 0x100, 16).substring(1));
	}//end for
	//System.out.println("Hashed password is: " +hashPass.toString());	//test
	
	Class.forName(DBDriver);
	conn = DriverManager.getConnection(strConn, DBusername, DBpassword);
	st = conn.createStatement();
	
	PreparedStatement pstmt1 = conn.prepareStatement("SELECT count(username) FROM users WHERE username=?");
	pstmt1.setString(1, username);
	ResultSet rs1 = pstmt1.executeQuery();
	
	while (rs1.next()){
		countCheck = rs1.getInt("count(username)");
	}
	
	if(countCheck > 0) {
		out.println("User already exists. Please try again!");
	}
	else if((password.length()<8) || (m.matches()==false)){
		out.println("The password must be at least 8 characters long, contain at least 1 letter and 1 number, and have no special characters.");
	}
	else {
		PreparedStatement pst = conn.prepareStatement("INSERT INTO users(type, username, password, name, address, credit_card) VALUES(?, ?, ?, ?, ?, ?)");
		pst.setInt(1, 0);
		pst.setString(2, username);
		pst.setString(3, hashPass.toString());
		pst.setString(4, name);
		pst.setString(5, address);
		pst.setLong(6, credit_card);
	
		int count = pst.executeUpdate();
	
		if(count > 0) {
			response.sendRedirect("http://localhost:8080/bookstore/Login.jsp");
			System.out.println("User successfully registered");
		}
		else {
			out.println("Missing or invalid fields, please try again.");
		}
	}//end else			
	
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