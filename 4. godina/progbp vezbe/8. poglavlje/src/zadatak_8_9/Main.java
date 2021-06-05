/* Napisati Java program u kojem se naredbe izvršavaju dinamički koji
 * briše sve nepoložene ispite u školskoj godini koja se zadaje sa 
 * standarnog ulaza. Nakon svakog brisanja ispita, ispisati naredne 
 * informacije o njemu na standardni izlaz: indeks, oznaku roka,
 * školsku godinu i identifikator predmeta. */

package zadatak_8_9;

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
			
			String sql = "SELECT INDEKS, OZNAKAROKA, SKGODINA, IDPREDMETA "
					   + "FROM DA.ISPIT "
					   + "WHERE OCENA = 5 AND STATUS = 'o' AND SKGODINA = ?";
			
			System.out.println("Unesite skolsku godinu:");
			short godina = sc.nextShort();
			
			PreparedStatement pstmt = con.prepareStatement(sql, ResultSet.TYPE_FORWARD_ONLY, 
																ResultSet.CONCUR_UPDATABLE); 
			pstmt.setShort(1, godina);
			ResultSet kursor = pstmt.executeQuery();
			
			while(kursor.next()) {
				int indeks = kursor.getInt(1);
				String oznaka = kursor.getString(2);
				int idPredmeta = kursor.getInt(4);
				
				kursor.deleteRow();
				
				System.out.println("Obrisano: " + indeks + " - " + oznaka + " - " + idPredmeta);
			}
			
			kursor.close();
			pstmt.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}
