import java.io.File
import java.util.Scanner
import java.util.concurrent.ConcurrentHashMap

import scala.collection.mutable.ArrayBuffer

// ConcurrentHashMap - u jednom trenutku jedna nit izvrsava operacije nad mapom
class Brojac(pocetak : Int, kraj : Int, linije : ArrayBuffer[String], mapaKaraktera : ConcurrentHashMap[Char, Int]) extends Thread{

  // [poc..kraj)
  override def run(): Unit ={
    for(i <- pocetak until kraj){
      // _=='a' -> lambda funkcija
      val a : Int = linije(i).count(_=='a')
      val g : Int = linije(i).count(_=='g')
      val c : Int = linije(i).count(_=='c')
      val t : Int = linije(i).count(_=='t')

      // Synchronized
      //  * def f() = synchronized { telo }
      //  * instanca.synchronized { blok }
      // bez sinhronizacije ce se javiti netacni rezultati
      // koristimo mapu kao monitor
      mapaKaraktera.synchronized {
        mapaKaraktera.replace('a', mapaKaraktera.get('a') + a)
        mapaKaraktera.replace('g', mapaKaraktera.get('g') + g)
        mapaKaraktera.replace('c', mapaKaraktera.get('c') + c)
        mapaKaraktera.replace('t', mapaKaraktera.get('t') + t)
      }
    }
  }
}

object MainDNK {
  def main(args: Array[String]): Unit = {
    println("--------- DNK Counter ---------")

    val sc1 : Scanner = new Scanner(new File("/home/mina/Downloads/programske paradigme/vezbe/cas09 - Konkurentno programiranje (Scala)/bio_podaci.txt"))
    val sc2 : Scanner = new Scanner(System.in)

    println("Broj procesora na sistemu je: " + Runtime.getRuntime.availableProcessors())
    println("Unesi broj niti: ")
    val brojNiti = sc2.nextInt()

    val brojaci = new Array[Brojac](brojNiti)
    val linije = new ArrayBuffer[String]()
    // ucitavanje fajla
    while(sc1.hasNextLine())
      linije.append(sc1.nextLine())

    val n : Int = linije.length
    println(s"Broj linija: $n.")

    val mapaKaraktera = new ConcurrentHashMap[Char, Int](4, 4, brojNiti)
    mapaKaraktera.put('a', 0)
    mapaKaraktera.put('g', 0)
    mapaKaraktera.put('c', 0)
    mapaKaraktera.put('t', 0)

    val korak : Int = Math.ceil(n.toDouble / brojNiti.toDouble).toInt
    for(i <- 0 until brojNiti)
      brojaci(i) = new Brojac(i*korak, Math.min((i+1)*korak, n), linije, mapaKaraktera)

    for(i <- 0 until brojNiti)
      brojaci(i).start()

    for(i <- 0 until brojNiti)
      brojaci(i).join()

    println("Count baza: ")
    println("A: "+mapaKaraktera.get('a'))
    println("G: "+mapaKaraktera.get('g'))
    println("C: "+mapaKaraktera.get('c'))
    println("T: "+mapaKaraktera.get('t'))
  }
}
