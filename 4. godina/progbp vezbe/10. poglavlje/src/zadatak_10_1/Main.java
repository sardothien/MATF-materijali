/* Napisati Java aplikaciju koja korišćenjem biblioteke Hibernate redom:

    1. unosi podatak o novom studijskom programu u tabeli STUDIJSKIPROGRAM 
       sa podacima iz naredne tabele,
    2. čita podatke o studijskom programu sa identifikatorom 102 iz tabele 
       STUDIJSKIPROGRAM,
    3. ažurira podatke o studijskom programu sa identifikatorom 102 iz tabele 
       STUDIJSKIPROGRAM,
    4. čita podatke o studijskom programu sa identifikatorom 102 iz tabele 
       STUDIJSKIPROGRAM,
    5. briše podatke o studijskom programu sa identifikatorom 102 iz tabele 
       STUDIJSKIPROGRAM,
    6. čita podatke o studijskom programu sa identifikatorom 102 iz tabele 
       STUDIJSKIPROGRAM.
 */

package zadatak_10_1;

import org.hibernate.Session;
import org.hibernate.Transaction;

public class Main {

	public static void main(String[] args) {
		
		System.out.println("Pocetak rada");
		
		// 1.
		unesiPodatke();
		// 2.
		procitajPodatke();
		// 3.
		azurirajPodatke();
		// 4.
		procitajPodatke();
		// 5.
		obrisiPodatke();
		// 6.
		procitajPodatke();
		
		System.out.println("Kraj rada");
		HibernateUtil.getSessionFactory().close();

	}

	private static void obrisiPodatke() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		try {
			
			tr = session.beginTransaction();
			
			StudijskiProgram sp = session.get(StudijskiProgram.class, 102);
			if(sp != null) {
				session.delete(sp);
				System.out.println("Studijski program je obrisan");
			}
			else {
				System.out.println("Nije pronadjen studijski program");
			}
			
			tr.commit();
			
		} catch (Exception e) {
			System.out.println("Neuspesno brisanje");
			if(tr != null)
				tr.rollback();
		} finally {
			session.close();
		}
		
	}

	private static void azurirajPodatke() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		try {
			tr = session.beginTransaction();
			
			StudijskiProgram sp = session.get(StudijskiProgram.class, 102);
			if(sp != null) {
				sp.setObimESPB((short) 120);
				sp.setOpis("Studijski program sa 120 ESPB");
				System.out.println("Studijski program je azuriran");
			}
			else {
				System.out.println("Nije pronadjen studijski program");
			}
			
			tr.commit();
			
		} catch (Exception e) {
			System.out.println("Neuspesno azuriranje");
			if(tr != null)
				tr.rollback();
		} finally {
			session.close();
		}		
	}

	private static void procitajPodatke() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		StudijskiProgram sp = session.get(StudijskiProgram.class, 102);
		
		if(sp == null)
			System.out.println("Nije pronadjen studijski program");
		else
			System.out.println(sp);
		
		session.close();
	}

	private static void unesiPodatke() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		StudijskiProgram sp = new StudijskiProgram();
		sp.setId(102);
		sp.setOznaka("MATF_2020");
		sp.setNaziv("Novi MATF studijski program u 2020. godini");
		sp.setObimESPB((short) 240);
		sp.setIdNivoa((short) 1);
		sp.setZvanje("Diplomirani informaticar");
		sp.setOpis("Novi studijski program na Matematickom fakultetu");
		
		try {
			tr = session.beginTransaction();
			session.save(sp);
			System.out.println("Uspesno unosenje podataka u bazu.");
			tr.commit();
		} catch (Exception e) {
			System.out.println("Studijski program nije unet");
			if(tr != null)
				tr.rollback();
		} finally {
			session.close();
		}
	}

}
