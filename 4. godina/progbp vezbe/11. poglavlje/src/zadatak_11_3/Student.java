package zadatak_11_3;

import java.util.List;

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
	
	@ManyToOne
	@JoinColumn(name="IDPROGRAMA", referencedColumnName="ID", insertable=false, updatable=false)
	private StudijskiProgram studProg;
	
	@OneToMany(mappedBy="student")
	private List<Ispit> ispiti;
	
	public Student() {
		
	}

	public Student(Integer indeks, Integer idPrograma, String ime, String prezime) {
		super();
		this.indeks = indeks;
		this.idPrograma = idPrograma;
		this.ime = ime;
		this.prezime = prezime;
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

	public StudijskiProgram getStudProg() {
		return studProg;
	}

	public void setStudProg(StudijskiProgram studProg) {
		this.studProg = studProg;
	}

	public List<Ispit> getIspiti() {
		return ispiti;
	}

	public void setIspiti(List<Ispit> ispiti) {
		this.ispiti = ispiti;
	}

	@Override
	public String toString() {
		return "Student [indeks=" + indeks + ", idPrograma=" + idPrograma + ", ime=" + ime + ", prezime=" + prezime
				+ ", prosek = " + prosek() + "]";
	}
	
	private double prosek() {
		double p = 0.0;
		int brPolozenih = 0;
		
		List<Ispit> ispit = this.getIspiti();
		for(Ispit i : ispit) {
			if(i.getOcena() != null && i.getOcena() > 5 && i.getStatus().equals('o')) {
				brPolozenih++;
				p += i.getOcena();
			}
		}
		
		if(brPolozenih == 0)
			return 0.0;
		
		return p / brPolozenih;
	}
}
