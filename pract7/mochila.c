#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mochila(int *benef, int *peso, int cap,int n);
unsigned long costo=0;

int main(){
	srand(time(NULL));
	printf("ingrese peso de la mochila: ");
	int cap;
	scanf("%d",&cap);
	int n,i=0;
 printf("ingrese cantidad de elementos: ");
 scanf("%d",&n);
 int peso[n];
 int benef[n];
 while(i<n){
 	printf("Ingrese peso %d: ",i+1 );
 	scanf("%d",&peso[i]);
 	i+=1;
 }
 i=0;
 while(i<n){
 	printf("Ingrese beneficio %d: ",i+1 );
 	scanf("%d",&benef[i]);
 	i+=1;
 }
 clock_t ti=clock();
 mochila(benef,peso,cap,n);
 clock_t tf=clock();
 printf("Costo temporal: %ld\nEl tiempo de ejecucion: %f segundos\n",costo,(double)(tf-ti)/CLOCKS_PER_SEC);

}

void mochila(int *benef, int *peso, int cap,int n){
	int resto,i;costo+=2;
	int sol[n];costo+=n;
	double peso1[n];costo+=n+1;

	double fact[n];costo+=n;
	for(i=0;i<n;i++){costo+=1;
		peso1[i]=peso[i];costo+=1;costo+=1;
	}costo+=2;

	for(i=0;i<n;i++){costo+=1;

		while(peso1[i]>100){costo+=1;
			peso1[i]/=10;
		}costo+=1;
		fact[i]=benef[i]/peso1[i];costo+=3;
	}costo+=1;

	for(i=0;i<n;i++){costo+=1;
	sol[i]=0;costo+=2;
	}costo+=1;
	resto=cap;costo+=1;
	i=0;costo+=1;

	int temp=0;costo+=2;
	while(resto!=-1){costo+=2;

		for(i=0;i<n;i++){costo+=1;
				if(fact[temp]>fact[i]){costo+=1;
					temp=temp;costo+=1;
				}else{costo+=1;
					temp=i;
				}
				
		}costo+=1;

		
		if(peso[temp]<=resto){costo+=1;
			sol[temp]=1;costo+=1;
			resto-=peso[temp];costo+=2;
			fact[temp]=-1;costo+=1;
		}else{costo+=1;
			resto=-1;
		}
	}
	printf("\n\n\n");

	for(i=0;i<n;i++){
		printf(" %d elementos de %d \n",sol[i],peso[i]);
	}
}
