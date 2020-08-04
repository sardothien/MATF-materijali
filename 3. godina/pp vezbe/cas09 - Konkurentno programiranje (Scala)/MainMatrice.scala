import java.io.{File, PrintWriter}
import java.util.Scanner

class Mnozilac(vrsta1 : Array[Int], matrica2 : Array[Array[Int]], rezultat : Array[Int]) extends Thread {
  val m : Int = vrsta1.length
  // broj elemenata u rezultatu
  val k : Int = rezultat.length
  // val k : Int = matrica2.length * matrica2(1).length / vrsta1.length

  override def run(){
    for(i <- 0 until k)
      rezultat(i) = skProizvod(i)
  }

  def skProizvod(j : Int) : Int = {
    var res : Int = 0
    for(i <- 0 until m)
      res += vrsta1(i) * matrica2(i)(j)

    res
  }

}

object MainMatrice {
  def main(args: Array[String]): Unit = {
    println("------------ MATRIX MUL ---------------")

    val sc1 : Scanner = new Scanner(new File("/home/mina/Downloads/programske paradigme/vezbe/cas09 - Konkurentno programiranje (Scala)/matrica1.txt"))
    val sc2 : Scanner = new Scanner(new File("/home/mina/Downloads/programske paradigme/vezbe/cas09 - Konkurentno programiranje (Scala)/matrica2.txt"))
    val pw : PrintWriter = new PrintWriter(new File("/home/mina/Downloads/programske paradigme/vezbe/cas09 - Konkurentno programiranje (Scala)/rezultat.txt"))

    // Dimenzije
    // (n, m1) x (m2, k)
    val n : Int = sc1.nextInt()
    val m1 : Int = sc1.nextInt()

    val m2 : Int = sc2.nextInt()
    val k : Int = sc2.nextInt()

    if(m1 != m2){
      println("Error: dimenzije!")
      return
    }

    // Array.ofDim[Type](dimensions)
    val matrica1 = Array.ofDim[Int](n, m1)
    val matrica2 = Array.ofDim[Int](m2, k)
    val rezultat = Array.ofDim[Int](n, k)

    // Ucitavanje prve matrice
    for(i <- 0 until n)
      for(j <- 0 until m1)
        matrica1(i)(j) = sc1.nextInt()

    // Ucitavanje druge matrice
    for(i <- 0 until m2)
      for(j <- 0 until k)
        matrica2(i)(j) = sc2.nextInt()

    // Definisanje niti
    // mnozioci = new Array[Mnozilac](n)
    val mnozioci = new Array[Mnozilac](n)
    for(i <- 0 until n)
      mnozioci(i) = new Mnozilac(matrica1(i), matrica2, rezultat(i))

    // pokretanje niti
    for(i <- 0 until n)
      mnozioci(i).start()

    // cekanje da se nit zavrsi
    for(i <- 0 until n)
      mnozioci(i).join()

    pw.append(s"$n $k\n")
    for(i <- 0 until n) {
      for(j <- 0 until k)
        pw.append(s"${rezultat(i)(j)} ")
      pw.append("\n")
    }

    pw.close()
  }
}
