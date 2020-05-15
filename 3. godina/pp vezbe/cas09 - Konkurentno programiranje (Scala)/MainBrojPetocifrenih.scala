import java.io.File
import java.util.Scanner

import scala.collection.mutable.ArrayBuffer

/* Napisati program koji konkurentno racuna broj pojavljivanja petocifrenih
   brojeva koji se nalaze u datotekama cija imena se ucitavaju sa standardnog
   ulaza. Svakoj niti dodeliti po jednu datoteku nad kojom ce racunati. Rezultate
   brojanja smestati u lokalne promenljive unutar niti i po zavrsetku racunanja
   za svaku datoteku ispisati broj pojavljivanja petocifrenih brojeva. */

class BrojaciPetocifrenih(datoteka : String) extends Thread {
  var rezultat : Int = 0

  override def run(): Unit = {
    val sc = new Scanner(new File(datoteka))

    while(sc.hasNextInt()){
      val broj = sc.nextInt()
      if(broj >= 10000 && broj <= 99999)
        this.rezultat += 1
    }
  }

  def getRezultat : Int = rezultat
  def getDatoteka : String = datoteka
}

object MainBrojPetocifrenih {
  def main(args: Array[String]): Unit = {
    val sc = new Scanner(System.in)

    val brojaci = ArrayBuffer[BrojaciPetocifrenih]()
    var kraj = false
    var odgovor = ""
    var datoteka = ""

    while(!kraj){
      println("Da li zelite da zadate ime datoteke? (y/n)")
      odgovor = sc.next()

      if(odgovor.toLowerCase() == "n")
        kraj = true
      else{
        println("Unesite ime datoteke:")
        datoteka = sc.next()
        brojaci.append(new BrojaciPetocifrenih(datoteka))
      }
    }

    // zapocinjemo izvrsavanje
    for(brojac <- brojaci)
      brojac.start()

    // cekamo sve brojace da zavrse izracunavanje
    for(brojac <- brojaci)
      brojac.join()

    // rezultat
    for(brojac <- brojaci)
      println(s"Datoteka ${brojac.getDatoteka} sadrzi ${brojac.getRezultat} petocifrenih brojeva.")
  }
}
