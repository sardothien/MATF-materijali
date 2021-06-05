/* Napisati Java program u kojem se SQL naredbe izvršavaju dinamički koji 
 * iz tabele UKUPNIBODOVI izdvaja 10 najuspešnijih studenata. Za svakog
 * studenta ispisati podatke iz te tabele i upitati korisnika da li želi 
 * da dodeli tom studentu počasnih 10 ESPB. Ukoliko želi, izvršiti 
 * odgovarajuću izmenu. Nakon svih izmena, ispisati izveštaj rada u kojem 
 * se vide izmene. Sve izmene i prikaz izveštaja implementirati kao jednu 
 * transakciju. Omogućiti da nijedan drugi korisnik ne može da vidi izmene 
 * tokom rada ovog programa. */

package zadatak_9_2;

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
			con.setTransactionIsolation(Connection.TRANSACTION_SERIALIZABLE);
			
			try {
				
				String sql = "SELECT INDEKS, IME, PREZIME, ESPB "
						   + "FROM DA.UKUPNIBODOVI "
						   + "FETCH FIRST 10 ROWS ONLY";
				Statement stmt = con.createStatement(ResultSet.TYPE_FORWARD_ONLY,
													 ResultSet.CONCUR_UPDATABLE);
				ResultSet kursor = stmt.executeQuery(sql);
				while(kursor.next()){
					int indeks = kursor.getInt(1);
					String ime = kursor.getString(2);
					String prezime = kursor.getString(3);
					short espb = kursor.getShort(4);
					System.out.println(indeks + " - " + ime + " " + prezime + " : " + espb);
					
					System.out.println("\tDa li zelite da dodate jos 10 ESBP? [da/ne]");
					String odgovor = sc.nextLine();
					if(odgovor.equalsIgnoreCase("da")){
						kursor.updateShort(4, (short) (espb+10));
						kursor.updateRow();
						System.out.println("\tUspesno azuriranje");
					}
				}
				
				kursor.close();
				
				System.out.println("----------------------------------------------------");
				
				// citamo podatke za izvestaj
				kursor = stmt.executeQuery(sql);
				while(kursor.next()){
					int indeks = kursor.getInt(1);
					String ime = kursor.getString(2);
					String prezime = kursor.getString(3);
					short espb = kursor.getShort(4);
					System.out.println(indeks + " - " + ime + " " + prezime + " : " + espb);
				}
				
				kursor.close();
				stmt.close();
				
				con.commit();
				
			} catch(Exception e){
				con.rollback();
				throw e;
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}
