<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@ include file="index.jsp" %>

<% 
String username=(String)session.getAttribute("user");
int userType = (Integer)session.getAttribute("type");
			
if(userType != 1){
	response.sendRedirect("http://localhost:8080/bookstore/401.jsp");
}
else if(username==null){
	response.sendRedirect("http://localhost:8080/bookstore/Login.jsp");
}
%>
<html> 
	<head> 
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"> 
		<title>Bookstore Books</title> 
	</head> 
	<body>
		<h1 align="center">Statistics</h1> 
		<h2 align="center">Order History</h2>
		<center>
		<div align="right" id="navigation">
			<a href="#"><%=username %></a>
			</br>
			<form action="Logout.jsp" method="post">
				<input type="submit" value="logout">
			</form>
		</div>
		
		<form action="SearchUser.jsp" method="post" align="right">
			<input type="text" name="userSearch" value="">
			<input type="submit" value="Search user">
		</form>
		<table border="1">
				<thead>
					<tr>
						<th>Order ID</th>
						<th>Order Date</th>
						<th>Isbn</th>
						<th>Quantity</th>
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
							//PreparedStatement pst = conn.prepareStatement("SELECT order_id, user_id, isbn, quantity FROM order_history");
							PreparedStatement pst = conn.prepareStatement("SELECT order_id, order_date, isbn, quantity FROM order_history WHERE date>? UNION ALL SELECT u.username FROM users u JOIN order_history o ON u.user_id=o.user_id WHERE username=?");
							ResultSet rs = pst.executeQuery(); 

							while(rs.next()){
					%>
					<%
						int order_id = rs.getInt("order_id");
						int order_date = rs.getInt("order_date");
						long isbn = rs.getLong("isbn");
						int quantity = rs.getInt("quantity");
					%>
	  				<tr>
	  						<td align="center"><%= order_id %></td>
	  						<td align="center"><%= order_date %></td>
	  						<td align="center"><%= isbn%></td>
	  						<td align="center"><%= quantity%></td>
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
		<br/>
		<a href="http://localhost:8080/bookstore/OrderHistory.jsp">Order History</a>
		</center> 
	</body> 
</html>