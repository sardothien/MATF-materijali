/* Napisati Java program u kojem se SQL naredbe izvršavaju dinamički koji redom:

    1. Pronalazi i ispisuje najveći indeks iz tabele ISPIT.
    2. Briše studenta sa pronađenim indeksom iz tabele ISPIT i 
       ispisuje poruku korisniku o uspešnosti brisanja.
    3. Ponovo pronalazi i ispisuje najveći indeks iz tabele ISPIT.
    4. Pita korisnika da li želi da potvrdi ili poništi izmene. 
       U zavisnosti od korisnikovog odgovora, aplikacija potvrđuje
       ili poništava izmene uz ispisivanje poruke korisniku.
    5. Ponovo pronalazi i ispisuje najveći indeks iz tabele ISPIT.
 */

package zadatak_9_1;

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

		try(Connection con = DriverManager.getConnection(url, "student", "abcdef")){
			
			// iskljucujemo automatski commit
			con.setAutoCommit(false);
			
			try { // zbog poziva commit ili rollback
				
				// 1.
				int indeks = maxIndeks(con);
				System.out.println("Max indeks: " + indeks);
				// 2.
				obrisiStudenta(con, indeks);
				// 3.
				indeks = maxIndeks(con);
				System.out.println("Max indeks: " + indeks);
				// 4. 
				potvrdiIliPonistiIzmene(con);
				// 5.
				indeks = maxIndeks(con);
				System.out.println("Max indeks: " + indeks);
				
				con.commit();
				
			} catch (Exception e){
				con.rollback();
				throw e;
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
			System.exit(2);
		} catch (Exception e) {
            e.printStackTrace();
            System.exit(2);
        }
	}

	private static void potvrdiIliPonistiIzmene(Connection con) throws SQLException {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Da li zelite da potvrdite izmene? [da/ne]");
		String odgovor = sc.nextLine();
		if(odgovor.equalsIgnoreCase("da")){
			con.commit();
			System.out.println("Izmene su potvrdjene");
		}
		else {
			con.rollback();
			System.out.println("Izmene su ponistene");
		}
		
		sc.close();
	}

	private static void obrisiStudenta(Connection con, int indeks) throws Exception {
		String sql = "DELETE FROM DA.ISPIT WHERE INDEKS = ?";
		PreparedStatement pstmt = con.prepareStatement(sql, ResultSet.TYPE_FORWARD_ONLY, ResultSet.CONCUR_UPDATABLE);
		pstmt.setInt(1, indeks);
		pstmt.executeUpdate();
		System.out.println("Uspesno brisanje studenta");	
		pstmt.close();
	}

	private static int maxIndeks(Connection con) throws Exception {
		String sql = "SELECT MAX(INDEKS) FROM DA.ISPIT";
		
		Statement stmt = con.createStatement();
		ResultSet kursor = stmt.executeQuery(sql);
		
		int indeks = 0;
		if(kursor.next())
			indeks = kursor.getInt(1);
		else 
			throw new Exception("Nema ispita u bazi");
		
		kursor.close();
		stmt.close();
		
		return indeks;
	}

}
