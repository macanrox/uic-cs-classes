<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>

<%! //this is a declaration tag
	static final String sFileName = "ShowBooks.jsp";
	static final String DBDriver  ="com.mysql.jdbc.Driver";
	static final String strConn   ="jdbc:mysql://localhost:3306/bookstore";
	static final String DBusername="root";
	static final String DBpassword="";
%>

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
							PreparedStatement pst = conn.prepareStatement("SELECT b.image, b.title, b.price, o.* FROM Orders o INNER JOIN Books b on o.isbn = b.isbn_number");
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