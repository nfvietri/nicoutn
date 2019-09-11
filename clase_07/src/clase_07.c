/*
 ============================================================================
 Name        : clase_07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define QTY_NOMBRES 5
#define QTY_CARACTERES 50

int main(void) {


	char aNombres[QTY_NOMBRES][QTY_CARACTERES];
	char aDNI[QTY_NOMBRES][QTY_CARACTERES];
	char nombre[QTY_CARACTERES];
	char DNI[QTY_CARACTERES];
	int i;


	for(i = 0;i<QTY_NOMBRES;i++)
	{
		getString(nombre,"Nombre?\n","Error",2,10,3);
		strcpy(aNombres[i],nombre);
		getString(DNI,"DNI?\n","Error",2,10,3);
		strcpy(aDNI[i],DNI);

	}

	/*imprimirArrayString(aNombres,QTY_NOMBRES);
	imprimirArrayString(aDNI,QTY_NOMBRES);



	imprimirArrayString(aNombres,QTY_NOMBRES);
	imprimirArrayString(aDNI,QTY_NOMBRES);*/
	for(i=0;i<QTY_NOMBRES;i++)
	{
		printf("Nombre: %s DNI: %s\n", aNombres[i],aDNI[i]);

	}

	ordenarArrayString(aNombres,aDNI,QTY_NOMBRES);

	for(i=0;i<QTY_NOMBRES;i++)
	{
		printf("Nombre: %s DNI: %s\n", aNombres[i],aDNI[i]);

	}

	return EXIT_SUCCESS;
}



