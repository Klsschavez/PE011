#include<stdio.h>

 int X = 50;


void funcion_leer_matriz(int [][X], int, int);
void funcion_sumar_matriz(int [][X], int [][X], int [][X], int, int);
void funcion_imprimir_matriz(int [][X], int, int);


int main(int num_de_arg, char **dimension){
  int M1[X][X], M2[X][X], MatrizResultante[X][X];
  int filas, columnas, contador;

do{
  printf("\nIngrese el numero de filas de las matrices: ");
  scanf("%d", &filas);
}while(filas > X || filas < 1);

do {
  printf("\nIngrese el numero de columnas de las matrices: ");
  scanf("%d", &columnas);
} while(columnas > X || columnas < 1);

			printf("\nLectura de la primer matriz\n");
			funcion_leer_matriz(M1, filas, columnas);
			printf("\nLectura de la segunda matriz\n");
			funcion_leer_matriz(M2, filas, columnas);
			funcion_sumar_matriz(M1, M2, MatrizResultante, filas, columnas);
			printf("\n\n La Matriz 1 es:\n\n" );
			funcion_imprimir_matriz(M1, filas, columnas);
			printf("\n\n La Matriz 2 es:\n\n" );
			funcion_imprimir_matriz(M2, filas, columnas);
			printf("\n\nMatriz resultante de la sumatoria:\n\n" );
			funcion_imprimir_matriz(MatrizResultante, filas, columnas);

}

				void funcion_leer_matriz(int A[][X], int f, int c){
					 int i, j;
						for(i = 0; i < f; i++){
					        for(j = 0; j < c; j ++){
					                  	printf("Ingrese el elemento de%d %d: ", i + 1, j + 1);
					                    scanf("%d", &A[i][j]);
                }
        }
}

				void funcion_sumar_matriz(int M1[][X], int M2[][X], int M3[][X], int f, int c){
				     int i, j;
				        for(i = 0; i < f; i ++){
				                for(j = 0; j < c; j ++){
				                	
				                        M3[i][j] = M1[i][j] + M2[i][j];
                }
        }
}

				void funcion_imprimir_matriz(int A[][X], int f, int c){
				     int i, j;
				        for(i = 0; i < f; i ++){
				                for(j = 0; j < c; j ++){
				                        printf("\t%d", A[i][j]);
				                }
				                printf("\n");
        }
}
