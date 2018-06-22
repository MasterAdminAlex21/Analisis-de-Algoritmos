#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long quicksort(int *a, int primero, int ultimo);

int main(){
 srand(time(NULL));
 int n;long costo;
 printf("Ingrese N: ");
 scanf("%d",&n);

 int a[n];
 for(int i=0;i<n;i++){
  a[i]=rand()%10000000;
  printf("|%d|",a[i] );
 }
 printf("\n--\n");

  clock_t ti=clock();
 costo=quicksort(a,0,n-1);
 clock_t tf=clock();


 for (int i=0;i<n;i++){
  printf("|%d|",a[i] );
 }
 printf("\n");
   printf("Tiempo transcurrido: %f segundos\n",(double)(tf-ti)/CLOCKS_PER_SEC );
  printf("Costo temporal del algoritmo:%ld\n",costo);
}

long quicksort(int *a,int primero,int ultimo){
 int pivote,temp,i,j;long costo=4;
 if(ultimo-primero>=1){costo+=2;
  pivote=primero;costo+=1;
  i=primero;costo+=1;
  j=ultimo;costo+=1;
  while(i<j){costo+=1;
   while(a[i]<=pivote && i<=ultimo){costo+=3;
    i++;costo+=1;
   }costo+=1;
   while(a[j]>a[pivote] && j>=primero){costo+=3;
    j--;costo+=1;
   }costo+=1;
   if(i<j){costo+=1;
    temp=a[i];costo+=1;
    a[i]=a[j];costo+=1;
    a[j]=temp;costo+=1;
   }costo+=1;
  }costo+=1;
  temp=a[j];costo+=1;
  a[j]=a[pivote];costo+=1;
  a[pivote]=temp;costo+=1;

  costo+=quicksort(a,primero,j-1);
  costo+=quicksort(a,j+1,ultimo);
 }else{
  return 0;
 }
 return costo;
}