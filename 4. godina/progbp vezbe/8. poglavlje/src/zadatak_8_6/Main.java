/* Napisati Java program u kojem se naredbe izvršavaju dinamički 
 * koji ispisuje podatke o ispitnim rokovima koristeći kursor 
 * kome je omogućeno kretanje i unazad kroz podatke. Podatke 
 * urediti po nazivu rastuće, ali ih ispisivati opadajuće. */

package zadatak_8_6;

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
			
			String sql = "SELECT * "
					   + "FROM DA.ISPITNIROK "
					   + "ORDER BY NAZIV ASC";
			
			// kursor je bidirekcioni i samo za citanje
			Statement stmt = con.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,
												 ResultSet.CONCUR_READ_ONLY);
			ResultSet kursor = stmt.executeQuery(sql);
			kursor.afterLast(); // citamo od pozadi
			
			while(kursor.previous()){
				short skGodina = kursor.getShort(1);
				String oznaka = kursor.getString(2);
				String naziv = kursor.getString(3);
				String datPocetka = kursor.getString(4);
				String datKraja = kursor.getString(5);
				
				System.out.println(skGodina + " " + oznaka + " " + naziv + "(" + datPocetka + " - " + datKraja + ")");
			}
			
			kursor.close();
			stmt.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}

}
