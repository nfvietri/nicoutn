/*
 ============================================================================
 Name        : clase_11.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pant.h"
#include "publicidad.h"

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	struct sPantalla aPantallas[QTY_PANTALLAS];
	struct sPantalla bPantalla;
	struct sPublicidad aPublicidad[QTY_PUBLICIDAD];
	struct sPublicidad bPublicidad;
	int idAux;
	int opcion;
	int respuesta;

	initLugarLibrePantalla(aPantallas,QTY_PANTALLAS);
	initLugarLibrePublicidad(aPublicidad,QTY_PUBLICIDAD);





	do{
		printf("------------BIENVENIDO-----------\n"
				"Por favor, selecciona una opcion: \n"
				"1-Alta pantalla\n"
				"2-Modificar pantalla\n"
				"3-Baja pantalla\n"
				"4-Alta publicidad\n"
				"10-Salir\n");

		scanf("%d",&opcion);


		switch(opcion)
		{
			case 1: getString(bPantalla.nombre,"Nombre de la pantalla?\n","Error",2,20,3);
					altaPantallaPorId(aPantallas,QTY_PANTALLAS,bPantalla);
					printf("Alta exitosa!\n");
					break;

			case 2: getInt(&idAux,"Ingrese el ID de la pantalla a modificar:\n","Error",0,101,3);
					buscarPantallaPorId(aPantallas,QTY_PANTALLAS,idAux);
					printf("Pantalla encontrada: %d - %s\n",aPantallas[idAux].idPantalla, aPantallas[idAux].nombre);
					getString(bPantalla.nombre,"Ingresa el nuevo nombre: \n","Error",0,101,3);
					bPantalla.idPantalla = aPantallas[idAux].idPantalla;
					modificarPantallaPorId(aPantallas,QTY_PANTALLAS,bPantalla);
					printf("Pantalla modificada!\n");
					break;


			case 3: getInt(&idAux,"Ingrese el ID de la pantalla a eliminar:\n","Error",0,101,3);
					buscarPantallaPorId(aPantallas,QTY_PANTALLAS,idAux);
					printf("Pantalla encontrada: %d - %s\n",aPantallas[idAux].idPantalla, aPantallas[idAux].nombre);
					getInt(&respuesta,"Desea eliminar?\n 1-si\n2-no\n","Error",0,100,3);
					if(respuesta == 1)
					{
						bajaPantallaPorId(aPantallas,QTY_PANTALLAS,idAux);
						printf("Baja exitosa!\n");
					}
					break;

			case 4: imprimirArrayPantallas(aPantallas,10);
					getInt(&bPublicidad.idPantalla,"Ingrese el ID de la pantalla:\n","Error",0,100,3);
					getString(bPublicidad.cuit,"Ingrese el cuit de la publicidad:\n","Error",0,1000,3);
					getString(bPublicidad.nombreArchivo,"Ingrese el nombre del archivo: \n","Error",0,1000,3);
					altaPublicidadPorId(aPublicidad,QTY_PUBLICIDAD,bPublicidad);

			}

		}while(opcion != 10);

	imprimirArrayPantallas(aPantallas,5);
	imprimirArrayPublicidad(aPublicidad,5);

	return EXIT_SUCCESS;
}
