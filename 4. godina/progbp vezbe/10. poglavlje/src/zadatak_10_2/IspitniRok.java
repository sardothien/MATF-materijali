package zadatak_10_2;

import javax.persistence.*;

@Entity
@Table(name="DA.ISPITNIROK")
public class IspitniRok {
	
	@Id
	private IspitniRokPK id;
	@Column(name="NAZIV", nullable=false)
	private String naziv;
	@Column(name="DATPOCETKA", nullable=false)
	private String pocetak;
	@Column(name="DATKRAJA", nullable=false)
	private String kraj;
	public IspitniRokPK getId() {
		return id;
	}
	public void setId(IspitniRokPK id) {
		this.id = id;
	}
	public String getNaziv() {
		return naziv;
	}
	public void setNaziv(String naziv) {
		this.naziv = naziv;
	}
	public String getPocetak() {
		return pocetak;
	}
	public void setPocetak(String pocetak) {
		this.pocetak = pocetak;
	}
	public String getKraj() {
		return kraj;
	}
	public void setKraj(String kraj) {
		this.kraj = kraj;
	}
	
	@Override
	public String toString() {
		return "IspitniRok [id=" + id + ", naziv=" + naziv + ", pocetak=" + pocetak + ", kraj=" + kraj + "]";
	}
	
	public IspitniRok(IspitniRokPK id, String naziv, String pocetak, String kraj) {
		super();
		this.id = id;
		this.naziv = naziv;
		this.pocetak = pocetak;
		this.kraj = kraj;
	}
	
	public IspitniRok() {
		
	}

}
