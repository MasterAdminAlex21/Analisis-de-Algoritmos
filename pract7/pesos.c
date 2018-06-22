#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
 srand(time(NULL));
 FILE *pesos;
 pesos=fopen("pesos.txt","w");
 if(pesos==NULL){
  printf("archivo no encontrado\n");
  exit(0);
 }
 for(int cont=0;cont<1000000;cont++){
  fprintf(pesos,"%d\n\n",rand()%10000);
 }
 fclose(pesos);

}