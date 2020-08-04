import java.io.File
import java.util.Scanner
import java.util.concurrent.atomic.AtomicInteger

import scala.collection.mutable.ArrayBuffer

/* Napisati Scala program koji pomoću više niti računa broj prijava User i Admin
   korisnika, kao i ukupno vreme tokom kojeg su bili prijavljeni. Sa standardnog
   ulaza unosi se broj niti. Datoteka korisnici.txt sadrži podatke o tipovima
   korisnika i dužini njihove prijave u sledećem formatu: TIP_KORISNIKA VREME_PRIJAVE.
   TIP_KORISNIKA može biti User i Admin. Učitati podatke o korisnicima i koristeći
   paralelizaciju podataka izračunati broj User i Admin korisnika kao i ukupno vreme
   prijave svih korisnika. Na standardni izlaz ispisati procenat User i Admin
   korisnika i prosečno vreme prijave po jednom korisniku. */

class Brojac(pocetak: Int, kraj: Int, korisnici: ArrayBuffer[(String, Int)], brAdmin: AtomicInteger, brUser: AtomicInteger, vreme: AtomicInteger) extends Thread {
  override def run(): Unit = {
    for(i <- pocetak until kraj){
      if(korisnici(i)._1.equals("User"))
        brUser.addAndGet(1)
      else
        brAdmin.addAndGet(1)

      vreme.addAndGet(korisnici(i)._2)
    }
  }
}

object sept1_2017_niti {
  def main(args: Array[String]): Unit = {
    val sc : Scanner = new Scanner(System.in)
    val sc1 : Scanner = new Scanner(new File("korisnici.txt"))

    val brNiti = sc.nextInt()

    val korisnici = new ArrayBuffer[(String, Int)]()
    while(sc1.hasNextLine)
      korisnici.append((sc1.next(), sc1.nextInt()))

    val brKorisnika = korisnici.length

    val brAdmin = new AtomicInteger(0)
    val brUser = new AtomicInteger(0)
    val vreme = new AtomicInteger(0)

    val niti = new Array[Brojac](brNiti)
    val korak = Math.ceil(brKorisnika / brNiti.toDouble).toInt

    for(i <- 0 until brNiti)
      niti(i) = new Brojac(i*korak, Math.min((i+1)*korak, brKorisnika), korisnici, brAdmin, brUser, vreme)

    for(n <- niti)
      n.start()

    for(n <- niti)
      n.join()

    println("Admin: " + ( brAdmin.toString.toInt / brKorisnika.toDouble)*100 )
    println("User: " + ( brUser.toString.toInt / brKorisnika.toDouble)*100 )
    println("Prosecan broj minuta po korisniku: " + (vreme.toString.toInt / (brKorisnika.toDouble * 60.0)) )
  }
}
