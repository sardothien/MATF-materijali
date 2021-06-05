/* Napisati Java program u kojem se naredbe izvršavaju dinamički koji:

    1. Kreira tabelu UNETIPREDMETI čije su kolone: 
       (1) identifikator predmeta i (2) broj položenih ispita za taj predmet.
       Postaviti odgovarajuće primarne i strane ključeve.
    2. Za svaki predmet koji nije prethodno obrađen (tj. koji se ne nalazi u 
       tabeli UNETIPREDMETI) pronalazi statistiku koja se sastoji od njegovog
       identifikatora i broja položenih ispita.
    3. Za svaku pronađenu statistiku ispisuje podatke na standardni izlaz i
       pita korisnika da li želi da unete statistiku u tabelu UNETIPREDMETI.
       Ukoliko korisnik potvrdi, potrebno je uneti statistiku u datu tabelu 
       i ispisati poruku o uspehu. U suprotnom, ispisati poruku da je korisnik 
       poništio unos.
 */

package zadatak_8_8;

import java.sql.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	static {
		try {
			Class.forName("com.ibm.db2.jcc.DB2Driver");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	private static class StatistikaPolaganja {
		private int idPredmeta;
		private int brPolaganja;
		
		public StatistikaPolaganja(int idPredmeta, int brPolaganja) {
			super();
			this.idPredmeta = idPredmeta;
			this.brPolaganja = brPolaganja;
		}
	}

	public static void main(String[] args) {
		String url = "jdbc:db2://localhost:50000/STUD2020";

		try(Connection con = DriverManager.getConnection(url, "student", "abcdef");
			Scanner sc = new Scanner(System.in)){
			
			// 1.
			kreirajTabelu(con);
			
			// 2.
			ArrayList<StatistikaPolaganja> statistike = new ArrayList<>();
			pronadjiStatistike(con, statistike);
			
			// 3. 
			unesiStatistike(con, statistike, sc);
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	private static void unesiStatistike(Connection con, ArrayList<StatistikaPolaganja> statistike, Scanner sc) throws SQLException {
		String sql = "SELECT * FROM DA.UNETIPREDMETI";
		
		Statement stmt = con.createStatement(ResultSet.TYPE_FORWARD_ONLY,
											 ResultSet.CONCUR_UPDATABLE);
		ResultSet kursor = stmt.executeQuery(sql);
		
		for(StatistikaPolaganja sp: statistike){
			kursor.moveToInsertRow();
			kursor.updateInt(1, sp.idPredmeta);
			kursor.updateInt(2, sp.brPolaganja);
			
			System.out.println(sp.idPredmeta + " : " + sp.brPolaganja);
			
			System.out.println("Da li zelite da unesete statistiku? [da/ne]");
			String odgovor = sc.nextLine();
			if(odgovor.equalsIgnoreCase("da")){
				kursor.insertRow();
				System.out.println("\tUspesan unos.");
			}
			else {
				System.out.println("\tPonistili ste unos.");
			}
			
			kursor.moveToCurrentRow();
		}
		
		while(kursor.next()){
			System.out.println(kursor.getInt(1) + " : " + kursor.getInt(2));
		}
		
		kursor.close();
		stmt.close();
	}

	private static void pronadjiStatistike(Connection con, ArrayList<StatistikaPolaganja> statistike) throws SQLException {
		String sql = "SELECT IDPREDMETA, COUNT(OCENA) "
				   + " FROM DA.ISPIT "
				   + "WHERE OCENA > 5 AND STATUS = 'o' "
				   + "	AND IDPREDMETA NOT IN (SELECT IDPREDMETA"
				   + "						   FROM DA.UNETIPREDMETI) "
				   + "GROUP BY IDPREDMETA";
		
		Statement stmt = con.createStatement();
		ResultSet kursor = stmt.executeQuery(sql);
		while(kursor.next()){
			int idPredmeta = kursor.getInt(1);
			int brPolozenih = kursor.getInt(2);
			statistike.add(new StatistikaPolaganja(idPredmeta, brPolozenih));
		}
		
		kursor.close();
		stmt.close();
	}

	private static void kreirajTabelu(Connection con) throws SQLException {
		String sql = "CREATE TABLE DA.UNETIPREDMETI ( "
					+ " IDPREDMETA INTEGER NOT NULL, "
					+ " BROJPOLOZENIH INTEGER NOT NULL, "
					+ " PRIMARY KEY (IDPREDMETA), "
					+ " FOREIGN KEY (IDPREDMETA) REFERENCES DA.PREDMET)";
		
		Statement stmt = con.createStatement();
		try{
			stmt.executeUpdate(sql);
		} catch(SQLException e){
			if(e.getErrorCode() == -601)
				System.out.println("Tabela je vec kreirana.");
			else
				throw e;
		}
		
		stmt.close();
	}

}
