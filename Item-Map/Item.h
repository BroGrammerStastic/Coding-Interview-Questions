#ifndef ITEM_H
#define ITEM_H
// TODO: your code goes here
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <tuple>

using namespace std;
using std::string;
using std::vector;
using std::get;


class Item {
  // some private variables within the scope of this class
private:
  string ID;
  double latitude;
  double longitude;
  int    time;


public:
  // ostream declared to be used to print refeence of Item objects
  friend ostream& operator<<(ostream& printStream, const Item & item);
  // A copy constructor of Item that does not take any params
  Item(){}
  // a constructor of item that takes params to distinguish particular object
  Item( double _Latitude, double _Longitude, string _ID, int _Time)
      // c++ style of initialising our variables witin constructor
      : latitude(_Latitude), longitude(_Longitude), ID(_ID), time(_Time) {
  }

  // method distanceTo needs to be declared before used
  double distanceTo(Item& i);

  // getter method to return ID of the item
  string getID() const {
    return ID;
  }

  // getter method to return Item's latitude
  double getLatitude() const {
    return latitude;
  }

  // getter method to return Item's longitude
  double getLongitude() const {
    return longitude;
  }

  // getter method to return Item's time
  int getTime() const{
    return time;
  }
}; // Class Item ends here

/*
 - Method called to convert our latidue and longitude to radians
*/
double convertDegreesToRadians(double degrees) {
  // found out its more efficient to use my own PI rather than calling it.
  double const PI = 3.141592653589793238462643383279502884L;
  return  (degrees * PI) / 180 ;
}

/*
  - Method used to calculate the distance between two objects (aka two Items)
  - Calls the lat and long of both items
  - perform some complex calculation using cos and sin
  - multply it by the earths circle
*/
double Item::distanceTo(Item & item) {
  double anotherItemLatitude, anotherItemLongitude,
         thisItemLatitude, thisItemLongitude, dLon, dLat, a, c, distance;

  // calling lat and long of both items
  anotherItemLatitude   =   convertDegreesToRadians(item.getLatitude());
  anotherItemLongitude  =   convertDegreesToRadians(item.getLongitude());
  thisItemLatitude      =   convertDegreesToRadians(getLatitude());
  thisItemLongitude     =   convertDegreesToRadians(getLongitude());

  // complex calculation
  dLon = anotherItemLongitude - thisItemLongitude;
  dLat = anotherItemLatitude  - thisItemLatitude;
  a    =  pow((sin(dLat/2)), 2)    +
          cos(thisItemLatitude)    *
          cos(anotherItemLatitude) *
          pow((sin(dLon/2)), 2)
  ;
  c    = 2 * atan2( sqrt(a), sqrt(1-a) );
  distance = 6373000 * c;
  // return it
  return distance;
}

// Like in java, we have toString() to print a particular class,
// We have ostream in c++ to print our particular class
ostream& operator<<(ostream& printStream, const Item& item) {
  printStream << "{" << item.getLatitude() <<
  ", " << item.getLongitude() << ", \"" <<
  item.getID() << "\", " << item.getTime() << "}";
  return printStream;
}

// another class created to distinguish map of the items
class MapOfItems {
private:
  // vector of items obtained from Item class
  vector<Item> vectorOfItem;

public:
  // this method, when called, will return the lowest value in our vector
  double getMinInt(vector<double>& v) {
    return *min_element(v.begin(), v.end());
  }

  /*
    - this method, will start the tour of items when the first item is available.
    - After the first item is available, we iterate through the remaining items
    - in the vector, and check their distance between the previous item, and the
    - one with the lowest distance is added next to our another vector.
    - But before we add it to the vector, we check that the item's time is less
    - than 15 minutes and the tour hasnt ended.
  */
  vector<Item> getTour(double walkingSpeed) {
    // this is the vector that will contain all the items that have been in tour
    vector<Item> tour;
    // vector used to add visited items. Its size is the same size as our items
    vector<int> visitedItems(size());
    // calling the fill method to initialise our vector with 0s
    fill(visitedItems.begin(), visitedItems.end(), 0);
    // some variables declared
    int _callingCurrentTime, setTourSizeTo, _callingItemIndex, finalIndex, FifteenMinutes;
    _callingCurrentTime = setTourSizeTo = 0;
    double finalTime, visitItem;
    // ---------------------------------------------------------
    // gets the lowest item index
    _callingItemIndex = getLowestItemIndex();
    // gets the time of the the item with the lowest value.
    // which is obtained from the _callingItemIndex
    _callingCurrentTime = getItemVector()[_callingItemIndex].getTime();
    // insuring that the items at index is visited (hence initialised to true)
    visitedItems[_callingItemIndex] = true;
    // push our item to our tour vector
    tour.push_back(getItemVector()[_callingItemIndex]);
    // a do {} while{} used to run untill less than 3600 seconds
    do {
      // insuring that our final and last time will be 3600 seconds
      finalTime = 3600;
      // lets make sure that our index does not exists so far
      finalIndex = false;
      // iterate our vector of items and
      for (int i = 0; i < size(); i++) {
        // check if the visited item does not exist in our vector
        if (visitedItems[i] == false) {
          // for each item that dont exist, calculate their visit time
          visitItem = visit(
            setTourSizeTo,i,_callingCurrentTime,walkingSpeed,tour
          );
          // each item can only be available for 15 minutes
          FifteenMinutes = getItemVector()[i].getTime() + 900;
          // if the item that just visited is less than 15 minutes
          if ( (visitItem < FifteenMinutes)) {
            // were going to set our visisted to the current time
            setVisitToCurrent(visitItem,i);
            /*
              - Creating a tuple that if visit item is less than finaltime
              - set the final time to the current time, and its index
            */
            auto getTuple = lessThan3600(visitItem,finalIndex,finalTime,i);
            // set the final time to visit time from the tuple
            finalTime   = get<0>(getTuple);
            // set its index of the visit time
            finalIndex  = get<1>(getTuple);
          }
        }
      }
      // after the for loop ends, were going to re-initialise our current time
      // to the final time obtained within the for loop
      _callingCurrentTime = finalTime;
      // calling this method to make sure that if the current time is still less
      // than 3600 seconds.
      check_If_Current_Is_Less_Than_3600(
        _callingCurrentTime,visitedItems,
        tour,finalIndex,setTourSizeTo
      );
      // only end the while loop when the currentTime overlaps 3600 seconds
    } while(_callingCurrentTime < 3600);
    // return our obtained vector of items that were on tour
    return tour;
  }

  /*
    - This method when, called will check if the current time passed is less
    - than 3600 seconds.
    - If so, then make the vector at index passed to true and push it to our
    - reference tour and increment the size
  */
  void check_If_Current_Is_Less_Than_3600(
    int          & _callingCurrentTime,
    vector<int>  & visitedItems,
    vector<Item> & tour,
    int          & finalIndex,
    int          & setTourSizeTo
  ) {
    if (_callingCurrentTime < 3600) {
      visitedItems[finalIndex] = true;
      tour.push_back(getItemVector()[finalIndex]);
      setTourSizeTo++;
    }
  }

  /*
    - Called when trying to set my visit item to the current time
  */
  double setVisitToCurrent(double & visitItem, int i) {
    if (visitItem < getItemVector()[i].getTime()) {
      visitItem = getItemVector()[i].getTime();
    }
  }

  /*
    - This method when called, will check if the tour is still running, i.e less
    - than 3600.
    @return tuple of two varibales at given index
  */
  tuple<double,int> lessThan3600(
    double  & visitItem,
    int     finalIndex,
    double  & finalTime,
    int     i
  ) {
    if (visitItem < finalTime) {
      finalTime = visitItem;
      finalIndex = i;
    }
    return std::make_tuple(finalTime,finalIndex);
  }

  /*
   - visit(i) will check the distance between two given items
  */
  double visit(
    int          prevItem,
    int          nextItem,
    int          currentTime,
    double       walkingSpeed,
    vector<Item> tour
  ) {
    return
      currentTime +
      (tour[prevItem].distanceTo(getItemVector()[nextItem])) /
      walkingSpeed
    ;
  }

  /*
    - This method will return the item with the lowest time
  */
  int getLowestItemIndex() {
    // first initialise our first item to the first item in the vector
    int firstItem = getItemVector()[0].getTime();
    // and its index to 0;
    int j = 0;
    // iterate over our vector and
    for (int i = 0; i < size(); i++) {
      // see if the item at index[i] time is less than the first items time
      if (getItemVector()[i].getTime() < firstItem) {
        // if so, then re-initialise our first item to the current item
        firstItem = getItemVector()[i].getTime(); j = i;
      }
    }
    // and return its index
    return j;
  }

  /*
    - add method that adds item to the vector
  */
  void addItem(Item item) {
    vectorOfItem.push_back(item);
  }

  /*
    - getter method that returns vector of items
  */
  vector<Item> & getItemVector() {
    return vectorOfItem;
  }

  /*
    - getter() method that returns the size of the vector
  */
  int size() const {
    return vectorOfItem.size();
  }
};



// don't write any code below this line

#endif
