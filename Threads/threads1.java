public class threads1{
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
            // System.out.println("Terminei");
        } catch (Exception e) {
            System.out.println("Deu ruim na main"+e.getMessage());
        }
    }
	
	public static class Threads extends Thread{
	    public int id;
	    public int start;
	    public int end;
	    public int ordem;

	    public Threads(int id, int start, int end, int ordem){
	        this.id = id;
	        this.start = start;
	        this.end = end;
	        this.ordem = ordem;
	    }

	    public void run(){
	        try {
	        	int cont=start;
	        	if (ordem == 0) { end+=1;} else { end-=1;}
	        	while(cont != end) {
	        		System.out.println("Thread: "+id+" valor: "+cont);
	        		if(ordem ==0) {
	        			cont++;
	        		}else {
	        			cont--;
	        		}
	        	}
	        } catch (Exception e) {
	            System.out.println("Deu ruim"+e.getMessage());
	        }
	    }
	}
}

