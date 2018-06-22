#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int fibonacci(int n);
int *tabla;
int costo=0;
int main(){
 int n=-1;
 while(n<0){
 	printf("Ingrese valor:");
 	scanf("%d",&n);
 	if(n<0){
 		printf("ERROR: no puede ser negativo\n");
 	}
 }

 tabla=(int*)malloc(sizeof(int)*n);
 if(tabla==NULL){
 	printf("ERROR: No hay memoria\n");
 	exit(0);
 }

 for(int i=n;i>-1;i--){
 	tabla[i]=-1;
 }

 clock_t ti=clock();
 int res=fibonacci(n);
 clock_t tf=clock(); 

 printf("vector resultante:\n|");
 for(int i=n;i>-1;i--){
   if(tabla[i]>=0 && tabla[i]<=n){
  	 printf(" %d |",tabla[i]);
   }

 }
 printf("\nCosto temporal: %d\nEl tiempo de ejecucion: %f segundos\n",costo,(double)(tf-ti)/CLOCKS_PER_SEC);
}

int fibonacci(int n){
 if(n<2){costo+=2;
  return n;
 }costo+=1;
 if(tabla[n-1]==-1){costo+=2;
  tabla[n-1]=fibonacci(n-1);costo+=3;
 }costo+=1;
 if(tabla[n-2]==-1){costo+=2;
  tabla[n-2]=fibonacci(n-2);costo+=3;
 }costo+=1;

 tabla[n]=tabla[n-1]+tabla[n-2];
 costo+=4;
 return tabla[n];
}