#include <stdio.h>

float tExec(int n, float td[], float ti[]){
  int i, j, cont=0;
  float somaTEx=0, TMExec;
  float t[n];

  for(i=0; i<n; i++){
    t[i] = td[i];
    if(i>0){
      for(j=0; j<cont; j++){
        t[i] += td[j];  
      }
    }
    cont++;
  }

  for(i=0;i<n;i++){
    somaTEx += t[i] - ti[i];
  } 


  TMExec = somaTEx/n;

  return TMExec;
}

float tEsp(int n, float td[], float ti[]){
  int i,j,cont=0;
  float somaTEs=0, TMEsp; 
  float comeco[n+1];
  float WT[n];
  
  comeco[0] = 0;
  int a=0;
  for(i=1;i<n+1;i++){    
    comeco[i] = td[a];
    for(j=0;j<cont;j++){
      comeco[i] += td[j];
    }
    a++;
    cont++;
  }

  for(i=0;i<n;i++){
    WT[i] = comeco[i] - ti[i]; 
    somaTEs += WT[i];
  }  

  TMEsp = somaTEs/n;
  return TMEsp;
}

int main(){
  int i, nProcessos = 1, cont=1;

  while(nProcessos != 0){
      printf("");
      scanf("%d", &nProcessos);
    
    if(nProcessos != 0){
      float tempoIngresso[nProcessos];
      float tempoDuracao[nProcessos];

      for(i=0; i<nProcessos; i++){
        printf("");
        scanf("%f", &tempoIngresso[i]);  
      
        printf("");
        scanf("%f", &tempoDuracao[i]);
        
      }

      printf("Teste %d\n", cont);
      printf("Tempo medio de execucao: %.2fs\n", tExec(nProcessos, tempoDuracao, tempoIngresso));
      printf("Tempo medio de espera: %.2fs\n", tEsp(nProcessos, tempoDuracao, tempoIngresso));
      for(i=0; i< nProcessos; i++){
        printf("P%d ", i+1);
      }
      printf("\n");
      cont++;
      

    }


    
  }

  
  return 0;
}
