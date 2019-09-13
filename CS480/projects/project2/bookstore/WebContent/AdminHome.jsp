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
		<h1 align="center">Bookstore Books</h1> 
		<h2 align="center">Administrator Page</h2>
		<h3 align="center">Welcome <%=username %>!</h3>

		<div align="right" id="navigation">
			<a href="#"><%=username %></a>
			</br>
			<form action="Logout.jsp" method="post">
				<input type="submit" value="logout">
			</form>
		</div>		
		<center> 
		<a href="http://localhost:8080/bookstore/UserManagement.jsp">User Management</a>
		<br/>
		<a href="http://localhost:8080/bookstore/Statistics.jsp">Statistics</a>
		</center> 
	</body> 
</html>