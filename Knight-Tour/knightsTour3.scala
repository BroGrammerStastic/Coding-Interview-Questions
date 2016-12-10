import scala.annotation.tailrec

// Part 3 about finding a single tour using the Warnsdorf Rule
//=============================================================

// copy any function you need from files knight1.scala and
// knight2.scala

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

/* ( 3.a ) =>
 * given dimension, path and (x,y), this function will calculate a list of legal moves (similar in 1.b), but orders them
 * according to the Warnsdorf’s rule. Which means moves with the fewest legal moves will come first
 * @param dim, path, pos - to calculate legal moves and return list in order
 * @return Option[Path] - list of legal moves in order
 */
def ordered_moves(dim: Int, path: Path, x: Pos): List[Pos] = {
  legal_moves(dim,path,x).sortWith { case (i,j) => legal_moves(dim,path,i).length < legal_moves(dim,path,j).length }
}

/* ( 3.b ) =>
 * given dimension, List[(x,y)], this function will search for single *closed* tour using the ordered moves function
 * @param dim, path, pos - to calculate legal moves and return list in order
 * @return Option[Path] - list of legal moves in order
 */
def first_closed_tour_heuristic(dim: Int, path: Path): Option[Path] = path match {
  case _ if legal_moves(dim, Nil, path(0) ).contains(path.last) &&  path.size == dim * dim => Some( path )
  case _ => first( ordered_moves(dim,path,path.head), ( position: Pos ) => first_closed_tour_heuristic( dim , position :: path ) )
}

/* ( 3.c ) =>
 * given dimension, List[(x,y)], this function will search for *Open" tours using the ordered moves function
 * @param dim, path, pos - to calculate legal moves and return list in order
 * @return Option[Path] - list of legal moves in order
 */
def first_tour_heuristic(dim: Int, path: Path): Option[Path] = {
  // tail recursion is used to implement this method, as I'd get stackoverflow error
  @tailrec
  def callBack(newPath : List[Path]) : Option[Path] = newPath match {
    // insuring that the list is not empty. If so, then return Some(None)
    case Nil => None
    // For the element inside our list...
    case head :: tail => head match {
      // first, we need to make sure its not closed tour and covers all the box in the grid. If so => return the element
      case _ if !legal_moves(dim, Nil, path( 0 ) ).contains(path.last) &&  head.size == dim * dim => Some( head )
      // If not the above, then if the tour is less than the size of the box, recursively yield the i to the element
      case _ if head.size < dim * dim => callBack(ordered_moves(dim,head,head.head).map( i => i :: head ) )
    }
  }
  // lets call out function
  callBack(List(path))
}


println("========================= Warning!: Testing Territory! =========================")
println(
  //"Closed tour heuristic: = " + first_closed_tour_heuristic( 6,List( ( 3 , 3 ) ) ) + "\n" +
  "Open tour heuristic: = "   + first_tour_heuristic(50 ,List( ( 25 , 25 ) ) )
)
