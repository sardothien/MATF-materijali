/* Napisati Java program u kojem se naredbe izvršavaju dinamički 
 * koji ispisuje podatke za predmet čiji je identifikator 2027. */

package zadatak_8_11;

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
		
		try(Connection con = DriverManager.getConnection(url, "student", "abcdef")){
			
			String sql = "SELECT * FROM DA.PREDMET WHERE ID = 2027";
			
			Statement stmt = con.createStatement();
			ResultSet kursor = stmt.executeQuery(sql);
			while(kursor.next()){
				System.out.println(kursor.getInt(1) + " - " + kursor.getString(2) + " - " +
								   kursor.getString(3) + " (" + kursor.getShort(4) + ")");
			}
			
			kursor.close();
			stmt.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}

}
