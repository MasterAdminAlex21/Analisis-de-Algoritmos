#include<stdio.h>

void main(){
 int ele,tip,i,j,k,cap,tam=0,rec=0;
 printf("Ingresa la cantidad de Elementos:\n");
 scanf("%d",&ele);
 printf("Ingresa la cantidad de Tipos de Elementos:\n");
 scanf("%d",&tip);
 int obj[ele][tip],pes[ele][tip];
 for(i=0;i<ele;i++){
  for(j=0;j<tip;j++){
   printf("Ingresa el valor del objeto %d tipo %d:\n",i+1,j+1);
   scanf("%d",&obj[i][j]);
   printf("Ingresa el peso %d tipo %d:\n",i+1,j+1);
   scanf("%d",&pes[i][j]);
  }
 }
 printf("Ingrese la capacidad de la mochila:\n");
 scanf("%d",&cap);
 int tabla[ele+2][ele+2];
 for(j=0;j<ele;j++){
  for(i=0;i<tip;i++){
   if(tam<=cap && pes[j][i]<=cap && rec!=i){
    tabla[j][i]=1;
    tam+=pes[j][i];
   }else{
    tabla[j][i]=0;
   }
   for(k=0;k<ele;k+=tip){
    tabla[0][k]=1;
    tam+=pes[k][0];
   }
  }
  rec++;
  tam=0;
 }
 tam=0;
 for(i=0;i<ele;i++){
  for(j=0;j<ele;j++){
   printf("Valor %d tipo %d Peso %d| ",obj[i][j],i+1,pes[i][j]);
   for(k=0;k<ele;k++){
    printf("%d,",tabla[k][j]);
    if(tabla[k][j]==1){
     tam=pes[i][j];
    }
   }
   printf("\n");
   if(tam==cap){
    break;
   }
  }
 }
}