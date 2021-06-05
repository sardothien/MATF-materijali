/* Napisati Java program u kojem se naredbe izvršavaju dinamički kojim se
 * brišu svi podaci o ispitima za studenta čiji se indeks unosi sa
 * standardnog ulaza. */

package zadatak_8_18;

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
			
			String sql = "SELECT INDEKS "
					   + "FROM DA.ISPIT I "
					   + "WHERE INDEKS = ? ";
			
			System.out.println("Unesite indeks studenta:");
			int indeks = sc.nextInt();
			
			PreparedStatement pstmt = con.prepareStatement(sql, ResultSet.TYPE_FORWARD_ONLY, ResultSet.CONCUR_UPDATABLE);
			pstmt.setInt(1, indeks);
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
