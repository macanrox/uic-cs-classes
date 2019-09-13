<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@page import ="java.util.regex.*" %>
<%@page import ="java.security.MessageDigest" %>
<%@ include file="index.jsp" %>

<%
String user=(String)session.getAttribute("user");
int userType = (Integer)session.getAttribute("type");
			
if(userType != 1){
	response.sendRedirect("http://localhost:8080/bookstore/401.jsp");
}
else if(user==null){
	response.sendRedirect("http://localhost:8080/bookstore/Login.jsp");
}
%>
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
	
	if((password.length()<8) || (m.matches()==false)){
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
			response.sendRedirect("http://localhost:8080/bookstore/UserManagement.jsp");
			out.println("User successfully added!");
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
		<div align="right" id="navigation">
			<a href="#"><%=user %></a>
			</br>
			<form action="Logout.jsp" method="post">
				<input type="submit" value="logout">
			</form>
		</div>
		<div align="left">
			<br/>
			<table border="1">
				<thead>
					<th><h4>Navigation</h4></th>
				</thead>
				<tbody>
					<tr>
						<td align="center"><a href="http://localhost:8080/bookstore/UserManagement.jsp">User Management</a></td>
					</tr>
					<tr>
						<td align="center"><a href="http://localhost:8080/bookstore/Statistics.jsp">Statistics</a></td>
					</tr>
				</tbody>
			</table>
		</div>
		<br/>
		<h2>Add User</h2>
		<form action="RegistrationAdministrator.jsp" method="post"> 
			Username: <input type="text" name="username"> 
			<br/>Password: <input type="password" name="password"> 
			<br/>Name: <input type="text" name="name"> 
			<br/>Address: <input type="text" name="address"> 
			<br/>Credit Card: <input type="text" name="cc"> 
			<br/>
			<br/><input type="submit" value="Register"> 
			<button type="submit" formaction="http://localhost:8080/bookstore/UserManagement.jsp">Back</button>
		</form>
		</center> 
	</body> 
</html>