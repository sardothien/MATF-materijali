import org.apache.spark.{SparkConf, SparkContext}

object MainLogPoruke {
  def main(args: Array[String]): Unit = {

    val conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val poruke = ctx.textFile("/home/mina/Downloads/programske paradigme/vezbe/cas10 - Distribuirano programiranje (Scala)/log.txt")
        // gledamo samo linije koje pocinju tagom i mora da sadrzi "java"
        .filter(linija => (linija.startsWith("[warn]") || linija.startsWith("[info]")
                         || linija.startsWith("[error]")) && linija.contains("java"))
        .map(linija => {
          val niz = linija.split(" ")
          (niz(0), niz.drop(1).mkString(" "))
        })
        .groupByKey() // kljuc je tag
        .map(par => (par._1, par._2.size))
        .collect() // jer ispisujemo na std izlaz

    ctx.stop()

    poruke.foreach(par => println(par._1 + ": " + par._2))
  }
}
