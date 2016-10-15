
//import tightlycoupled.Cop;
//import tightlycoupled.Evidence;
//import tightlycoupled.EvidenceBox;

import looselycoupled.Cop;
import looselycoupled.Evidence;
import looselycoupled.EvidenceBox;

public class Main {

    public static void main(String[] args) {

        // creating and instances of Evidence object
        Evidence pE = new Evidence("personal ephemera");
        Evidence cF = new Evidence("clothing fibre");

        // Printing the objects
        System.out.println(pE);
        System.out.println(cF);

        // Creating an instance of EvidenceBox object
        EvidenceBox crimeBox1 = new EvidenceBox(2005000381, "S.Avery");
        // Adding Evidences to the EvidenceBox
        crimeBox1.add(pE);
        crimeBox1.add(cF);

        // Display the x amount of evidences in a evidence box
        crimeBox1.display();

        // Creating instances of Cop object
        Cop policeman1 = new Cop("J. Lenk");
        Cop policeman2 = new Cop("A. Colborn");

        // Cop takes and evidence box
        policeman1.takes(crimeBox1);

        // Checking if the case number matches any Evidence box
        // Also checking if DNA is on the list
        System.out.println(policeman1.getParticularEvidence(2005000381, "DNA"));

    }

}