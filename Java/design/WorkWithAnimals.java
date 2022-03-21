public class WorkWithAnimals {
    public static void main(String[] args) {
        Dog fido = new Dog();
        
        fido.setName("Fido");;
        System.out.println(fido.getName());
        
            fido.digWhole();
            fido.setWeight(10);
            changeObjectName(fido);
            System.out.println("Name of the DOg after his name has beeen chnage :" + fido.getName());
    
        }
        public static void changeObjectName(Dog anyDog) {
            anyDog.setName("Markuss");
        }
}
