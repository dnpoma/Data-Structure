#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
	int **segmentar(int); // no es necesario declarar la variable cunado defino el prototipo
	void encerar(int **,int);
	void ingresar(int**);   // metodo del espejo 
	void calcular(int**,int**,int**,int);
	void imprimir(int**,int);


int **segmentar(int dim){ //reservar el espacio de memoria 
		int **matriz,j;
		//                    tamaño del espacio a reservar
		//					  4 * 4   = 16 espacios reseervo 
		matriz=(int**)malloc(dim*sizeof(int *));
		//segmente el espacio--reselve 4 byte
		for(j=0;j<dim;j++)
		{				//casting
			*(matriz+j)=(int *)malloc(dim*sizeof(int));
		}
		return matriz;
	}

void encerar(int **matriz,int dim)
	{
		int i,j;
		for(i=0;i<dim;i++)
			for(j=0;j<dim;j++)
			{
				// fila-columna  depalzo de  la a0 -> a4
				*(*(matriz+i)+j)=0;
			}
}
	
void ingresar(int** matriz, int dim)
	{
		int i,j;
		for(i=0;i<dim;i++)
			for(j=0;j<dim;j++)
			{
				scanf("%d",&(*(*(matriz+i)+j))); //cambiar i -> j para columnas filas 
			}
}

void calcular(int**matriz1,int** matriz2,int** matrizR,int dim){
		 int i,j,k;
			for(i=0;i<dim;i++)
				for(j=0;j<dim;j++)
					for(k=0;k<dim;k++)
					{
						*(*(matrizR+i)+j) = *(*(matrizR+i)+j) + *(*(matriz1+i)+k) *  *(*(matriz2+k)+j);
					}
}

void imprimir(int** matriz,int dim)
{
		int i,j;
		for(i=0;i<dim;i++)
		{
			for(j=0;j<dim;j++)
			{
				// fila-columna  depalzo de  la a0 -> a4
				printf("%d",*(*(matriz+i)+j)); //cambiar i -> j para columnas filas 
				printf("%*s",j+5,"");			
			}
			printf("\n");
		}
}


int main(int argc, char** argv) {
	int dim;
    int **mat1, ** mat2, **matR;
    printf("\nIngrese la dimensión :");
    scanf("%d",&dim);
    mat1=segmentar(dim);
    mat2=segmentar(dim);
    matR=segmentar(dim);
    encerar(mat1,dim);
    encerar(mat2,dim);
    encerar(matR,dim);
    ingresar(mat1, dim);
    ingresar(mat2, dim);
    printf("\n");
    imprimir(mat1,dim);
    printf("\n");
    imprimir(mat2,dim);
    printf("\n");
    calcular(mat1,mat2,matR,dim);
    imprimir(matR,dim);
    
	return 0;
}
