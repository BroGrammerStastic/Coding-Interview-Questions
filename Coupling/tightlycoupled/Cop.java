package tightlycoupled;

// importing required libraries
import java.util.ArrayList;

/**
 * Cop class is a class that represents a policeman. Every Policeman has a name. Their purpose is to check whether a certain evidence is in a specific box.
 */
public class Cop {

    // declaring private variables
    private String name;

    // Making a new array list of evidence boxes
    private ArrayList<EvidenceBox> collectionOfEvidenceBoxes = new ArrayList<>();

    // Cop class Constructor
    /**
     * Cop constructor is used to give a name to every instance of policeman
     * @param name This is a field that stores the name of the police
     */
    public Cop(String name) {
        this.name = name;
    }

    // Method for Cop to take an evidence box
    /**
     * This is a method that allows every a policeman to take an Evidencebox and put it inside his collection
     * @param box This is Object instance of EvidenceBox that is used to take a certain Evidencebox
     */
    public void takes(EvidenceBox box) {
        collectionOfEvidenceBoxes.add(box);
    }

    // method for checking if a certain evidence is in a specific box
    /**
     * This is a method that allows a policeman to check whether a certain evidence exists in a specific box.
     * @param caseNumber This is a number  for the Evidencebox that the policeman will search by - Think of this as our primary ley to check for a unique Evidencebox.
     * @param type This is a parameter that allows the policeman to search for a specific evidence in the specified bo.
     * @return It will return the list of evidences.
     */
    public ArrayList<Evidence> getParticularEvidence(int caseNumber, String type) {
        ArrayList<Evidence> evidencePieces = new ArrayList<>();
        for(EvidenceBox e : collectionOfEvidenceBoxes) {
            // Checking if the case number matches the requested number
            if( e.getCaseNumber() == caseNumber) {
                ArrayList<Evidence> extractedList = e.extract();
                for(Evidence e2 : extractedList) {
                    // Checking if the type matched the requested type
                    if(e2.getType().equals(type)) {
                        evidencePieces.add(e2);
                    }
                }
            }
            else {
                // Message for when a case number does not have a match
                System.out.println("Not Found!");
            }
        }
        // Message of the evidence and case number requested
        System.out.println("Pieces of " + type + " Evidence in Evidence Box number " + caseNumber + " found  by " + name + ": ");
        // IF the evidence matches then it will return it
        return evidencePieces;
    }

    // toSting method to return string representation of and object
    /**
     * toString method will print the name of the policeman
     * @return It will return the name of the police
     */
    public String toString() {
        return name;
    }
}
