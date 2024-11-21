
#include "scanner.h"
#include <string.h>

const char* tokenAPalabra(PALABRA token)
{
        switch (token) {
        case INICIO: return "INICIO";
        case FIN: return "FIN";
        case LEER: return "LEER";
        case ESCRIBIR: return "ESCRIBIR";
        case ID: return "ID";
        case CONSTANTE: return "CONSTANTE";
        case PARENIZQUIERDO: return "PARENIZQUIERDO";
        case PARENDERECHO: return "PARENDERECHO";
        case PUNTOYCOMA: return "PUNTOYCOMA";
        case COMA: return "COMA";
        case ASIGNACION: return "ASIGNACION";
        case SUMA: return "SUMA";
        case RESTA: return "RESTA";
        case FDT: return "FDT";
        case RECHAZO: return "RECHAZO";
    }

}


char _buffer[TAMANIO_BUFFER+1];
int  _pos = 0;

void LimpiarBuffer(void) {
    _buffer[0] = '\0';
    _pos = 0;
}

void AgregarCaracter(int caracter) {
    _buffer[_pos++] = caracter;
}

const char *Buffer(void) {
    _buffer[_pos] = '\0';
    return _buffer;
}

TOKEN EsReservada(void) {

    if((strcmp(_buffer,"inicio")==0))
    {
        return INICIO;
    }
    if((strcmp(_buffer,"fin")==0))
    {
        return FIN;
    }
    if((strcmp(_buffer,"leer")==0))
    {
        return LEER;
    }
    if((strcmp(_buffer,"escribir")==0))
    {
        return ESCRIBIR;
    }

    return ID;
}

int ObtenerColumna(int simbolo) {
    if (isalpha(simbolo)) {
        return 0;
    } else if (isdigit(simbolo)) {
        return 1;
    } else if (simbolo == '+') {
        return 2;
    } else if (simbolo == '-') {
        return 3;
    } else if (simbolo == '(') {
        return 4;
    } else if (simbolo == ')') {
        return 5;
    } else if (simbolo == ',') {
        return 6;
    } else if (simbolo == ';') {
        return 7;
    } else if (simbolo == ':') {
        return 8;
    } else if (simbolo == '=') {
        return 9;
    } else if (simbolo == -1) {
        return 10;
    } else if (isspace(simbolo)) {
        return 11;
    }    
    return 12;
}


ESTADO Transicion(ESTADO estado, int simbolo) {
    static ESTADO TT[15][13] = {
        /*L   D   +   -   (   )   ,   ;   :   =  fdt  sp otro */
        {1,3,5,6,7,8,9,10,11,99,13,0,99},
		{1,1,2,2,2,2,2,2,2,2,2,2,2},
		{99,99,99,99,99,99,99,99,99,99,99,99,99},
		{4,3,4,4,4,4,4,4,4,4,4,4,4},
		{99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,12,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99},
        {99,99,99,99,99,99,99,99,99,99,99,99,99}
    };
    int columna = ObtenerColumna(simbolo);
    return TT[estado][columna];
}

TOKEN Scanner(void) {
    TOKEN token = 0;
    int c, pos = 0;
    ESTADO estado = 0;
    LimpiarBuffer();
    while (c=getchar()) {
        estado = Transicion(estado, c);
        switch (estado) {
            case 1:
            case 3:
                AgregarCaracter(c);
                break;
            case 2:
                ungetc(c, stdin);
                return EsReservada();  /* CONSTANTE */              
            case 4:
                ungetc(c, stdin);
                return CONSTANTE; /* CONSTANTE */
            case 5:
                AgregarCaracter(c);
                return SUMA; /* SUMA */
            case 6:
                AgregarCaracter(c);
                return RESTA; /* RESTA */
            case 7:
                AgregarCaracter(c);
                return PARENIZQUIERDO;  /* PARENIZQUIERDO */
            case 8:
                AgregarCaracter(c);
                return PARENDERECHO;  /* PARENDERECHO */
            case 9:
                AgregarCaracter(c);
                return COMA;  /* COMA */
            case 10:
                AgregarCaracter(c);
                return PUNTOYCOMA;  /* PUNTOYCOMA */
            case 11:
                AgregarCaracter(c);
                break;
            case 12:
                AgregarCaracter(c);
                return ASIGNACION; /* ASIGNACION */
            case 99:
                AgregarCaracter(c);
                return RECHAZO;
            case 13:
                return FDT; /* FDT */
        }
    }
}
