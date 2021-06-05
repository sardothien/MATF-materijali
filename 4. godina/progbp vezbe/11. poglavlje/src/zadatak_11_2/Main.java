/* Napisati Java aplikaciju koja korišćenjem biblioteke Hibernate za
 * sve studente, koji su rođeni u mestu koje se unosi sa standardnog 
 * ulaza i upisali su studijski program obima epsb koji se unosi sa 
 * standardnog ulaza, ispisuje ime, prezime i naziv studijskog programa. */

package zadatak_11_2;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

public class Main {

	public static void main(String[] args) {
		System.out.println("Pocetak rada");

		Scanner sc = new Scanner(System.in);
		ispisiStudente(sc);
		
		System.out.println("Kraj rada");
		HibernateUtil.getSessionFactory().close();
	}

	private static void ispisiStudente(Scanner sc) {
		System.out.println("Unesite naziv mesta:");
		String mesto = sc.nextLine();
		System.out.println("Unesite obim ESPB:");
		short espb = sc.nextShort();
		
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		try {
			
			tr = session.beginTransaction();
			
			String sql = "SELECT S.ime, S.prezime, SP.naziv "
					   + "FROM Student AS S INNER JOIN S.studProg AS SP "
					   + "WHERE S.mesto = :mesto AND SP.obimESPB = :espb";
			
			Query<Object[]> upit = session.createQuery(sql, Object[].class);
			upit.setParameter("mesto", mesto);
			upit.setParameter("espb", espb);
			
			List<Object[]> studenti = upit.list();
			if(studenti.isEmpty()){
				System.out.println("Nema studenata");
			}
			else {
				for(Object[] s : studenti)
					System.out.println(Arrays.toString(s));
			}
			
			tr.commit();
			
		} catch (Exception e) {
			System.out.println("Neuspeh");
			e.printStackTrace();
			if(tr != null)
				tr.rollback();
		} finally {
			session.close();
		}
	}

}
