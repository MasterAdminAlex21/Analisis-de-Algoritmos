
#include<stdio.h>
#include<stdlib.h>


int main(){
 int n=-1;
 while(n<0){
  printf("Ingrese n: ");
  scanf("%d",&n);
  if(n<1) printf("ERROR: ingrese numero positivo\n");
}
 FILE *datos,*datos2;
 int valor;
 datos=fopen("numeros10millones.txt","r");
 if(datos==NULL){
  perror("No existe el archivo\n");
  exit(0);
 }
 datos2=fopen("numero.txt","w");
 for(int i=0;i<n;i++){
  fscanf(datos,"%d",&valor);
  fprintf(datos2, "| %d |",valor );
 }
 fclose(datos2);
 fclose(datos);
}