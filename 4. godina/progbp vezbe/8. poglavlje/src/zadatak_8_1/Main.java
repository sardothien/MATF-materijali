/* Napisati Java program u kojem se naredbe izvršavaju dinamički 
 * koji izlistava oznake i nazive svih predmeta koji imaju više
 * od 20 ESPB bodova. */

package zadatak_8_1;

import java.sql.*;

public class Main {
	
	static {
		try {
			Class.forName("com.ibm.db2.jcc.DB2Driver");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		
		String url = "jdbc:db2://localhost:50000/STUD2020";
		
		try (Connection con = DriverManager.getConnection(url, "student", "abcdef")) {
		
			String sql = "SELECT OZNAKA, NAZIV "
					   + "FROM DA.PREDMET "
					   + "WHERE ESPB > 20";
			
			Statement stmt = con.createStatement();
			ResultSet kursor = stmt.executeQuery(sql);
			
			while(kursor.next()){
				String oznaka = kursor.getString(1);
				String naziv = kursor.getString(2);
				
				System.out.printf("%s %s\n", oznaka, naziv);
			}
			
			kursor.close();
			stmt.close();
			
		} catch (SQLException e) {
			System.out.println(e.getErrorCode());
			e.printStackTrace();
			System.out.println(e.getMessage());
			System.exit(1);
		}
	}

}
