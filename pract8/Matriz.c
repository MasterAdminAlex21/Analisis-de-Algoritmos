#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void matriz(int *d, int n, int *m, int *factor);

int main(){

 printf("pruebas con n=3\n");
 int factor[6]={2,3,3,4,4,5};
 int d[6];
 matriz();

}

void matriz(int *d, int n, int *m, int *factor){
	int i,diagonal;
	for(i=0;i<=n;i++){
	 m[i][i]=0;
	}

	for(diagonal=0;diagonal<=n-1;diagonal++){
	 for(i=0;i<=n-diagonal;i++){
	  m[i][i+diagonal]=min(d,m,i,i+diagonal);
  // factor[i][i+diagonal]=k1
	 }
	}

}

int min(int *d, int *m,int i, int j){
 int aux,k,min=100000;
 for(k=i;k<=j-1;k++){
  aux=m[i][k]+m[k+1][j]+(d[i-1]*d[k]*d[j]);

  if(aux<min){
   min=aux;
   //k1=k;
  }
 }
 return min;
}