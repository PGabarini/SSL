#include "scanner.h"

int main(void) {
    TOKEN t;
    printf("%s","Scanner generador de TOKENS de MICRO \n");
    printf("%s", "LEXEMA || TOKEN \n");
    while ((t = Scanner()) != FDT) {


        if (t==RECHAZO){

            printf("%s   ->  %s\n", Buffer(),tokenAPalabra(t));
        }else{

        printf("%s   ->  %s\n", Buffer(),tokenAPalabra(t));

        }
        
    }
    return 0;
}
