/* Napisati Java aplikaciju koja korišćenjem biblioteke Hibernate
 * ispisuje podatke o svim ispitnim rokovima. */

package zadatak_11_1;

import java.util.List;

import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

public class Main {

	public static void main(String[] args) {
		
		System.out.println("Pocetak rada");
		
		ispisiIR();
		
		System.out.println("Kraj rada");
		HibernateUtil.getSessionFactory().close();
	}

	private static void ispisiIR() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		try {
			tr = session.beginTransaction();

			String sql = "FROM IspitniRok";
			
			Query<IspitniRok> upit = session.createQuery(sql, IspitniRok.class);
			List<IspitniRok> ispitniRokovi = upit.list();
			
			for(IspitniRok ir : ispitniRokovi) {
				System.out.println(ir);
			}
			
			tr.commit();
			
		} catch (Exception e) {
			System.out.println("Neuspeh");
			if(tr != null) 
				tr.rollback();
		} finally {
			session.close();
		}
	}

}
