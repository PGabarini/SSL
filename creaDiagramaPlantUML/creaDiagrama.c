#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void obtenerPalabra(char palabraALeer[]);
void acomodarFinalDeMetodo(char nombreDeMetodo[]);
void acomodarNombreObjClase(char nombreDeObjoClase[]);
void acomodarNombreDeVariable(char nombreDeVariable[]);
void acomodarNombreDeConstante(char nombreDeConstante[]);
int esComentario(char palabraALeer[]);
void ignorarComentarios(char palabraALeer[],FILE *file);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("%s", "Uso: ./crearDiagrama archivo_entrada \n");
        exit(EXIT_SUCCESS);
    }
    
char PILA[20] ;
PILA[0]= '$';
char *topePILA = PILA; 
freopen("diagrama.plantuml", "w", stdout);

printf("%s%s","@startuml diagramaDelCodigo", "\n\n");

for(int i= 1; i< argc ; i++)
{

FILE *file = freopen(argv[i], "r", stdin);  

int noInstanciado = 0;
char palabraActual[100];
char posibleConstante[100];
char chequeoDeIntancia[100];
char chequeoDeIntancia2[100];


strcpy(palabraActual," a ");

do{     
        if (esComentario(palabraActual)==0)
        {
            ignorarComentarios(palabraActual,file);
        }

        if (((strcmp("object",palabraActual)==0) || (strcmp("class",palabraActual)==0))&&(strlen(palabraActual) > 0))
        {
                if(*topePILA =='R')
                {   
                    *topePILA = '\0';
                    --topePILA;
                    printf("%s","} \n\n");
                    
                }      

                ++topePILA;
                *topePILA = 'R';

                printf("%s%s", palabraActual, " ");

                obtenerPalabra(palabraActual);
                acomodarNombreObjClase(palabraActual);
                     
                printf("%s%s", palabraActual, " { \n");

                do{
                    if(noInstanciado)
                    {

                    obtenerPalabra(palabraActual);
                    
                    }else{--noInstanciado;}

                    if (esComentario(palabraActual)==0)
                    {

                    ignorarComentarios(palabraActual,file);
                   
                    }                                             

                                if(strcmp("method",palabraActual)==0)
                                {
                                    acomodarFinalDeMetodo(palabraActual);
                                    printf("%s%s", palabraActual, "\n");
                                }

                                if((strcmp("var",palabraActual)==0))
                                {
                                    obtenerPalabra(palabraActual);

                                    if(strcmp("property",palabraActual)==0)
                                    {
                                        obtenerPalabra(palabraActual);
                                        acomodarNombreDeVariable(palabraActual);
                                        printf("%s%s", palabraActual, "\n");

                                    }
                                    else{
                                            acomodarNombreDeVariable(palabraActual);
                                            printf("%s%s", palabraActual, "\n");
                                        }
                                }

                                if((strcmp("const",palabraActual)==0))
                                {
                                    obtenerPalabra(palabraActual);
                                    acomodarNombreDeConstante(palabraActual);
                                        
                                    strcpy(posibleConstante,palabraActual);
                                    obtenerPalabra(chequeoDeIntancia);                                     
                        
                                    if(((strcmp("=new",chequeoDeIntancia))==0)||((strcmp("new",chequeoDeIntancia))==0))
                                    {                                           
                                    }                                      
                                    else if((strcmp("=",chequeoDeIntancia))==0)
                                    {
                                        obtenerPalabra(chequeoDeIntancia2);
                                        if((strcmp("new",chequeoDeIntancia2))==0)
                                        {                                                                                             
                                        }else if(posibleConstante[0] != ' ')
                                        {
                                            printf("%s%s", posibleConstante, "\n");
                                            strcpy(palabraActual,chequeoDeIntancia2);
                                            ++noInstanciado;
                                        }  

                                            
                                    }else if(posibleConstante[0] != ' ')
                                        {
                                            printf("%s%s", posibleConstante, "\n");
                                            strcpy(palabraActual,chequeoDeIntancia);
                                            ++noInstanciado;
                                        }                                            
                                             
                                }

                                                                                                  
                }while((strcmp("object",palabraActual)!=0) && (strcmp("class",palabraActual)!=0) && (strlen(palabraActual) > 0));    

        }else{obtenerPalabra(palabraActual);}
         
    }while(strlen(palabraActual) > 0);


if(*topePILA =='R')
    {   
        *topePILA = '\0';
         --topePILA;
        printf("%s","} \n\n");
    }

fclose(file);
}

printf("%s%s","\n","@enduml");
fclose(stdout);
return 0;
}

void obtenerPalabra(char palabraALeer[]) {

   
    int caracter, i = 0;

    
    while ((caracter = getchar()) != EOF && isspace(caracter));

    
        if (caracter != EOF) 
        {
            palabraALeer[i] = caracter;
            i++;
            
            while (i < 100 && (caracter = getchar()) != EOF && !isspace(caracter)) {
                palabraALeer[i] = caracter;
                i++;
            
        }

            palabraALeer[i] = '\0'; 
            
        }else{

            palabraALeer[0] = '\0'; 
        }

    }

void acomodarFinalDeMetodo(char nombreDeMetodo[]){
    
    char nombreCompletoDelMetodo[100];
    char PILAmetodo[100] = "$";
    char *topePILAmetodo = PILAmetodo;
    int i,j,longitudDelNombre;
    int contador = 0;

while(*topePILAmetodo != 'R')
{
    obtenerPalabra(nombreDeMetodo);
    longitudDelNombre =  strlen(nombreDeMetodo);

     for(i=0 ; i < longitudDelNombre ; i++)
    {
        if(nombreDeMetodo[i] == '(')
        {
            ++topePILAmetodo;
            *topePILAmetodo = 'R';
            longitudDelNombre = 0;
        }
        
        nombreCompletoDelMetodo[contador] = nombreDeMetodo[i];
        ++contador;
    }
}

while(*topePILAmetodo != '$')
{
    longitudDelNombre =  strlen(nombreDeMetodo);

    for(j = i ; j < longitudDelNombre ; j++)
    {
     if((nombreDeMetodo[j] == ')'))
        {            
            *topePILAmetodo = '\0';
            --topePILAmetodo;           
            longitudDelNombre = 0;
        }

        nombreCompletoDelMetodo[contador] = nombreDeMetodo[j];
        ++contador;
     } 

    i=0;
    
     if (*topePILAmetodo == 'R')  
        {obtenerPalabra(nombreDeMetodo);}
}
 nombreCompletoDelMetodo[contador] = '\0' ;
 strcpy(nombreDeMetodo,nombreCompletoDelMetodo);
}   

void acomodarNombreObjClase(char nombreDeObjoClase[]){

    int longitudDelNombre =  strlen(nombreDeObjoClase);
    int i = 0;
   
    for(i ; i < longitudDelNombre ; i++)
    {
        if(nombreDeObjoClase[i] == '{')
        {
            nombreDeObjoClase[i] = '\0';
            i = longitudDelNombre;
        }
    }
}

void acomodarNombreDeVariable(char nombreDeVariable[])
{
    int longitudDelNombre =  strlen(nombreDeVariable);
    int i = 0;
   
    for(i ; i < longitudDelNombre ; i++)
    {
        if(nombreDeVariable[i] == '=')
        {
            nombreDeVariable[i] = '\0';
            i = longitudDelNombre;
        }
    }
}

void acomodarNombreDeConstante(char nombreDeConstante[])
{
    int longitudDelNombre =  strlen(nombreDeConstante);
    int i = 0;
   
    for(i ; i < longitudDelNombre ; i++)
    {
        if(nombreDeConstante[i] == '=')
         {   
            
            if((nombreDeConstante[i+1] == 'n') &&(nombreDeConstante[i+2] == 'e')  && (nombreDeConstante[i+3] == 'w') ) 
            {
            nombreDeConstante[0] = ' ';
            nombreDeConstante[1] = '\0';
            }
            else{
            nombreDeConstante[i] = '\0';
            i = longitudDelNombre;
            }
        }
    }
}

int esComentario(char palabraALeer[])
{
    
        if(palabraALeer[0] == '/')
        {
            if((palabraALeer[1] == '/'))           
            {
                return 0;
            }

            if((palabraALeer[1] == '*'))           
            {
                return 0;
            }
        }
        else { return 1; }

}

void ignorarComentarios(char palabraALeer[],FILE *file)
{
    char PILAcomentario[100] = "$";
    char *topePILAcomentario = PILAcomentario ;
    char caracter;
    int i,longitudDelNombre;

        
        if((palabraALeer[0] == '/') && (palabraALeer[1] == '/'))
        {
            while((*topePILAcomentario != 'R'))
            {
                
                longitudDelNombre =  strlen(palabraALeer);

                
                    if(caracter == '\n')
                    {
                        ++topePILAcomentario;
                        *topePILAcomentario = 'R';
                        
                    }
                    
                   
                    caracter= fgetc(file);
                    
                
            }
            
        }

        if((palabraALeer[0] == '/') && (palabraALeer[1] == '*'))
        {
            while((*topePILAcomentario != 'R'))
            {
                
                longitudDelNombre =  strlen(palabraALeer);

                
                    if((palabraALeer[longitudDelNombre-2] == '*')&&(palabraALeer[longitudDelNombre-1] == '/')) 
                    {
                        ++topePILAcomentario;
                        *topePILAcomentario = 'R';                       
                    }
                    
                    if(*topePILAcomentario != 'R')
                    {
                        obtenerPalabra(palabraALeer);
                    }
                
            }
            
        }

}

