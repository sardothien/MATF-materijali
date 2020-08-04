import java.io.File
import java.util.Scanner
import java.util.concurrent.{ConcurrentLinkedQueue, ThreadLocalRandom}
import java.util.concurrent.atomic.AtomicIntegerArray

/* Milovan ima vocnjak u kome gaji tresnje, kajsije, kruske i sljive.
   Doslo je vreme berbe i mora uposliti mlade studente da oberu vosnjak.
   U datoteci drvoredi.txt se nalaze podaci o drvoredima vocnjaka. Sa
   standardnog ulaza ucitati broj zaposlenih studenata a iz datoteke
   ucitati podatke o drvoredima. Svaka nit predstavlja jednog studenta.
   Student odlazi do jednog drvoreda skidajuci ga iz reda drvoreda koje
   je potrebno obrati i pocinje branje. Ako pretpostavimo da jedno stablo
   voca moze roditi od 30-50 kilograma voca, student za svako stablo iz
   drvoreda nasumicno racuna broj kilograma voca koji je obran i dodaje ih
   u skladiste. Ukoliko su svi drvoredi obrani studenti prestaju sa radom i
   na standardni izlaz se ispisuje ukupna kolicina obranog voca svake vrste. */

class Berac(drvoredi : ConcurrentLinkedQueue[(String, Int)], skladiste : AtomicIntegerArray) extends Thread {

  override def run(): Unit = {
    while(true){
      val drvored = drvoredi.poll()
      if(drvored == null)
        return
      println("Berac bere drvo " + drvored._1)

      Thread.sleep(ThreadLocalRandom.current().nextInt(1, 10)*1000)

      for(_ <- 0 until drvored._2){
        val obrano = ThreadLocalRandom.current().nextInt(30, 50)
        if(drvored._1 == "tresnje")
          skladiste.getAndAdd(0, obrano)
        else if(drvored._1 == "kruske")
          skladiste.getAndAdd(1, obrano)
        else if(drvored._1 == "kajsije")
          skladiste.getAndAdd(2, obrano)
        else if(drvored._1 == "sljive")
          skladiste.getAndAdd(3, obrano)
      }
    }
  }
}

object MainBerba {
  def main(args: Array[String]): Unit = {

    val sc1 = new Scanner(new File(drvoredi.txt"))
    val sc2 = new Scanner(System.in)

    val skladiste = new AtomicIntegerArray(4)
    skladiste.set(0, 0) // tresnje
    skladiste.set(1, 0) // kruske
    skladiste.set(2, 0) // kajsije
    skladiste.set(3, 0) // sljive

    // svaki drvored je jedan par (voce, brojStabala)
    val drvoredi = new ConcurrentLinkedQueue[(String, Int)]()

    while(sc1.hasNextLine)
      drvoredi.add((sc1.next(), sc1.nextInt()))

    println("Unesite broj beraca:")
    val brojBeraca = sc2.nextInt()

    val beraci = new Array[Berac](brojBeraca)
    for(i <- 0 until brojBeraca)
      beraci(i) = new Berac(drvoredi, skladiste)

    for(b <- beraci)
      b.start()

    for(b <- beraci)
      b.join()

    println("Tresnje: " + skladiste.get(0))
    println("Kruske: " + skladiste.get(1))
    println("Kajsije: " + skladiste.get(2))
    println("Sljive: " + skladiste.get(3))
  }
}
