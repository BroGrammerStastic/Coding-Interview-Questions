package tightlycoupled;

// Importing required libraries
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 * An EvidenceBox is a class that consists of an arbitrary number of evidences
 */
public class EvidenceBox {

    // Declaring private variables
    private int caseNumber;
    private String caseName;

    // Making a new array list of evidences
    private ArrayList<Evidence> evidenceBoxList = new ArrayList<>();

    // EvidenceBox class Constructor
    /**
     * A constructor is used for every instance of EvidenceBox. This constructor will have two parametrs that will allow us to recognise a specific box (i.e. eah evidencebox has a number and name).
     * @param caseNumber This is a unique number that every Evidencebox will have.
     * @param caseName Every Evidencebox will have a name associated.
     */
    public EvidenceBox(int caseNumber, String caseName)  {
        this.caseNumber = caseNumber;
        this.caseName = caseName;
    }

    // Method to add evidence to the list
    /**
     * This is a method that will enable the evidencebox to add a specific evidence or evidences.
     * @param evidence An object parameter of Evidence is used to add an instance of evidence.
     */
    public void add(Evidence evidence)  {
                evidenceBoxList.add(evidence);
    }

    // method to return the list
    /**
     * This is a method that will give the ability for the evidencebox to return the list of evidences that is stored in an arraylist.
     * @return This returns the list of evidences
     */
    public ArrayList<Evidence> extract() {
        return evidenceBoxList;
    }

    // Method to check the list for x number of evidences
    /**
     * This is a method that will allow the evidencebox to search for any duplicates types of evidences that has occurred. We accomplish this by using HashMap
     */
    public void display() {
        // Map interface instantiated - currently at this stage it is empty
        Map<String, Integer> map = new HashMap<>();
        // iterate over every evidence instance in evidenceboxlist and store those evidences that are not empty
        for (Evidence e : evidenceBoxList) {
            if ( map.putIfAbsent( e.getType(), 1 ) != null )
                map.put(e.getType(), map.get(e.getType()) + 1);
        }
        // iterate over our map and print it
        for (Map.Entry<String, Integer> e : map.entrySet()) {
            System.out.println(e.getValue() + "x " + e.getKey());
        }
    }

    // Get method to return casenumber
    /**
     * Getter method can be used to return the caseNumber
     * @return This returns the caseNumber
     */
    public int getCaseNumber() {
        return caseNumber;
    }
}
