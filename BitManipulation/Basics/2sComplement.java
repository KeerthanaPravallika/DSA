// The 2's complement of a binary number is obtained by first finding the 1's complement 
// (flipping all the bits) and then adding 1 to the least significant bit (LSB). 

public class Main {
    public static void main(String[] args) {
        String binary = "11101"; // Example binary number
        String twosComplement = getTwosComplement(binary);
        System.out.println("Binary: " + binary + " -> 2's Complement: " + twosComplement);
    }

    public static String getTwosComplement(String binary) {
        // Step 1: Find 1's complement
        StringBuilder onesComplement = new StringBuilder();
        for (char bit : binary.toCharArray()) {
            onesComplement.append(bit == '0' ? '1' : '0');
        }

        // Step 2: Add 1 to the 1's complement
        StringBuilder twosComplement = new StringBuilder(onesComplement.toString());
        boolean carry = true;
        for (int i = twosComplement.length() - 1; i >= 0; i--) {
            if (twosComplement.charAt(i) == '1' && carry) {
                twosComplement.setCharAt(i, '0');
            } else if (twosComplement.charAt(i) == '0' && carry) {
                twosComplement.setCharAt(i, '1');
                carry = false;
            }
        }

        // If carry is still true, prepend '1' to the result
        if (carry) {
            twosComplement.insert(0, '1');
        }

        return twosComplement.toString();
    }
}
