import java.util.Scanner

/* Napisati program koji konkurentno sabira dva vektora. Sa standardnog ulaza
   se ucitava dimenzija vektora, elementi oba vektora i broj niti. Svakoj niti
   dodeliti indeks pocetka i kraja vektora nad kojim racuna zbir a rezultat
   smestati u prvi vektor. Indekse racunati na osnovu dimenzije vektora i broja
   niti. Rezultujuci vektor ispisati na standardni izlaz. */

class Sabirac(pocetak : Int, kraj : Int,
              vektor1 : Array[Float], vektor2 : Array[Float]) extends Thread {

  override def run(): Unit = {
    for(i <- pocetak until kraj)
      vektor1(i) += vektor2(i)
  }
}

object MainZbirVektora {
  def main(args: Array[String]): Unit = {
    val sc = new Scanner(System.in)

    println("Unesite dimenziju vektora:")
    val n = sc.nextInt()

    val vektor1 : Array[Float] = new Array(n)
    val vektor2 : Array[Float] = new Array(n)

    println("Unesite elemente prvog vektora:")
    for(i <- 0 until n)
      vektor1(i) = sc.nextFloat()

    println("Unesite elemente drugog vektora:")
    for(i <- 0 until n)
      vektor2(i) = sc.nextFloat()

    println("Unesite broj niti:")
    val brojNiti = sc.nextInt()

    val niti = new Array[Sabirac](brojNiti)
    val korak = Math.ceil(n / brojNiti.toDouble).toInt

    // pravimo niti i zadajemo im granice
    for(i <- 0 until brojNiti)
      niti(i) = new Sabirac(i*korak, Math.min((i+1)*korak, n), vektor1, vektor2)

    // pokrecemo racunanje
    for(i <- 0 until brojNiti)
      niti(i).start()

    // cekamo da niti zavrse sa racunanjem
    for(i <- 0 until brojNiti)
      niti(i).join()

    // rezulat
    print("Zbir vektora je:\n [")
    for(i <- 0 until n-1)
      print(vektor1(i) + ", ")
    println(vektor1(n-1) + " ]")
  }
}
