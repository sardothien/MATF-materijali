import org.apache.spark.{SparkConf, SparkContext}

object MainBrojPojavljivanja {
  def main(args: Array[String]): Unit = {

    var conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    ctx.textFile("/home/mina/Downloads/programske paradigme/vezbe/cas10 - Distribuirano programiranje (Scala)/knjiga.txt")
        .flatMap(_.split(" +"))
        .map(rec => (rec, 1))
        .reduceByKey(_+_) // sabiramo brojeve pojavljivanja
        .sortByKey()
        .saveAsTextFile("brPojavlj")

    ctx.stop()
  }
}
