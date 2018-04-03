#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int seleccion(int *A, int n);

int main(){
 srand(time(NULL));
 int tam;
 printf("Ingrese tamaño del arreglo: ");
 scanf("%d",&tam);
 int A[tam];
 for(int i=0;i<tam;i++){
  A[i]=rand()%100;
  //printf("|%d|",A[i]);
 }//*/

 printf("\n");

 clock_t ti=clock();

 int costo=seleccion(A,tam);

 clock_t tf=clock();
 for(int i=0;i<tam;i++){
  printf("|%d|",A[i]);
 }
 printf("\n\nCosto temporal del algoritmo:%d\n",costo);
  printf("Tiempo transcurrido: %f segundos\n",(double)(tf-ti)/CLOCKS_PER_SEC );
}

int seleccion(int *A, int n){
 int k,i,p,temp,costo=1;

 for(k=0;k<n-1;k++){costo+=1;
  p=k;costo+=1;
  for(i=k+1;i<n;i++){costo+=1;
   if(A[i]<A[p]){costo+=1;
    p=i;costo+=1;
   }
  }
  if(p!=k){costo+=1;
   temp=A[p];costo+=1;
   A[p]=A[k];costo+=1;
   A[k]=temp;costo+=1;
  }
 }
 return costo;
}