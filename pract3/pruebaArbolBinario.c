#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct ABB{
	int *dato;
	struct ABB *izq;
	struct ABB *der;	
};

struct ABB *CrearArbol(){
	struct ABB *raiz;
	raiz = (struct ABB*)malloc(sizeof(struct ABB));
	raiz->dato=(int*)malloc(2*sizeof(int));
	raiz->dato[0]=0;
	raiz->dato[1]=-1;
	raiz->izq=NULL;
	raiz->der=NULL;
	return raiz;
	
};
void insertar(int dato,struct ABB *raiz){
	if(raiz!=NULL && raiz->izq==NULL && raiz->der==NULL){
		raiz->dato[0] = dato;
		raiz->dato[1]=0;
		raiz->izq= CrearArbol();
		raiz->der= CrearArbol();
	}
	if(dato<raiz->dato[0]){
		insertar(dato,raiz->izq);
	}
	else if(dato>raiz->dato[0]){
		insertar(dato,raiz->der);
	}
}

void Preorden(struct ABB *raiz){
	if(raiz!=NULL){
		if(raiz->dato[1]!=-1)
		printf("%d \n",raiz->dato[0]);
		Preorden(raiz->izq);
		Preorden(raiz->der);
	}
}


int main(int argc, char **argv)
{
	int i,j,k,temp,v,p,l;
	
	FILE *archivo;
	FILE *save;
	FILE* fichero;
	
	clock_t inicio, final;
	double tiempod=0;
	int contt=0;
	archivo = fopen("numrandom.txt", "r");
	save = fopen("ordenadosarbolbin.txt", "w");

	struct ABB *arbol;
	arbol= CrearArbol();
	printf("El contenido de prueba es: \n");
	 fichero = fopen("ordenadoarbolbin.txt", "wt");
	for(i=1;i<=100000;i++){
		insertar(i,arbol);
	     
   
    fprintf (fichero, "%d \n", i);
	
	}
	printf("Elementos leidos \n");
	printf("Ordenando los elementos, por favor espere... \n");
	
	inicio = clock();
	Preorden(arbol);
		final = clock();
	
	
	printf("Ordenamiento finalizado \n");
	tiempod = (double) (final-inicio) / CLOCKS_PER_SEC;
	printf("El tiempo del algoritmo de busqueda es de %f segundos \n", tiempod);
	
	//fclose(archivo);
	fclose(save);
	//system("pause");
return 0;	

	
}
