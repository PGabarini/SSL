#include <stdio.h>
#define EnUnaPalabra 1 /* en una palabra */
#define FueraDeUnaPalabra 0 /* fuera de una palabra */
/* cuenta lineas, palabras, y caracteres de la entrada */

int main( )
{

FILE *file = freopen("archivitonasheo.txt", "r", stdin);
int caracter, numeroLineas, numeroPalabras, numeroCaracteres, state;
state = FueraDeUnaPalabra;

numeroLineas = numeroPalabras =numeroCaracteres =0 ;

while ((caracter = getchar( )) != EOF)
 {
    ++numeroCaracteres;

    if (caracter == '\n' )
        ++numeroLineas;

    if (caracter == ' ' || caracter == '\n'  || caracter == '\t')
        state = FueraDeUnaPalabra;

    else if (state == FueraDeUnaPalabra) 
        {
        ++numeroPalabras;
        state = EnUnaPalabra;
        }   
}
printf ("\n%s%d\n%s%d\n%s%d\n",
        "Cant Lineas: ", numeroLineas,
        "Cant Palabras: ",numeroPalabras,
        "Cant Caracteres: ", numeroCaracteres);
        
fclose(file);
}