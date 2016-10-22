public class Unique {
  /**
    > checkDuplicate(String uniqueString) is a method that, when called, will
      go through the string and check if a particular char has apeared before
      or not.
      ==========================================================================
    > How do we do this?
    > First thing first, there are few assumptions we need to make:
        > Does the String have any ASCII characters or not?
        > Do we need to exlude any captital letters or not?
        > Is there a size limitation or not?
        > Is there a specific time complexity your looking into?
        The answer for all of them is...Yes!
    > First, we need a boolean array of size 256 - as ASCII have 256 different
      chars.
    > Traverse through our string and check if our array at index i has the same
      char or not.
      ==========================================================================
      Time Complexity : O(n);
      space complexity: O(n);
  **/
  public static boolean checkDuplicate(String uniqueString) {
    // our array that contains value of true or false at given index i
    boolean[] charSet = new boolean[256];
    // lets go through each char in the uniqueString
    for (int i = 0; i < uniqueString.length(); i++ ) {
      // store the the value of that char in its equivalence int value
      int val = uniqueString.charAt(i);
      // see if the index at i in our array is true or false
      if (charSet[val]) {
        // duplicate value detected;
        return false;
      } else {
        // Unique value detected, store true;
        charSet[val] = true;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    boolean checkUnique = Unique.checkDuplicate("Naseb");
    System.out.println(checkUnique);
  }

}
