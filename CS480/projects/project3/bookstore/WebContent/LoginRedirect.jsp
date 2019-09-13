<%@page import ="java.sql.*"%>
<%@page import ="javax.sql.*"%>
<%@ include file="index.jsp" %>

<%
java.sql.Connection conn = null;
java.sql.Statement st = null;
String directUrl = "http://localhost:8080/bookstore/Login.jsp?returnFrom=ShowBooks.jsp";
try {
	Class.forName(DBDriver);
	conn = DriverManager.getConnection(strConn, DBusername, DBpassword);
	st = conn.createStatement();

	response.sendRedirect(directUrl);

}//end try
catch(Exception e) {
	out.println(e.toString());
	//out.println("</br></br><a href='http://localhost:8080/bookstore/Login.html'>Back</a>");
}
%>