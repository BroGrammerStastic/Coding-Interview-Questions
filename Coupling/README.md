#Setting up the packages

Create a new project in your chosen IDE. Inside this project, create a new package named
according to a concatenation of your first name, and the first name of your partner
(<partnerApartnerB>). So, if Martin Chapman and Steffen Zschaler were embarking
on this exercise, our project would contain a package called martinsteffen. The order of
names here is unimportant.<br \><br \>

Inside this package, create a subpackage called tightlycoupled. After creating this subpackage
its name, in most IDEs, should appear in the package or project view as <partnerApartnerB>
.tightlycoupled, with <partnerApartnerB> naturally replaced with your first name, and
that of your partner. If you locate the actual folder structure created in your filesystem
by your IDE for this project, you should now find a tightlycoupled folder inside a
<partnerApartnerB> folder.<br \><br \>

#Gathering evidence
Inside your tightlycoupled package, create a new class called Evidence. This class is designed
to reflect a piece of evidence collected from, or relating to, a crime scene or a crime.
As such, you should ensure that this class can be used to store the type of evidence found
(e.g. “clothing fibre”), and you should take appropriate steps to ensure that all instances of
the Evidence class contain this type information. In addition, you should ensure that when
any Evidence object is printed (i.e. passed as an argument to the System.out.println
method), the content of the evidence’s type is printed to the terminal, as opposed to the
object’s memory identifier. Finally, provide a means of getting the type of evidence stored
in any instance of the Evidence class.<br \><br \>

Once you have done this, the following test case should successfully create a new Evidence
object:<br \><br \>

`Evidence clothingFibre = new Evidence(‘‘clothing fibre’’);`

To test that this is indeed the case, create another class, Main, within the <partnerApartnerB>
package. Your package structure should now look something like this:
<br \><br \>

`<partnerApartnerB>/`<br />
`. . . . . . Main.java`<br />
`. . . . . . tightlycoupled/`<br />
`. . . . . . . . . . . . Evidence.java`<br />

If this package structure representation doesn’t make sense to you, follow the appropriate
channels listed in the ‘Additional Support’ section of KEATS for further clarification.
Main should be directly executable, and into Main you should paste the test case given
above. In addition, in your partner’s project specification (which they too should download
from the link given on KEATS), they too will have a test case that creates an Evidence
object, which may contain the same type of evidence, or a different type. Paste your partner’s
test case into Main also, so that Main contains both of your test cases, both of which
should make brand new Evidence objects, that either pertain to two different, or two of
the same types of evidence.

Call System.out.println with each of your Evidence objects so that when Main is executed,
the two types of evidence that these objects represent are printed to the console
in your IDE. If your partner was to have the evidence type “DNA”, then the output from
your program should look like the following:

`clothing fibre`
`DNA`
`3 Storing evidence`

Implement a class called EvidenceBox, that will represent a box that contains multiple
pieces of evidence collected from a crime scene or relating to a crime. This class should
also exist in the tightlycoupled package:
3
<partnerApartnerB>/
. . . . . . Main.java
. . . . . . tightlycoupled/
. . . . . . . . . . . . Evidence.java
. . . . . . . . . . . . EvidenceBox.java
EvidenceBox should maintain a record of all the Evidence it currently contains. In addition,
it should be possible to:
1. Add new pieces of Evidence to the box.
2. Extract the record of all the Evidence currently in the box.
3. Display each type of Evidence currently in the box on a new line in the console of
the IDE. If there are multiple instances of the same type of evidence in a box, then
the output line for that type should be Nx type, where N is the number of occurrences
of that type (e.g. 2x clothing fibre).
In addition, every EvidenceBox should have a caseNumber and a caseName (written on
the side, we might imagine). It should be possible to get the case number from an
EvidenceBox.
Inside Main, after the code which creates your test case Evidence object, and your partner’s,
and prints them, create an EvidenceBox with the case number 2005000381 and the
case name “S. Avery”, and then add your two Evidence objects to it.
Then, display all the types of evidence in the EvidenceBox you just created, so that
when Main is now executed the output from your program appears as the following (again
assuming your partner has the evidence type “DNA”):
clothing fibre
DNA
1x clothing fibre
1x DNA
So, the types of both test case Evidence objects should be printed (as implement in the
previous section), and then summarised by adding these objects to an EvidenceBox and
displaying the contents of that box (as implemented in this section).
4
4 Examining the evidence
Implement a class called Policeman (or Cop, if you prefer to use the vernacular from across
the pond):
<partnerApartnerB>/
. . . . . . Main.java
. . . . . . tightlycoupled/
. . . . . . . . . . . . Evidence.java
. . . . . . . . . . . . EvidenceBox.java
. . . . . . . . . . . . Policeman.java
Every Policeman should have a name, and this name should be printed to the console in
your IDE whenever a Policeman object is printed.
Policemen can have, in their possession at any one time, a collection of EvidenceBoxes
for examination. When a Policeman takes an EvidenceBox, it should be stored in this
collection.
Inside Main, create two Policemen with the names “J. Lenk” and “A. Colborn”. Then,
make the Policeman object that represents J. Lenk take the EvidenceBox you created in
the previous section, with the case number 2005000381 and the case name S. Avery.
Next, we want to give a Policeman the ability to get all pieces of evidence of a certain
type from a box in their possession with a certain case number. For example, J. Lenk may
wish to find all pieces of DNA evidence in the box with the case number 2005000381. The
general procedure required within the Policeman class to do this is as follows:
1. Assume the presence of a desired caseNumber (e.g. 2005000381) and a desired type
of evidence (e.g. “DNA”).
2. Define a list that will store all the objects from an evidence box that match the
desired type.
3. Go through each EvidenceBox in the Policeman’s possession.
4. Determine whether the case number of the current EvidenceBox matches the desired
case number. If it does, select this box.
5. Extract the record of all pieces of Evidence in the selected EvidenceBox (this functionality
was provided inside EvidenceBox in Section 3, Point 2).
5
6. Examine each piece of Evidence in the record extracted from the selected EvidenceBox
in turn.
7. Check whether the current piece of Evidence being examined matches the desired
type of evidence that is being searched for. If it does, add it to the list of objects
that match the desired type.
Implement this procedure, so that inside Main you can instruct J. Lenk to get all the
DNA evidence in S. Avery’s case, 2005000381 (there may not be any DNA evidence in
your EvidenceBox instance, depending on the types of evidence you and your partner have
on your coursework specification, but this is ok). To confirm that this evidence has been
located, you should print the result of the procedure above (i.e. in this example, the list
of Evidence objects that are of DNA type in your EvidenceBox), with a suitable prefix.
Again, this may be a null result if you do not happen to have any DNA evidence in your
evidence box.
Your sample output should therefore now look like the following:
clothing fibre
DNA
1x clothing fibre
1x DNA
Pieces of DNA Evidence in Evidence Box number 2005000381 found by J. Lenk:
[DNA]
5 Starting to visualise things (optional)
At this point, you may like to implement a simple console-based GUI to allow a user to
interact with the code you have produced so far. In other words, you might like to extend
your program in order to use Scanner and System.in to read input from a user in order
to carry out the tasks you have done so far in Main in an ad-hoc and dynamic manner.
For example, you might like to offer the user a simple choice whereby they can choose to
create a new piece of evidence with a type, a new evidence box with a case number and
case name, or to add an existing piece of evidence to an evidence box. Feedback can be
given to the user via System.out.
Essential: Your console-based code must not interfere with your existing classes. Use
Main as a model; a class that simply makes and interacts with the objects created, without
6
those objects being dependent upon Main’s existence. Separating the ‘view’ of a program
from the ‘functionality’ was discussed briefly in PRP last semester, and will be discussed
in more detail in this module later in the semester.
