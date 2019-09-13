<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@page import = "java.util.Date, java.text.DateFormat, java.text.SimpleDateFormat" %>
<%@ include file="index.jsp" %>

<%
java.sql.Connection conn = null;
java.sql.Statement st = null;
String directUrl = "http://localhost:8080/bookstore/ShowBooks.jsp";
try {
	Class.forName(DBDriver);
	conn = DriverManager.getConnection(strConn, DBusername, DBpassword);
	st = conn.createStatement();
	
	String user = request.getParameter("username");

	PreparedStatement pst = conn.prepareStatement("DELETE FROM users WHERE username=?");
	pst.setString(1, user);
	pst.executeUpdate();
	
	response.sendRedirect("http://localhost:8080/bookstore/UserManagement.jsp");

}//end try
catch(Exception e) {
	out.println(e.toString());
	//out.println("</br></br><a href='http://localhost:8080/bookstore/Login.html'>Back</a>");
}
%>