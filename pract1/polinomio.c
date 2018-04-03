#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void polinomio(int n, int z, int *A);
void algor(int z,int n);

int main(){
 srand(time(NULL));
 int n;
 printf("Ingrese valor de n: ");
 scanf("%d",&n);
 int randz=rand()%50,A[n];
 for(int i=0;i<n;i++){
  A[i]=rand()%20;
 }
 algor(randz,n);
 polinomio(n,randz,A);

}

void polinomio(int n,int z, int *A){
 int cont=0;
 int poli=0;cont=2;
 for(int i=0;i<=n;i++,cont++){
  cont+=1;
   poli=poli*z+A[n-1];cont+=3;
 }
 cont+=1;
 printf("costo del algoritmo: %d \n",cont);
 printf("Costo espacial del algoritmo: %d\n",2+n);

}

void algor(int z,int n){
 printf("int poli=0;//costo: 1\nfor(int i=0;i<=n;i++){//1 asig, n+2 comp, n+1 incrementos\n poli=poli*z+A[n-1];costo: 3\n}\n");
 printf("valor de z=%d\n",z );
 printf("Tamaño de A: %d\n",n);

}