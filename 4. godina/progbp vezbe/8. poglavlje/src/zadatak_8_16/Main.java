/* Napisati Java program u kojem se naredbe izvršavaju dinamički kojim 
 * se, za sve položene ispite čiji se naziv predmeta unosi sa standardnog 
 * ulaza, ocena uvećava za 1. */

package zadatak_8_16;

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
					   + "WHERE OCENA > 5 AND STATUS = 'o' "
					   + " AND IDPREDMETA IN (SELECT ID "
					   + "					  FROM DA.PREDMET P "
					   + "					  WHERE P.ID = I.IDPREDMETA AND NAZIV = ?)";
			
			System.out.println("Unesite naziv predmeta:");
			String naziv = sc.nextLine();
			
			PreparedStatement pstmt = con.prepareStatement(sql, ResultSet.TYPE_FORWARD_ONLY, ResultSet.CONCUR_UPDATABLE);
			pstmt.setString(1, naziv);
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
