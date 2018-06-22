
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

long mergesort(int *v,int i,int f);
long merge(int *v,int i,int m,int f);

int main(){
  srand(time(NULL));
 int n;long costo=0;
 printf("Ingrese n: ");
 scanf("%d",&n);
 printf("Agrendo valores.\n");
 int v[n];
 for (int i = 0; i < n; i++)
 {
  v[i]=rand()%100000;
  printf("|%d|",v[i] );
 }
 printf("\n");

 clock_t ti=clock();
 costo=mergesort(v,0,n-1);
 clock_t tf=clock();


 for(int i=0;i<n;i++){
  printf("%d ",v[i]);
 }
 printf("\n");

  printf("Tiempo transcurrido: %f segundos\n",(double)(tf-ti)/CLOCKS_PER_SEC );
  printf("Costo temporal del algoritmo:%ld\n",costo);
 return 0;
}

long mergesort(int *v,int i,int f){
  long costo=0;
 if(i!=f){costo+=1;
  int m=(i+f)/2;costo+=4;
  costo+=mergesort(v,i,m);costo+=1;
  costo+=mergesort(v,m+1,f);costo+=1;
  costo+=merge(v,i,m,f);costo+=1;
 }
 return costo;
}

long merge(int *v,int i,int m,int f){
 int aux[m-i+1];long costo=0;costo+=5;
 for(int j=i;j<=m;j++){costo+=1;
  aux[j-i]=v[j];costo+=3;
  costo+=1;
 }costo+=1;
 int c1=0,c2=m+1;costo+=5;
 for(int j=i;j<=f;j++){costo+=1;
  if(aux[c1]<v[c2]){costo+=1;
   v[j]=aux[c1++];costo+=2;
   if(c1==m-i+1){costo+=5;
    for(int k=c2;k<=f;k++){costo+=1;
     v[++j]=v[k];costo+=2;
     costo+=1;
    }costo+=1;
   }costo+=1;
  }else{
   v[j]=v[c2++];costo+=2;
   if(c2==f+1){costo+=4;
    for(int k=c1;k<=m-i;k++){costo+=1;
     v[++j]=aux[k];costo+=2;
     costo+=1;
    }costo+=1;
   }costo+=1;
  }costo+=1;
 }costo+=1;
 return costo;
}