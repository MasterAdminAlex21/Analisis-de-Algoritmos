#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "pila.h"

int main(){
	srand(time(NULL));
	pila p=creapila();/*
	printf("creo la pila\n");
	p=push(p,2);
	p=push(p,3);
	p=push(p,1);

	pila aux=p;
	while(aux!=NULL){
		printf("%d\n",aux->dato);
		aux=aux->sig;
	}
	printf("\npila despues de un pop\n");

	p=pop(p);
	aux=p;
	while(aux!=NULL){
		printf("%d\n",aux->dato);
		aux=aux->sig;
	}
printf("\npila despues de 2 pop\n");

	p=pop(p);
	aux=p;
	while(aux!=NULL){
		printf("%d\n",aux->dato);
		aux=aux->sig;
	}

	printf("\npila despues de 3 pop\n");

	p=pop(p);
	aux=p;
	while(aux!=NULL){
		printf("%d\n",aux->dato);
		aux=aux->sig;
	}*/
	int n=-1,busc=0;
	while(n<0){
		printf("ingrese tamaño pila: ");
		scanf("%d",&n);
		if(n<0){
			printf("ERROR: es negativo.\n");
		}
	}
	for(int i=0;i<n;i++){
		p=push(p,rand()%50,i+1);
	}
	while(busc>=0){
	
		printf("ingrese dato a buscar(entre 0 y 50): ");
		scanf("%d",&busc);
		if(busc<=-1) {
			while(p!=NULL){
				p=pop(p);
			}
			exit(0);
		}
		buscar(p,busc);

	}
}

pila creapila(){
	pila p=NULL;
	return p;
}

pila push(pila p, int e,int pos){
	pila elem=(pila)malloc(sizeof(Pila));
	if(elem==NULL){
		printf("ERROR: no hay memoria\n");
		exit(0);
	}
	elem->dato=e;
	elem->pos=pos;
	elem->sig=NULL;

	if(p==NULL){
		p=elem;
	}
	else{
		pila aux=p;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=elem;
	}

	return p;

}

pila pop(pila p){
 pila aux2=p;
	if(p->sig==NULL){
		free(aux2);
		p=NULL;
	}else{
		pila aux=p->sig;
		while(aux->sig!=NULL){
			aux=aux->sig;
			aux2=aux2->sig;
		}
		aux2->sig=NULL;
		free(aux);
	}
	return p;
}

void buscar(pila p, int dato){
	pila aux=p;
	int costo=0;
	while(aux!=NULL){costo+=1;
		if(aux->dato==dato){costo+=1;
			printf("el dato se encuentra en la posicion %d\n",aux->pos);
			break;
		}else{
			costo+=1;
		}
		aux=aux->sig;costo+=1;
	}
	if(aux==NULL){
	  printf("No se encuentra el dato\n");
   }
	printf("Costo total del algoritmo de busqueda: %d\n",costo);
}