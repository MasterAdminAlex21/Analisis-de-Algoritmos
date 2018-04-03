#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int insercion(int *A, int n);

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

 int costo=insercion(A,tam);

 clock_t tf=clock();
 for(int i=0;i<tam;i++){
  printf("|%d|",A[i]);
 }
 printf("\n\nCosto temporal del algoritmo:%d\n",costo);
  printf("Tiempo transcurrido: %f segundos\n",(double)(tf-ti)/CLOCKS_PER_SEC );
}

int insercion(int *A, int n){
 int i,j,temp,costo=0;
 for(i=0;i<n;i++){costo+=1;
  temp=A[i];costo+=1;
  j=i-1;costo+=1;
  while((A[j]>temp) && (j>=0)){costo+=3;
   A[j+1]=A[j];costo+=1;
   j--;costo+=1;
  }
  A[j+1]=temp;costo+=1;
 }
 return costo;
}