<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@page import = "java.util.Date, java.text.DateFormat, java.text.SimpleDateFormat" %>
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
		<div align="left">
			<br/>
			<table border="1">
				<thead>
					<th><h4>Navigation</h4></th>
				</thead>
				<tbody>
					<tr>
						<td align="center"><a href="http://localhost:8080/bookstore/UserManagement.jsp">User Management</a></td>
					</tr>
					<tr>
						<td align="center"><a href="http://localhost:8080/bookstore/Statistics.jsp">Statistics</a></td>
					</tr>
				</tbody>
			</table>
		</div>	
	</body> 
</html>