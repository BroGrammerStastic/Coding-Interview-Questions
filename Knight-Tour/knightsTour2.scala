// Part 2 about finding a single tour for a board
//================================================

// copy any function you need from file knight1.scala

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

/* ( 2.a ) =>
 * Given List[(x,y)], this function will return the first element x, if f is not None
 * @param List[(x,y)], f: Pos => Option[Path] - Used to return first element x from list y
 * @return Option[Path] - It will return first element of list y
 */
def first(currentPath: List[Pos], f: Pos => Option[Path]): Option[Path] = currentPath match {
  case Nil => None
  case elementX :: currentPath => val a = f(elementX); if ( a.isEmpty ) first(currentPath, f) else a
}

/* ( 2.b ) =>
 * Given dimension and path, this function will recursively try to return open tour in each legal move
 * @param dim, path - Used to recursively call each legal move and return first element of open tour
 * @return Option[Path] - It will return first element of open tour
 */
def first_tour(dimension: Int, path: Path): Option[Path] = path match {
  // Two cases, what if the path size is the same as the dimension? - That means all the squares in the box has been visited -Breake the recursion
  case _ if path.size == ( dimension * dimension ) => Some( path )
  // If that's not the case, then we need to call our method that will recursively append our list with all possible moves.
  case _ => first( legal_moves( dimension, path, path.head ), ( position: Pos ) => first_tour( dimension , position :: path ) )
}


println(
  "=========================================" + "\n" +
    "Warning!: Testing Territory" + "\n" +
    "========================================="
)
println(
  first_tour(6,List((0,0)))
)
