#ifndef KNIGHTS_H
#define KNIGHTS_H
#include <utility>
#include <vector>
#include <algorithm>
using std::pair;
using std::make_pair;
using std::vector;

typedef vector<pair<int,int> > Path;

/** Helper function: adds two pairs of ints */
pair<int,int> operator+(const pair<int,int> & a, const pair<int,int> & b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

/**
 * ( 1.a ) =>
 * Given [pair<> a, pair<> b], this function will return a vector containing all
 * the positions that could be reached from there. These should be in
 * anti-clockwise order, starting at 6 o'clock.
 * @param pair<int,int> - requires specific position to calc legal moves
 * @return Path - will return list of all legal moves
 */
const Path moves(const pair<int,int> & position) {
  // we're going to hard code our moves in anti-clockwise fasion
  return Path {
    // shallow-right-deep-top             deep-right-shallow-top
    position + make_pair( 1 , 2 )   ,  position + make_pair( 2 , 1 ),
    // deep-right-shallow-bottom        shallow-right-deep-bottom
    position + make_pair( 2 , -1 )  ,  position + make_pair( 1 , -2 ),
    // shallow-left-deep-bottom         deep-left-shallow-bottom
    position + make_pair( -1 , -2 ) ,  position + make_pair( -2 , -1 ),
    // deep-left-shallow-top             shallow-left-deep-top
    position + make_pair( -2 , 1 )  ,  position + make_pair( -1 , 2 )
  };
}

/**
 * ( 1.b ) =>
 * Given position and Path, this function will determine all the legal mooves.
 * It insures that the current position is within the box, and it does not exist
 * in the existing path.
 * @param pair<int,int> - requires specific position to calc legal moves
 * @param Path - requires the current path to check if position exists or not.
 * @return Path - will return list of all legal moves
 */
const Path legal_moves( const int & dim, const Path & path, const pair<int,int> & position ) {
  // first lets check if the base of our position is within the box. If so...
  if ( ( position.first < dim ) && ( position.second < dim ) && ( position.first >= 0 ) && ( position.second >= 0 ) ) {
    // Lets assign the legal moves of the position to a variable
    Path lMoves = moves( position );
    // At this point, our lMoves concists of 8 moves in general. (consist of negative numbers)
    lMoves.erase( remove_if( lMoves.begin(), lMoves.end(),
      // erase from the path, if the following is met...
      [&](const pair<int,int> & o) {
        // check if vector contains the element
        auto itsVisited = find(path.begin(), path.end(),o) == path.end();
        // check if its within the box
        auto itsInsideTheBox = ( o.first < dim ) && ( o.second < dim ) && ( o.first >= 0 ) && ( o.second >= 0 );
        // remove if any of them returns false
        return ( !itsInsideTheBox || !itsVisited );
      }), lMoves.end()
    );
    // lets return the newPath after the remove if
    return lMoves;
    // otherwise return an empty path
  } else { return Path(); }
}

/**
 * ( 1.c ) =>
 * Given the size of the board and a path, it will recursively search for open
 * tour and stop once found
 * @param Path - requires path to add moves
 * @return a pair of path and bool
 */
const pair<Path,bool> first_tour(int & dim, const Path & path) {
  // Lets store our legal moves of the last element in the path
  Path legalMoves = legal_moves( dim , path , path.back() );
  // iterate the legal moves
  for (auto i = 0; i < legalMoves.size() ; i++) {
    // lets create a new Path variable
    Path newPathWithNewLegalMoves = path;
    /*
     * We need to speedup our process of finding tour as its very time consuming.
     * We can use sort to sort our legal moves accoridng to their legal moves.
     * This will recursively go to the branch when its the shortest
    */
    sort(
      // to sort, we loop from the begining to end of our legal moves
      legalMoves.begin(),legalMoves.end(),
      [&](pair<int,int> & p1, pair<int,int> & p2) {
        // so now lets sort the legal moves by their legal moves
        return legal_moves(dim,newPathWithNewLegalMoves,p1).size() < legal_moves(dim,newPathWithNewLegalMoves,p2).size();
      }
    );
    // and insert it to our new copy
    newPathWithNewLegalMoves.push_back(legalMoves[i]);
    // at this point, we need to be recursively calling the same method again
    auto pair = first_tour(dim,newPathWithNewLegalMoves);
    // the recursion will take place until the size of the first is equal to full width
    if ( pair.first.size() == dim * dim ) return pair;
  }
  // if recurisvely checked the whole grid, then return the pair, else return empty pair
  return (path.size() == dim * dim) ? make_pair(path,true) : make_pair(Path(), false);
}

// Do not edit below this line

#endif
