import org.apache.spark.{SparkConf, SparkContext}

object MainSkalarniProizvod {
  def main(args: Array[String]): Unit = {

    var conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val v1RDD = ctx.textFile("vektor1.txt")
      .flatMap(_.split(", *"))
      .map(_.toInt)

    val v2RDD = ctx.textFile("vektor2.txt")
      .flatMap(_.split(", *"))
      .map(_.toInt)

    val sp = v1RDD
      .zip(v2RDD) // dobijamo uredjene parove - transformacija
      .map(par => par._1 * par._2) // mnozimo odg. parove  - transformacija
      .reduce((a,b) => a + b) // sabiramo niz - akcija
    // .reduce(_+_) // drugi nacin za reduce
    // dok se ne pozove akcija (reduce), nista od prethodnog (zip i map)
    // se ne izvrsava

    ctx.stop()

    println(sp)
  }
}
