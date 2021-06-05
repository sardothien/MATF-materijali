/* Napisati Java program u kojem se naredbe izvršavaju dinamički koji 
 * sa standardnog ulaza učitava ceo broj N i izdvaja indeks, ime, 
 * prezime i naziv studijskog programa svih studenata koji su položili 
 * tačno N predmeta, kao i spisak tih predmeta (naziv i ocena). */

package zadatak_8_4;

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
			
			String sql = ucitajSQL("upit.sql");
			
			System.out.println("Ucitaj ceo broj N:");
			int N = sc.nextInt();
			
			PreparedStatement pstmt = con.prepareStatement(sql);
			pstmt.setInt(1, N);
			ResultSet kursor = pstmt.executeQuery();
			
			int indeks = 0;
			while(kursor.next()){
				
				if(indeks != kursor.getInt(1)){
					if(indeks != 0)
						System.out.println("\n");
					
					indeks = kursor.getInt(1);
					String ime = kursor.getString(2);
					String prezime = kursor.getString(3);
					String nazivSP = kursor.getString(4);
					
					System.out.println(indeks + ": " + ime + " " + prezime + " - " + nazivSP);
				}
				
				String nazivPredmeta = kursor.getString(5);
				short ocena = kursor.getShort(6);
				
				System.out.println("\t" + nazivPredmeta + " : " + ocena);
			}			
			
			kursor.close();
			pstmt.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
			System.exit(1);
		} catch (FileNotFoundException e) {
			System.out.println("File not found");
			e.printStackTrace();
		}
	}


	private static String ucitajSQL(String dat) throws FileNotFoundException {
		String putanja = "./bin/zadatak_8_4/" + dat;
		StringBuilder sb = new StringBuilder("");
		String linija = null;
		try(Scanner in = new Scanner(new File(putanja), "utf-8")){
			while(in.hasNext()){
				linija = in.nextLine();
				sb.append(linija);
				sb.append('\n');
			}
		}
		
		return sb.toString();
	}

}
