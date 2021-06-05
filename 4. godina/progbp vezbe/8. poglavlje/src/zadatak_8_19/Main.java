/* Napisati Java program u kojem se naredbe izvršavaju dinamički koji
 * iz tabele PREDMET briše podatak o predmetu čija se oznaka unosi sa
 * standardnog ulaza. */

package zadatak_8_19;

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
			
			String sql = "SELECT NAZIV "
					   + "FROM DA.PREDMET "
					   + "WHERE OZNAKA = ? ";
			
			System.out.println("Unesite oznaku predmeta:");
			String oznaka = sc.next();
			
			PreparedStatement pstmt = con.prepareStatement(sql, ResultSet.TYPE_FORWARD_ONLY, ResultSet.CONCUR_UPDATABLE);
			pstmt.setString(1, oznaka);
			ResultSet kursor = pstmt.executeQuery();
			
			while(kursor.next()){
				System.out.println(kursor.getInt(1));
				
				kursor.deleteRow();
			}
			
			kursor.close();
			pstmt.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}

}
