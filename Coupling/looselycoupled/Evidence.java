package looselycoupled;

/**
 * Evidence class is a simple class that specifies the type of evidence.
 */
public class Evidence {
    // private type modifier that will only be visible to this class
    private String type;

    // Evidence class Constructor
    /**
     * Evidence class with constructor that requires the type to be specified when instantiated
     * @param type type is a String field that will be used to store the result of the type
     */
    public Evidence (String type) {
        this.type = type;
    }

    // Get method to return type od evidence
    /**
     * Getter method that, when invoked, will return the type
     * @return Returns the value that is stored in type
     */
    public String getType() {
        return type;
    }

    // toSting method to return string representation of and object
    /**
     * toString method that prints the type
     * @return This returns the type
     */
    public String toString() {
        return type;
    }
}