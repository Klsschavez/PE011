#include <stdio.h>
  main(){
  	const largo = 20, ancho = 40;
 	int i, j, k, x = 1;
  	while(x < 3){ 
 		for(i = 1; i <= ancho; i++){ 

  			if(i == 1 || i == ancho){ 

				printf("+"); 
				}else{ 
				printf("-"); 
			} 
 		}  
		printf("\n"); 
 		if(x == 1){ 

 			while(k <= largo - 2){ 
 				for(j = 1; j <= ancho; j++){
  					if(j == 1 || j == ancho){

 						printf("I"); 

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
return 0;
 }
