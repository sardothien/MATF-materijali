package zadatak_10_4;

import javax.persistence.*;

@Entity
@Table(name="DA.PREDMET")
public class Predmet {

	@Id
	private Integer id;
	@Column(name="OZNAKA", nullable=false)
	private String oznaka;
	@Column(name="NAZIV", nullable=false)
	private String naziv;
	@Column(name="ESPB", nullable=false)
	private Integer espb;
	
	public Predmet() {
		
	}

	public Predmet(Integer id, String oznaka, String naziv, Integer espb) {
		super();
		this.id = id;
		this.oznaka = oznaka;
		this.naziv = naziv;
		this.espb = espb;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getOznaka() {
		return oznaka;
	}

	public void setOznaka(String oznaka) {
		this.oznaka = oznaka;
	}

	public String getNaziv() {
		return naziv;
	}

	public void setNaziv(String naziv) {
		this.naziv = naziv;
	}

	public Integer getEspb() {
		return espb;
	}

	public void setEspb(Integer espb) {
		this.espb = espb;
	}

	@Override
	public String toString() {
		return "Predmet [id=" + id + ", oznaka=" + oznaka + ", naziv=" + naziv + ", espb=" + espb + "]";
	}
}
