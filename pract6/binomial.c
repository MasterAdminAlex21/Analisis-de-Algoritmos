#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int coef_bin(int n,int p,int k);
unsigned long **tabla;
unsigned long costo=0;
int main(){
 int obj,cant,cont,cont2;unsigned long val;
 printf("Ingrese la cantidad de objetos:\n");
 scanf("%d",&obj);
 printf("Ingrese la cantidad de subcombinaciones:\n");
 scanf("%d",&cant);
 tabla=(unsigned long **)malloc(sizeof(unsigned long*)*obj);
 for(cont=0;cont<=obj;cont++){
  tabla[cont]=(unsigned long *)malloc(sizeof(unsigned long)*obj+1);
 }

 clock_t ti=clock();
 for(cont=0;cont<=obj;cont++){
  for(cont2=0;cont2<=obj;cont2++){
   val=coef_bin(cont,cont2,cant);
  }
 }
 clock_t tf=clock();
 
 for(cont=0;cont<=obj;cont++){
  for(cont2=0;cont2<=obj;cont2++){
   printf(" %ld",tabla[cont][cont2]);
  }
  printf("\n");
 }
 printf("\nC(%d,%d)=%ld\n",obj,cant,val);
 
}

int coef_bin(int n,int p,int k){
 int i,j;costo+=3;
 for(i=0;i<=n;i++){costo+=1;
  tabla[i][0]=1;costo+=2;
 }costo+=2;
 for(i=1;i<=n;i++){costo+=1;
  tabla[i][1]=i;costo+=2;
 }costo+=2;
 for(i=2;i<=p;i++){costo+=1;
  tabla[i][i]=1;costo+=1;
 }costo+=2;
 for(i=3;i<=n;i++){costo+=2;
  for(j=2;j<=i-1;j++){costo+=1;
   if(j<=p){costo+=1;
    tabla[i][j]=tabla[i-1][j-1]+tabla[i-1][j];costo+=5;
   }
  }costo+=1;
 }costo+=1;
 return tabla[n][k];
}