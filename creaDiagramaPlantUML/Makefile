# Nombre del ejecutable
EXEC = creaDiagrama
SRC = creaDiagrama.c

CC = gcc

all: $(EXEC) #USAR PARA COMPILAR Make all

$(EXEC): $(SRC)
	$(CC) -g $(SRC) -o $(EXEC)

#USAR PARA LIMPIAR Make clean
clean:  
	del /f $(EXEC).exe

#PARA EJECUTAR(LEER README antes simpre)
#./crearDiagrama archivo(s)DeEntrada.extension  	(pueden usarse varios archivos
#												 	sin importar la extension seran leidos como texto)