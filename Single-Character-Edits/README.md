# Single character edits

There are three sorts of single character edit that can be made to a string:

* Replacing one character with another, at some position
* Removing a character, from some position
* Inserting a character at some position, before what was previously there

Implement the method in the `SingleCharacterEdit` class (provided) that takes two strings, `a` and `b`, and returns a String that prescribes what single-character edit will turn a into b; or returns `null` if no such single-character edit exists.  The format of the string returned should be as follows:

* If the character at position *n* was replaced with the character *c*, return the string `replace,n,c`.  For instance, if character 1 was replaced with an x, return `replace,1,x`
* If the character at position *n* was removed, return `remove,n`.  For instance, if the first character was removed, return `remove,0`.
* If a new character *c* was inserted at position *n*, return the string `insert,n,c`.  For instance, for input strings `cat` and `chat`, return `insert,1,h`

Note the string returned should be exactly as prescribed here.  Do not add additional spacing, and replace, remove and insert should be in lowercase.

To test your code, run the given class `TestSingleCharacterEdit`.  This will perform some basic testing of your code, by calling it and checking it gives the right outputs.
