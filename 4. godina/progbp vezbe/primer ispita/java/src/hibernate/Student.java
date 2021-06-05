package hibernate;

import javax.persistence.*;

@Entity
@Table(name="DA.DOSIJE")
public class Student {
	
	@Id
	private Integer indeks;
	@Column(name="IME", nullable=false)
	private String ime;
	@Column(name="PREZIME", nullable=false)
	private String prezime;
	@Column(name="IDPROGRAMA", nullable=false)
	private Integer idPrograma;
	
	@OneToOne(mappedBy="student")
	private Praksa praksa;
	
	@ManyToOne
	@JoinColumn(name="IDPROGRAMA", referencedColumnName="ID", insertable=false, updatable=false)
	private Smer studProg;
	
	public Student() {
		
	}

	public Student(Integer indeks, String ime, String prezime, Integer idPrograma) {
		super();
		this.indeks = indeks;
		this.ime = ime;
		this.prezime = prezime;
		this.idPrograma = idPrograma;
	}

	public Integer getIndeks() {
		return indeks;
	}

	public void setIndeks(Integer indeks) {
		this.indeks = indeks;
	}

	public String getIme() {
		return ime;
	}

	public void setIme(String ime) {
		this.ime = ime;
	}

	public String getPrezime() {
		return prezime;
	}

	public void setPrezime(String prezime) {
		this.prezime = prezime;
	}

	public Integer getIdPrograma() {
		return idPrograma;
	}

	public void setIdPrograma(Integer idPrograma) {
		this.idPrograma = idPrograma;
	}

	public Praksa getPraksa() {
		return praksa;
	}

	public void setPraksa(Praksa praksa) {
		this.praksa = praksa;
	}

	@Override
	public String toString() {
		return "Student [indeks=" + indeks + ", ime=" + ime + ", prezime=" + prezime + ", idPrograma=" + idPrograma
				+ "]";
	}
}