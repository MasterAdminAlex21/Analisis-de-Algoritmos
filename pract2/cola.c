#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "cola.h"

int main(){
 srand(time(NULL));
 cola c;
 c=crearcola();
 int tam;
 printf("Ingrese tamaño de la cola: ");
 scanf("%d",&tam);
 for(int i=0;i<tam;i++){
  c=agregar(c,rand()%50,i+1);
 }
 cola aux=c;
 /*while(aux!=NULL){
  printf("|%d|",aux->dato);
  aux=aux->sig;
 }*/

 while(tam>-1){
  printf("Ingrese dato a buscar(entre 0 y 50): ");
  scanf("%d",&tam);
  if(tam<=-1) {
      while(c!=NULL){
        c=quitar(c);
      }
      exit(0);
    }
  else{
   buscar(c,tam);
  }
 }
}

cola crearcola(){
 cola c=NULL;
 return c;
}

cola agregar(cola c, int e,int pos){
 cola elem=(cola)malloc(sizeof(Cola));
 if(elem==NULL){
  printf("Error: no hay memoria\n");
  exit(0);
 }
 elem->dato=e;
 elem->pos=pos;
 elem->sig=NULL;
 if(c==NULL){
  c=elem;
 }else{
  cola aux=c;
  while(aux->sig!=NULL){
   aux=aux->sig;
  }
  aux->sig=elem;;
 }
 return c;
}

cola quitar(cola c){
 cola aux=c;
 if(c->sig==NULL){
  free(aux);
  c=NULL;
 }else{
  c=c->sig;
  free(aux);
 }
 return c;
}

void buscar(cola c, int dato){
 cola aux=c;
 int costo=0;
 while(aux!=NULL){costo+=1;
  if(aux->dato==dato){costo+=1;
   printf("El dato se encuentra en la posicion %d\n",aux->pos );
   break;
  }else{
   costo+=1;
  }
  aux=aux->sig;costo+=1;
 }
 if(aux==NULL){
  printf("El dato no se encuentra\n");
 }
 printf("el costo del algoritmo es: %d\n",costo);
}
