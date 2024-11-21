#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*
la biblioteca ctype.h incluye una función que permite determinar si un caracter
es un dígito o no.
Una cadena para la cuál todos sus caracteres son dígitos es Número.

Hay que construir la función esNumero para que devuelva 1 cuando todos
 los caracteres sean dígitos o 0 cuando al menos uno no lo es.

 */
int esNumero(const char *nro) {
    for(int i=0;nro[i] !='\0';i++ )
      {  
        if(!isdigit(nro[i]))
            {return 0;}
      }
      
      return 1;
        
}

int main(int argc, char **argv) {
	if (argc != 3) {
		puts("uso: suma nro1 nro2");
		exit(0);
	}
	if (!esNumero(argv[1]) || !esNumero(argv[2])) {
		puts("nro1 y nro2 deben ser constantes numéricas");
		exit(-1);
	} 
	int sum1 = atoi(argv[1]);
	int sum2 = atoi(argv[2]);
	printf("la suma de %d y %d es %d", sum1, sum2, sum1+sum2);
	return 0;
}