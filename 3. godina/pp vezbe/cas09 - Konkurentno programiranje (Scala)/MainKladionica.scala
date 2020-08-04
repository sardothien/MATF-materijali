import java.io.File
import java.util.Scanner
import java.util.concurrent.ThreadLocalRandom

import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer

class Kladionicar(ime : String, novac : Int, tiket : mutable.HashMap[String, Char],
                  utakmice : mutable.HashMap[String, (Float, Float, Float, Char)]) extends  Thread {

  var zarada : Float = 0

  def getZarada : Float = zarada
  def getIme : String = ime

  override def toString: String = ime + " " + novac.toString

  override def run(): Unit ={
    // cekam na odigravanje utakmica
    utakmice.synchronized{
      utakmice.wait()
    }

    // racunamo zaradu
    var pogodjeno : Int = 0
    var ukupnaKvota : Float = 0
    for(t <- tiket)
      // ako je prognoza za utakmicu jednaka stvarnom rezultatu
      if(t._2 == utakmice(t._1)._4){
        println(ime + " je pogodio rezultat utakmice " + t._1 + " : " + t._2)
        pogodjeno += 1
        if(utakmice(t._1)._4 == '1')
          ukupnaKvota += utakmice(t._1)._1 // kvota na 1
        else if(utakmice(t._1)._4 == 'x') // kvota na x
          ukupnaKvota += utakmice(t._1)._2
          else // kvota na 2
          ukupnaKvota += utakmice(t._1)._3
      }

    if(pogodjeno > 0)
      zarada = ukupnaKvota * novac / pogodjeno
  }
}

object MainKladionica {
  def main(args: Array[String]): Unit = {

    println("-------- KLADIONICA ------------")

    val sc1 : Scanner = new Scanner(new File("/home/mina/Downloads/programske paradigme/vezbe/cas09 - Konkurentno programiranje (Scala)/utakmice.txt"))
    val sc2 : Scanner = new Scanner(new File("/home/mina/Downloads/programske paradigme/vezbe/cas09 - Konkurentno programiranje (Scala)/kladionicari.txt"))

    // Utakmice
    // torke su azurabilne
    // pristup elementima torke: torka._1, torka._2, ...
    val utakmice = new mutable.HashMap[String, (Float, Float, Float, Char)]()
    while(sc1.hasNextLine()){
      utakmice.put(sc1.nextLine(), (sc1.nextFloat(), sc1.nextFloat(), sc1.nextFloat(), '-'))
      sc1.nextLine()
    }

    // Kladionicari - niti
    // koristimo ArrayBuffer jer ne znamo koliko imamo kladionicara
    val kladinicari = new ArrayBuffer[Kladionicar]()
    while(sc2.hasNextLine()){
      val ime = sc2.next()
      val novac = sc2.nextInt()

      val tiket = new mutable.HashMap[String, Char]()
      for(i <- 0 until 5){
        sc2.nextLine()
        tiket.put(sc2.nextLine(), sc2.next()(0))
      }

      kladinicari.append(new Kladionicar(ime, novac, tiket, utakmice))
    }

    // provera
    // for(k <- kladinicari)
      // println(k)

    // kladionicari se startuju i ulaze u trku za resurse
    for(k <- kladinicari)
      k.start()

    println("Utakmice se trenutno igraju...")
    Thread.sleep(5000)

    val rezultat = Array('1', 'x', '2')
    for(u <- utakmice)
      utakmice(u._1) = (u._2._1, u._2._2, u._2._3, rezultat(ThreadLocalRandom.current().nextInt(0, 3)))

    // obavesti sve kladionicare
    utakmice.synchronized{
      utakmice.notifyAll()
    }

    for(k <- kladinicari)
      k.join()

    // izvestaj kompletne kladionice
    var isplata : Float = 0
    for(k <- kladinicari) {
      isplata += k.getZarada
      println(k.getIme + " ceka na isplatu: " + k.getZarada + " dinara.")
    }
    println("Kladionica ukupno isplacuje: " + isplata + " dinara.")
  }
}
