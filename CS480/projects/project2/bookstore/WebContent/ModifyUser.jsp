<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@ include file="index.jsp" %>

<html> 
	<head> 
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"> 
		<title>Bookstore Books</title> 
	</head> 
	<body>
		<h1 align="center">User Management</h1> 
		<h2 align="center">Modify User</h2>
		<% String username=(String)session.getAttribute("user");
			int userType = (Integer)session.getAttribute("type");
			
			if(userType != 1){
				response.sendRedirect("http://localhost:8080/bookstore/401.jsp");
			}
			else if(username==null){
				response.sendRedirect("http://localhost:8080/bookstore/Login.jsp");
			}
			%>
		<center> 
	  				<%
						java.sql.Connection conn = null;
						java.sql.Statement st = null;

						try {
							Class.forName(DBDriver);
							conn = DriverManager.getConnection(strConn, DBusername, DBpassword);
							st = conn.createStatement();
							
							String user = request.getParameter("username");

							PreparedStatement pst = conn.prepareStatement("SELECT * FROM users WHERE username=?");
							pst.setString(1, user);
							ResultSet rs = pst.executeQuery();

							while(rs.next()){
					%>
					<%
						int typeOfUser = rs.getInt("type");
						String pass = rs.getString("password");
						String name = rs.getString("name");
						String address = rs.getString("address");
						long credit_card = rs.getLong("credit_card");
					%>
	  				<form action="ModifyUser.jsp" method="post">
	  					Type: <input type="text" name="userType" value=<%=typeOfUser %>>
	  					<br/>
	  					Username: <input type="text" name="username" value=<%=user %>>
	  					<br/>
	  					Password: <input type="text" name="password" value=<%=pass %>>
	  					<br/>
	  					Name: <input type="text" name="name" value=<%=name %>>
	  					<br/>
	  					Address: <input type="text" name="address" value=<%=address %>>
	  					<br/>
	  					Credit Card: <input type="text" name="credit_card" value=<%=credit_card %>>
	  					<br/>
	  					<input type="submit" value="Modify user">
	  				</form>
	  				<% 
	  						}//end while
	  					
	  						int type = Integer.parseInt(request.getParameter("userType"));
	  						String password = request.getParameter("password");
	  						String name = request.getParameter("name");
	  						String address = request.getParameter("address");
	  						long credit_card = Long.parseLong(request.getParameter("credit_card"));
	  						
							PreparedStatement pst2 = conn.prepareStatement("UPDATE users SET type=?, password=?, name=?, address=?, credit_card=? WHERE username=?");
				  			pst2.setInt(1, type);
				  			pst2.setString(2, password);
				  			pst2.setString(3, name);
				  			pst2.setString(4, address);
				  			pst2.setLong(5, credit_card);
				  			pst2.setString(6, user);
				  			pst2.executeUpdate();		
	  					}//end try
	  					catch(Exception e){
	  						out.println(e.toString());
	  					}	
	  				%>
	
		<br/><a href="http://localhost:8080/bookstore/UserManagement.jsp">Return</a>
		</center> 
	</body> 
</html>