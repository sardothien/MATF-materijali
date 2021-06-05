/* Napisati Java program u kojem se naredbe izvršavaju dinamički koji
 * ispisuje broj studenata koji su upisali studije u školskoj godini 
 * koja se unosi sa standardnog ulaza. */

package zadatak_8_12;

import java.sql.*;
import java.util.Scanner;

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
		
		try(Connection con = DriverManager.getConnection(url, "student", "abcdef");
			Scanner sc = new Scanner(System.in)){
			
			String sql = "SELECT COUNT(*) FROM DA.DOSIJE WHERE YEAR(DATUPISA) = ?";
			
			System.out.println("Unesite godinu:");
			int godina = sc.nextInt();
			
			PreparedStatement pstmt = con.prepareStatement(sql);
			pstmt.setInt(1, godina);
			ResultSet kursor = pstmt.executeQuery();
			while(kursor.next()){
				System.out.println(kursor.getInt(1));
			}
			
			kursor.close();
			pstmt.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}

}
