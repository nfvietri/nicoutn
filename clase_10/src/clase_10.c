/*
 ============================================================================
 Name        : clase_10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"


int main(void) {

	struct sPantalla aPantallas[QTY_PANTALLAS];
	struct sPantalla bPantalla;
	int resultado;
	int opcion;
	char respuesta;

	do{
		printf("Por favor, selecciona una opción: \n"
				"1-Alta pantalla\n"
				"2-Modificar pantalla\n"
				"3-Baja pantalla\n"
				"4-Salir\n");

		scanf("%d",&opcion);


		switch(opcion)
		{
		case 1: getString(bPantalla.nombre,"Nombre de la pantalla?\n","Error",2,20,3);
				altaPantallaPorId(aPantallas,QTY_PANTALLAS,bPantalla);
				break;

		case 3: getString(&resultado,"Ingresa el ID:\n","Error",2,10,3);
				if(buscarPantallaPorId(aPantallas,QTY_PANTALLAS,resultado))
				{
					printf("Pantalla seleccionada: %s", aPantallas[resultado].nombre);
				}


		}

		}while(opcion != 4);


	imprimirArrayPantallas(aPantallas,QTY_PANTALLAS);

	return EXIT_SUCCESS;
}
