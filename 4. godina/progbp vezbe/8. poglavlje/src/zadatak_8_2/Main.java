/* Napisati Java program u kojem se naredbe izvršavaju dinamički koji u
 * tabelu PREDMET unosi podatak o predmetu čiji je identifikator 2001, 
 * oznaka Pred1, naziv Predmet 1 i nosi 5 ESPB bodova. */

package zadatak_8_2;

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

		try(Connection con = DriverManager.getConnection(url, "student", "abcdef")) {
			
			String sql = "INSERT INTO DA.PREDMET VALUES (2001, 'Pred1', 'Predmet 1', 5)";
			
			Statement stmt = con.createStatement();
			int brIzmenjenihRedova = stmt.executeUpdate(sql);
			
			System.out.println("Uspesno ste promenili " + brIzmenjenihRedova + " redova.");
			
			stmt.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

}
