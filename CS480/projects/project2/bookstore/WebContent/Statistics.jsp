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
		<center>
		<div align="right" id="navigation">
			<a href="#"><%=username %></a>
			</br>
			<form action="Logout.jsp" method="post">
				<input type="submit" value="logout">
			</form>
		</div>		
		<br/>
		<a href="http://localhost:8080/bookstore/OrderHistory.jsp">Order History</a>
		</center> 
	</body> 
</html>