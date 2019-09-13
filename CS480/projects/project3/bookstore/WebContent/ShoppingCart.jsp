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
		<h2 align="center">Shopping Cart</h2>
		<div align="right" id="navigation">
			<% 
				String username=(String)session.getAttribute("user");
				if(username==null){
			%>
			<form action="http://localhost:8080/bookstore/LoginRedirect.jsp">
				<button type="submit">Login</button>
			</form>
			<% 
				}//end if
				else {
			%>
			<a href="#"><%=username %></a>
			</br>
			<form action="Logout.jsp" method="post">
				<input type="submit" value="logout">
			</form>
			<%}//end else %>
		</div>
		</br>
		<center>
			<table border="1">
				<thead>
					<tr>
						<td>Title</td>
						<td>Quantity</td>
						<td>Price</td>
						<td>Total Price</td>
					</tr>
				</thead>
				<tbody>
	  		<%
	  			java.sql.Connection conn = null;
	  			java.sql.Statement st = null;
						
				try {
					Class.forName(DBDriver);
					conn = DriverManager.getConnection(strConn, DBusername, DBpassword);
					st = conn.createStatement();
							
					int user_id = (Integer)session.getAttribute("user_id");
					double order_price = 0;
					double total_price = 0;
					//System.out.println("user_id = " + user_id);
					PreparedStatement pstmt = conn.prepareStatement("SELECT image, quantity, price FROM books, orders WHERE user_id=? AND orders.isbn=books.isbn_number");		
					pstmt.setInt(1, user_id);
					
					ResultSet rs = pstmt.executeQuery();
					
					while(rs.next()) {
						
						int quantity = rs.getInt("quantity");
						float price = rs.getFloat("price");
			%>			
						<tr>
						<td align="center"><img src="<%=rs.getString("image") %>" style="height: 318px; width: 197px;"></td>
						<td align="center"><%=quantity %></td>
						<td align="center">$<%=price %></td>
						<%
							order_price = quantity*price; 
							total_price += order_price;
							double newTotalPrice = Math.round(total_price*100.0)/100.0;
						%>
						<td>$<%=newTotalPrice %></td>
						</tr>
			<%
					}
							
	  			}//end try
	  			catch(Exception e){
	  				out.println(e.toString());
	  			}	
	  		%>
	  			</tbody>
	  		</table>
	  		</br>
	  		<% 
	  			if(username==null){
	  				out.println("Please login to view your shopping cart.");
	  			}//end if
	  			else {
	  				%>
	  				<a href="http://localhost:8080/bookstore/ShowBooks.jsp">Continue shopping</a>
	  				</br>
	  				<br/>
	  				<form action="Checkout.jsp" method="post">
						<input type="submit" value="Proceed to checkout">
					</form>
					<%}//end else %>
		</center>
	</body> 
</html>