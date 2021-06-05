package hibernate;

import javax.persistence.*;

@Entity
@Table(name="DA.PRAKSA")
public class Praksa {
	
	@Id
	private Integer indeks;
	@Column(name="POENI_STUDIJE", nullable=false)
	private double poeniStudije;
	@Column(name="POENI_TEST", nullable=false)
	private double poeniTest;
	
	@OneToOne
	@JoinColumn(name="INDEKS", referencedColumnName="INDEKS", insertable=false, updatable=false)
	private Student student;
	
	public Praksa() {
		
	}

	public Praksa(Integer indeks, double poeniStudije, double poeniTest) {
		super();
		this.indeks = indeks;
		this.poeniStudije = poeniStudije;
		this.poeniTest = poeniTest;
	}

	public Integer getIndeks() {
		return indeks;
	}

	public void setIndeks(Integer indeks) {
		this.indeks = indeks;
	}

	public double getPoeniStudije() {
		return poeniStudije;
	}

	public void setPoeniStudije(double poeniStudije) {
		this.poeniStudije = poeniStudije;
	}

	public double getPoeniTest() {
		return poeniTest;
	}

	public void setPoeniTest(double poeniTest) {
		this.poeniTest = poeniTest;
	}

	public Student getStudent() {
		return student;
	}

	public void setStudenti(Student student) {
		this.student = student;
	}

	@Override
	public String toString() {
		return "Praksa [indeks=" + indeks + ", poeniStudije=" + poeniStudije + ", poeniTest=" + poeniTest + "]";
	}
	
}
