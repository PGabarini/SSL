/*
Escribamos un programa para contar el número de ocurrencias de cada dígito,
de caracteres espaciadores (blancos, tabuladores, nueva línea), y de todos los
otros caracteres. Esto es artificioso, pero nos permite ilustrar varios aspectos de
C en un program a.*/
#include <stdio.h>

int main( )
{

FILE *file = freopen("archivitonasheo.txt", "r", stdin);
int caracter, i, espacioBlancoOSalto, noDigitoNiEspacio;
int ndigit[10];
espacioBlancoOSalto = noDigitoNiEspacio = 0 ;


for (i = 0 ; i < 10 ; ++ i)
    ndigit[i] = 0; 

    while ((caracter = getchar( )) != EOF)
    {
    if (caracter >= '0' && caracter <= '9')
        ++ndigit[caracter-'0'];
    else if (caracter == ' ' || caracter == '\n' || caracter == '\t' )
        ++espacioBlancoOSalto;
    else
    ++noDigitoNiEspacio;
    }
 

printf("dígitos ");
for(i = 0 ; i < 10 ; ++i)
   { printf("%d", ndigit[i]);};   

    printf(", espacios blancos = %d, otros = %d\n",espacioBlancoOSalto, noDigitoNiEspacio);
    fclose(file);
}