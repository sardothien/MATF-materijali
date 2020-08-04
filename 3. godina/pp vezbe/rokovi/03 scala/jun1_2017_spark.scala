import org.apache.spark.{SparkConf, SparkContext}

/* Napisati Spark program koji računa prosečne plate zaposlenih za svaku
   šifru zaposlenja posebno i ispisuje ih na standardan izlaz. Spisak
   zaposlenih se nalazi u datoteci zaposleni.txt u formatu:
   s0 s1 s2 s3 s4 s5 SIFRA_ZAPOSLENJA PLATA
   Niske s0...s5 se mogu zanemariti. */

object jun1_2017_spark {
  def main(args: Array[String]): Unit = {

    val conf = new SparkConf()
      .setAppName("ispit")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    val plate = ctx.textFile("zaposleni.txt")
        .map(linija => {
          val niz = linija.split(" ")
          (niz(6), niz(7).toFloat)
        })
        .groupByKey()
        .map(elem => {
          val suma = elem._2.sum
          (elem._1, suma / elem._2.size)
        })

    println("Prosecne plate: ")
    plate.foreach(e => println("Sifra: " + e._1 + " - Plata: " + e._2))

    ctx.stop()
  }
}
