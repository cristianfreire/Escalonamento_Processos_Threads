// Objetivo: Duas threads (500-1) (1-500)
public class Conta{
    public static void main(String args[]){
        try {
            Threads t1, t2;
            
            // id, start, end, ordem
            t1 = new Threads(1, 1, 500, 0);
            t2 = new Threads(2, 500, 1, 1);

            t1.start();
            t2.start();

            t1.join();
            t2.join();
            System.out.println("Terminei");
        } catch (Exception e) {
            System.out.println("Deu ruim na main"+e.getMessage());
        }
    }
}