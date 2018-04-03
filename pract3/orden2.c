#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int burbujaMejorada(int *a, int n);

int main(){
	srand(time(NULL));
	int tam;
	printf("Ingrese tamaño del arreglo: ");
	scanf("%d",&tam);
	int A[tam];
	for(int i=0;i<tam;i++){
		A[i]=rand()%100;
	}

	printf("\n");

	clock_t ti=clock();

	int costo=burbujaMejorada(A,tam);

	clock_t tf=clock();
	
	for(int i=0;i<tam;i++){
		printf("|%d|",A[i]);
	}
	printf("\n\nCosto temporal del algoritmo:%d\n",costo);
  printf("Tiempo transcurrido: %f segundos\n",(double)(tf-ti)/CLOCKS_PER_SEC );
}

int burbujaMejorada(int *a,int n){

	int i,j,temp,costo=2;//costo por asignacion de i y j

	for(i=1;i<n;i++){costo+=1;//costo de que entra
		for(j=0;j<i;j++){costo+=1;//costo de que entra
			if(a[i]<a[j]){
				temp=a[j];costo+=1;//costo de asignacion
				a[j]=a[i];costo+=1;//costo de asignacion
				a[i]=temp;costo+=1;//costo de asignacion
			}costo+=1;//costo de comparacion
			costo+=1;//costo de incremento en j
		}
		costo+=1;//costo de incremento en i
	}
	return costo;
}