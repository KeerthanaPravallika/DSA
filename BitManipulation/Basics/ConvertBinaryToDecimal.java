/* Convert Binary to Decimal */

// Approach 1 
public class BinaryToDecimal {
    public static void main(String[] args) {
        String binary = "11101"; // Example binary number
        int decimal = convertToDecimal(binary);
        System.out.println("Binary: " + binary + " -> Decimal: " + decimal);
    }

    public static int convertToDecimal(String binary) {
        int decimal = 0;
        int length = binary.length();
        for (int i = 0; i < length; i++) {
            char bit = binary.charAt(length - 1 - i);
            if (bit == '1') {
                decimal += Math.pow(2, i);
            }
        }
        return decimal;
    }
}

// Approach 2 

/* The Integer.parseInt(String s, int radix) method takes a string and a radix (base) as arguments. For binary conversion, the radix is 2. */

public class BinaryToDecimal {
    public static void main(String[] args) {
        String binary = "11101"; // Example binary number
        int decimal = Integer.parseInt(binary, 2);
        System.out.println("Binary: " + binary + " -> Decimal: " + decimal);
    }
}