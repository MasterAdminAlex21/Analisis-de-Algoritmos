#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void for2(int n, int A[][n],int B[][n],int C[][n]);
void algor();

int main(){
srand(time(NULL));
 int n;
 printf("Ingrese valor de n: ");
 scanf("%d",&n);
 int C[n][n],A[n][n],B[n][n];
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
   C[i][j]=rand()%10;
   A[i][j]=rand()%10;
   B[i][j]=rand()%10;
  }
 }

algor();
for2(n,A,B,C);

}

void for2(int n, int A[][n],int B[][n],int C[][n]){
 int costo=3;
 for(int i=1;i<=n;i++,costo++){
  for(int j=1;j<=n;j++,costo++){
   C[i][j]=0;costo+=1;
   for(int k=1;k<=n;k++,costo++){
    C[i][j]=C[i][j]+A[i][k]*B[k][j];costo+=3;
   }costo+=1;
  }costo+=1;
 }costo+=1;

 printf("Costo del algoritmo: %d\n",costo);
 printf("Costo espacial del algoritmo: %d\n",3+3*(n*n));
}

void algor(){
 printf("for(int i=1;i<=n;i++){//1 asig, n+1 comp,n incr\nfor(int j=1;j<=n;j++){//1 asig, n+1 comp,n incr\nC[i][j]=0;//costo:1\nfor(int k=1;k<=n;k++){//1 asig, n+1 comp,n incr\n");
 printf("C[i][j]=C[i][j]+A[i][k]*B[k][j];//costo: 3\n}\n}\n}\n");
}