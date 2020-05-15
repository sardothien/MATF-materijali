import org.apache.spark.{SparkConf, SparkContext}

object MainPopulacije {
  def main(args: Array[String]): Unit = {

    val conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val rez = ctx.textFile("cities.csv")
        .map(_.split("\"?,\"?"))
        /* Drugi nacin za ovaj regex
        *   .map(_.split(","))
        *   .map(niz => (niz(2).substring(1, niz(2).length - 1) ,...)  */
        // (oznakaRegiona, (vrednosti populacija))
        .map(niz => (niz(2), (niz(3).toDouble * 1000, niz(4).toDouble * 1000, niz(5).toDouble * 1000, niz(6).toDouble * 1000, niz(7).toDouble * 1000)))
        .reduceByKey((acc, t) => (acc._1 + t._1, acc._2 + t._2, acc._3 + t._3, acc._4 + t._4, acc._5 + t._5))
        .sortByKey()
        .map(t => (t._1, (t._2._1.toInt, t._2._2.toInt, t._2._3.toInt, t._2._4.toInt, t._2._5.toInt)))
        .collect()

    ctx.stop()

    rez.foreach(t => println(t._1 + ": " + t._2._1 + ", " + t._2._2 + ", " + t._2._3 + ", " + t._2._4 + ", " + t._2._5))
  }
}
