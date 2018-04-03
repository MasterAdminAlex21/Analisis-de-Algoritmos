#include <stdio.h>
#include<stdlib.h>

void pfor(int n,int *A);
void algor();

int main(){
	int val;
	printf("ingrese valor de n: ");
	scanf("%d",&val);
	int A[val];
	for(int i=0;i<val;i++){
	 A[i]=i+1;
	}
	algor();
	pfor(val,A);
}

void pfor(int n, int *A){
    int contador=0;
	int temp;contador+=3;
	for(int i=1;i<n;i++,contador++){contador+=1;
	for(int j=0;j<n-1;j++,contador++){contador+=1;
	 temp=A[j];contador+=1;
	 A[j]=A[j+1];contador+=1;
	 A[j+1]=temp;contador+=1;
	}
	}
	contador+=2;
	printf("Costo del algoritmo: %d \n",contador);
	printf("Costo espacial del algoritmo: %d\n",(3+n));
}

void algor(){
	printf("int temp; //costo=1;\nfor(int i=1;i<n;i++){ //costo:1 asignacion, n comparaciones, n-1 incrementos\nfor(int j=0;j<n-1;j++){ //costo: 1 asignacion, n comparaciones, n-1 incrementos\n");
	printf("temp=A[j];//costo=1;\nA[j]=A[j+1];//costo=1;\nA[j+1]=temp;//costo=1;\n}\n}\n");
}