public class PThread extends Thread{
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