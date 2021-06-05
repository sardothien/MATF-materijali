package zadatak_10_3;

import javax.persistence.*;

@Entity
@Table(name="DA.NIVOKVALIFIKACIJE")
public class NivoKvalifikacije {
 
	@Id
	private Integer id;
	@Column(name="NAZIV", nullable=false)
	private String naziv;
	
	public NivoKvalifikacije() {
		
	}

	public NivoKvalifikacije(Integer id, String naziv) {
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

	@Override
	public String toString() {
		return "NivoKvalifikacije [id=" + id + ", naziv=" + naziv + "]";
	}
	
	
}
