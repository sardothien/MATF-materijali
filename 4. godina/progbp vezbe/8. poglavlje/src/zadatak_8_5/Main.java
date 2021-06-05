/* Napisati Java program u kojem se naredbe izvršavaju dinamički koji 
 * izdvaja ime, prezime i datum diplomiranja za sve studentkinje
 * (pol = ‘z’) programa čiji je identifikator 202 iz tabele DOSIJE.
 * Ukoliko datum diplomiranja nije poznat, ispisati Nije diplomirala. */

package zadatak_8_5;

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
			
			String sql = "SELECT IME, PREZIME, DATDIPLOMIRANJA "
					   + "FROM DA.DOSIJE "
					   + "WHERE POL = 'z' AND IDPROGRAMA = 202";
			
			Statement stmt = con.createStatement();
			ResultSet kursor = stmt.executeQuery(sql);
			while(kursor.next()){
				String ime = kursor.getString(1);
				String prezime = kursor.getString(2);
				String datum = kursor.getString(3);
				boolean datumNull = kursor.wasNull();
				
				System.out.println(ime + " " + prezime + " : " + (datumNull ? "Nije diplomirala" : datum));
			}
			
			kursor.close();
			stmt.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}
