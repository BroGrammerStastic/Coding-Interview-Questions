#Uniqueness Of Given String

Implement an algorithm to determine if a string has all unique characters.

######**Insure:**
  1. ***The complexity time of given algorithm is O(n).***
  2. ***The space complexity of given algorithm is O(n).***
  3. ***You need to consider ASCII chars as well.***

######**Test Case**
*Input:*
  1. `YourMethod("Nas")`
  2. `YourMethod("Hello")`
  3. `YourMethod("Naseebullah")`

*Output:*
  1. **`True`**
  2. **`False`**
  3. **`False`**


####Challenge
Once a **`char[]`** has been detected duplicate, replace that **`char[]`** with
a new character that comes after the old character.

for example:
`YourMethod("Hello")` - **`char[ "H", "e", "l", "l", "o"]`**.
duplicate value detected at index **3**. replace *`l`* with *`m`*. 
