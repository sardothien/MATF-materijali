import java.io.{File, PrintWriter}

import org.apache.spark.{SparkConf, SparkContext}

object MainUredjajiTransakcije {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
      .setAppName("MyApp")
      .setMaster("local[4]")

    val ctx = new SparkContext(conf)

    ctx.textFile("/home/mina/Downloads/programske paradigme/vezbe/cas10 - Distribuirano programiranje (Scala)/uredjaji.txt")
        .map(linija => {
          val niz = linija.split("\\s+")
          (niz(0), niz.drop(1).mkString(" "))
        })
        .groupByKey()
        .foreach(par => {
          val f = new PrintWriter(new File(par._1.toLowerCase() + ".txt"))
          f.write("--- " + par._1 + " ---\n")
          par._2.foreach(t => f.append(t + "\n"))
          f.close()
        })

    ctx.stop()
  }
}