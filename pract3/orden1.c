#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int burbuja(int *a, int n);

int main(){
	srand(time(NULL));
	int tam;
	printf("Ingrese tamaño del arreglo: ");
	scanf("%d",&tam);
	int A[tam];
	for(int i=0;i<tam;i++){
		A[i]=rand()%100;
		//printf("|%d|",A[i]);
	}//*/

	printf("\n");

	clock_t ti=clock();

	int costo=burbuja(A,tam);

	clock_t tf=clock();
	
	for(int i=0;i<tam;i++){
		printf("|%d|",A[i]);
	}
	printf("\n\nCosto temporal del algoritmo:%d\n",costo);
  printf("Tiempo transcurrido: %f segundos\n",(double)(tf-ti)/CLOCKS_PER_SEC );
}

int burbuja(int *a, int n){

	int temp,i,j,costo=2;//2 asignaciones, de i y j en el for

	for(i=1;i<n;i++){costo+=1;//costo de que entra
		for(j=0;j<n-1;j++){costo+=1;//costo de que entra
			if(a[j]>a[j+1]){
				temp=a[j];costo+=1;//costo de asignacion
					a[j]=a[j+1];costo+=1;//costo de asignacion
					a[j+1]=temp;costo+=1;//costo de asignacion
			}
			costo+=1;//costo de comparacion
			costo+=1;//costo de incremeno en j
		}
		costo+=1;//costo de incremento en i
	}
	return costo;
}