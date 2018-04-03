#ifndef _lista_
#define _lista_

typedef struct Lista{
 int dato;
 int pos;
 struct Lista *sig;
 struct Lista *ant;
}Lista;

typedef Lista *lista;

lista crearlista();
lista agregar(lista l, int dato, int pos);
lista quitar(lista l);
void buscar(lista l, int dato);

#endif