#include <stdio.h>

int FKnap(int CantObj, int *W, int *P, int M);
void dibujar(int x,int y,int *reg,int vac,int rep);

int main(){
	int optimizacion,cantidad_objetos,M,contador;
	printf("Ingrese la Cantidad de Objetos:\n");
	scanf("%d",&cantidad_objetos);
	int W[cantidad_objetos],P[cantidad_objetos];
	printf("Ingrese la Cantidad de Valores por Objeto:\n");
	scanf("%d",&M);
	printf("Ingrese los valores de W:\n");
	for(contador=0;contador<cantidad_objetos;contador++){
		scanf("%d",&W[contador]);
	}
	printf("Ingrese los valores de P:\n");
	for(contador=0;contador<cantidad_objetos;contador++){
		scanf("%d",&P[contador]);
	}
	optimizacion=FKnap(cantidad_objetos,W,P,M);
	printf("Ganancia Optima:%d\n",optimizacion);
}

int FKnap(int CantObj, int *W, int *P, int M){
	int g[CantObj+1][M+1];
	int c,j,vac=CantObj-1,rep=2,rev;
	for(c=0;c<=M;c++){
		g[CantObj][c]=0;
	}
	printf("Objetos: %d\n",CantObj);
	printf("Elementos: %d\nw={",M);
	for(rev=0;rev<CantObj;rev++){
		printf("%d",W[rev]);
		if(rev<CantObj-1){
			printf(",");
		}else{
			printf("}");
		}
	}
	printf("\np={");
	for(rev=0;rev<CantObj;rev++){
		printf("%d",P[rev]);
		if(rev<CantObj-1){
			printf(",");
		}else{
			printf("}");
		}
	}
	printf("\n");
	dibujar(M,CantObj,g[CantObj],vac,rep);
	for(j=CantObj-1;j>=0;j--){
		for(c=0;c<=M;c++){
			if (W[j]<=c){
				if(g[j+1][c]>g[j+1][c-W[j]]+P[j]){
					g[j][c]=g[j+1][c];
				}else{
					g[j][c]=g[j+1][c-W[j]]+P[j];
				}
			}else{
				g[j][c]=g[j+1][c];
			}
		}
		vac--;
		rep++;
		printf("Objetos: %d\n",CantObj);
		printf("Elementos: %d\nw={",M);
		for(rev=0;rev<CantObj;rev++){
			printf("%d",W[rev]);
			if(rev<CantObj-1){
				printf(",");
			}else{
				printf("}");
			}
		}
		printf("\np={");
		for(rev=0;rev<CantObj;rev++){
			printf("%d",P[rev]);
			if(rev<CantObj-1){
				printf(",");
			}else{
				printf("}");
			}
		}
		printf("\n");
		dibujar(M,CantObj,g[j],vac,rep);
	}
	return g[0][M];
}

void dibujar(int x,int y,int *reg,int vac,int rep){
	int col,fil;
	for(col=0;col<=vac;col++){
		for(fil=0;fil<=x;fil++){
			printf("| |");
		}
		printf("\n");
	}
	for(fil=0;fil<=x;fil++){
		printf("|%d|",reg[fil]);
	}
	if(vac+1>0){
		printf("\nLos valores se repiten hasta el elemento: %d\n",vac+1);
		printf("Para los %d elementos faltantes se cumple la operacion: G[%d,%d-%d]=max(G[%d,%d-%d],G[%d,0-%d]+p[%d])\n",x-(vac+1),vac+rep,x-rep,x,vac+2,x-rep,x,vac+2,x-vac,vac);
	}
	printf("\n");
}
