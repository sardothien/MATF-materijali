/* Napisati Java aplikaciju koja korišćenjem biblioteke Hibernate redom:

    1. Unosi podatak o novom predmetu u tabelu PREDMET sa identifikatorom 
       predmeta id i ostalim podacima koji se unose sa standardnog ulaza.
    2. Ispisuje podatake o predmetu sa identifikatorom id iz tabele PREDMET.
    3. Proverava da li korisnik želi da ažurira broj ESPB bodova za predmet
       sa identifikatorom id u tabeli PREDMET. Ukoliko korisnik odgovori 
       potvrdno, izvršava odgovarajuće ažuriranje. Novi broj bodova unosi
       se sa standardnog ulaza.
    4. Ispisuje podatake o predmetu sa identifikatorom id iz tabele PREDMET.
    5. Briše podatake o predmetu sa identifikatorom id iz tabele PREDMET.
    6. Ispisuje podatake o predmetu sa identifikatorom id iz tabele PREDMET.
 * Svaki zahtev implementirati kao posebnu transakciju. */

package zadatak_10_4;

import java.util.Scanner;

import org.hibernate.Session;
import org.hibernate.Transaction;

public class Main {

	public static void main(String[] args) {
		System.out.println("Pocetak rada");
		
		Scanner sc = new Scanner(System.in);
		
		// 1.
		unosPodataka(sc);
		// 2.
		ispisPodataka();
		// 3.
		azurirajPodatak(sc);
		// 4.
		ispisPodataka();
		// 5.
		obrisiPodatak();
		// 6.
		ispisPodataka();
		
		System.out.println("Kraj rada");
		sc.close();
		HibernateUtil.getSessionFactory().close();
	}

	private static void obrisiPodatak() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		try {
			tr = session.beginTransaction();
			
			Predmet pr = session.get(Predmet.class, 1570);
			if(pr != null){
				session.delete(pr);
				System.out.println("Uspesno brisanje");
			}
			else {
				System.out.println("Neuspesno brisanje");
			}
			
			tr.commit();
		} catch (Exception e) {
			System.out.println("Predmet nije obrisan");
			if(tr != null)
				tr.rollback();
		} finally {
			session.close();
		}
		
	}

	private static void azurirajPodatak(Scanner sc) {
		System.out.println("Da li zelite da azurirate ESPB predmeta? [da/ne]");
		sc.nextLine();
		String odgovor = sc.nextLine();
		if(odgovor.equalsIgnoreCase("ne")) {
			System.out.println("Nema azuriranja");
			return ;
		}
		else {
			System.out.println("Unesite novi broj ESPB:");
			Integer espb = sc.nextInt();
			
			Session session = HibernateUtil.getSessionFactory().openSession();
			Transaction tr = null;
			
			try {
				tr = session.beginTransaction();
				
				Predmet pr = session.get(Predmet.class, 1570);
				if(pr != null){
					pr.setEspb(espb);
					System.out.println("Uspesno azuriranje");
				}
				else {
					System.out.println("Neuspesno azuriranje");
				}
				
				tr.commit();
			} catch (Exception e) {
				System.out.println("Predmet nije azuriran");
				if(tr != null)
					tr.rollback();
			} finally {
				session.close();
			}
		}
	}

	private static void ispisPodataka() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		
		Predmet pr = session.get(Predmet.class, 1570);
		if(pr != null)
			System.out.println(pr);
		else
			System.out.println("Predmet nije pronadjen");
		
		session.close();
	}

	private static void unosPodataka(Scanner sc) {
		System.out.println("Unesite podatke o predmetu (oznaka, naziv, espb):");
		String oznaka = sc.nextLine();
		String naziv = sc.nextLine();
		Integer espb = sc.nextInt();
		
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		Predmet pr = new Predmet();
		pr.setId(1570);
		pr.setOznaka(oznaka);
		pr.setNaziv(naziv);
		pr.setEspb(espb);
		
		try {
			tr = session.beginTransaction();
			session.save(pr);
			System.out.println("Predmet je uspesno unet");
			tr.commit();
		} catch (Exception e) {
			System.out.println("Predmet nije unet");
			if(tr != null)
				tr.rollback();
		} finally {
			session.close();
		}
		
	}

}
