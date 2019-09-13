<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@ include file="index.jsp" %>

processOrder(stat, conn, out, session, request);

<html> 
	<head> 
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"> 
		<title>Bookstore Shopping Cart</title> 
	</head> 
	<body>
		<h1 align="center">Bookstore Shopping Cart</h1> 
		<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"> 
		<title>Bookstore Books</title> 
	</head>
	<body>
		<h1 align="center">Books at Bookstore</h1>
		<center>
			<table border="1">
				<thead>
					<tr>
						<th></th>
						<th>Item</th>
						<th>Price</th>
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
							
							String quantity = request.getParameter("quantity");
							String isbn_number = request.getParameter("isbn_number");
							String user_id = (String)session.getAttribute("user_id");
							String query = "INSERT into orders(order_id, isbn, user_id, quantity) VALUES(?, ?, ?, ?)";
							
							PreparedStatement pstInsert = conn.prepareStatement(query);
							pstInsert.setString(2, isbn_number);
							pstInsert.setString(3, user_id);
							pstInsert.setString(4, quantity);
							
							ResultSet rs1 = pstInsert.executeQuery();

							PreparedStatement pst = conn.prepareStatement("SELECT b.title, b.price, o.* FROM orders o INNER JOIN books b on o.isbn = b.isbn_number");
							ResultSet rs = pst.executeQuery(); 

							while(rs.next()){
					%>
	  				<tr>
	  					<td align="center"><img src="<%=rs.getString("image") %>" style="height: 318px; width: 197px;"></td>
	  					<td align="center"><%=rs.getString("title") %></td>
	  					<td align="center">$<%=rs.getFloat("price") %></td>
	  				<% 
	  						}//end while
	  					}//end try
	  					catch(Exception e){
	  						out.println(e.toString());
	  					}	
	  				%>
	  				</tr>
	  				<tr>
	  					<td>Total Price: $17.62</td>
	  					<td>
	  						<form align="right" action="Checkout.html" method="post">
	  						</br><input type="submit" value="Checkout">
	  						</form>
	  					</td>
	  				</tr>
	  					</td>
	  				</tr>
	  			</tbody>
			</table>
		</center>
	</body>
</html>
	</body> 
</html>