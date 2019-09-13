/*
 ============================================================================
 Name        : clase_08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//PARA PROXIMA CLASE
//hacer empleados.c y empleados.h, funciones para ordenar, incluir el struct, agregar DNI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 10
#define QTY_CARACTERES 50
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sEmpleado
{
	int idEmpleado;
	int status;
	//***************
	char nombre[50];
	char apellido[50];
};

int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int ordenarArrayEmpleadosAsc(struct sEmpleado *aEmpleado, int cantidad);
int ordenarArrayEmpleadosDes(struct sEmpleado *aEmpleado, int cantidad);


int main(void)
{

	struct sEmpleado aEmpleados[1000];
	struct sEmpleado bEmpleado;
	int i;
	int idEmpleado = 0;

	for(i=0;i<3;i++){

		getString(bEmpleado.nombre,"Ingrese el nombre",
				"ERROR", 1, 49, 2);

		getString(bEmpleado.apellido,"Ingrese el apellido",
						"ERROR", 1, 49, 2);

		bEmpleado.idEmpleado = idEmpleado;
		idEmpleado++;
		bEmpleado.status = STATUS_NOT_EMPTY;

		aEmpleados[i] = bEmpleado;
	}
	imprimirArrayEmpleados(aEmpleados,3);
	printf("Orden ascendente\n");
	ordenarArrayEmpleadosAsc(aEmpleados,3);
	imprimirArrayEmpleados(aEmpleados,3);
	printf("Orden descendente\n");
	ordenarArrayEmpleadosDes(aEmpleados,3);
	imprimirArrayEmpleados(aEmpleados,3);

	return EXIT_SUCCESS;
}

int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Id: %d - Nombre: %s - Apellido: %s \n",aEmpleado[i].idEmpleado,aEmpleado[i].nombre,aEmpleado[i].apellido);
		}
	}
	return retorno;
}

int ordenarArrayEmpleadosAsc(struct sEmpleado *aEmpleado, int cantidad)
{
	int retorno = -1;
	int fSwap;
	int i;
	struct sEmpleado buffer;

	if(aEmpleado != NULL && cantidad > 0)
	{
		retorno = 0;
		do{
			fSwap = 0;
			for(i = 0;i<cantidad-1;i++)
			{
				if((strncmp(aEmpleado[i].nombre, aEmpleado[i+1].nombre, QTY_CARACTERES)) > 0)
				{

					fSwap = 1;
					buffer = aEmpleado[i];
					aEmpleado[i] = aEmpleado[i+1];
					aEmpleado[i+1] = buffer;
				} else if((strncmp(aEmpleado[i].nombre, aEmpleado[i+1].nombre, QTY_CARACTERES)) == 0)
				{
					if((strncmp(aEmpleado[i].apellido, aEmpleado[i+1].apellido, QTY_CARACTERES)) > 0)
					{

						fSwap = 1;
						buffer = aEmpleado[i];
						aEmpleado[i] = aEmpleado[i+1];
						aEmpleado[i+1] = buffer;
					}
				}

			}

		}while(fSwap);

	}


	return retorno;

}


int ordenarArrayEmpleadosDes(struct sEmpleado *aEmpleado, int cantidad)
{
	int retorno = -1;
	int i;
	int fSwap;
	struct sEmpleado buffer;

	if(aEmpleado != NULL && cantidad > 0)
	{
		retorno = 0;

		do{
			fSwap = 0;
			for(i = 0; i<cantidad-1;i++)
			{
				if((strncmp(aEmpleado[i].nombre, aEmpleado[i+1].nombre, QTY_CARACTERES)) < 0)
				{

					fSwap = 1;
					buffer = aEmpleado[i];
					aEmpleado[i] = aEmpleado[i+1];
					aEmpleado[i+1] = buffer;

				} else if((strncmp(aEmpleado[i].nombre, aEmpleado[i+1].nombre, QTY_CARACTERES)) == 0)
				{
					if((strncmp(aEmpleado[i].apellido, aEmpleado[i+1].apellido, QTY_CARACTERES)) > 0)
				{

						fSwap = 1;
						buffer = aEmpleado[i];
						aEmpleado[i] = aEmpleado[i+1];
						aEmpleado[i+1] = buffer;
					}
				}

			}

		}while(fSwap);

	}
	return retorno;
}
