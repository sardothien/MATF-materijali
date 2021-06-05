package zadatak_11_3;

import java.util.List;

import javax.persistence.*;

@Entity
@Table(name="DA.STUDIJSKIPROGRAM")
public class StudijskiProgram {
	
	@Id
	private Integer id;
	@Column(name="NAZIV", nullable=false)
	private String naziv;
	
	@OneToMany(mappedBy="studProg")
	private List<Student> studenti;
	
	public StudijskiProgram(){
		
	}
	
	public StudijskiProgram(Integer id, String naziv) {
		super();
		this.id = id;
		this.naziv = naziv;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getNaziv() {
		return naziv;
	}

	public void setNaziv(String naziv) {
		this.naziv = naziv;
	}

	public List<Student> getStudenti() {
		return studenti;
	}

	public void setStudenti(List<Student> studenti) {
		this.studenti = studenti;
	}

	@Override
	public String toString() {
		return "StudijskiProgram [ " + naziv + " ]";
	}

}