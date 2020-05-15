import org.apache.spark.{SparkConf, SparkContext}

object MainProcesi {
  def main(args: Array[String]): Unit = {

    val conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val fileRDD = ctx.textFile("procesi.txt")
        .map(_.split("\\s*,\\s*"))
        .cache()

    val svi = fileRDD
        // (ramZauzece, cpuZauzece)
        .map(parts => (parts(1).toInt, parts(2).toInt))
        .reduce((acc, v) => (acc._1 + v._1, acc._2 + v._2))

    val sys = fileRDD
        // ako imamo vise od 3 stavke u liniji, znaci da je sistemska
        // (ima sys kao cetvrtu stavku)
        .filter(_.length > 3)
        // (ramZauzece, cpuZauzece)
        .map(parts => (parts(1).toInt, parts(2).toInt))
        .reduce((acc, v) => (acc._1 + v._1, acc._2 + v._2))

    ctx.stop()

    println("svi: " + svi._1 + " , " + svi._2)
    println("sys: " + sys._1 + " , " + sys._2)
  }
}
