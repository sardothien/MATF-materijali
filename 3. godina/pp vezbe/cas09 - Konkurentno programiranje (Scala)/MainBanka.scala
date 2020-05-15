import java.io.File
import java.util.Scanner
import java.util.concurrent.{ConcurrentLinkedDeque, ThreadLocalRandom}
import java.util.concurrent.atomic.AtomicLong

class Klijent(ime : String, pozajmica : Int) {

  var dug: Float = 0

  def getIme : String = ime
  def getPozajmica : Int = pozajmica
  def getDug : Float = dug

  def setDug(_dug : Float): Unit = {
    dug = _dug
  }
}

class Sluzbenica(kamata : Float, kapital : AtomicLong,
                 redKlijenata : ConcurrentLinkedDeque[Klijent],
                 zaduzeniKlijenti : ConcurrentLinkedDeque[Klijent]) extends Thread {

  override def run(): Unit = {
    while(true){
      // povlacimo klijenta iz reda
      val k : Klijent = redKlijenata.poll()
      if(k == null)
        return

      println("Klijent " + k.getIme + " razgovara sa sluzbenicom.")
      Thread.sleep(ThreadLocalRandom.current().nextInt(1, 5) * 1000)

      kapital.synchronized { // problem je ovaj ovde deo - kriticna sekcija
        if (k.getPozajmica > kapital.get())
          println("Klijent " + k.getIme + " ne moze dobiti pozajmicu od banke.")
        else {
          k.setDug(k.getPozajmica * ((100 + kamata.toFloat) / 100))
          val novKapital = kapital.get() - k.getPozajmica
          kapital.set(novKapital)
          println("Klijent " + k.getIme + " je dobio kredit u iznosu od " + k.getPozajmica + "e. " +
            "Dug: " + k.getDug + "e.")
          zaduzeniKlijenti.add(k)
        }
      }
    }
  }
}

object MainBanka {
  def main(args: Array[String]): Unit = {
    println("------------- BANKA ----------------")

    val sc : Scanner = new Scanner(System.in)

    print("Pocetni kapital banke: ")
    // koristimo AtomicLong jer je kapital kriticna sekcija
    val kapital = new AtomicLong(sc.nextLong())
    val sacuvaniKapital : Float = kapital.get()

    print("Unesi kamatnu stopu: ")
    val kamata : Float = sc.nextFloat()

    print("Broj sluzbenica: ")
    val sluzbeniceBr : Int = sc.nextInt()

    val scFile : Scanner = new Scanner(new File("red_klijenata.txt"))

    // ConcurrentLinkedQueue - operacije bezbedne za konkurentni scenario
    val redKlijenata = new ConcurrentLinkedDeque[Klijent]()
    val zaduzeniKlijenti = new ConcurrentLinkedDeque[Klijent]()

    while(scFile.hasNextLine)
      redKlijenata.add(new Klijent(scFile.next(), scFile.nextInt()))

    // Kreiranje sluzbenica
    val sluzbenice = new Array[Sluzbenica](sluzbeniceBr)
    for(i <- sluzbenice.indices)
      sluzbenice(i) = new Sluzbenica(kamata, kapital, redKlijenata, zaduzeniKlijenti)

    for(s <- sluzbenice)
      s.start()

    for(s <- sluzbenice)
      s.join()

    // Obracun
    var dug : Float = 0
    val iterator = zaduzeniKlijenti.iterator()
    while(iterator.hasNext())
      dug += iterator.next().getDug

    println(s"Dug: $dug. Ostalo kapitala: " + kapital.get())
//    println(s"Zarada banke: ${dug-kapital}")
  }
}
