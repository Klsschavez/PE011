  
#include<stdio.h>
#include<stdlib.h>

int funcion_fib(int n){

  if (n==0 || n==1){
       
	   return 1;
	   
	   
  }else {
        return funcion_fib(n - 1) + funcion_fib(n - 2);
        
  }
  
}

int main (){

    int v = 0;

    do{
            printf("Ingrese el numero a evaluar:\n");
            scanf("%d", &v);
    }while (v > 40 || v < 1);

    printf("El numero %d recibe el valor de %d en Fibonacci", v, funcion_fib(v));
  return 0;
}
