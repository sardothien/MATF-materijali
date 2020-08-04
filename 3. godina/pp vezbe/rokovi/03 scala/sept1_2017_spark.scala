import org.apache.spark.{SparkConf, SparkContext}

import scala.compat.Platform

/* Napisati Spark program koji izdvaja dva slučajna uzorka muških i ženskih
   zaposenih, tako što nasumično bira tri muška i tri ženska zaposlena radnika.
   Izračunati prosečnu vrednost plate muškog i ženskog uzorka i izračunate
   vrednosti ispisati na standardni izlaz. Spisak zaposlenih se nalazi u datoteci
   zaposleni.txt u formatu:  s0 s1 POL s2 s3 s4 s5 PLATA.
   Niske s0...s5 se mogu zanemariti, a POL može biti F ili M.*/

object sept1_2017_spark {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
      .setAppName("ispit")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val zaposleni = ctx.textFile("zaposleni.txt")
        .map(linija => {
          val niz = linija.split(" ")
          (niz(2), niz(7).toInt)
        })
        .cache()

    val uzorakM = zaposleni.filter(x => x._1.equals("M"))
        .map(e => e._2)
        .takeSample(withReplacement = false, 3, Platform.currentTime)
        .sum

    val uzorakZ = zaposleni.filter(x => x._1.equals("F"))
      .map(e => e._2)
      .takeSample(withReplacement = false, 3, Platform.currentTime)
      .sum

    val plataM = uzorakM / 3.0
    val plataZ = uzorakZ / 3.0

    println("Prosek plate M:")
    println(plataM)
    println("Prosek plate Z:")
    println(plataZ)

    ctx.stop()
  }
}
