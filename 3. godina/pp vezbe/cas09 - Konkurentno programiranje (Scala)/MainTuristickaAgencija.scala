import java.io.File
import java.util.Scanner
import java.util.concurrent.ThreadLocalRandom

/* Turisticka agencija FlyProgrammer organizuje nagradnu igru i
   daje pet vaucera od 20% popusta na cenu kupljenje karte svojim
   klijentima. U datoteci ucesnici.txt se nalaze podaci o klijentima
   i cenama. Napisati program koji simulira nagradnu igru. Svaka nit
   ceka na rezultate nagradne igre za jednog klijenta. Turisticka
   agencija izvlaci dobitnike slucajnom selekcijom i nakon zavrsenog
   izvlacenja obavestava niti. Niti proveravaju da li je izvucen
   odgovarajuci klijent i ispisuje poruku o ishodu. */

class Ucesnik(ime: String, cena: Int, dobitnici: Array[String]) extends Thread{

  override def run(): Unit = {
    dobitnici.synchronized{
      dobitnici.wait()
    }

    for(d <- dobitnici)
      if(d == ime){
        println("Cestitamo " + ime + "! Osvojili ste 20% popusta! Vasa karta sada kosta: " + cena*0.8 + "e.")
        return
      }

    println("Nazalost " + ime + " niste osvojili popust :( Vasa karta kosta: " + cena + "e.")
  }

  def getIme : String = ime
}

object MainTuristickaAgencija {
  def main(args: Array[String]): Unit = {

    val sc = new Scanner(new File("/home/mina/Downloads/programske paradigme/vezbe/cas09 - Konkurentno programiranje (Scala)/ucesnici.txt"))

    val dobitnici = new Array[String](5)
    val n = sc.nextInt()
    sc.nextLine()

    val ucesnici = new Array[Ucesnik](n)
    for(i <- 0 until n) {
      ucesnici(i) = new Ucesnik(sc.nextLine(), sc.nextInt(), dobitnici)
      sc.nextLine()
    }

    for(u <- ucesnici)
      u.start()

    println("Izvlacenje je u toku.")
    Thread.sleep(5000)

    // kriticna sekcija
    dobitnici.synchronized{
      val izvuceniIndeksi = ThreadLocalRandom.current().ints(0,n).distinct().limit(5).toArray

      for(j <- 0 until izvuceniIndeksi.length)
        dobitnici(j) = ucesnici(izvuceniIndeksi(j)).getIme

      dobitnici.notifyAll()
    }
  }
}
