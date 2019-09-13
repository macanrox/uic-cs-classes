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
		<title>Bookstore Books</title> 
	</head>
	<body>
		<h1 align="center">Books at Bookstore</h1>
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
							PreparedStatement pst = conn.prepareStatement("SELECT * FROM Books");
							ResultSet rs = pst.executeQuery(); 

							while(rs.next()){
					%>
	  				<tr>
	  					<td align="center"><%=rs.getLong("isbn_number") %></td>
	  					<td align="center"><%=rs.getString("title") %></td>
	  					<td align="center"><%=rs.getString("author") %></td>
	  					<td><%=rs.getString("description") %></td>
	  					<td align="center">$<%=rs.getFloat("price") %></td>
	  					<td align="center"><img src="<%=rs.getString("image") %>" style="height: 318px; width: 197px;"></td>
	  					<td>
	  						<form action="Confirm.html" method="post">
	  							<br/>Quantity: <input type="number" name="quantity" min="1" max="10">
	  							<br/><input type="submit" value="Add to cart">
	  						</form>
	  					</td>
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