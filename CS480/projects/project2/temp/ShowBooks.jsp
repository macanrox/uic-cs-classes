<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@ include file="index.jsp" %>

<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"> 
		<title>Bookstore Books</title> 
	</head>
	<body>
		<h1 align="center">Books at Bookstore</h1>
		<div align="right" id="navigation">
			<a href="#">user</a>
			</br>
			<form action="logout" method="post">
				<input type="submit" value="logout">
			</form>
		</div>
		</br>
		<center>
			<table border="1">
				<thead>
					<tr>
						<th>ISBN</th>
						<th>Title</th>
						<th>Author</th>
						<th>Description</th>
						<th>Price</th>
						<th></th>
						<th>Order</th>
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
							PreparedStatement pst = conn.prepareStatement("SELECT b.*, a.name FROM books b JOIN booksandauthors c on b.isbn_number = c.isbn_number JOIN authors a on c.id=a.ID");
							ResultSet rs = pst.executeQuery(); 

							while(rs.next()){
					%>
	  				<tr>
	  					<form action="ShoppingCart.jsp" method="post">
	  						<td align="center"><%=rs.getLong("isbn_number") %></td>
	  						<td align="center"><%=rs.getString("title") %></td>
	  						<td align="center"><%=rs.getString("name") %></td>
	  						<td><%=rs.getString("description") %></td>
	  						<td align="center">$<%=rs.getFloat("price") %></td>
	  						<td align="center"><img src="<%=rs.getString("image") %>" style="height: 318px; width: 197px;"></td>
	  						<td>
	  							<br/>Quantity: <input type="number" name="quantity" min="1" max="10">
	  							<br/><input type="submit" value="Add to cart">
	  						</td>
	  					</form>
	  				<% 
	  						}//end while
	  					}//end try
	  					catch(Exception e){
	  						out.println(e.toString());
	  					}	
	  				%>
	  				</tr>
	  			</tbody>
			</table>
		</center>
	</body>
</html>