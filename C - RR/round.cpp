#include <stdio.h>

int main(){
	
	int Q,tes=0,N,w=0,h=0,t=0,T=0,X=0,xc=0,e=0,li=0;
	float espera=0;
	
	scanf("%d",&Q);
	
	while(true){
		
		scanf("%d",&N);
		tes++;
		
		if(N==0)	break;
		
		int x[N],y[N],esp[N];
		
//Zera o contador de esperas-----------------------------------------------------------------------------------------------
		while(w<N){
			esp[w]=0;
			w++;
		}w=0;
		
//Recebe programas---------------------------------------------------------------------------------------------------------
		while(w<N){
			
			scanf("%d %d",&x[w],&y[w]);
			
			t=t+y[w];
			
			w++;
		}w=0;
		
		int lis[t/Q];

//Execux�o circular--------------------------------------------------------------------------------------------------------
		while(T<t+e){
			
			//Executa o programa pronto 
			if(x[h]<=T){
				if(y[h]>0){
					printf("");
					xc=0;
					
					while(X<Q && X<y[h])	X++;
						
					y[h]=y[h]-X;
					T=T+X;
					
					lis[li]=h;
					li++;
				}
			}
			
			//Adiciona o tempo de espera aos programas
			if(X>0)
				while(w<N){
					
					if(h!=w){
						
						if(x[w]<=T){
							
							if(y[w]!=0){
								
								esp[w]=esp[w]+X;
							}
						
						}
					}
					w++;
				}w=0;			
			xc++;
			
			//Se nenhum programa estiver pronto, avan�a um quantum
			if(xc>N){
				
				T++;
				e++;
				xc=0;
			}
			
			//Analisa os programas de maneira circular
			if(h<N-1)	h++;
			else		h=0;
			
		}h=0;
		
		//Ajustes
		while(w<N){
			
			espera=espera+esp[w];
			w++;
		}w=0;
		
		espera=espera/N;
		
//Sa�da---------------------------------------------------------------------------------------------------------------------
		printf("Teste %d\n",tes);
		
		printf("Tempo de execucao: %d quantum\n",T);
		
		printf("Tempo medio de espera: %.2f quantum\n",espera);
		
		while(w<li){
			
			printf("P%d, ",lis[w]);
			w++;
		}w=0;
		
		printf("\n\n");
		t=0;	T=0;	X=0;	xc=0;	e=0;	li=0;
	}
}
