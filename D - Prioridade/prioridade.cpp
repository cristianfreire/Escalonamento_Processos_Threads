#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int w=0,h=0,N,teste=0,mai=0,agr=0,t=0;
	float exe=0,d=0;
	bool i=true;
	
	while(true){
		
		scanf("%d",&N);
		
		int ent[N],dur[N],pri[N],lis[N],esp[N];
		
		teste++;
		
		while(w<N){
			
			esp[w]=0;
			
			w++;
		}w=0;
		
		while(w<N){
		
			scanf("%d %d %d",&ent[w],&dur[w],&pri[w]);
			
			if(pri[w]>mai)		mai=pri[w];
			exe=exe+dur[w];
			
			w++;
		}w=0;
		
		while(w<N){
			while(h<N){
				
				if(pri[h]==agr && i){
					
					agr--;
					
					i=false;
					
					d=dur[h];
					
					lis[h]=w+1;
					w++;
					
					pri[h]=INT_MAX;
				}
				else if(pri[h]>agr && ent[h]<=t){
					
					if(pri[h]!=INT_MAX)		esp[h]=esp[h]+d;
				}
				h++;
				
			}h=0;
			
			i=true;
			
			agr++;
			
		}w=0;d=0;
		
		while(w<N){
		
			d=d+esp[h];
			
			w++;	
		}w=0;
				
		printf("teste %d\n",teste);
		
		printf("Tempo medio de execucao %.2f\n",exe/N);
		
		printf("Tempo medio de espera %.2f\n",d/N);
		
		while(w<N){
			
			printf("P%d ",lis[w]);
			w++;
		}w=0;
		
		printf("\n\n");
		
		mai=0;	agr=0;	t=0;	exe=0;	d=0;
	}
}
