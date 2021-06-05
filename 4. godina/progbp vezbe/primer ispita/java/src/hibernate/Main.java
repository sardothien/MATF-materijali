/* Napisati Java aplikaciju koja korišćenjem biblioteke Hibernate priprema 
 * finalni spisak kandidata. Za svaki studijski program čiji naziv počinje na
 * karakter koji korisnik unese sa standardnog ulaza ispisuje zaglavlje sa 
 * narednim informacijama: (1) naziv, (2) identifikator, i (3) broj ESPB potrebnih
 * da se taj studijski program završi. Aplikacija zatim pronalazi studente koji su
 * kandidati za praksu na tom studijskom programu, i za svakog kandidata:
 * - Ako je kandidat polagao test za praksu, izdvojiti: (1) ime, (2) prezime studenta, 
 *   (3) poene na osnovu studiranja, (4) poene koje je student dobio na testu za praksu
 *   i (5) ukupne poene. Urediti spisak po ukupnim poenima opadajuće.
 * - Ako kandidat nije polagao test za praksu, obrisati podatke o tom kandidatu.
 * Obavezno je koristiti podatke iz tabela DA.PRAKSA, DA.DOSIJE i DA.STUDIJSKIPROGRAM.
 * Napomene: Obraditi ceo zahtev zadatka u jednoj transakciji. Objektno-relaciono preslikavanje 
 * uraditi isključivo Java anotacijama. Za sve tabele koje se koriste u rešenju zadatka, a koje 
 * imaju ograničenja stranih ključeva jedne ka drugima, potrebno je implementirati odgovarajuća 
 * dvosmerna preslikavanja tih stranih ključeva. Nije dozvoljeno korišćenje SQL upita. Obavezno 
 * je obradjivanje grešaka. */

package hibernate;

import java.util.List;
import java.util.Scanner;

import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

public class Main {
	
	public static void main(String[] args) {
		
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		Scanner ulaz = new Scanner(System.in);
		
		try {
			tr = session.beginTransaction();
			
			System.out.println("Unesite karakter za pretragu studijskih programa:");
			String karakter = ulaz.next();
			
			String hql = "FROM Smer s WHERE s.naziv LIKE :nazivLike";
			Query<Smer> upit = session.createQuery(hql, Smer.class);
			upit.setParameter("nazivLike", karakter + "%");
			
			List<Smer> smerovi = upit.list();
			for(Smer s : smerovi){
				System.out.println(s);
				
				for(Student stud : s.getStudenti()) {
					hql = "FROM Praksa P WHERE P.indeks = :indeks";
					Query<Praksa> praksaUpit = session.createQuery(hql, Praksa.class);
					praksaUpit.setParameter("indeks", stud.getIndeks());
					
					List<Praksa> prakse = praksaUpit.list();
					
					for(Praksa p : prakse) {
						System.out.println("\t" + stud.getIme() + " " + stud.getPrezime() + " " + 
								p.getPoeniStudije() + " " + p.getPoeniTest());
					}
				}
				
				System.out.println();
			}
			
			ulaz.close();
			tr.commit();
			
		} catch (Exception e) {
			System.out.println("Greska");
			if(tr != null)
				tr.rollback();
		} finally {
			session.close();
		}
		
		HibernateUtil.getSessionFactory().close();
	}
	
}
