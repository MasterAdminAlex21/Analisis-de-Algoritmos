#ifndef _pila_
#define _pila_

typedef struct Pila{
	int dato;
	int pos;
	struct Pila *sig;
}Pila;

typedef Pila *pila;

pila creapila();
pila push(pila p,int e,int pos);
pila pop(pila p);
void buscar(pila p,int dato);

#endif