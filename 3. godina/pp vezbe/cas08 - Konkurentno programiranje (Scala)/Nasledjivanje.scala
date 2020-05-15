/* Classes:
*     class name {
*         body
*     }
*
*     class name(args) {
*         body
*     }
*/

class Film {
  // default prazan konstruktor
  var naslov : String = ""
  var trajanje : Int = 0
  var godina : Int = 0

  // konstruktor
  def this(naslov : String, trajanje : Int, godina : Int) = {
    this()
    this.naslov = naslov
    this.trajanje = trajanje
    this.godina = godina
  }

  def getNaslov() : String = {
    return this.naslov
  }

//  def getTrajanje() : Int = {
//    return this.trajanje
//  }

  // DRUGI NACIN
  def getTrajanje() : Int = {
    this.trajanje
  }

//  def getGodina() : Int = {
//    return this.godina
//  }

  // DRUGI NACIN
  def getGodina() : Int = this.godina

  override def toString: String = {
    "Film " + this.naslov + ", traje " + this.trajanje + " minuta. " +
      "Film je iz " + this.godina + " godine."
  }
}

class CrtaniFilm extends Film {
  var autor : String = ""

  def this(naslov : String, trajanje : Int, godina : Int, autor : String) {
    this()
    this.naslov = naslov
    this.trajanje = trajanje
    this.godina = godina
    this.autor = autor
  }

  def getAutor() : String = this.autor

  override def toString: String = super.toString + " Autor: " + this.autor
}

object Nasledjivanje {
  def main(args: Array[String]): Unit = {

    println("-------- NASLEDJIVANJE - OSNOVNI KONCEPTI ------------")

    val f : Film = new Film()
    println(f)

    val p : Film = new Film("Tarzan", 92, 1990)
    println(p)

    println("Naslov: " + p.getNaslov())
    println("Trajanje: " + p.getTrajanje())
    println("Godina: " + p.getGodina())

    val c : CrtaniFilm = new CrtaniFilm("Tarzan Animirani", 36, 1999, "Walt Disney")
    println(c)
  }
}

/* Array, ArrayBuffer, Map, HashMap, Queue... */