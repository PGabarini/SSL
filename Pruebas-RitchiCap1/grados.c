#include <stdio.h> 
/* imprime la tabla Fahrenheit-Celsius 
para fahr = 0, 20, ..., 300 */ 
/*
 int main () 
{ 
int fahr, celsius; 
int lower, upper, step; 
lower = 0 ; //límite inferior de la tabla de temperaturas 
upper = 300; // límite superior  
step = 20 ; //f* tamaño del incremento 
fahr = lower; 
while (fahr <= upper) { 
celsius = 5 * (fahr-32) / 9; 
printf("%s%d\t%s%d\n","Farenhexxri", fahr,"Celsius", celsius); 
fahr = fahr + step; 
} 
} 
*/
/*VERSION CON FLOAT DE CELSIUS A FHAR*/

int main() 
{ 
float fahr, celsius; 
int lower, upper, step; 


lower = 0 ; //límite superior de la tabla de temperaturas 
upper = 300; // límite superior 
step = 20 ; // tamaño del incremento 

celsius = upper; 

printf("%s\n","CONVERSION DE CELS A FARG ");

while (celsius >= lower) 
    { 
    fahr = (celsius * 9) * 0.2 + 32 ; 
    printf("%s%3.0f%s%6.1f\n", " CEL " ,celsius," FAR ",fahr); 
    celsius = celsius - step;
    }   

}

/*Version simple con un for
 imprime la tabla Fahrenheit-Celsius:

int fahr; 
for (fahr = 0; fahr < = 300; fahr = fahr + 20) 
printf("%3d %6.1f/n", fahr, (5.0/9.0)*(fahr-32)); 

*/

/* USO DE DEFINE
#define LOWER 0 /* límite inferior de la tabla 
#define UPPER 300 /* limite superior 
#define STEP 20 /* tamaño del increment
int main()
{
    int fahr; 
    for (fahr = LOWER; fahr < = UPPER; fahr = fahr + STEP) 
        printf("%3d %6.1f/n", fahr, (5.0/9.0)*(fahr-32)); 

}


*/