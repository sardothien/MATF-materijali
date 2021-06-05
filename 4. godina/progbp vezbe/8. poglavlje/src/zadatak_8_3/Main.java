/* Napisati Java program u kojem se naredbe izvršavaju dinamički koji
 * učitava dva cela broja, X i Y, a zatim svim predmetima koji imaju 
 * X ESPB bodova, postavlja broj bodova na Y. Nakon toga ispisati broj
 * ažuriranih redova. */

package zadatak_8_3;

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
			Scanner sc = new Scanner(System.in)) {
			
			String sql = "UPDATE DA.PREDMET SET ESPB = ? WHERE ESPB = ?";
			
			System.out.println("Unesite dva cela broja X i Y:");
			short x = sc.nextShort();
			short y = sc.nextShort();
			
			PreparedStatement pstmt = con.prepareStatement(sql);
			pstmt.setShort(1, x);
			pstmt.setShort(2, y);
			
			int brIzmenjenihRedova = pstmt.executeUpdate();
			System.out.println("Izmenili ste " + brIzmenjenihRedova + " redova.");
			
			pstmt.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

}
