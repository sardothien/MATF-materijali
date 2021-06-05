/* Napisati Java aplikaciju koja korišcenjem biblioteke Hibernate redom:

    1. Unosi podatak o novom novou kvalifikacije u tabelu NIVOKVALIFIKACIJE
       sa podacima iz naredne tabele.
    2. Ispisuje podatake o novou kvalifikacije sa identifikatorom 42 iz 
       tabele NIVOKVALIFIKACIJE.
    3. Ažurira stepen za nivo kvalifikacije sa identifikatorom 42 iz tabele
       NIVOKVALIFIKACIJE. Naziv postaviti na vrednost Novi nivo kvalifikacije.
    4. Ispisuje podatake o novou kvalifikacije sa identifikatorom 42 iz tabele 
       NIVOKVALIFIKACIJE.
    5. Briše podatake o novou kvalifikacije sa identifikatorom 42 iz tabele 
       NIVOKVALIFIKACIJE.
    6. Ispisuje podatake o novou kvalifikacije sa identifikatorom 42 iz tabele
       NIVOKVALIFIKACIJE.
 * Svaki zahtev implementirati kao posebnu transakciju. */

package zadatak_10_3;

import org.hibernate.Session;
import org.hibernate.Transaction;

public class Main {

	public static void main(String[] args) {
		System.out.println("Pocetak rada");

		// 1.
		unesiPodatke();
		// 2.
		ispisiPodatke();
		// 3.
		azurirajPodatke();
		// 4.
		ispisiPodatke();
		// 5.
		obrisiPodatak();
		// 6.
		ispisiPodatke();
		
		System.out.println("Kraj rada");
		HibernateUtil.getSessionFactory().close();
	}

	private static void obrisiPodatak() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		try {
			tr = session.beginTransaction();
			
			NivoKvalifikacije nk = session.get(NivoKvalifikacije.class, 42);
			if(nk != null) {
				session.delete(nk);
				System.out.println("Uspesno brisanje");
			} 
			else {
				System.out.println("Nije pronadjen podatak");
			}
			
			tr.commit();
		} catch (Exception e) {
			System.out.println("Neuspesno brisanje podataka");
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
			
			NivoKvalifikacije nk = session.get(NivoKvalifikacije.class, 42);
			if(nk != null) {
				nk.setNaziv("Novi nivo kvalifikacije");
				System.out.println("Uspesno azuriranje");
			} 
			else {
				System.out.println("Nije pronadjen podatak");
			}
			
			tr.commit();
		} catch (Exception e) {
			System.out.println("Neuspesno azuriranje podataka");
			if(tr != null)
				tr.rollback();
		} finally {
			session.close();
		}		
	}

	private static void ispisiPodatke() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		NivoKvalifikacije nk = session.get(NivoKvalifikacije.class, 42);
		if(nk != null){
			System.out.println(nk);
		}
		else {
			System.out.println("Nivo kvalifikacije nije pronadjen");
		}
		
		session.close();
	}

	private static void unesiPodatke() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		NivoKvalifikacije nk = new NivoKvalifikacije();
		nk.setId(42);
		nk.setNaziv("Novi nivo");
		
		try {
			tr = session.beginTransaction();
			session.save(nk);
			System.out.println("Uspesno unosenje podataka");
			tr.commit();
		} catch (Exception e) {
			System.out.println("Neuspesno unosenje podataka");
			if(tr != null)
				tr.rollback();
		} finally {
			session.close();
		}
		
	}

}
