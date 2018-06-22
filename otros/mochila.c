#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mochila(int *benef, int *peso, int cap,int n);

int main(){
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

 mochila(benef,peso,cap,n);

}

void mochila(int *benef, int *peso, int cap,int n){
	int resto,i;
	int sol[n];
	double peso1[n];

	double fact[n];
	for(i=0;i<n;i++){
		peso1[i]=peso[i];
	}

	for(i=0;i<n;i++){

		while(peso1[i]>100){
			peso1[i]/=10;
		}
		fact[i]=benef[i]/peso1[i];
	}

	for(i=0;i<n;i++){
	sol[i]=0;
	}
	resto=cap;
	i=0;
	/*
	while(i<n && peso[i]<=resto){
	sol[i]=1;
	resto-=peso[i];
	i+=1;
	}

	if(i<n){
	sol[i]=resto/peso[i];
	}*/

	int temp=0;
	while(resto!=-1){

		for(i=0;i<n;i++){
				if(fact[temp]>fact[i]){
					temp=temp;
				}else{
					temp=i;
				}
		}

		
		if(peso[temp]<=resto){
			sol[temp]=1;
			resto-=peso[temp];
			fact[temp]=-1;
		}else{
			resto=-1;
		}
	}

	//return sol;
	for(i=0;i<n;i++){
		printf(" %d elementos de %d \n",sol[i],peso[i]);
	}
	//return 0;
}
