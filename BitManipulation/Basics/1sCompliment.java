/* 

The 1's complement of a binary number is obtained by flipping all the bits in the number, changing every 0 to 1 and every 1 to 0. 

 */

public class OnesComplement {
    public static void main(String[] args) {
        String binary = "11101"; // Example binary number
        String onesComplement = getOnesComplement(binary);
        System.out.println("Binary: " + binary + " -> 1's Complement: " + onesComplement);
    }

    public static String getOnesComplement(String binary) {
        StringBuilder onesComplement = new StringBuilder();
        for (char bit : binary.toCharArray()) {
            onesComplement.append(bit == '0' ? '1' : '0');
        }
        return onesComplement.toString();
    }
}
