/* Napisati Java program u kojem se naredbe izvršavaju dinamički koji 
 * ispisuje sadržaj tabele PREDMET i, u istoj iteraciji, ukoliko je 
 * broj bodova jednak X, postavlja se broj bodova na Y i ispisuje se
 * poruka da je promena izvršena, zajedno sa ispisom novih podataka o
 * tom predmetu. Brojevi X i Y se učitavaju sa standardnog ulaza. */

package zadatak_8_7;

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
			
			String sql = "SELECT * FROM DA.PREDMET";
			
			System.out.println("Unesite dva cela broja X i Y:");
			short x = sc.nextShort();
			short y = sc.nextShort();
			
			// dovoljan je kursor koji ide u napred i azurirajuci je
			Statement stmt = con.createStatement(ResultSet.TYPE_FORWARD_ONLY,
											     ResultSet.CONCUR_UPDATABLE);
			ResultSet kursor = stmt.executeQuery(sql);
			
			while(kursor.next()){
				int id = kursor.getInt(1);
				String oznaka = kursor.getString(2);
				String naziv = kursor.getString(3);
				short espb = kursor.getShort(4);
				
				System.out.println(id + " : " + oznaka + " - " + naziv + " (" + espb + ")");
				
				if(espb < x){
					kursor.updateShort(4, y);
					kursor.updateRow();
					System.out.println("\tUspesno promenjen broj bodova.");
				}
			}
			
			kursor.close();
			stmt.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}
