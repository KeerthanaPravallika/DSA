/* Convert Decimal to Binary */

// Approach 1

public class DecimalToBinary {
    public static void main(String[] args) {
        int decimal = 29; 
        String binary = convertToBinary(decimal);
        System.out.println("Decimal: " + decimal + " -> Binary: " + binary);
    }

    public static String convertToBinary(int decimal) {
        String binary = "";
        while (decimal > 0) {
            int remainder = decimal % 2;
            binary += remainder;
            decimal = decimal / 2;
        }
        return binary;
    }
}

// Approach 2 
public class DecimalToBinary {
    public static void main(String[] args) {
        int decimal = 29; // Example decimal number
        String binary = Integer.toBinaryString(decimal);
        System.out.println("Decimal: " + decimal + " -> Binary: " + binary);
    }
}

