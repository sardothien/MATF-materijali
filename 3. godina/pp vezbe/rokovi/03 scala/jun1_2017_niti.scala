import java.io.{File, PrintWriter}
import java.util.Scanner

import scala.collection.mutable.ArrayBuffer

/* Napisati Scala program koji pomoću više niti za svaki dan računa prosečnu
   količinu potrošenog novca u prodavnici po jednom kupcu. Sa standardnog ulaza
   unosi se broj niti n. Datoteka kupovina.txt sadrži podatke o broju kupaca i
   količini potrošenog novca za svaki dan u posebnoj liniji u sledećem formatu:
   Br_KUPACA POTROSEN_NOVAC. Učitati podatke o broju kupaca i količini potrošenog
   novca i izračunati proseke potrošenog novca za svaki dan koristeći paralelizaciju
   podataka. Kada sve niti završe sa radom u datoteku proseciPoDanu.txt upisati
   izračunate proseke. */

class Prosek(pocetak: Int, kraj: Int, transakcije: ArrayBuffer[(Int, Int)], proseciPoDanu: Array[Float]) extends Thread{
  override def run(): Unit = {
    for(i <- pocetak until kraj){
      proseciPoDanu(i) = transakcije(i)._2.toFloat / transakcije(i)._1
    }
  }
}

object jun1_2017_niti {
  def main(args: Array[String]): Unit = {
    val sc : Scanner = new Scanner(System.in)
    val sc1 : Scanner = new Scanner(new File("kupovina.txt"))
    val pw : PrintWriter = new PrintWriter(new File("proseciPoDanu.txt"))

    val brNiti = sc.nextInt()

    val transakcije = new ArrayBuffer[(Int,Int)]()

    while(sc1.hasNextLine())
      transakcije.append((sc1.nextInt(), sc1.nextInt()))

    val brTransakcija = transakcije.length

    val proseciPoDanu = new Array[Float](brTransakcija)

    val niti = new Array[Prosek](brNiti)
    val korak = Math.ceil(brTransakcija / brNiti.toDouble).toInt

    for(i <- 0 until brNiti)
      niti(i) = new Prosek(i*korak, Math.min((i+1)*korak, brTransakcija), transakcije, proseciPoDanu)

    for(n <- niti)
      n.start()

    for(n <- niti)
      n.join()

    for(p <- proseciPoDanu)
      pw.append(p + "\n")

    pw.close()
  }
}
