/* El sig program a cuenta líneas a la entrada. Como se mencionó anterior-
mente, la biblioteca estándar asegura que una secuencia de texto de entrada pa-
rezca una secuencia de líneas, cada una terminada por un carácter nueva línea.

Por lo tanto, contar líneas es solamente contar caracteres nueva línea:

cuenta las líneas de la entrada */
#include <stdio.h>
int main( )
{
int c, nl;
FILE *file = freopen("archivitonasheo.txt", "r", stdin);

nl = 1 ;
while ((c = getchar()) != EOF )
{
    putchar(c);
    if (c == '\n')
        {   
            ++nl;
        };
}
printf("\n%s%d\n","Lineas Del archivo: ",nl);
fclose(file);
}