#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int fibonacci(int n);
int *tabla;
int costo=0;
int main(){
 int n=-1;
 while(n<0){
  printf("Ingrese numero: ");
  scanf("%d",&n);
  if(n<0){
  	printf("ERROR: no puede ser negativo\n");
  }
 }
 tabla=(int*)malloc(sizeof(int)*(n*2));
 if(tabla==NULL){
 	printf("ERROR: no hay memoria suficiente\n");
 	exit(0);
 }

 clock_t ti=clock();
 int resul=fibonacci(n);
 clock_t tf=clock();

 printf("vector resultante: \n| %d |",tabla[0]);
 for(int i=0;i<n;i++){
 	if(tabla[i]!=0){
   	printf(" %d |", tabla[i]);
   }
 }
 printf("\nCosto temporal: %d\nEl tiempo de ejecucion: %f segundos\n",costo,(double)(tf-ti)/CLOCKS_PER_SEC);
}

int fibonacci(int n){
 if(n<2){costo+=2;
  return n;
 }else{costo+=1;
 int i;costo+=1;
 tabla[0]=0;costo+=1;
 tabla[1]=1;costo+=2;
 for(i=2;i<n;i++){costo+=1;
 	if(tabla[i-1]+tabla[i-2]<=n){costo+=4;
     tabla[i]=tabla[i-1]+tabla[i-2];costo+=4;
   }else{
    costo+=1;
    break;
   }
  }
 }
 return tabla[n-1];
}