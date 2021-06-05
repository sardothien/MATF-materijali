/* Napisati Java aplikaciju koja korišćenjem biblioteke Hibernate ispisuje 
 * nazive svih studijskih programa. Nakon svakog naziva studijskog programa,
 * ispisuju se indeks, ime, prezime i prosek svih studenata na tom studijskom
 * programu. */

package zadatak_11_3;

import java.util.List;

import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

public class Main {

	public static void main(String[] args) {
		System.out.println("Pocetak rada");
		
		ispisiPodatke();
		
		System.out.println("Kraj rada");
		HibernateUtil.getSessionFactory().openSession();
	}

	private static void ispisiPodatke() {
		Session session = HibernateUtil.getSessionFactory().openSession();
		Transaction tr = null;
		
		
		try {
			tr = session.beginTransaction();
			
			String sql = "FROM StudijskiProgram";
			Query<StudijskiProgram> upit = session.createQuery(sql, StudijskiProgram.class);
			
			List<StudijskiProgram> studProgrami = upit.list();
			for(StudijskiProgram sp : studProgrami) {
				System.out.println(sp);
				
				sql = "FROM Student AS S "
					+ "WHERE S.idPrograma = :id";
				Query<Student> upitStudenti = session.createQuery(sql, Student.class);
				upitStudenti.setParameter("id", sp.getId());
				List<Student>  studenti = upitStudenti.list();
				
				for(Student s : studenti) {
					System.out.println("\t" + s);
				}
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
