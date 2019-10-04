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
#include "utn.h"
#include <string.h>

int main(void) {



	struct sPantalla aPantallas[QTY_PANTALLAS];
	struct sPantalla bPantalla;
	struct sPublicidad aPublicidad[QTY_PUBLICIDAD];
	struct sPublicidad bPublicidad;
	int idAux;
	int opcion;
	int respuesta;
	int prueba;

	initLugarLibrePantalla(aPantallas,QTY_PANTALLAS);
	initLugarLibrePublicidad(aPublicidad,QTY_PUBLICIDAD);

	do{
		printf("------------BIENVENIDO-----------\n"
				"Por favor, selecciona una opcion: \n"
				"1-Alta pantalla\n"
				"2-Modificar pantalla\n"
				"3-Baja pantalla\n"
				"4-Alta publicidad\n"
				"5-Modificar condiciones publicaci�n\n"
				"6-Cancelar contrataci�n\n"
				"7-Consulta facturaci�n\n"
				"8-Listar contrataciones\n"
				"9-Imprimir\n"
				"10-Informes\n"
				"20-Salir\n");

		scanf("%d",&opcion);


		switch(opcion)
		{
			case 1: getString(bPantalla.nombre,"Nombre de la pantalla?\n","Error",2,20,3);
					getString(bPantalla.direccion,"direccion de la pantalla?\n","Error",2,20,3);
					getFloat(&bPantalla.precio, "Precio?\n", "Error", 0, 2000000, 3);
					getInt(&bPantalla.tipo, "Tipo de pantalla? 1-LED 2-LCD\n", "Error", 0, 3, 3);
					altaPantallaPorId(aPantallas,QTY_PANTALLAS,bPantalla);
					printf("Alta exitosa!\n");
					break;

			case 2: imprimirArrayPantallas(aPantallas,5);
					getInt(&idAux,"Ingrese el ID de la pantalla a modificar:\n","Error",0,101,3);
					buscarPantallaPorId(aPantallas,QTY_PANTALLAS,idAux);
					printf("Pantalla encontrada: %d - %s\n",aPantallas[idAux].idPantalla, aPantallas[idAux].nombre);
					getString(bPantalla.nombre,"Ingresa el nuevo nombre: \n","Error",0,101,3);
					getString(bPantalla.direccion,"direccion nueva\n","Error",2,20,3);
					getFloat(&bPantalla.precio, "Precio nuevo?\n", "Error", 0, 2000000, 3);
					getInt(&bPantalla.tipo, "Tipo de pantalla? 1-LED 2-LCD\n", "Error", 0, 3, 3);
					bPantalla.idPantalla = aPantallas[idAux].idPantalla;
					modificarPantallaPorId(aPantallas,QTY_PANTALLAS,bPantalla);
					printf("Pantalla modificada!\n");
					break;


			case 3: imprimirArrayPantallas(aPantallas,5);
					getInt(&idAux,"Ingrese el ID de la pantalla a eliminar:\n","Error",0,101,3);
					buscarPantallaPorId(aPantallas,QTY_PANTALLAS,idAux);
					printf("Pantalla encontrada: %d - %s\n",aPantallas[idAux].idPantalla, aPantallas[idAux].nombre);
					getInt(&respuesta,"Desea eliminar?\n 1-si\n2-no\n","Error",0,100,3);
					if(respuesta == 1)
					{
						bajaPantallaPorId(aPantallas,QTY_PANTALLAS,idAux);
						printf("Baja exitosa!\n");
					}
					break;

			case 4: imprimirArrayPantallas(aPantallas,5);
					getInt(&idAux,"Ingrese el ID de la pantalla donde va a publicar:\n","Error",0,101,3);
					buscarPantallaPorId(aPantallas, 5, idAux);
					printf("Pantalla encontrada: %d - %s\n",aPantallas[idAux].idPantalla, aPantallas[idAux].nombre);
					getString(bPublicidad.cuit,"Ingrese el cuit: \n","Error",0,50,3);
					getInt(&bPublicidad.cantidadDias,"Ingrese cantidad de d�as: \n","Error",0,50,3);
					getString(bPublicidad.nombreArchivo,"Ingrese el nombre del archivo: \n","Error",0,50,3);
					bPublicidad.idPantalla = idAux;
					altaPublicidadPorId(aPublicidad,QTY_PUBLICIDAD,bPublicidad);
					printf("Alta exitosa!\n");
					break;

			case 5:	getString(bPublicidad.cuit, "ingresa el cuit:\n", "Error", 2, 15, 3);
					listarPantallasPorCuit(aPublicidad, aPantallas, 10, bPublicidad.cuit);
					idAux = getInt(&bPublicidad.idPantalla, "Ingrese el id que desea modificar:\n","Error",0,100,3);
					getInt(&bPublicidad.cantidadDias,"Ingrese la nueva cantidad de dias:\n","Error",0,100,3);
					aPublicidad[idAux].cantidadDias = bPublicidad.cantidadDias;
					printf("Cantidad de d�as modificado!\n");
					break;

			case 6:	getString(bPublicidad.cuit, "ingresa el cuit:\n", "Error", 2, 15, 3);
					listarPantallasPorCuit(aPublicidad, aPantallas, 10, bPublicidad.cuit);
					idAux = getInt(&bPublicidad.idPantalla, "Ingrese el id que desea dar de baja:\n","Error",0,100,3);
					aPublicidad[idAux].status = 0;
					printf("Baja exitosa!");
					break;

			case 7: getString(bPublicidad.cuit, "ingresa el cuit:\n", "Error", 2, 15, 3);
					listarPantallasPorCuit(aPublicidad, aPantallas, 10, bPublicidad.cuit);
					break;

			case 8: listarContrataciones(aPublicidad,10,aPantallas);
					break;

			case 9: imprimirArrayPantallas(aPantallas,5);
					printf("array publicidad\n");
					imprimirArrayPublicidad(aPublicidad,5);
					break;

			case 10: idAux = idImporteMasAltoFact(aPantallas,10);
					 imprimirPublicidadPorIdPantalla(aPublicidad, 10, idAux);

			}


		}while(opcion != 20);




	return EXIT_SUCCESS;
}


