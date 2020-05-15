object Intro {
  def main(args: Array[String]): Unit = {

    println("---------- PROMENLJIVE -----------")

    // var - promenljiva
    var x : Int = 6 // prom. x tipa Int uzima vr. 6
    println("x : " + x)
    x += 10
    println("x : " + x)

    // val - predstavlja konstantu
    val c : Int = 6
    // c += 10
    println("c : " + c)

    println("--------- GRANANJE ----------")
    if(x > 6)
      println("x je vece od 6")
    else if(x == 6)
      println("x je jednako 6")
    else
      println("x je manja od 6")

    println("--------- NISKE ---------")

    val predmet : String = "Programske Paradigme"
    println("Niska predmet: " + predmet)
    println("Duzina niske: " + predmet.length())

    val godine : String =
      """
        | PPI SLUSAJU:
        | 1 godina
        | 2 godina
        | 3 godina
        |""".stripMargin
    println("godine: " + godine)

    // Interpolacija niski
    var trajanje : Int = 3
    println("Vezbe na predmetu " + predmet + " traju " + trajanje + "h.")
    println(s"Vezbe na predmetu $predmet traju $trajanje h.")

    println("-------- PETLJE ---------")

    // WHILE
    var i : Int = 1
    var vreme : Int = 0
    while(i <= 3){
      i += 1
      vreme += 45
    }
    println(s"$trajanje casa vezbi predmeta $predmet traju $vreme min.")

    // FOR
    for(i <- 1 to 13) // [a..b]
      print(i + " ")
    println()

    for(i <- 1 until 13) // [a..b)
      print(i + " ")
    println()

    for(i <- Range(1,13)) // [a..b)
      print(i + " ")
    println()

    for(i <- Range(1,13, 2)) // [a..step..b)
      print(i + " ")
    println()

    println("--------- NIZOVI ----------")

    var predmeti : Array[String] = new Array[String](5)
    predmeti(0) = "PPI"
    predmeti(1) = "RBP"
    predmeti(2) = "URBP"
    predmeti(3) = "P1"
    predmeti(4) = "P2"
    println("Predmeti: " + predmeti)

    for(i <- 0 until predmeti.length)
      println(predmeti(i))

    // Kolekcijska petlja
    for(p <- predmeti)
      println(p)

    println("------- FUNKCIJE ---------")
    /* def name([args list]) : ret {
          body
       }
    */

    writeOutSorted(predmeti)

    def writeOutSorted(predmeti : Array[String]) : Unit = {
      println("Sortirani predmeti: ")
      // for(p <- predmeti.sortWith(cmpString))
      // drugi nacin je koriscenje lambda funkcije
      for(p <- predmeti.sortWith((p1, p2) => {if(p1.compareTo(p2)<0) true else false}))
        println(p)
    }

    def cmpString(p1 : String, p2: String) : Boolean = {
      if(p1.compareTo(p2) < 0)
        return true
      else
        return false
    }

  }
}
