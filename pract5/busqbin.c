#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int busquedabinaria(int buscar, int *lista, int inicio, int centro, int final, int costo);
void burbujamejorada(int *lista,int n);

int main(){
 srand(time(NULL));
 int n=-1;
 while(n<0){
  printf("Ingrese n: ");
  scanf("%d",&n);
  if(n<1) printf("ERROR: ingrese numero positivo\n");
}
 FILE *datos;
 int valor,lista[n];
 datos=fopen("numeros10millones.txt","r");
 if(datos==NULL){
  perror("No existe el archivo\n");
  exit(0);
 }
 for(int i=0;i<n;i++){
  fscanf(datos,"%d",&valor);
  lista[i]=valor;
 }

 fclose(datos);

 burbujamejorada(lista,n); 

 while(valor>-1){
  printf("\nIngrese valor a buscar: \n");
  scanf("%d",&valor);

  if(valor==-1){
   exit(0);
  }

  int costo=0;
  clock_t ti=clock();
  int pos=busquedabinaria(valor,lista,0,n/2,n-1,costo);
  clock_t tf=clock();
  if(pos==-1){
   printf("No existe el numero\n");
  }else{
   printf("El numero %d esta en la posicion %d\n",valor,pos );
  }
  printf("El tiempo de ejecucion: %f segundos\n",(double)(tf-ti)/CLOCKS_PER_SEC);
 }
}

int busquedabinaria(int buscar, int *lista, int inicio, int centro, int final, int costo){
 if(inicio>final){
  costo+=1;
  printf("costo total: %d\n",costo );
  return -1;
 }else if(buscar==lista[centro]){
  costo+=1;
  printf("costo total: %d\n",costo );
  return centro;
 }else if(buscar<lista[centro]){
  costo+=1;
  return busquedabinaria(buscar,lista,inicio,(int)((inicio+centro-1)/2),centro-1,costo);
 }else{
  costo+=1;
  return busquedabinaria(buscar,lista,centro+1,(int)((final+centro+1)/2),final,costo);
 }
}

void burbujamejorada(int *lista,int n){
 int i,j,temp;

 for(i=1;i<n;i++){
  for(j=0;j<i;j++){
   if(lista[i]<lista[j]){
    temp=lista[j];
    lista[j]=lista[i];
    lista[i]=temp;
   }
  }
 }
}