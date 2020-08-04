import java.io.File
import java.util.Scanner
import java.util.concurrent.ConcurrentLinkedQueue

/* Nekoliko taksista je odlučilo da dele klijente i time smanje troškove reklamiranja.
   Međutim zbog povoljnih cena, klijenata ima više nego taksista tako da se napravio
   red čekanja na taksistu. Sa standardnog ulaza se unosi broj niti (taksista) n. Datoteka
   voznja.txt sadrži podatke o klijentima u sledećem formatu: IME_KLIJENTA BR_KILOMETARA.
   Napisati program koji simulira vožnje taksista. Taksisti redom uzimaju klijente, a vožnju
   završavaju nakon isteka odgovarajućeg broja sekundi (koji se poklapa sa kilometražom
   klijenta). Kada započne vožnju, taksita ispisuje poruku o preuzetom klijentu, a kada se
   vožnja završi ispisuje poruku o završetku vožnje. Taksisti prestaju sa radom kada razvezu
   sve klijente.*/

class Taxi(redKlijenata: ConcurrentLinkedQueue[(String, Float)]) extends Thread {
  override def run(): Unit = {
    while(true){
      var klijent = redKlijenata.poll()
      if(klijent == null)
        return

      println("Klijent " + klijent._1 + " krece u voznju.")
      Thread.sleep((klijent._2 * 1000).toInt)

      println("Klijent " + klijent._1 + " je zavrsio sa voznjom.")
    }
  }
}

object jun2_2017_niti {
  def main(args: Array[String]): Unit = {
    val sc : Scanner = new Scanner(System.in)
    val sc1 : Scanner = new Scanner(new File("voznja.txt"))

    val brNiti = sc.nextInt()

    val voznje = new ConcurrentLinkedQueue[(String, Float)]()
    while(sc1.hasNextLine)
      voznje.add((sc1.next(), sc1.nextFloat()))

    val taksisti = new Array[Taxi](brNiti)

    for(i <- 0 until brNiti)
      taksisti(i) = new Taxi(voznje)

    for(t <- taksisti)
      t.start()

    for(t <- taksisti)
      t.join()
  }
}
