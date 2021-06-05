package zadatak_11_3;

import org.hibernate.SessionFactory;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;

public class HibernateUtil {
	
	private static SessionFactory sessionFactory = null;
	
	static {
		try {
			StandardServiceRegistry registry = new StandardServiceRegistryBuilder().configure().build();
			sessionFactory = new MetadataSources(registry)
					.addAnnotatedClass(Student.class)
					.addAnnotatedClass(StudijskiProgram.class)
					.addAnnotatedClass(Ispit.class)
					.buildMetadata().buildSessionFactory();
		} catch (Throwable e){
			e.printStackTrace();
			System.exit(1);
		}
	}

	public static SessionFactory getSessionFactory() {
		return sessionFactory;
	}

}
