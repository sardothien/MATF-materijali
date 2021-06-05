package zadatak_10_1;

import javax.persistence.*;

@Entity
@Table(name="DA.STUDIJSKIPROGRAM")
public class StudijskiProgram {
	
	@Id
	private Integer id;
	@Column(name="OZNAKA", nullable=false)
	private String oznaka;
	@Column(name="NAZIV", nullable=false)
	private String naziv;
	@Column(name="IDNIVOA", nullable=false)
	private short idNivoa;
	@Column(name="OBIMESPB", nullable=false)
	private short obimESPB;
	@Column(name="ZVANJE", nullable=false)
	private String zvanje;
	@Column(name="OPIS", nullable=true)
	private String opis;
	
	public StudijskiProgram(){
		
	}
	
	public StudijskiProgram(Integer id, String oznaka, String naziv, short idNivoa, short obimESPB, String zvanje,
			String opis) {
		super();
		this.id = id;
		this.oznaka = oznaka;
		this.naziv = naziv;
		this.idNivoa = idNivoa;
		this.obimESPB = obimESPB;
		this.zvanje = zvanje;
		this.opis = opis;
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

	public short getIdNivoa() {
		return idNivoa;
	}

	public void setIdNivoa(short idNivoa) {
		this.idNivoa = idNivoa;
	}

	public short getObimESPB() {
		return obimESPB;
	}

	public void setObimESPB(short obimESPB) {
		this.obimESPB = obimESPB;
	}

	public String getZvanje() {
		return zvanje;
	}

	public void setZvanje(String zvanje) {
		this.zvanje = zvanje;
	}

	public String getOpis() {
		return opis;
	}

	public void setOpis(String opis) {
		this.opis = opis;
	}

	@Override
	public String toString() {
		return "StudijskiProgram [id=" + id + ", oznaka=" + oznaka + ", naziv=" + naziv + ", idNivoa=" + idNivoa
				+ ", obimESPB=" + obimESPB + ", zvanje=" + zvanje + ", opis=" + opis + "]";
	}

	
	
}
