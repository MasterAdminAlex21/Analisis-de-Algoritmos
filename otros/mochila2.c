#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mochila(double *benef, double *peso, int cap,int n);

int main(){
	printf("ingrese peso de la mochila: ");
	int cap;
	scanf("%d",&cap);
	int n,i=0;
 printf("ingrese cantidad de elementos: ");
 scanf("%d",&n);
 double peso[n];
 double benef[n];
 while(i<n){
 	printf("Ingrese peso %d: ",i+1 );
 	scanf("%lf",&peso[i]);
 	i+=1;
 }
 i=0;
 while(i<n){
 	printf("Ingrese beneficio %d: ",i+1 );
 	scanf("%lf",&benef[i]);
 	i+=1;
 }

 mochila(benef,peso,cap,n);

}

void mochila(double *benef, double *peso, int cap,int n){
	int resto,i;
	float sol[n];
	double peso1[n];

	for(i=0;i<n;i++){
	sol[i]=0;
	}
	resto=cap;
	i=0;

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
/*
	double temp;
 while(i<n && resto>0){
	
	 if(peso[i]<resto){
	 	sol[i]=1;
	  resto-=peso[i];
	 }else{
  	temp=peso[i]/benef[i];
  	sol[i]=resto*temp;
  	resto=0;
  }
	i+=1;
	}//*/

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
			sol[temp]=fact[temp]*resto;
			while(sol[temp]>1){
				sol[temp]/=10;
			}
			resto=-1;
		}
	}

	//return sol;
	for(i=0;i<n;i++){
		printf(" %0.2f elementos de %0.0lf \n",sol[i],peso[i]);
	}
	//return 0;
}
