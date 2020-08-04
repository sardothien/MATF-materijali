import org.apache.spark.{SparkConf, SparkContext}

/* Napisati Spark program koji računa minimalnu i maksimalnu temperaturu po danu
   za svaki dan posebno u gradu Boston i ispisuje ih sortirane po danima. Podaci
   se nalazi u datoteci temperatureBoston.txt u formatu: s0 DAN s1 TEMPERATURA.
   Niske s0 i s2 se mogu zanemariti. */

object jun2_2017_spark {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
      .setAppName("ispit")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val temp = ctx.textFile("temperatureBoston.txt")
        .map(linija => {
          val niz = linija.split(" ")
          (niz(2).toInt, niz(4).toFloat)
        })
        .groupByKey()
        .map(par => {
          (par._1, (par._2.max, par._2.min))
        })
        .sortByKey()
        .collect()

    temp.foreach(e => println("Dan: "+e._1+" max: "+e._2._1+" min: "+e._2._2))

    ctx.stop()
  }
}
