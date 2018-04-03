#include<stdio.h>
#include<stdlib.h>

void while1(int n);
void algor();

int main(){
 int n;
 printf("ingrese valor de n:");
 scanf("%d",&n);
 algor();
 while1(n);
}

void while1(int n){
 int costo;
 int anterior=1,actual=1,aux;costo=3;

 while(n>2){costo+=1;
  aux=anterior + actual;costo+=2;
  anterior=actual;costo+=1;
  actual=aux;costo+=1;
  n=n-1;costo+=2;
 }costo+=1;

 printf("Costo del algoritmo: %d \n",costo );
 printf("Costo espacial del algoritmo: 4\n");
}

void algor(){
printf("int anterior=1,actual=1,aux;//costo: 3\nwhile(n>2){//n-1  comp\naux=anterior + actual;//costo: 2\nanterior=actual;//costo: 1");
 printf("\nactual=aux;//costo: 1;\nn=n-1;//costo: 2;\n}\n"); 
}