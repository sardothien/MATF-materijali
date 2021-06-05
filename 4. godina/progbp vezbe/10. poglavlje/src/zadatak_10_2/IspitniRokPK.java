package zadatak_10_2;

import java.io.Serializable;
import javax.persistence.Embeddable;

@Embeddable
public class IspitniRokPK implements Serializable {

	private static final long serialVersionUID = 1L;

	private Integer skGodina;
	private String oznakaRoka;
	
	public IspitniRokPK() {
		
	}

	public IspitniRokPK(Integer skGodina, String oznakaRoka) {
		super();
		this.skGodina = skGodina;
		this.oznakaRoka = oznakaRoka;
	}

	public Integer getSkGodina() {
		return skGodina;
	}

	public void setSkGodina(Integer skGodina) {
		this.skGodina = skGodina;
	}

	public String getOznakaRoka() {
		return oznakaRoka;
	}

	public void setOznakaRoka(String oznakaRoka) {
		this.oznakaRoka = oznakaRoka;
	}

	@Override
	public String toString() {
		return "IspitniRokPK [skGodina=" + skGodina + ", oznakaRoka=" + oznakaRoka + "]";
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((oznakaRoka == null) ? 0 : oznakaRoka.hashCode());
		result = prime * result + ((skGodina == null) ? 0 : skGodina.hashCode());
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
		IspitniRokPK other = (IspitniRokPK) obj;
		if (oznakaRoka == null) {
			if (other.oznakaRoka != null)
				return false;
		} else if (!oznakaRoka.equals(other.oznakaRoka))
			return false;
		if (skGodina == null) {
			if (other.skGodina != null)
				return false;
		} else if (!skGodina.equals(other.skGodina))
			return false;
		return true;
	}
	
}
