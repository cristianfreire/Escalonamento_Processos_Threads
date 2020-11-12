// Objetivo: inverter linhas de uma matriz 3x3
import java.util.Scanner;

public class threads2{
	public static void main(String[] args) {
		int m[][] = new int[3][3];
		
		Scanner leitura = new Scanner(System.in);
		
		for(int i = 0; i<3; i++) {
			for(int j=0; j<3; j++) {
				System.out.println("");
				m[i][j] = leitura.nextInt();
			}
		}
		
		
		try {
			PThread t1, t2, t3;
			
			t1 = new PThread(1, 0, m);
			t2 = new PThread(2, 1, m);
			t3 = new PThread(3, 2, m);
			
			t1.start();
			t2.start();
			t3.start();
			
			t1.join();
			t2.join();
			t3.join();
			
			for(int i=0; i<3; i++) {
				for(int j=0; j<3;j++) {
					System.out.print(m[i][j]+ " ");
				}
				System.out.println();
			}
			// System.out.println("Done!");
		} catch (Exception e) {
			System.out.println("Erro na main"+e.getMessage());
		}
	}
	
	public static class PThread extends Thread{
		public int id;
		public int linha;
		public int matriz[][];
		
		public PThread(int id, int linha, int matriz[][]) {
			this.id = id;
			this.linha = linha;
			this.matriz = matriz;
		}
		
		public void run() {
			try {
				int aux;
				//System.out.println("Thread da linha: " +linha);
				aux = matriz[linha][0];
				matriz[linha][0] = matriz[linha][2];
				matriz[linha][2] = aux;
			} catch (Exception e) {
				System.out.println("Erro!!"+e.getMessage());
			}
		}
		
	}
}