package hibernate;

import java.util.List;

import javax.persistence.*;

@Entity
@Table(name="DA.STUDIJSKIPROGRAM")
public class Smer {

	@Id
	private Integer id;
	@Column(name="NAZIV", nullable=false)
	private String naziv;
	@Column(name="OBIMESPB", nullable=false)
	private Integer obimESPB;
	
	@OneToMany(mappedBy="studProg")
	private List<Student> studenti; 
	
	public Smer(){
		
	}

	public Smer(Integer id, String naziv, Integer obimESPB) {
		super();
		this.id = id;
		this.naziv = naziv;
		this.obimESPB = obimESPB;
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

	public Integer getObimESPB() {
		return obimESPB;
	}

	public void setObimESPB(Integer obimESPB) {
		this.obimESPB = obimESPB;
	}

	public List<Student> getStudenti() {
		return studenti;
	}

	public void setStudenti(List<Student> studenti) {
		this.studenti = studenti;
	}

	@Override
	public String toString() {
		return naziv + " (" + id + ") -- bodovi: " + obimESPB; 
	}
}
