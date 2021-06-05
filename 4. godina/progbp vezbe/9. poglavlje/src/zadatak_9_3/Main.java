/* Napisati Java program u kojem se SQL naredbe izvršavaju dinamički koji
 * pronalazi indekse i nazive predmeta za sva polaganja koja su bila neuspešna. 
 * Sortirati podatke po indeksu rastuće. Obezbediti da aplikacija briše podatke 
 * o najviše 10 studenata. Jednu transakciju čine brisanja za sve pronađene 
 * studente. Prilikom obrade podataka, ispisati informacije o indeksu studenta, 
 * a zatim prikazati nazive predmeta za obrisana polaganja tog studenta. Nakon 
 * brisanja podataka o jednom studentu, upitati korisnika da li želi da poništi 
 * izmene za tog studenta (voditi računa da brisanja za sve prethodne studente 
 * ostanu nepromenjena). */

package zadatak_9_3;

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
			con.setAutoCommit(false);
			
			try {
				
				String sql = "SELECT INDEKS, "
						   + "       (SELECT NAZIV FROM DA.PREDMET WHERE ID = I.IDPREDMETA) "
						   + "FROM DA.ISPIT I "
						   + "WHERE OCENA = 5 AND STATUS = 'o' "
						   + "ORDER BY INDEKS ASC";
				// TYPE_SCROLL_SENSITIVE -> jer upit sadrzi Order By klauzu
				Statement stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,
													 ResultSet.CONCUR_UPDATABLE);
				ResultSet kursor = stmt.executeQuery(sql);
				
				int prethIndeks = -1;
				int brStudenata = 0;
				
				Savepoint savepoint = null;
				
				while(kursor.next()){
					int indeks = kursor.getInt(1);
					String naziv = kursor.getString(2);
					
					if(indeks != prethIndeks){
						if(prethIndeks != -1){
							System.out.println("Da li zelite da ponistite brisanja za: " + prethIndeks + "?");
							String odgovor = sc.nextLine();
							if(odgovor.equalsIgnoreCase("da")){
								con.rollback(savepoint);
							}
							else {
								con.releaseSavepoint(savepoint);
							}
						}
						
						prethIndeks = indeks;
						++brStudenata;
						if(brStudenata == 10)
							break;
						System.out.println("Brisemo polaganja za studenta: " + indeks);
						savepoint = con.setSavepoint();
					}
					
					System.out.println("\tBrisemo polaganje predmeta " + naziv);
					kursor.deleteRow();
				}
				
				kursor.close();
				stmt.close();
				
				con.commit();
				
			} catch (Exception e) {
				con.rollback();
				throw e;
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}

}
