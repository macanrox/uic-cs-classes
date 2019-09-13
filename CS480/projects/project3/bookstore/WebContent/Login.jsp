<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@page import ="java.security.MessageDigest" %>

<%! //this is a declaration tag
	static final String sFileName = "Login.jsp";
	static final String DBDriver  ="com.mysql.jdbc.Driver";
	static final String strConn   ="jdbc:mysql://localhost:3306/bookstore";
	static final String DBusername="root";
	static final String DBpassword="1234";
%>

<%
java.sql.Connection conn = null;
java.sql.Statement st = null;
String directUrl = "http://localhost:8080/bookstore/ShowBooks.jsp";
String directUrlAdmin = "http://localhost:8080/bookstore/AdminHome.jsp";
try {
	String referrerUrl = request.getHeader("referer");
	System.out.println(referrerUrl);
	
	String user = request.getParameter("username");
	session.putValue("user", user);
	String pass = request.getParameter("password");
	
	//hashing password to put into the database
	String tempPass = pass;	//store in a different variable to hash
	MessageDigest md = MessageDigest.getInstance("MD5");
	md.update(tempPass.getBytes());
	byte passToByte[] = md.digest();
	StringBuffer hashPass = new StringBuffer();	//we're using stringbuffer because its faster
	int x;
	for(x=0; x < passToByte.length; x++){
		hashPass.append(Integer.toString((passToByte[x] & 0xff) + 0x100, 16).substring(1));
	}//end for
	System.out.println("Hashed password is: " +hashPass.toString());	//test
	
	Class.forName(DBDriver);
	conn = DriverManager.getConnection(strConn, DBusername, DBpassword);
	st = conn.createStatement();

	PreparedStatement pst = conn.prepareStatement("SELECT type, user_id, username, password FROM Users WHERE username=? AND password=?");
	pst.setString(1, user);
	pst.setString(2, hashPass.toString());
	ResultSet rs = pst.executeQuery();

	if(rs.next()) {
		//HttpSession ss = request.getSession(true);
		session.setAttribute("type", rs.getInt(1));
		session.setAttribute("user_id", rs.getInt(2));
		session.setAttribute("username", rs.getString(3));
		
		//compare the hashed passwords and check if they're the same
		String dbPass = rs.getString("password");
		if(!hashPass.toString().equals(dbPass)){
			out.println("Password is invalid, please try again.");
		}
		
		int type = (Integer)session.getAttribute("type");
		//System.out.println("type = " + type);
		if(type == 0) {
			if(referrerUrl.contains("returnFrom")){
				String redirectTo = referrerUrl.substring(referrerUrl.lastIndexOf("=")+1);
				response.sendRedirect("http://localhost:8080/bookstore/"+redirectTo);
				//System.out.println("http://localhost:8080/bookstore/"+redirectTo);
			}
			else {
				response.sendRedirect(directUrl);
			}
		}
		else {
			response.sendRedirect(directUrlAdmin);
		}
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
		<title>Bookstore Books</title> 
	</head> 
	<body>
		<h1 align="center">Bookstore Books</h1> 
		<h2 align="center">Login</h2>
		<center> 
		<h2>Sign In</h2> 
		<form action="Login.jsp" method="post"> 
			<br/>Username: <input type="text" name="username"> 
			<br/>Password: <input type="password" name="password"> 
			<br/>
			<br/><input type="submit" value="Submit"> 
			<button type="submit" formaction="http://localhost:8080/bookstore/Registration.jsp">Register</button>
		</form>
		</center> 
	</body> 
</html>