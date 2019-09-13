package project4;

import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.math.BigInteger;
import java.sql.*;
import java.sql.Date;
import java.text.SimpleDateFormat;

import static java.lang.System.out;

public class Userinput {

	public static void main(String[] args) throws Exception{
		//java.sql.Connection conn = null;
		//java.sql.Statement st = null;
		
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the name of the database you want to add the tuples to: ");
		String dbName = s.nextLine();
		System.out.println(dbName+" will be used.\n");
		
		//prompt for tuples
		System.out.print("Enter the number of tuples to add to the authors table: ");
		String authorTuple = s.nextLine();
		System.out.println(""+authorTuple+" created in the authors table.\n");
		
		System.out.print("Enter the number of tuples to add to the books table: ");
		String bookTuple = s.nextLine();
		System.out.println(""+bookTuple+" created in the books table.\n");
		
		System.out.print("Enter the number of tuples to add to the users table: ");
		String usersTuple = s.nextLine();
		System.out.println(""+usersTuple+" created in the users table.\n");
		
		System.out.print("Enter the number of tuples to add to the booksandauthors table: ");
		String booksandauthorsTuple = s.nextLine();
		System.out.println(""+booksandauthorsTuple+" created in the booksandauthors table.\n");
		
		System.out.print("Enter the number of tuples to add to the orderhistory table: ");
		String orderhistoryTuple = s.nextLine();
		System.out.println(""+orderhistoryTuple+" created in the orderhistory table.\n");
		
		//convert the strings into integer arrays for randomizing
		int authorTuple2 = Integer.parseInt(authorTuple);
		int bookTuple2 = Integer.parseInt(bookTuple);
		int booksandauthorsTuple2 = Integer.parseInt(booksandauthorsTuple);
		int orderhistoryTuple2 = Integer.parseInt(orderhistoryTuple);
		int usersTuple2 = Integer.parseInt(usersTuple);
		
		//generate random values for tuples based on user input
		Integer[] arr1 = new Integer[authorTuple2];
		Integer[] authorYear = new Integer[authorTuple2];
		Integer[] authorID = new Integer[authorTuple2];
		Integer[] arr2 = new Integer[bookTuple2];
		Integer[] bookYear = new Integer[bookTuple2];
		Long[] bookIsbn = new Long[bookTuple2];
		Long[] bookPrice = new Long[bookTuple2];
		Integer[] arr3 = new Integer[usersTuple2];
		Integer[] userYear = new Integer[usersTuple2];
		Integer[] userID = new Integer[usersTuple2];
		Integer[] arr4 = new Integer[orderhistoryTuple2];
		List<String> orderDate = new ArrayList<String>();
		Integer[] orderUser = new Integer[orderhistoryTuple2];
		Long[] orderIsbn = new Long[orderhistoryTuple2];
		Integer[] arr5 = new Integer[booksandauthorsTuple2];
		Integer[] baaAuthor = new Integer[booksandauthorsTuple2];
		Long[] baaIsbn = new Long[booksandauthorsTuple2];
		Pattern p = Pattern.compile("[0-9]+$");
		
		//AUTHOR
		for(int i=0; i < arr1.length; i++){
			arr1[i] = i+1;	//to avoid zero
		}
		Collections.shuffle(Arrays.asList(arr1));
		for(int j=0; j < authorYear.length; j++){
			Random rand = new Random();
			int result = rand.nextInt(4000);
			authorYear[j] = result;
			//System.out.println(result);
		}
		Collections.shuffle(Arrays.asList(authorYear));
		for(int k=0; k < authorID.length; k++){
			Random rand = new Random();
			int result = rand.nextInt(90000)+10000;
			authorID[k] = result;
			//System.out.println(result);
		}
		Collections.shuffle(Arrays.asList(authorID));
		System.out.println("\nInserting into the author table.");	//test
		
		String pa2="author";
		StringBuilder authorName = new StringBuilder();
		authorName.append(pa2);
		for(int k=0; k < arr1.length; k++){
			String val = arr1[k].toString();
			int year = authorYear[k];
			int id = authorID[k];
			authorName.append(val);
			
			//then we should send values to the database here
//			System.out.println("Submitting to database: "+id+", "+authorName+", "+year);
			try {
				Class.forName("com.mysql.jdbc.Driver");
			}catch(java.lang.ClassNotFoundException e) {
			      System.err.print("ClassNotFoundException: "); 
			      System.err.println(e.getMessage());
			}//end catch
			
			try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/"+dbName, "root", "1234"); 
					Statement st = conn.createStatement(); 
					PreparedStatement pst = conn.prepareStatement("INSERT INTO author(id, name, year) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE id=VALUES(id), name=VALUES(name), year=VALUES(year)");){
				pst.setInt(1, id);
				pst.setString(2,  authorName.toString());
				pst.setInt(3, year);
				pst.executeUpdate();
				
			}//end try
			catch(Exception e){
				out.println("AUTHOR: "+e.toString());
			}//end catch
			
			//delete the value we append so we can submit new queries
			Matcher m = p.matcher(authorName);
			if(m.find()){
				authorName.delete(m.start(0), m.end(0));
			}
		}//end for
		System.out.println("Entry successful.");	//test
		
		//BOOKS
		for(int i=0; i < arr2.length; i++){
			arr2[i] = i+1;	//to avoid zero
		}
		Collections.shuffle(Arrays.asList(arr2));
		for(int j=0; j < bookYear.length; j++){
			Random rand = new Random();
			int result = rand.nextInt(4000);
			bookYear[j] = result;
		}
		Collections.shuffle(Arrays.asList(bookYear));
		for(int x=0; x < bookIsbn.length; x++){
			Random rand = new Random();			
			long val = 1000000000L * (rand.nextInt(9000) + 1000) + rand.nextInt(1000000000);
			bookIsbn[x]=val;
		}
		Collections.shuffle(Arrays.asList(bookIsbn));
		for(int y=0; y < bookPrice.length; y++){
			Random rand = new Random();	
			long result = rand.nextInt(100);
			bookPrice[y] = result;
		}
		Collections.shuffle(Arrays.asList(bookPrice));
		System.out.println("\nInserting into the books table.");	//test
		
		String pb2="book";
		StringBuilder bookTitle = new StringBuilder();
		bookTitle.append(pb2);
		for(int k=0; k < arr2.length; k++){
			String val = arr2[k].toString();
			int year = bookYear[k];
			long isbn = bookIsbn[k];
			long price = bookPrice[k];
			bookTitle.append(val);
			
			//then we should send values to the database here
			//System.out.println("Submitting to database: " +bookTitle+", "+val2+", "+val3+", $"+val4);
			try {
				Class.forName("com.mysql.jdbc.Driver");
			}catch(java.lang.ClassNotFoundException e) {
			      System.err.print("ClassNotFoundException: "); 
			      System.err.println(e.getMessage());
			}//end catch
			try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/"+dbName, "root", "1234");
					Statement st = conn.createStatement(); 
					PreparedStatement pst = conn.prepareStatement("INSERT INTO books(isbn, title, price, year) VALUES(?, ?, ?, ?) ON DUPLICATE KEY UPDATE isbn=VALUES(isbn), "
							+ "title=VALUES(title), price=VALUES(price), year=VALUES(year)");){			
				pst.setLong(1, isbn);
				pst.setString(2,  bookTitle.toString());
				pst.setLong(3, price);
				pst.setInt(4, year);
				pst.executeUpdate();
				
				//System.out.println("Entry successful.");	//test
			}//end try
			catch(Exception e){
				out.println("BOOK: "+e.toString());
			}//end catch
			
			//delete the value we append so we can submit new queries
			Matcher m = p.matcher(bookTitle);
			if(m.find()){
				bookTitle.delete(m.start(0), m.end(0));
			}
		}
		System.out.println("Entry successful.");	//test

		//USERS
		for(int i=0; i < arr3.length; i++){
			arr3[i] = i+1;	//to avoid zero
		}
		Collections.shuffle(Arrays.asList(arr3));
		for(int j=0; j < userYear.length; j++){
			Random rand = new Random();
			int result = rand.nextInt(6000);
			userYear[j] = result;
		}
		Collections.shuffle(Arrays.asList(userYear));
		for(int k=0; k < userID.length; k++){
			Random rand = new Random();
			int result = rand.nextInt(90000)+10000;
			
			userID[k] = result;
		}
		Collections.shuffle(Arrays.asList(userID));
		System.out.println("\nInserting into the users table.");	//test
		
		String pu2="user";
		String pu3="pass";
		String pu4="address";
		StringBuilder username = new StringBuilder();
		StringBuilder password = new StringBuilder();
		StringBuilder address = new StringBuilder();
		username.append(pu2);
		password.append(pu3);
		address.append(pu4);
		for(int k=0; k < arr3.length; k++){
			String val = arr3[k].toString();
			int year = userYear[k];
			int id = userID[k];
			username.append(val);
			password.append(val);
			address.append(val);
			
			//then we should send values to the database here
			//System.out.println("Submitting to database: " +val3+", "+sbUser1+", "+sbUser2+", "+sbUser3+", "+val2);
			try {
				Class.forName("com.mysql.jdbc.Driver");
			}catch(java.lang.ClassNotFoundException e) {
			      System.err.print("ClassNotFoundException: "); 
			      System.err.println(e.getMessage());
			}//end catch
			try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/"+dbName, "root", "1234");
					Statement st = conn.createStatement();
					PreparedStatement pst = conn.prepareStatement("INSERT INTO users(id, username, password, address, year) VALUES(?, ?, ?, ?, ?) ON DUPLICATE KEY UPDATE"
							+ " id=VALUES(id), username=VALUES(username), password=VALUES(password), address=VALUES(address), year=VALUES(year)");){
				pst.setInt(1, id);
				pst.setString(2, username.toString());
				pst.setString(3, password.toString());
				pst.setString(4, address.toString());
				pst.setInt(5, year);
				pst.executeUpdate();
				
				//System.out.println("Entry successful.");	//test
			}//end try
			catch(Exception e){
				out.println("USERS: "+e.toString());
			}//end catch
			
			//delete the value we append so we can submit new queries
			Matcher m = p.matcher(username);
			Matcher m2 = p.matcher(password);
			Matcher m3 = p.matcher(address);
			
			if(m.find() && m2.find() && m3.find()){
				username.delete(m.start(0), m.end(0));
				password.delete(m2.start(0), m2.end(0));
				address.delete(m3.start(0), m3.end(0));
			}
			//System.out.println("After deletion: "+sbUser1+", "+sbUser2+", "+sbUser3);
		}
		System.out.println("Entry successful.");	//test
		
		//ORDERHISTORY
		for(int i=0; i < arr4.length; i++){
			arr4[i] = i+1;	//to avoid zero
		}
		Collections.shuffle(Arrays.asList(arr4));
		for(int j=0; j < orderhistoryTuple2; j++){
			long dateMin = Timestamp.valueOf("1971-01-01 00:00:01").getTime();
			long dateMax = Timestamp.valueOf("2038-01-19 03:14:07").getTime();
			long range = dateMax - dateMin + 1;
			Timestamp rand = new Timestamp(dateMin + (long)(Math.random()*range));
			
			if(rand.toString().contains("1969") || rand.toString().contains("2039")){
				Timestamp rand1 = new Timestamp(dateMin + (long)(Math.random()*range));
				orderDate.add(String.valueOf(rand1));
			}
			else {
				orderDate.add(String.valueOf(rand));
			}
		}//end for
		Collections.shuffle(Arrays.asList(orderDate));
		for(int k=0; k < orderUser.length; k++){
			Random rand = new Random();
			int result = rand.nextInt(90000)+10000;
			
			orderUser[k] = result;
		}
		Collections.shuffle(Arrays.asList(orderUser));
		for(int x=0; x < orderIsbn.length; x++){
			Random rand = new Random();			
			long val = 1000000000L * (rand.nextInt(9000) + 1000) + rand.nextInt(1000000000);
			orderIsbn[x]=val;
		}
		Collections.shuffle(Arrays.asList(orderIsbn));
		System.out.println("\nInserting into the orderhistory table.");	//test
		for(int x=0; x < arr4.length; x++){
			//String val = arr4[x].toString();
			String orderdate = orderDate.get(x);
			int userid = orderUser[x];
			long isbn = orderIsbn[x];
			
			//to convert the string to timestamp
			SimpleDateFormat dateFormat = new SimpleDateFormat("YYYY-MM-DD HH:MM:SS");
			java.util.Date newDate = dateFormat.parse(orderdate);
			Timestamp timestamp = new java.sql.Timestamp(newDate.getTime());
			//System.out.println(timestamp.toString());

			//send values to database
			//System.out.println("Submitting to database: "+val2+", "+val3+", "+val4);
			try {
				Class.forName("com.mysql.jdbc.Driver");
			}catch(java.lang.ClassNotFoundException e) {
			      System.err.print("ClassNotFoundException: "); 
			      System.err.println(e.getMessage());
			}//end catch
			try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/"+dbName, "root", "1234");
					Statement st = conn.createStatement();){
				int count1=0, count2=0;
				
				PreparedStatement pst1 = conn.prepareStatement("SELECT COUNT(id) FROM users WHERE id=?");
				pst1.setInt(1, userid);
				ResultSet rs1 = pst1.executeQuery();
				while(rs1.next()){
					count1 = rs1.getInt("COUNT(id)");
					//System.out.println("Count1: "+count1);	//test	
				}				
				PreparedStatement pst2 = conn.prepareStatement("SELECT COUNT(isbn) FROM books WHERE isbn=?");
				pst2.setLong(1, isbn);
				ResultSet rs2 = pst2.executeQuery();
				while(rs2.next()){
					count1 = rs2.getInt("COUNT(isbn)");
					//System.out.println("Count2: "+count2);	//test	
				}
					//count1 and count2 were empty
					PreparedStatement pst9 = conn.prepareStatement("SET foreign_key_checks = 0");
					pst9.executeUpdate();
					
					PreparedStatement pst10 = conn.prepareStatement("INSERT INTO orderhistory(orderdate, userID, isbn_number)"
							+ "VALUES(?, ?, ?)");				
					pst10.setTimestamp(1, timestamp);
					pst10.setInt(2, userid);
					pst10.setLong(3, isbn);
					pst10.executeUpdate();
					
					PreparedStatement pst11 = conn.prepareStatement("SET foreign_key_checks = 1");
					pst11.executeUpdate();
				
			}catch(Exception e){
				out.println("ORDER HISTORY: "+e.toString());
			}//end catch
		}//end for
		System.out.println("Entry successful.");	//test
		
		//BOOKSANDAUTHORS
		for(int i=0; i < arr5.length; i++){
			arr5[i] = i+1;	//to avoid zero
		}
		Collections.shuffle(Arrays.asList(arr5));
		for(int k=0; k < baaAuthor.length; k++){
			Random rand = new Random();
			int result = rand.nextInt(90000)+10000;
			
			baaAuthor[k] = result;
		}
		Collections.shuffle(Arrays.asList(baaAuthor));
		for(int x=0; x < baaIsbn.length; x++){
			Random rand = new Random();			
			long val = 1000000000L * (rand.nextInt(9000) + 1000) + rand.nextInt(1000000000);
			baaIsbn[x]=val;
		}
		Collections.shuffle(Arrays.asList(baaIsbn));
		System.out.println("\nInserting into the booksandauthors table.");	//test
		for(int k=0; k < arr5.length; k++){
			//String val = arr5[k].toString();
			int authorid = baaAuthor[k];
			long isbn = baaIsbn[k];
			
			//then we should send values to the database here
			//System.out.println("Submitting to database: " +val+", "+val2);
			try {
				Class.forName("com.mysql.jdbc.Driver");
			}catch(java.lang.ClassNotFoundException e) {
			      System.err.print("ClassNotFoundException: "); 
			      System.err.println(e.getMessage());
			}//end catch
			try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/"+dbName, "root", "1234");
					Statement st = conn.createStatement();){
				int count1 = 0, count2 = 0;
				
				PreparedStatement pst1 = conn.prepareStatement("SELECT COUNT(id) FROM author WHERE id=?");
				pst1.setInt(1, authorid);
				ResultSet rs1 = pst1.executeQuery();
				while(rs1.next()){
					count1 = rs1.getInt("COUNT(id)");
					//System.out.println("Count1: "+count1);	//test	
				}
				PreparedStatement pst2 = conn.prepareStatement("SELECT COUNT(isbn) FROM books WHERE isbn=?");
				pst2.setLong(1, isbn);
				ResultSet rs2 = pst2.executeQuery();
				while(rs2.next()){
					count2 = rs2.getInt("COUNT(isbn)");
					//System.out.println("Count2: "+count2);	//test	
				}
					//count1 and count2 were empty
					PreparedStatement pst9 = conn.prepareStatement("SET foreign_key_checks = 0");
					pst9.executeUpdate();
					
					PreparedStatement pst10 = conn.prepareStatement("INSERT INTO booksandauthors(authorid, isbnNumber)"
							+ "VALUES(?, ?)");				
					pst10.setInt(1, authorid);
					pst10.setLong(2, isbn);
					pst10.executeUpdate();
					
					PreparedStatement pst11 = conn.prepareStatement("SET foreign_key_checks = 1");
					pst11.executeUpdate();

			}catch(Exception e){
				out.println("BOOKS AND AUTHORS: "+e.toString());
			}//end catch			
		}//end for
		System.out.println("Entry successful.");	//test
		
		
	}//end main

}
