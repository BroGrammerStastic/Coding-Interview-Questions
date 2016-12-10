// Part 2 about Buy-Low-Sell-High using Yahoo Financial Data
//===========================================================
import io.Source

/**
 * ( 1 ) =>
 * This function will return a pair of indices for when to buy and sell this
 * commodity.
 * ===========
 * Example:
 * List(28.0, 18.0, 20.0, 26.0, 24.0) => (1, 3)
 * Because at index 1 the price is lowest and then at index 3 the price is
 * highest.
 * =================
 * @param <List[Double]> - Requires list od doubles to calculate the min and max
 * @return (Int,Int) - index of min and max prices, respectively
 */
def trade_times(xs: List[Double]): (Int, Int) = {
  // We need two variables to hold the indexes
  var minIndex, maxIndex = -1
  // We need two variables to hold the values of those indexes
  var minValue,maxValue = 0.0
  minIndex = xs.zipWithIndex.minBy(_._1)._2
  // loop through our list starting from minimum value
  for ( n <- minIndex to xs.length - 1  ) {
    // if there exists a value greater than the current value
    if ( xs(n) > maxValue ) {
      // reinitialise it
      maxValue = xs(n)
      maxIndex = n
    }
  }
  // return a pair of min and max value's indexes
  return ( minIndex, maxIndex )
}


val prices = List(28.0, 18.0, 20.0, 26.0, 24.0);
val prices2 = List(28.0, 18.0, 20.0, 26.0, 50.0);
val prices3 = List(8.0, 18.0, 20.0, 26.0, 8.0);
val prices4 = List(28.0, 18.0, 200.0, 26.0, 8.0);
println(trade_times(prices))
println(trade_times(prices2))
println(trade_times(prices3))
println(trade_times(prices4))

/**
 * ( 2 ) =>
 * This function will request CSV list from the Yahoo websevice that provides
 * historical data for stock indices.
 * It will return a List of strings, where each string is one line in this
 * CVS-list (representing one day’s data).
 * Header of CSV =>  Date || Open || High || Low || Close || Volume || Adj Close
 * =================
 * @param <String>        - Requires the Stock symbol to produce CSV
 * @return <List[String]> - Will return List of strings from the server
 */
def get_page(symbol: String): List[String] = {
  // whatever stock we call, will be passed to YAHOO server
  val url = "http://ichart.yahoo.com/table.csv?s=" + symbol
  // Will return the data from server and converted into string
  return List(Source.fromURL(url).mkString)
}

/**
 * ( 3 ) =>
 * This function will ignore the first line (the header) and then extracts
 * from each line : Date(row 0) || Adj Close(row 6)
 * The Adjusted Close price should be converted into a Double.
 * =================
 * @param <String>               - Requires string of data produced from the server
 * @return List[(String,Double)] -  List of pairs where the first components are strings
 * (the dates) and the second are doubles (the adjusted close prices).
 */
def process_page(symbol: String): List[(String,Double)] = {
  // Lets declair and initialise empty list of string and double
  var col_0_and_6 = List[(String,Double)]()
  // loop through the list of data day by day, ignoring the first and last element of list.
  get_page(symbol).toString().split("\n").zipWithIndex.drop(1).dropRight(1).foreach {
    case(element,index) => {
      // lets split our day into 7 columns
      var column = element.split(",")
      // lets add our column 0 and 6 together
      col_0_and_6 = column(0) -> column(6).toDouble :: col_0_and_6
    }
  }
  // and return it
  return col_0_and_6
}

/**
 * ( 4 ) =>
 * This function will require the stock market symbol, and returns the date of when you should
 * have bought and sold.
 * =================
 * @param <String>         - Requires the tuple of of date and price
 * @return <String,String> - Return the 2 dates of min and max respectively
 */
def query_company(symbol: String): (String, String) = {
  return (
    // calculuate the minimum value of second tuple (price) and return its date
    process_page(symbol).minBy(_._2)._1,
    // calculuate the maximum value of second tuple (price) and return its date
    process_page(symbol).maxBy(_._2)._1
  )
}

 val indices = List("GOOG", "AAPL", "MSFT", "IBM", "FB", "YHOO", "AMZN", "BIDU")
 for (name <- indices) {
   val times = query_company(name)
   println(s"Buy ${name} on ${times._1} and sell on ${times._2}")
 }
