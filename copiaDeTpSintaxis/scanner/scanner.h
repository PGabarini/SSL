#ifndef SCANNER_H_
#define SCANNER_H_
#include <stdio.h>
#include <ctype.h>

#define TAMANIO_BUFFER 20
typedef int TOKEN;


typedef int ESTADO;

typedef enum {
 INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENIZQUIERDO, 
 PARENDERECHO, PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT,RECHAZO
} PALABRA;

const char* tokenAPalabra(PALABRA t);

const char *Buffer(void);

TOKEN EsReservada(void);

TOKEN Scanner(void);

#endif