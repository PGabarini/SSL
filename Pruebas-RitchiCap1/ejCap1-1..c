#include <stdio.h>


/*Ejercicio 1-8. Escriba un program a que cuente espacios en blanco, tabuladores
y nuevas líneas. □ */


void ej1_8 ()
{
    int caracter, espacioEnBlanco,tabuladores,nuevasLineas;
    espacioEnBlanco = tabuladores = nuevasLineas =0;
    FILE *file = freopen("archivitonasheo.txt", "r", stdin);

    
    while ((caracter = getchar()) != EOF )
    {
        putchar(caracter);
        if (caracter == ' ')
            {++espacioEnBlanco;};
        if (caracter == '\n')
            {++nuevasLineas;};
        if (caracter == '\t')
            {++tabuladores;};
        
    }
    printf("\n%s%d\n%s%d\n%s%d\n",
        "Los ESPBLANCO SON  ",espacioEnBlanco,
        "LAS NUEVAS LINEAS  ",nuevasLineas,
        "LOS TBS  ",tabuladores);
    fclose(file);
}

/*Ejercicio 1.9. Escriba un programa que copie su entrada a la salida, reemplazando
cada cadena de uno o más blancos por un solo blanco.*/
void ej1_9()
{
    int caracter,caracAnterior;
   

    FILE *file = freopen("archivitonasheo.txt", "r", stdin);
    
    while ((caracter = getchar()) != EOF )
    {
        if(caracter == ' ')
        {
            if(caracAnterior!= ' ')
            {putchar(caracter) ;};
        }
        else{{putchar(caracter) ;}}

        caracAnterior =caracter;
    }
     fclose(file);
}

/*Ejercicio 1-11. ¿Cómo probaría el program a para contar palabras? ¿Qué clase
de entrada es la más conveniente para descubrir errores si éstos existen? */
void ej1_11()
{
    int caracter,caracAnterior;

    FILE *file = freopen("archivitonasheo.txt", "r", stdin);
    
    while ((caracter = getchar()) != EOF )
    {
        if(caracter == ' ')
        {
            {putchar('\n') ;};
        }
        else{{putchar(caracter) ;}}

    }

 fclose(file);
}

/*Ejercicio 1-19. Escriba una función reverse(s) que invierta la cadena de caracte-
res s. Usela para escribir un program a que invierta su entrada, línea a línea.
NO anda*/
void ej1_19()
{
    int caracter;
    int programa[100];
    int i = 100;

    FILE *file = freopen("archivitonasheo.txt", "r", stdin);
    
    while ((caracter = getchar()) != EOF )
    {
        programa[i] = caracter;
        i--;
    }

    for(i; i<=100; i++)
    { printf("%s\n",programa);}

     fclose(file);
}

int main()
{
    ej1_19();
    
}