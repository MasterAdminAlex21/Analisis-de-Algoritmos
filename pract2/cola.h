#ifndef _cola_
#define _cola_

typedef struct Cola{
 int dato;
 int pos;
 struct Cola *sig;
}Cola;

typedef Cola *cola;

cola crearcola();
cola agregar(cola c,int e,int pos);
cola quitar(cola c);
void buscar(cola c, int dato);

#endif