  
#include <stdio.h>
#include <stdlib.h>

int funcion_fact(int mem){
  if(mem <= 0){
    return 1;

  } else{
    return mem * funcion_fact(mem - 1);
  }
}

int main (int contador, char **contador_mem){
  int num = 0, resultado, i = 0;

  for(i = 1; i < contador; i++){
  	
	   	num = atoi(contador_mem[i]);
	  	resultado = funcion_fact(num);
	  	
    printf("\nEl factorial del numero %d es: %d\n", num, resultado);
    
  }
  
  return 0;
}
