import org.apache.spark.{SparkConf, SparkContext}

object MainUspesnaPreuzimanja {
  def main(args: Array[String]): Unit = {

    val conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val preuzimanja = ctx.textFile("mavenLog.txt")
        .cache()

    val zapocetaPreuzimanja = preuzimanja
      .filter(linija => linija.startsWith("Downloading:"))
      .count()

    val zavrsenaPreuzimanja = preuzimanja
      .filter(linija => linija.startsWith("Downloaded:"))
      .count()

    ctx.stop()

    println("%.2f".format(zavrsenaPreuzimanja * 100.0 / zapocetaPreuzimanja) + " procenat" +
      "zapocetih preuzimanja je zavrsen.")
  }
}
