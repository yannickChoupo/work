public class Basis {
    public static void main(String[] args) {
        String[] copyFrom = {
            "Affogato", "Americano", "Cappucino", "Corretto", "Cortado",
            "Dopio", "Expresso", "Frappucino", "Freddo", "Lungo" ,"Macchiato",
            "Marochino", "Ristretto"};

            String[] copyTo = new String[7];
            System.arraycopy(copyFrom, 2, copyTo, 0, 7); 
            for (String coffee : copyTo) {
                System.out.println(coffee + "  ");
            }

            System.out.println(args[0]);
    }
}
