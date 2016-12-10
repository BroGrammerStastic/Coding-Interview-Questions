// Part 1 about finding and counting Knight's tours
//==================================================

type Pos = (Int, Int)    // a position on a chessboard
type Path = List[Pos]    // a path...a list of positions

/* ( 1.a ) =>
 * This function will test whether the position given is inside the board and not yet element in the path.
 * @param Int, Path - We need a dimension to test our position on. And path to see if the position exists.
 * @return Boolean
 */
def is_legal(dimension: Int, path: Path)(x: Pos): Boolean = {
  // first lets check if (x,y) is inside the box
  val ItsInsideTheBox = if ( ( x._1 < dimension ) && ( x._2 < dimension ) && ( x._1 >= 0 ) && ( x._2 >= 0 ) ) true else false
  // Lets also check if given (x,y) is not present in the path - If it was then it would mean that it has been visited again
  val HasNotVisited = if (!path.contains(x)) true else false
  // This function will only return true if (x,y) is inside the box and has not been visited before
  ItsInsideTheBox && HasNotVisited
}

/* ( 1.b ) =>
 * Given (x,y), this function will calculate all possible moves (that has not been visited before) that a knight can make
 * in clockwise fashion
 * @param dim, path, pos - We need the pos to produce the possible moves. Path to ensure the pos has not existed previously
 * @return List[Pos] - It will return list of all possible positions that  knight can make
 */
def legal_moves(dimension: Int, path: Path, x: Pos): List[Pos] = {
  /* A knight is able to make a move in 'L' shape in any direction. If you observe this point, you'll realise that there
   * are 8 possible moves that a knight can make maximum. To return list of moves in clock wise, the order of the move in
   * the list matters.
   */
  val moves = List(
    //    top-right             top-right           bottom-right          bottom-right
    (x._1 + 1, x._2 + 2), (x._1 + 2, x._2 + 1), (x._1 + 2, x._2 - 1), (x._1 + 1, x._2 - 2),
    //   bottom-left          bottom-left            top-right             top-right
    (x._1 - 1, x._2 - 2), (x._1 - 2, x._2 - 1), (x._1 - 2, x._2 + 1), (x._1 - 1, x._2 + 2)
  )

  val possibleMoves = if (path != Nil) {
    // if there is no tour of the knight, then find the difference and return it
    moves.filter( is_legal(dimension, path)).map { case (row,column) => (row,column) }.diff(path)
  } else {
    // if there is some tour, then return the path
    moves.filter( is_legal(dimension, path)).map { case (row,column) => (row,column) }
  }
  possibleMoves
}

/* Given (currentPath,legalMoves), this function will recursively call its self getting the new moves and appending the
 * path until it reaches its base case.
 * @param currentPath, legalMoves - We need the legal moves of its current path
 * @return Int - It will return the counter of the recursive call
 */
def callBack(currentPath: Path, legalMoves: Path, incrementCounter: Int, dimension: Int): Int = legalMoves match {
  // First case is that what if the legalMove is empty? if is, then just return an empty List (aka Nil)
  case Nil => incrementCounter
  // If the the legal moves list is not empty, then we need the head of the legal move list and callback
  case head :: legalMoves => callBack( currentPath, legalMoves, incrementCounter + count_tours(dimension, head :: currentPath), dimension )
}

/* ( 1.c.a ) =>
 * Given (x,y), this function will calculate all possible "open" tours a knight can make
 * @param dim, path - We need dim * dim as base case for our recursive call
 * @return Int - It will return number of tours a knight made
 */
def count_tours(dimension: Int, path: Path): Int = path match {
  // Two cases, what if the path size is the same as the dimension? - That means all the squares in the box has been visited -Breake the recursion
  case _ if path.size == (dimension * dimension) => 1
  // If that's not the case, then we need to call our method that will recursively append our list with all possible moves.
  case _ => callBack( path , legal_moves(dimension, path, path.head) , 0 , dimension )
}

/* ( 1.c.b ) =>
 * Given (x,y), this function will calculate all possible "open" tours a knight can make
 * @param dim, path - We need dim * dim as base case for our recursive call
 * @return Int - It will return list of paths
 */
def enum_tours(dimension: Int, path: Path): List[Path] = {
  // a variable that will consist of legal moves and its corresponding legal moves
  val newLegalMove = legal_moves(dimension,path,path.head).map(i => i :: path).map(j => enum_tours(dimension,j))
  // we need to match the current path
  path match {
    // if the path has a size the same as the 2D board, then break the recursive call and return list of path
    case _ if path.length == dimension * dimension => List(path)
    // If the knight has not visited each sqaure in 2D box, then call the
    case _ if path.length <  dimension * dimension => newLegalMove.flatten
    // else return Nil
    case _ => Nil
  }
}

println(
  "=========================================" + "\n" +
    "Warning!: Testing Territory" + "\n" +
  "========================================="
)
println(
  "Legal_Moves() => " + "\n" +
  legal_moves(8, Nil, (2,2)) + "\n" +
  legal_moves(8, Nil, (7,7)) + "\n" +
  legal_moves(8, List((4,1), (1,0)), (2,2)) + "\n" +
  legal_moves(8, List((6,6)), (7,7)) + "\n" +
  "Count_Tours() => " + "\n" +
  count_tours(5,List((0,0)))
)
