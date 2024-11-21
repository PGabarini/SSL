/*program a que lea un conjunto de líneas de texto e im prim a la de mayor longitud. El pseudocó-
digo es bastante simple:

while (hay otra línea)
if (es más larga que la anterior más larga)
guárdala
guarda su longitud
imprime la línea más larga*/

#include <stdio.h>
#define MAXLINE 1000 /* tamaño máximo de la línea de entrada */

int obtenerLongituDeLinea(char lineaALeer[], int lineaMaximaPosible);
void copiarLinea2en1(char to[], char from[]);
/* imprime la línea de entrada más larga */

int main( )
{
FILE *file = freopen("archivitonasheo.txt", "r", stdin);

int longitudLineaActual; //longitud actual de la línea 
int longitudLineaMaxima;//Máxima longitud vista hasta el momento 

char lineaActual[MAXLINE];// línea de entrada actual 
char lineaMasLarga[MAXLINE]; // la línea más larga se guarda aquí 

longitudLineaMaxima= 0 ;
while ((longitudLineaActual = obtenerLongituDeLinea(lineaActual, MAXLINE)) > 0)
   { if (longitudLineaActual > longitudLineaMaxima) 
    {
    longitudLineaMaxima = longitudLineaActual;
    copiarLinea2en1(lineaMasLarga, lineaActual);
    }  
   }

if (lineaMasLarga > 0 ) // hubo una línea 
{printf("%s", lineaMasLarga);}

fclose(file);
return 0 ;
}


/* getline: lee una línea en s, regresa su longitud */
int obtenerLongituDeLinea(char lineaALeer[], int lineaMaximaPosible)
{
int caracter, i;

for (i = 0; i < lineaMaximaPosible-1 && (caracter = getchar( )) !=EOF && caracter!= '\n'; ++i)
    {lineaALeer[i] = caracter;};

if (caracter == '\n') 
    {
    lineaALeer[i] = caracter;
        ++i;
    }
lineaALeer[i] = '\0';
return i;
}    
/* copy: copia 'from' en 'to'; supone que to es suficientemente grande */
void copiarLinea2en1(char to[], char from[])
{
    int i;
    i = 0 ;
    while((to[i] = from[i]) != '\0')
    ++i;
}