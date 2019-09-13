<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@ include file="index.jsp" %>

<html> 
	<head> 
	</head> 
	<body>
		<h1 align="center">Bookstore Books</h1>
		<h2 align="center">Your order was successfully added to your shopping cart!</h2>
		<div align="right" id="navigation">
			<% String username=(String)session.getAttribute("user"); %>
			
			<a href="#"><%=username %></a>
			</br>
			<form action="logout" method="post">
				<input type="submit" value="logout">
			</form>
		</div>
		</br>
		<center>
	  		<%
	  			java.sql.Connection conn = null;
	  			java.sql.Statement st = null;
						
				try {
					Class.forName(DBDriver);
					conn = DriverManager.getConnection(strConn, DBusername, DBpassword);
					st = conn.createStatement();
							
					int quantity = Integer.parseInt(request.getParameter("quantity"));
					long isbn = Long.parseLong(request.getParameter("isbn"));
					int user_id = (Integer)session.getAttribute("user_id");
					
					//System.out.println("quantity = " + quantity);
					//System.out.println("isbn = " + isbn);
					//System.out.println("user_id = " + user_id);
							
					PreparedStatement pstInsert = conn.prepareStatement("INSERT into orders(isbn, user_id, quantity) VALUES(?, ?, ?)");
					pstInsert.setLong(1, isbn);
					pstInsert.setInt(2, user_id);
					pstInsert.setInt(3, quantity);
							
					pstInsert.executeUpdate();
							
	  			}//end try
	  			catch(Exception e){
	  				out.println(e.toString());
	  			}	
	  		%>
	  		</br>
	  		<a href="http://localhost:8080/bookstore/ShoppingCart.jsp">View shopping cart</a>
	  		</br>
	  		<a href="http://localhost:8080/bookstore/Checkout.jsp">Proceed to checkout</a>
	  		</br>
	  		<a href="http://localhost:8080/bookstore/ShowBooks.jsp">Back</a>
		</center>
	</body> 
</html>