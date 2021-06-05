/* Napisati Java program u kojem se SQL naredbe izvršavaju dinamički koji 
 * za svaki predmet koji je obavezan na studijskom programu čiji je 
 * identifikator 103, pita korisnika da li želi da poveća broj ESPB bodova 
 * za 1. Ukoliko je odgovor korisnika ”da”, izvršava se odgovarajuća naredba. 
 * Zadatak uraditi tako da aplikacija radi u višekorisničkom okruženju. 
 * Obrada jednog predmeta treba da predstavlja jednu transakciju. Postaviti 
 * istek vremena na 5 sekundi. Omogućiti da drugi korisnici mogu da pristupaju 
 * predmetima koje ovaj program trenutno obrađuje. */

package zadatak_9_4;

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

	public static void main(String[] args) {
		String url = "jdbc:db2://localhost:50000/STUD2020";

		try(Connection con = DriverManager.getConnection(url, "student", "abcdef");
			Scanner sc = new Scanner(System.in)) {
			
			con.setAutoCommit(false);
			con.setTransactionIsolation(Connection.TRANSACTION_REPEATABLE_READ);
			
			Statement lockStmt = con.createStatement();
			lockStmt.executeUpdate("SET CURRENT LOCK TIMEOUT 5");
			
			try {
				
				String sql = "SELECT ID, NAZIV, ESPB "
						   + "FROM DA.PREDMET P "
						   + "WHERE ID IN (SELECT IDPREDMETA "
						   + "			   FROM DA.PREDMETPROGRAMA "
						   + "			   WHERE IDPROGRAMA = 103 AND "
						   + "					VRSTA = 'obavezan')";
				// HOLD_CURSORS_OVER_COMMIT -> kada imamo lockStmt
				Statement stmt = con.createStatement(ResultSet.TYPE_FORWARD_ONLY,
													 ResultSet.CONCUR_UPDATABLE,
													 ResultSet.HOLD_CURSORS_OVER_COMMIT);
				ResultSet kursor = stmt.executeQuery(sql);
				
				ArrayList<Integer> obradjeniPredmeti = new ArrayList<>();
				
				boolean imaRedova = true;
				for(;;){
					try{ // S ili U katanac
						imaRedova = kursor.next();
					} catch(SQLException e) {
						int sqlCode = e.getErrorCode();
						if(-913 <= sqlCode && sqlCode <= -911){
							System.out.println("Doslo je do cekanja");
							con.rollback();
							kursor.close();
							kursor = stmt.executeQuery(sql);
							continue;
						}
						throw e;
					}
					
					if(!imaRedova)
						break;
					
					int idPredmeta = kursor.getInt(1);
					String naziv = kursor.getString(2);
					short espb = kursor.getShort(3);
					
					if(obradjeniPredmeti.contains(idPredmeta))
						continue;
					
					System.out.println(idPredmeta + " : " + naziv + " (" + espb + ")");
					
					System.out.println("Da li zelite da povecate ESPB za 1? [da/ne]");
					String odgovor = sc.nextLine();
					if(odgovor.equalsIgnoreCase("da")){
						try{ // X katanac
							kursor.updateShort(3, (short) (espb+1));
							kursor.updateRow();
							System.out.println("Uspesno azuriranje");
						} catch(SQLException e){
							int sqlCode = e.getErrorCode();
							if(-913 <= sqlCode && sqlCode <= -911){
								System.out.println("Doslo je do cekanja");
								con.rollback();
								kursor.close();
								kursor = stmt.executeQuery(sql);
								continue;
							}
							throw e;
						}
					}
					
					obradjeniPredmeti.add(idPredmeta);
					con.commit();
					
					System.out.println("Da li zelite da zavrsite sa obradom? [da/ne]");
					odgovor = sc.nextLine();
					if(odgovor.equalsIgnoreCase("da"))
						break;
				}
				
				kursor.close();
				stmt.close();
				
				con.commit();
				
			} catch (Exception e){
				con.rollback();
				throw e;
			} finally {
                con.setAutoCommit(true);
                lockStmt.execute("SET CURRENT LOCK TIMEOUT NULL");
                lockStmt.close();
            }
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
	}

}
