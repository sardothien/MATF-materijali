/* Napisati Java program u kojem se naredbe izvršavaju dinamički koji
 * izdvaja indeks, ime, prezime i naziv studijskog programa svih studenata 
 * koji su položili tačno N predmeta, kao i spisak tih predmeta (naziv i 
 * ocena). Broj N se učitava sa standardnog ulaza. Za svakog studenta
 * napraviti posebnu sekciju izveštaja. */

package zadatak_8_10;

import java.io.File;
import java.io.FileNotFoundException;
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
			
			String sql_ispiti = ucitajSQL("ispiti.sql");
			String sql_predmeti = ucitajSQL("predmeti.sql");
			
			System.out.println("Unesite ceo broj N:");
			int n = sc.nextInt();
			
			PreparedStatement pstmt = con.prepareStatement(sql_ispiti);
			pstmt.setInt(1, n);
			ResultSet kursor1 = pstmt.executeQuery();
			
			while(kursor1.next()){
				int indeks = kursor1.getInt(1);
				String ime = kursor1.getString(2);
				String prezime = kursor1.getString(3);
				String nazivSP = kursor1.getString(4);
				
				System.out.println(indeks + " - " + ime + " " + prezime + " (" + nazivSP + ")");
				
				PreparedStatement pstmt_in = con.prepareStatement(sql_predmeti);
				pstmt_in.setInt(1, indeks);
				ResultSet kursor2 = pstmt_in.executeQuery();
				
				while(kursor2.next()){
					String nazivPredmeta = kursor2.getString(1);
					short ocena = kursor2.getShort(2);
					
					System.out.println("\t" + nazivPredmeta + " : " + ocena);
				}
				
				kursor2.close();
				pstmt_in.close();
			}
			
			kursor1.close();
			pstmt.close();
			
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	private static String ucitajSQL(String dat){
		String putanja = "./bin/zadatak_8_10/" + dat;
		StringBuilder sb = new StringBuilder("");
		String linija = null;
		try(Scanner in = new Scanner(new File(putanja))){
			while(in.hasNextLine()){
				linija = in.nextLine();
				sb.append(linija);
				sb.append("\n");
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		return sb.toString();
	}
}
