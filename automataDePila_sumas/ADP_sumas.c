
/**
 * Este código es una implementación con fines didácticos del Ejemplo 6 
 * de la sección 2.3 AFPDs Y EXPRESIONES ARITMÉTICAS del libro de 
 * Sintaxis y Semántica de los Lenguajes del Profesor Daniel Muchnik.
 * 
 * En este ejemplo implementamos el autómata de pilas suponiendo que
 * los tokens fueron verificados y son correctos en una etapa anterior.
 * 
 * El autómata reconoce palabras del lenguaje de las expresiones 
 * matemáticas que incluyen el dígito 4.
 * 
 * Dos extensiones rápidas:
 * - que soporte otros dígitos
 * - que valide los tokens antes de ingresar
 * 
 * Compilación:
 * 
 * gcc expresiones.c -o expresiones
 * 
 * Ejecución:
 * 
 * En Linux:                           En Windows Powershell
 *   ./expresiones "4 + 4"                .\expresiones.exe "4 + 4"
 * 
 * Debería aceptar la palabra en ambas, sino son bienvenidas correcciones.
 * 
 * Está pensado para ser utilizado con fines didácticos exclusivamente. 
 * 
 * Bajo ninguna circunstancia se autoriza el uso comercial del ejemplo
 * ni del código sin expresa autorización de los autores.
 * 
 * La modificación y extensión queda autorizada siempre que se respeten
 * las restricciones de los dos párrafos anteriores inmediatos.
 * 
 * Quién publica este gist es el autor de la objetable implementación
 * el 11 septiembre de 2024.
 * 
 * Disfrutenlo y a mejorar!
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define fdc '\0'
#define epsilon '\0'
#define e0   0
#define e1   1
#define e2   2
#define e3   3
#define e99 99

/**
 * Tokens que acepta cadena son '4', '+','*' '(' ')', fdc = '\0' 
 * 
 * TM       4       +,*     (       )       fdc
 * e0,$     e1,$             e0,R$   
 * e0,R     e1,R             e0,RR
 * e1,$     e1,$    e0,$                    e3,$
 * e1,R     e1,R    e0,R            e2,\0
 * e2,$             e0,$                    e3,$
 * e2,R             e0,R            e2,\0
 * e3,$ 
 */
int reconocer_palabra(const char *cadena) {
    int estado_actual = 0;
    char PILA[4096] = "$"; /* { '$', '\0', ... } */
    char *tope = PILA;     /* puntero al top de la pila : va guardando cual es la última posicion */ 
    puts("Estado inicial: e0");

    for (int i = 0; i <= strlen(cadena); ++i) {
        char token = cadena[i];
        if (token == ' ')
            continue;

        if (isdigit(token))
        {   
            if (estado_actual == e0 || estado_actual == e1) {
                    estado_actual = e1;
                } else {
                    estado_actual = e99;
                }
        }
        switch (token) {
            case '+':
            case '*':
                if (estado_actual == e1 || estado_actual == e2) {
                    estado_actual = e0;
                } else {
                    estado_actual = e99;
                }
                break;
            case '(':
                if (estado_actual != e0) estado_actual = e99;
                ++tope;
                *tope = 'R';
                break;
            case ')':
                if (*tope == 'R'
                    && (estado_actual == e1 || estado_actual == e2)  )  {
                    *tope = epsilon;
                    --tope;
                } else {
                    estado_actual = e99;
                }

                break;            
            case fdc: 
                if ( *tope == '$' 
                    && (estado_actual == e1 || estado_actual == e2)) {
                    estado_actual = e3;
                }
        }

    }


    /* condicion de aceptación */
    if (estado_actual == e3 && *tope == '$')
        return 1;
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        puts("uso: ./pila PALABRA_A_RECONOCER");
        exit(EXIT_SUCCESS);
    }
    char *tokens = argv[1]; //"4 + 4";    /* mi serie de tokens de entrada */
    /*
    "4", DIGITO
    "+", OPERADOR
    "4", DIGITO
    */
    if (reconocer_palabra(tokens) == 1) {
        printf("%s es una palabra del LIC de expresiones.\n", tokens);
    } else {
        printf("La cadena %s no es una palabra del LIC :(\n", tokens);
    }

    return EXIT_SUCCESS;
}
