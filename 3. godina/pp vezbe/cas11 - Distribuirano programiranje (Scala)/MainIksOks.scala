import org.apache.spark.{SparkConf, SparkContext}

object MainIksOks {

  def main(args: Array[String]): Unit = {

    val conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val fileRDD = ctx.textFile("tictactoe.csv")
        .map(_.split(","))
        // (indikatorPobedeX, brojPoljaX, brojPoljaO, brojPoljaB)
        .map(t => (t.last.equals("W"), t.count(_.equals("x")), t.count(_.equals("o")), t.count(_.equals("b"))))
        .cache()

    val rez1 = fileRDD.filter(_._1 == true).count() / fileRDD.count().toDouble * 100
    val rez2 = fileRDD.filter(x => x._1 && x._4 == 0).count()
    val rez3 = fileRDD.filter(x => x._1 && x._2 > 3).count()

    ctx.stop()

    println(rez1)
    println(rez2)
    println(rez3)
  }
}
