<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@page import = "java.util.Date, java.text.DateFormat, java.text.SimpleDateFormat" %>
<%@ include file="index.jsp" %>

<html> 
	<head> 
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"> 
		<title>Bookstore Checkout</title> 
	</head> 
	<body>
		<h1 align="center">Bookstore Books</h1> 
		<h2 align="center">Checkout</h2>
		
		<div align="right" id="navigation">
			<% String username=(String)session.getAttribute("user"); %>
			
			<a href="#"><%=username %></a>
			</br>
			<form action="logout" method="post">
				<input type="submit" value="logout">
			</form>
		</div>
		</br>
		
		<% 
			try {				
				java.sql.Connection conn = null;
	  			java.sql.Statement st = null;
	  			
	  			Class.forName(DBDriver);
				conn = DriverManager.getConnection(strConn, DBusername, DBpassword);
				st = conn.createStatement();
	  			
	  			//get the timestamp for the user
				int user_id = (Integer)session.getAttribute("user_id");
				//DateFormat dateformat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
				Date date = new Date();
				//String datetime = dateformat.format(date);
				//java.sql.Date(date.getTime());
				java.sql.Date sqldate = new java.sql.Date(date.getTime());
	  			
	  			PreparedStatement pstmt1 = conn.prepareStatement("SELECT * FROM orders WHERE user_id=?");
	  			pstmt1.setInt(1, user_id);
	  			ResultSet rs1 = pstmt1.executeQuery();
	  			
	  			while(rs1.next()){
	  				int order_id = rs1.getInt("order_id");
	  				long isbn = rs1.getLong("isbn");
	  				int quantity = rs1.getInt("quantity");
	  				
	  				PreparedStatement pstmt2 = conn.prepareStatement("INSERT INTO order_history(order_id, user_id, order_date, isbn, quantity) VALUES(?, ?, ?, ?, ?)");
	  				pstmt2.setInt(1, order_id);
	  				pstmt2.setInt(2, user_id);
	  				pstmt2.setDate(3, sqldate);
	  				pstmt2.setLong(4, isbn);
	  				pstmt2.setInt(5, quantity);
	  				
	  				pstmt2.executeUpdate();
	  			}//end while
	  				
	  			PreparedStatement pstmt3 = conn.prepareStatement("DELETE FROM orders WHERE user_id=?");
	  			pstmt3.setInt(1, user_id);
	  			pstmt3.executeUpdate();
	  			
			}
			catch(Exception e){
				out.println(e.toString());
			}
		%>
		<% response.sendRedirect("http://localhost:8080/bookstore/Confirm.html"); %>
	</body> 
</html>