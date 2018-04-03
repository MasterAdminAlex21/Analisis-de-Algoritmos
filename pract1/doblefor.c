#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void dobfor(int n, int *s, int *s2);
void algor();

int main(){
 srand(time(NULL)); 
 int n;
 printf("inrese valor de n: ");
 scanf("%d",&n);
 int s[n],s2[n];

 for(int i=0;i<n;i++){
  s[i]=rand()%10;
  s2[i]=rand()%10;
 }

 algor(); 
 dobfor(n,s,s2);
}

void dobfor(int n, int *s, int *s2){
int costo=2;
 for(int i=n-1, j=0;i>=0;i--,j++,costo+=2){costo+=1;
  s2[j]=s[i];costo+=1;
 }costo+=2;
 for(int i=0;i<n;i++,costo++){costo+=1;
  s[i]=s2[i];costo+=1;
 }costo+=1;

 printf("Costo del algoritmo: %d\n",costo);
 printf("Costo espacial del algoritmo: %d\n",2+(2*n));
}


void algor(){
printf("for(int i=n-1, j=0;i>=0;i--,j++){//2 asig, n+1 comp,n incr, n decr\n s2[j]=s[i];//costo: 1\n}\nfor(int i=0;i<n;i++){1 asig, n+1 comp, n incr\n s[i]=s2[i];//costo: 1\n}\n"); 
}