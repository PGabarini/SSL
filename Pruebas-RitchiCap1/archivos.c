#include <stdio.h>
/* copia la entrada a la salida; la . versión 
int main( )
{
int c;
c = getchar( );
while (c != EOF) {
printf("%s","Usted escrubibio  :");
putchar(c);
c = getchar( );
}
}
*/

/*VERSION MEJOR 
/* copia la entrada a la salida; 2 a. versión */
/*
int main( )
{
int c;

while ((c = getchar( )) != EOF)
putchar(c);
}
/*

/* cuenta los caracteres de la entrada; la. versión 
int main( )
{
long nc;
nc = 0 ;
while (getchar( ) != EOF)
{
++nc;
}
printf("%ld\n", nc);
}
*/

/* cuenta los caracteres de la entrada; 2 a. versión */
/*
int main( )
{
double nc;
for (nc = 0; getchar( ) != EOF; ++nc)
   ;
printf("%.0f\n", nc);
}
*/
int main( )
{
FILE *file = freopen("archivitonasheo.txt", "r", stdin);   

int caracter;

while (((caracter = getchar( )) != EOF)!=0)
   {
     

   putchar(caracter);
   printf("%s\n"," es 1 verdadero " );

   if(((caracter = getchar( )) != EOF)==0)
     {printf("%s\n"," es 0 FALSO " );}
   }




fclose(file);
}
