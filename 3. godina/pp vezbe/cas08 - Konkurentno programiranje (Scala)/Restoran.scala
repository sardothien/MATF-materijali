/* Pet konobara radi u restoranu, i nakon sto dodju na posao, 
poslovodja im dodeli broj stolova koje moraju da usluze. Napisati
program koji ucitava sa standardnog ulaza broj neusluzenih stolova 
u restoranu i rasporedjuje ih konobarima. Nakon sto usluze jedan
sto, konobari salju poruku tako da poslovodja u svakom trenutku ima
uvid u brojcano stanje. Konobare implementirati kao posebne niti koje
usluzuju sto (spavaju nasumicno izabran broj sekundi), ispisuju redni 
broj stola koji su usluzili i po zavrsetku ispisuju poruku da su zavrsili. */

import java.util.Scanner
import java.util.concurrent.ThreadLocalRandom
// Pravljenje niti

// Prvi nacin:
//  * klasa nasledjuje Thread
//  * implementiramo metod run()

// Drugi nacin:
//  * implements Runnable
//  * implements run()
//  * instancirati Thread

class Konobar(ime : String, brStolova : Int) extends Thread {
  override def run() : Unit = {
    for(i <- 0 until brStolova){
      // usluziavnje stola i
      Thread.sleep(ThreadLocalRandom.current().nextInt(1, 3)*1000)
      println(s"Konobar $ime je usluzio sto $i.")
    }
    println(s"Konobar $ime je zavrsio smenu.")
  }
}

object Restoran {
  def main(args: Array[String]): Unit = {
    println("--------- RESTORAN ----------")

    val sc : Scanner = new Scanner(System.in)

    println("Unesi broj stolova: ")
    val brStolova : Int = sc.nextInt()
    val korak = Math.ceil(brStolova / 5.0).toInt

    val milan = new Konobar("Milan", korak)
    val ivan = new Konobar("Ivan", korak)
    val rastko = new Konobar("Rastko", korak)
    val nemanja = new Konobar("Nemanja", korak)
    val strahinja = new Konobar("Strahinja", korak)

    milan.start()
    ivan.start()
    rastko.start()
    nemanja.start()
    strahinja.start()
  }
}
