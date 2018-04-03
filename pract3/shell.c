#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int shell(int *A, int n);

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

 int costo=shell(A,tam);

 clock_t tf=clock();

 for(int i=0;i<tam;i++){
  printf("|%d|",A[i]);
 }
 printf("\n\nCosto temporal del algoritmo:%d\n",costo);
  printf("Tiempo transcurrido: %f segundos\n",(double)(tf-ti)/CLOCKS_PER_SEC );

}

int shell(int *A, int n){
 int k,i,j,v,costo=0;

 k=n/2;costo+=2;
 while(k>=1){costo+=1;
  for(i=k;i>=n;i++){costo+=1;
   v=A[i];costo+=1;
   j=i-k;costo+=1;
   while(j>=0 && A[j]>v){costo+=3;
    A[j+k]=A[j];costo+=1;
    j-=k;costo+=2;
   }
   A[j+k]=v;costo+=1;
  }
  k/=2;costo+=2;
 }
 return costo;
}