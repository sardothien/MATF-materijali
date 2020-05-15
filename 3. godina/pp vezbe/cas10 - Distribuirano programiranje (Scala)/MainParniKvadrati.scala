import org.apache.spark.{SparkConf, SparkContext}

object MainParniKvadrati {
  def main(args: Array[String]): Unit = {

    var conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")
      // .set("spark.testing.memory", "214748080")

    val ctx = new SparkContext(conf)

    println("Unesite n:")
    val n = scala.io.StdIn.readInt()

    val niz = (2 to n by 2).toArray
    val nizRDD = ctx.parallelize(niz)

    val rez = nizRDD
      .map(x => x*x)
      .take(10)

    println("Rezultat:")
    println(rez.mkString(", "))

    ctx.stop()
  }
}
