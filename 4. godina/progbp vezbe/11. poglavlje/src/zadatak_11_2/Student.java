package zadatak_11_2;

import javax.persistence.*;

@Entity
@Table(name="DA.DOSIJE")
public class Student {

	@Id
	private Integer indeks;
	@Column(name="IDPROGRAMA", nullable=false)
	private Integer idPrograma;
	@Column(name="IME", nullable=false)
	private String ime;
	@Column(name="PREZIME", nullable=false)
	private String prezime;
	@Column(name="MESTORODJENJA", nullable=true)
	private String mesto;
	
	@ManyToOne
	@JoinColumn(name="IDPROGRAMA", referencedColumnName="ID", insertable=false, updatable=false)
	private StudijskiProgram studProg;
	
	public Student() {
		
	}

	public Student(Integer indeks, Integer idPrograma, String ime, String prezime, String mesto) {
		super();
		this.indeks = indeks;
		this.idPrograma = idPrograma;
		this.ime = ime;
		this.prezime = prezime;
		this.mesto = mesto;
	}

	public Integer getIndeks() {
		return indeks;
	}

	public void setIndeks(Integer indeks) {
		this.indeks = indeks;
	}

	public Integer getIdPrograma() {
		return idPrograma;
	}

	public void setIdPrograma(Integer idPrograma) {
		this.idPrograma = idPrograma;
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

	public String getMesto() {
		return mesto;
	}

	public void setMesto(String mesto) {
		this.mesto = mesto;
	}

	public StudijskiProgram getStudProg() {
		return studProg;
	}

	public void setStudProg(StudijskiProgram studProg) {
		this.studProg = studProg;
	}

	@Override
	public String toString() {
		return "Student [indeks=" + indeks + ", idPrograma=" + idPrograma + ", ime=" + ime + ", prezime=" + prezime
				+ ", mesto=" + mesto + "]";
	}
}
