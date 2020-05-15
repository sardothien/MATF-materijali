import org.apache.spark.{SparkConf, SparkContext}

object MainBrojPetocifrenih {
  def main(args: Array[String]): Unit = {

    var conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val dataRDD = ctx.textFile("/home/mina/Downloads/programske paradigme/vezbe/cas10 - Distribuirano programiranje (Scala)/brojevi.txt")

    val brPetocifrenih = dataRDD
        .filter(x => x.length == 5) // jer je x String
        .count()

    ctx.stop()

    println(brPetocifrenih)
  }
}
