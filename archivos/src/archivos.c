/*
 ============================================================================
 Name        : archivos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "parser.h"

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	 Cliente clientes[1000];
	 int r,i;
	 r = parseData("cliente.txt",clientes,3);
	 for(i=0; i<r; i++)
	 printf("id:%d nombre:%s direccion:%s cuit:%s localidad:%s\n", clientes[i].idCliente,
			 clientes[i].nombre,
			 clientes[i].direccion,
			 clientes[i].cuit,
			 clientes[i].localidad);

	return EXIT_SUCCESS;
}
