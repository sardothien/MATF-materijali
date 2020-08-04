import org.apache.spark.{SparkConf, SparkContext}

import scala.compat.Platform

object MainPokloni {
  def main(args: Array[String]): Unit = {

    val conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val dobitnici = ctx.textFile("/home/mina/Downloads/programske paradigme/vezbe/cas10 - Distribuirano programiranje (Scala)/zaposleni.txt")
        .filter(_.contains("IT_PROG"))
        .map(linija => {
          val niz = linija.split(" ")
          // (ime, prezime, username)
          (niz(0), niz(1), niz(3))
        })
        // biramo nasumicno 3 coveka
        .takeSample(false, 3, Platform.currentTime)

    ctx.stop()

    dobitnici.foreach(d => println("Ime i prezime: " + d._1 + " " + d._2 + " (" + d._3 + ")"))
  }
}
