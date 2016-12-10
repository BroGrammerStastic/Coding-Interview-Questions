// Part 1 about the 3n+1 conceture
//=================================

/**
 * collatz() - calculates the number of steps needed until series reaches the
 * number 1.
 * @param n<Long> takes in a long number
 */
 def collatz(n: Long): Int = n match {
   case 1 => 1
   case _ => if ( n % 2 == 0 ) 1 + collatz( n / 2 ) else 1 + collatz( ( 3 * n ) + 1 )
 }

/**
 * collatz_max() - how many steps are needed for each number from 1 upto a bound
 * and returns the maximum number of steps and the corresponding number that
 * needs that many steps.
 * @param bnd<Int> takes in an int number
 */
 def collatz_max(bnd: Int): (Int, Int) = {
   var takes, largest = 0
   for ( n <- (1 to bnd) ) {
     if ( collatz( n ) > takes ) {
       largest = n; takes = collatz(largest);
     }
   }
   return ( takes , largest )
 }


println(collatz(9));
println(collatz(97));
println(collatz(871));
println(collatz(6171));
println(collatz(77031));
println(collatz(837799));
println(collatz_max(10));
println(collatz_max(100));
println(collatz_max(1000));
println(collatz_max(10000));
