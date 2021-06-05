package zadatak_11_3;

import java.io.Serializable;

import javax.persistence.Embeddable;

@Embeddable
public class IspitPK implements Serializable {

	private static final long serialVersionUID = 1L;

	private short skGodina;
	private String oznakaRoka;
	private Integer indeks;
	private Integer idPredmeta;
	
	public IspitPK() {
		
	}

	public IspitPK(short skGodina, String oznakaRoka, Integer indeks, Integer idPredmeta) {
		super();
		this.skGodina = skGodina;
		this.oznakaRoka = oznakaRoka;
		this.indeks = indeks;
		this.idPredmeta = idPredmeta;
	}

	public short getSkGodina() {
		return skGodina;
	}

	public void setSkGodina(short skGodina) {
		this.skGodina = skGodina;
	}

	public String getOznakaRoka() {
		return oznakaRoka;
	}

	public void setOznakaRoka(String oznakaRoka) {
		this.oznakaRoka = oznakaRoka;
	}

	public Integer getIndeks() {
		return indeks;
	}

	public void setIndeks(Integer indeks) {
		this.indeks = indeks;
	}

	public Integer getIdPredmeta() {
		return idPredmeta;
	}

	public void setIdPredmeta(Integer idPredmeta) {
		this.idPredmeta = idPredmeta;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((idPredmeta == null) ? 0 : idPredmeta.hashCode());
		result = prime * result + ((indeks == null) ? 0 : indeks.hashCode());
		result = prime * result + ((oznakaRoka == null) ? 0 : oznakaRoka.hashCode());
		result = prime * result + skGodina;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		IspitPK other = (IspitPK) obj;
		if (idPredmeta == null) {
			if (other.idPredmeta != null)
				return false;
		} else if (!idPredmeta.equals(other.idPredmeta))
			return false;
		if (indeks == null) {
			if (other.indeks != null)
				return false;
		} else if (!indeks.equals(other.indeks))
			return false;
		if (oznakaRoka == null) {
			if (other.oznakaRoka != null)
				return false;
		} else if (!oznakaRoka.equals(other.oznakaRoka))
			return false;
		if (skGodina != other.skGodina)
			return false;
		return true;
	}

	@Override
	public String toString() {
		return "IspitPK [skGodina=" + skGodina + ", oznakaRoka=" + oznakaRoka + ", indeks=" + indeks + ", idPredmeta="
				+ idPredmeta + "]";
	}
	
	
}
