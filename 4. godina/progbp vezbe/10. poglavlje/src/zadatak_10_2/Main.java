/* Napisati Java aplikaciju koja korišćenjem biblioteke Hibernate implementira
 * unos podataka o novom ispitnom roku (jun 2020. godine) u tabelu ISPITNIROK,
 * a zatim briše podatke o unetom ispitnom roku iz tabele ISPITNIROK. */

package zadatak_10_2;

import org.hibernate.Session;
import org.hibernate.Transaction;

public class Main {

	public static void main(String[] args) {
		System.out.println("Pocetak rada");

		unosPodataka();
		obrisiPodatke();
		
		System.out.println("Kraj rada");
		HibernateUtil.getSessionFactory().close();
	}

	private static void obrisiPodatke() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		try {
			tr = session.beginTransaction();
			
			IspitniRokPK irpk = new IspitniRokPK(2020, "jun");
			IspitniRok ir = session.get(IspitniRok.class, irpk);
			session.delete(ir);
			System.out.println("Uspesno brisanje podataka");
			
			tr.commit();
			
		} catch (Exception e) {
			System.out.println("Neuspesno brisanje podataka");
			if(tr != null)
				tr.rollback();
		} finally {
			session.close();
		}
		
	}

	private static void unosPodataka() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		IspitniRok ir = new IspitniRok();
		ir.setId(new IspitniRokPK(2020, "jun"));
		ir.setNaziv("Jun 2020");
		ir.setPocetak("6/1/2021");
        ir.setKraj("6/22/2021");
        
        try {
        	tr = session.beginTransaction();
        	session.save(ir);
        	System.out.println("Ispitni rok je uspesno dodat");
        	System.out.println(ir);
        	tr.commit();
        } catch (Exception e) {
        	System.out.println("Neuspesno dodavanje ispitnog roka");
        	if(tr != null)
        		tr.rollback();
        } finally {
        	session.close();
        }
		
	}

}
