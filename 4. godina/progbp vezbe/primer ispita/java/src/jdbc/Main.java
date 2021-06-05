/* U klasi Main.java implementirati naredne metode. Nije dozvoljeno menjati
 * potpise metoda; jedino je moguće dodavati izuzetke koje oni ispaljuju. 
 * Nije dozvoljeno implementirati opisane operacije van tela metoda (ali je 
 * moguće koristiti pomoćne metode).
 * 
 * (a) Napisati metod private static void aPronadjiSveKandidate(Connection con) throws SQLException 
 *     koja na standardni izlaz ispisuje naredne informacije o kandidatima: 
 *     (1) indeks, i (2) poeni tokom studija. Podatke ispisati samo za one kandidate koji nisu
 *     polagali test (tj. koji imaju -1 poen na testu). Podatke urediti po poenima ostvarenim 
 *     tokom studija opadajuće. 
 *     Napomene: Proveravati greške koje se javljaju prilikom izvršavanja aplikacije u 
 *     višekorisničkom okruženju.
 * (b) Napisati metod private static void bUnesiPoeneSaTesta(Connection con, Scanner ulaz) 
 *     throws SQLException koji zahteva od korisnika da odabere jedan od indeksa koji je 
 *     ispisan metodom pod (a). Nakon odabira indeksa, aplikacija vrši izmenu podataka za 
 *     dati indeks metodom pod (c). Zatim, aplikacija pita da li korisnik želi da unese
 *     poene za još jednog studenta. Ukoliko je odgovor potvrdan, cela akcija se ponavlja. 
 *     U suprotnom, metod se završava.
 *     Napomene: Obrada podataka za jednog studenta predstavlja jednu transakciju.
 * (c) Napisati metod private static void cUnesiPoeneNaTestuZaStudenta(Connection con, Integer indeks, 
 *     Scanner ulaz) throws SQLException koji za studenta čiji se indeks prosledjuje metodu pita 
 *     korisnika da unese poene na testu za praksu. Nakon unošenja poena, aplikacija vrši izmenu 
 *     podataka u tabeli DA.PRAKSA tako što studentu sa datim indeksom postavlja poene na testu.
 *     Napomene: Proveravati greške koje se javljaju prilikom izvršavanja aplikacije u višekorisničkom
 *     okruženju.
 * Napisati Java/SQL aplikaciju u kojoj se SQL naredbe izvršavaju dinamički (JDBC) koja metodom pod
 * (a) ispisuje podatke. Zatim, aplikacija metodom pod (b) obraduje informacije o kandidatima, sve dok 
 * korisnik ne završi obradu.
 * Napomene: Postaviti istek vremena za zahtevanje katanaca na 5 sekundi na nivou celokupne aplikacije. 
 * Omogućiti da nijedna druga aplikacija ne može da menja podatke sve dok ova aplikacija ne završi sa 
 * transakcijama, ali može da unosi nove podatke za obradu. Obavezno je obradivanje grešaka. */

package jdbc;

import java.sql.*;
import java.util.Scanner;

public class Main {
	
	static {
		try {
			Class.forName("com.ibm.db2.jcc.DB2Driver");
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public static void main(String[] args) {
		String url = "jdbc:db2://localhost:50000/STUD2020";

		try (
			Connection con = DriverManager.getConnection(url, "student", "abcdef");
			Scanner ulaz = new Scanner(System.in);
		) {
			
			con.setAutoCommit(false);
			
			Statement lockStmt = con.createStatement();
			lockStmt.executeUpdate("SET CURRENT LOCK TIMEOUT 5");
			
			try {
				aPronadjiSveKandidate(con);
				bUnesiPoeneSaTesta(con, ulaz);
			} catch (Exception e) {
				con.rollback();
				throw e;
			} finally {
				con.setAutoCommit(true);
				lockStmt.executeUpdate("SET CURRENT LOCK TIMEOUT NULL");
			}
			
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(2);
		}
	}

	private static void aPronadjiSveKandidate(Connection con) throws SQLException {
		String sql = "SELECT INDEKS, POENI_STUDIJE "
				   + "FROM DA.PRAKSA "
				   + "WHERE POENI_TEST = -1 "
				   + "ORDER BY POENI_STUDIJE DESC";
		
		Statement stmt = con.createStatement(ResultSet.TYPE_FORWARD_ONLY,
											 ResultSet.CONCUR_READ_ONLY,
											 ResultSet.HOLD_CURSORS_OVER_COMMIT);
		ResultSet kursor = stmt.executeQuery(sql);
		
		boolean imaRedova;
		while(true){
			try {
				imaRedova = kursor.next();
			} catch (SQLException e) {
				if(-913 <= e.getErrorCode() && e.getErrorCode() <= -911){
					System.out.println("Fetch");
					con.rollback();
					kursor.close();
					kursor = stmt.executeQuery(sql);
					continue;
				}
				throw e;
			}
			
			if(!imaRedova)
				break;
			
			System.out.println(kursor.getInt(1) + "  " + kursor.getDouble(2));
		}
		
		kursor.close();
		stmt.close();
	}
	
	private static void bUnesiPoeneSaTesta(Connection con, Scanner ulaz) throws SQLException {
		for(;;){
			System.out.println("Odaberite narednog kandidata iz liste:");
			Integer indeks = ulaz.nextInt();
			ulaz.nextLine();
			
			cUnesiPoeneNaTestuZaStudenta(con, indeks, ulaz);
			
			con.commit();
			
			System.out.println("Nastaviti dalje? [da/ne]");
			String odgovor = ulaz.nextLine();
			if(odgovor.equalsIgnoreCase("da")){
				continue;
			}
			else {
				break;
			}
		}
	}

	private static void cUnesiPoeneNaTestuZaStudenta(Connection con, Integer indeks, Scanner ulaz) throws SQLException {
		System.out.println("Unesite poene sa testa za kandidata sa indeksom: " + indeks);
		double poeni = ulaz.nextDouble();
		ulaz.nextLine();
		
		String sql = "UPDATE DA.PRAKSA SET POENI_TEST = ? WHERE INDEKS = ?";
		PreparedStatement pstmt = con.prepareStatement(sql);
		pstmt.setDouble(1, poeni);
		pstmt.setInt(2, indeks);
		
		while(true){
			try {
				pstmt.executeUpdate();
			} catch (SQLException e) {
				if(-913 <= e.getErrorCode() && e.getErrorCode() <= -911){
					System.out.println("Update");
					con.rollback();
					continue;
				}
				throw e;
			}
			break;
		}
		
		System.out.println();
		
		pstmt.close();
	}
}
