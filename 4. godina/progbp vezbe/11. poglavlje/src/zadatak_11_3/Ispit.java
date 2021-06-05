package zadatak_11_3;

import javax.persistence.*;

@Entity
@Table(name="DA.ISPIT")
public class Ispit {
	
	@Id
	private IspitPK id;
	@Column(name="OCENA", nullable=true)
	private Integer ocena;
	@Column(name="STATUS", nullable=false)
	private String status;
	
	@ManyToOne
	@MapsId("indeks")
	@JoinColumn(name="INDEKS", referencedColumnName="INDEKS")
	private Student student;

	public Ispit() {
		
	}

	public Ispit(IspitPK id, Integer ocena, String status) {
		super();
		this.id = id;
		this.ocena = ocena;
		this.status = status;
	}

	public IspitPK getId() {
		return id;
	}

	public void setId(IspitPK id) {
		this.id = id;
	}

	public Integer getOcena() {
		return ocena;
	}

	public void setOcena(Integer ocena) {
		this.ocena = ocena;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	public Student getStudent() {
		return student;
	}

	public void setStudent(Student student) {
		this.student = student;
	}

	@Override
	public String toString() {
		return "Ispit [id=" + id + ", ocena=" + ocena + ", status=" + status + "]";
	}
	
	
}
