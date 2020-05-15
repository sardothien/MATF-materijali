import org.apache.spark.{SparkConf, SparkContext}

object MainProsecnaTemperatura {

  def main(args: Array[String]): Unit = {

    val conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    ctx.textFile("temperatureBoston.txt")
        .map(linija => {
          val niz = linija.split(" ")
          // Na pocetku reda imamo belinu tako da ce indeksiranje
          // niza samo biti za 1 vece.
          // Kljuc nam je godina - niz(3)
          (niz(3), (niz(1), niz(2), niz(4).toFloat))
        })
        // acc._1 + v._3 -> azurirana suma: 0.0 + niz(3)
        // acc._2 + 1 -> uvecava se brojac
        .aggregateByKey((0.0, 0))((acc, v) => (acc._1 + v._3, acc._2 + 1), (a1, a2) => (a1._1 + a2._1, a1._2 + a2._2))
        // rezultat aggregateByKey: (godina, (ukupnaTempUGodini, brojDana))
        .map(p => (p._1, p._2._1 / p._2._2))
        .sortByKey()
        .collect()
        .foreach(p => println("Godina " + p._1 + " : " + p._2 + "F."))

    ctx.stop()
  }
}
