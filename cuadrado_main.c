#include <stdio.h>

	struct cuadrado{
		int largo, ancho;
	}

	main(){

	struct cuadrado espec;
	espec.largo = 20;
	espec.ancho = 40;

	int i, j, k, x = 1;

	while(x < 3){

		for(i = 1; i <= espec.ancho; i++){


			if(i == 1 || i == espec.ancho){
				printf("+");
				}else{
				printf("-");
			}

		}

		printf("\n");

		if(x == 1){

			while(k <= espec.largo - 2){

				for(j = 1; j <= espec.ancho; j++){

					if(j == 1 || j == espec.ancho){
						printf("|");
					}else{
						printf(" ");
						//Para poner un texto dentro (No es recomendable)
						/*if(k == largo/2 && j == (ancho/2){
							printf("Holaa");
						}*/
					}

				}

				printf("\n");

				k = k + 1;
			}

		}

		x = x + 1;
	}
	
}
