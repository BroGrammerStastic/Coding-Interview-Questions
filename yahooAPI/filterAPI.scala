// Advanvced Part 3 about really dump investing strategy
//=======================================================
//two test portfolios

val blchip_portfolio = List("GOOG", "AAPL", "MSFT", "IBM", "FB", "YHOO", "AMZN", "BIDU")
val rstate_portfolio = List("PLD", "PSA", "AMT", "AIV", "AVB", "BXP", "CBG", "CCI",
                            "DLR", "EQIX", "EQR", "ESS", "EXR", "FRT", "GGP", "HCP")

/**
 * ( 1.a ) =>
 * The function below will obtain the first trading price for a stock symbol by
 * using the query:
 * http://ichart.yahoo.com/table.csv?s=<<symbol>>&a=0&b=1&c=<<year>>&d=1&e=1&f=<<year>>
 * and extracting the first January Adjusted Close price in a year.
 * =================
 * @param <String(Symbol),Int(Year)> - Needs the symbol to return stock data
 * @return (Int,Int) - index of min and max prices, respectively
 */
 def get_first_price(symbol: String, year: Int): Option[Double] = {
   // We will be using Yahoo engine to retrieve data. We will pass symbol and the year
   val url = "http://ichart.yahoo.com/table.csv?s=" + symbol + "&a=0&b=1&c=" + year + "&d=1&e=1&f=" + year
   // There may be a stock that will not be available at some point. Its best
   // to retrieve data from early January. So we'll need a list of doubles
   var january = List[Double]()
   // We need to aquire each line of the data. Lets read it using io.Source
   val bufferedSource = io.Source.fromURL(url).mkString
   // lets split each line by '\n' and drop the first row
   bufferedSource.split("\n").zipWithIndex.drop(1).foreach {
     case(element,index) => {
       // Split each line by comma
       var column = element.split(",")
       // retrieve the 6th column, convert it to double and place it in our list.
       january = column(6).toDouble :: january
     }
   }
   // Lets return the first element of january. If error occures, return None
   try { Some( january.head ) } catch { case e: Exception => None }
 }

/**
 * ( 1.b ) =>
 * The function below will obtain all first prices for the stock symbols from a portfolio
 * for the given range of years
 * =================
 * @param <List[portfolio],Range(Year)> - This will get us prices for list of stocks
 * @return List[List[Option[Double]]] - index of min and max prices, respectively
 */
 def get_prices(portfolio: List[String], years: Range): List[List[Option[Double]]] = {
   // loop through the years range
   for { i <- years.toList } yield {
     // for each year...
     for {
       // call the stock in the portfolio
       j <- portfolio.toList
     } yield try {
       // call the method to return prices for early january
       get_first_price(j, i)
       // if anything fails, return None
     } catch { case e: Exception => None }
   }
 }

 /**
  * ( 2.a ) =>
  * The first function below calculates the change factor (delta) between a price in year
  * n and a price in year n+1. The function differentiates if one of the prices given
  * is null.
  * =================
  * @param <Option[Double],Option[Double]> - We need to compare two prices
  * @return List[List[Option[Double]]] - index of min and max prices, respectively
  */
  def get_delta(price_old: Option[Double], price_new: Option[Double]): Option[Double] = (price_old, price_new) match {
    // if two prices are given to us, then do the necessary calculations
    case (Some(oldPrice), Some(newPrice)) => Some((newPrice - oldPrice) / oldPrice)
    // otherwise return none
    case _ => None
  }

  /**
   * ( 2.b ) =>
   * This function calculates all chnage factors obtaind from (=> 2.a)
   * =================
   * @param <List[List[Option[Double]]]> - we need list of list of options
   * @return List[List[Option[Double]]] - list of chnage factors
   */
  def get_deltas(data: List[List[Option[Double]]]):  List[List[Option[Double]]] = {
    // call each nested list, zip both of them, and calculate the chnage factor
    data.sliding( 2 ).map { case List( a, b ) => ( a zip b ).map { case ( x, y ) => get_delta( x, y ) } }.toList
  }

  /**
   * ( 3.a ) =>
   * This function, given change factors, a starting balance and a year calculates the
   * yearly yield, i.e. new balanace, according to our dump investment strategy. Another
   * function calculates given the same data calculates the compound yield up to a given
   * year. Finally a function combines all calculations by taking a portfolio, a range of
   * years and a start balance as arguments.
   * =================
   * @param <List[List[Option[Double]]],Long,Int>
   * @return Long - the new Blance for that year
   */
   def yearly_yield(data: List[List[Option[Double]]], balance: Long, year: Int): Long = {
     // first we need to split our balance with equal amount for each symbol
     val halfOfData = if (data(year).flatten.length != 0) balance / data(year).flatten.length else 0
     // then times multiply each element in the data on that year with halfOfData, add it, and add the balance
     return balance + ((data(year).flatten.collect { case value => { value * halfOfData } }.sum )).toLong
   }

   /**
    * ( 3.a.a ) =>
    * This function, instead of calculating the yield for one year. We will
    * calculate it for multiple years.
    * =================
    * @param <List[Option[Double]],Long,Int> - given data, balance and year
    * @return Long - the total new balance for the next year
    */
   def compound_yield(data: List[List[Option[Double]]], balance: Long, year: Int): Long = {
     // initial balance as newBlance
     var newBalance = balance
     // loop through the year and update the balance
     for ( i <- (0 until year) ) newBalance = yearly_yield(data,newBalance,i)
     // and return it
     return newBalance
   }

   /**
    * ( 3.a ) =>
    * This function, given change factors, a starting balance and a year calculates the
    * yearly yield, i.e. new balanace, according to our dump investment strategy. Another
    * function calculates given the same data calculates the compound yield up to a given
    * year. Finally a function combines all calculations by taking a portfolio, a range of
    * years and a start balance as arguments.
    * =================
    * @param <List[String],Range,Long> - List of symbols, range of years and starting balance
    * @return Long - The nw balance for the range of years
    */
   def investment(portfolio: List[String], years: Range, start_balance: Long): Long = {
     var callWeb        = get_prices(portfolio,years)
     var callDelta      = get_deltas(callWeb)
     var finalResult    = compound_yield(callDelta,start_balance,years.length - 1)
     return finalResult
   }

/*
================================================================================
=============================   Testing Territory   ============================
================================================================================
*/
   println(
     "blchip_portfolio = { $" + investment(blchip_portfolio, 1978 to 2016, 100) + " }" + "\n" +
     "rstate_portfolio = { $" + investment(rstate_portfolio, 1978 to 2016, 100) + " }" + "\n"
   )
