#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "lista.h"

int main(){

 srand(time(NULL));
 lista l;
 l=crearlista();
 int tam;
 printf("Ingrese tamaño de la lista: ");
 scanf("%d",&tam);
 for(int i=0;i<tam;i++){
  l=agregar(l,rand()%50,i+1);
 }
 lista aux=l;
 /*while(aux!=NULL){
  printf("|%d|",aux->dato);
  aux=aux->sig;
 }*/

 while(tam>=0){
  printf("Ingrese dato a buscar(entre 0 y 50): ");
  scanf("%d",&tam);
  if(tam<=-1) {
   while(l!=NULL){
    l=quitar(l);
   }
   exit(0);
  }
  else{
   buscar(l,tam);
  }
 }
 
}

lista crearlista(){
 lista l;
 l=NULL;
 return l;
}

lista agregar(lista l,int dato,int pos){
 lista elem;
 elem=(lista)malloc(sizeof(Lista));
 if(elem==NULL){
  printf("Error: no hay memoria\n");
  exit(0);
 }
 elem->dato=dato;
 elem->pos=pos;
 elem->sig=NULL;
 if(l==NULL){
  l=elem;
  elem->ant=NULL;
 }else{
  lista aux=l;
  while(aux->sig!=NULL){
   aux=aux->sig;
  }
   aux->sig=elem;
   elem->ant=aux;
 }
 return l;
}

lista quitar(lista l){
 lista aux=l;
 if (l->sig==NULL){
  free(l);
  l=NULL;
 }else{
  while(aux->sig!=NULL){
   aux=aux->sig;
  }
  aux->ant->sig=NULL;
  free(aux);
 }
 return l;
}

void buscar(lista l, int dato){
 lista aux=l;
 int costo=0;
 while(aux!=NULL){costo+=1;
  if(aux->dato==dato){costo+=1;
   printf("El elemento esta en la posicion %d\n",aux->pos );
   break;
  }else{costo+=2;
   aux=aux->sig;
  }
 }
 if(aux==NULL){
  printf("No existe el elemento\n");
 }
 printf("Costo del algoritmo: %d\n",costo );
}