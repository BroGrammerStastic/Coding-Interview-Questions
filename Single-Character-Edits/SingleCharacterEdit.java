import java.util.*;

public class SingleCharacterEdit {

  public static String singleCharacterEditWillTurnAIntoB(String a, String b) {
    // TODO: your code goes here, replacing the next line with your actual code
    // checking
    String returnValue = "";

    // first check if the string length of a and b are the same
    if (a.length() == b.length()) {
      // if so, then call checkIfArrayMatch()
      returnValue = checkIfArrayMatch(a,b);
    } else if (a.length() < b.length()) {
      // else if string a length is smaller then b, then, we gonna insert
      returnValue = insert(a,b);
    } else if (a.length() > b.length()) {
      // if the string a's length is higher than b, then we gonna remove
      returnValue = remove(a,b);
    } else {
      // if the none of the above is satisfied, just return null
      returnValue = null;
    }
    return returnValue;
  }

  /*
    - The replace mehtod will replace the char in string a that does not match
    - in string b, and return the updated string a
  */
  public static String replace(String a, String b) {
    String returnValue = "";
    ArrayList<Integer> replacePosition = new ArrayList<>();
    ArrayList<Character> replaceChar = new ArrayList<>();

    /*
      - loop through the a's length
      - if the char at a does not match the char at b
      - then call the charArray and replace it
    */
    for (int i = 0; i < a.length() ; i++) {
      if (a.charAt(i) != b.charAt(i)) {
        a = replaceCharAt(a, a.indexOf(a.charAt(i)) ,a.charAt(i));
        replacePosition.add(b.indexOf(b.charAt(i)));
        replaceChar.add(b.charAt(i));
        returnValue = changeArray("replace,",replacePosition,replaceChar);
      }
    }
    return returnValue;
  }

  /*
    - This method, when called will remove the char that not apear in b
  */
  public static String remove(String a, String b) {
    String returnValue = "";
    ArrayList<Integer> removePosition = new ArrayList<>();
    char compare = '\0';

    /*
      - first check if string a contains duplicate or not.
      - If it does, then remove the duplicated val
      - If no duplicate, then check if b array contains the char in a, and,
      - make sure the we called the remove method less than twice, if so, then remove.
      - Otherwise return null
    */
    if (isDuplicate(a).size() > 0 ) {
      returnValue = changeArray("remove,",isDuplicate(a),"");
    } else {
      for(int i = 0; i < a.length(); i++) {
        if(!setArray(b,null).contains(a.charAt(i)) && removePosition.size() < 2 ) {
          removePosition.add(i);
          returnValue = changeArray("remove,",removePosition,"");
        } else if(removePosition.size() >= 2) {
          returnValue = null;
        }
      }
    }
    return returnValue;
  }

  /*
    - This method checks if there is any duplicates within a given string
  */
  public static ArrayList isDuplicate(String a) {
    ArrayList<Integer> removePosition = new ArrayList<>();
    for (int i = 0; i < a.length() - 1; i++) {
      for (int j = i + 1; j < a.length(); j++) {
        if(a.charAt(i) == a.charAt(j)){
          removePosition.add(i);
        }
      }
    }
    return removePosition;
  }

  /*
    - This method will insert the char in b to string a
    - Check if the string a array does not contain char in b, and the insert
    - call is less than 2. If so, then we insert
    - Otherwise return null
  */
  public static String insert(String a, String b) {
    String returnValue = "";
    ArrayList<Integer> insertPosition = new ArrayList<>();
    ArrayList<Character> insertChar = new ArrayList<>();

    for(int i = 0; i < b.length(); i++) {
      if(!setArray(a,null).contains(b.charAt(i)) && insertPosition.size() < 2) {
        setArray(a,b.charAt(i));
        insertPosition.add(i);
        insertChar.add(b.charAt(i));
        returnValue = changeArray("insert,",insertPosition,insertChar);
      } else if (insertPosition.size() >= 2){
        returnValue = null;
      }
    }
    return returnValue;
  }

  /*
    - we check if char in string a does not exist, then we call replace
    - otherwise return null
  */
  public static String checkIfArrayMatch(String a, String b) {
    int callMethod = 0;
    String returnValue = "";
    for (int i = 0; i < a.length() ; i++) {
      if ((a.charAt(i) != b.charAt(i)) ) {
        returnValue = replace(a,b);
      } else {
        returnValue = null;
      }
    }
    return returnValue;
  }

  /*
    - This method will add char in str to an arraylist
  */
  public static ArrayList setArray(String str, Object c) {
    ArrayList<Character> charactersList = new ArrayList<>();
    for(int i = 0; i < str.length(); i++) {
      charactersList.add(str.charAt(i));
    }
    charactersList.add((Character) c);
    return charactersList;
  }

  /*
    - This method when called, will strip all the brackets from an array,
    - and return a string
  */
  public static String changeArray(String action, ArrayList addArray, Object charArray) {
    String returnValue = "";
    String actionStringify = action + addArray.toString().replace(" ", "").replace("[","").replace("]","").trim();
    String charArrayStringyfy = charArray.toString().replace(" ", "").replace("[","").replace("]","").trim();
    if (charArray instanceof String) {
      returnValue = actionStringify + charArrayStringyfy;
    } else {
      returnValue = actionStringify + "," + charArrayStringyfy;
    }
    return returnValue;
  }

  /*
    - This method will replace the char at given index
  */
  public static String replaceCharAt(String s, int pos, char c) {
    return s.substring(0, pos) + c + s.substring(pos + 1);
  }
}
