#include <stdlib.h>
#include <stdio.h>
#include "pant.h"
#include "utn.h"
#include <string.h>
#include "publicidad.h"

static int generarId(void)
{
	static int id = -1;
	id++;
	return id;
}


int initLugarLibrePantalla(struct sPantalla *aArray, int cantidad){
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0; i<cantidad; i++)
		{
			aArray[i].status = STATUS_EMPTY;
		}
	}

	return retorno;
}


int imprimirArrayPantallas(struct sPantalla *aPantalla, int cantidad){
	int i;
	int retorno = -1;
	if(aPantalla != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aPantalla[i].status != 0)
			{
				printf("Status: %d "
								"// Id: %d "
								"// Nombre: %s "
								"// Direccion: %s"
								"// Precio: %f"
								"// Tipo: %d\n"
								,aPantalla[i].status,
								aPantalla[i].idPantalla,
								aPantalla[i].nombre,
								aPantalla[i].direccion,
								aPantalla[i].precio,
								aPantalla[i].tipo);
			}

		}
	}
	return retorno;
}



int buscarLugarLibrePantalla(struct sPantalla *aArray, int cantidad)
{
	int index = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		for(i=0; i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_EMPTY)
			{
				index = i;
				break;
			}

		}

	}

	return index;
}


int altaPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla pantalla)
{
	int retorno = -1;
	int index;

	if(buscarLugarLibrePantalla(aArray,QTY_PANTALLAS) != -1)
	{
		index = buscarLugarLibrePantalla(aArray,cantidad);
		aArray[index] = pantalla;
		aArray[index].status = STATUS_NOT_EMPTY;
		aArray[index].idPantalla = generarId();
		retorno = 0;
	}

	return retorno;
}




int buscarPantallaPorId(struct sPantalla *aArray, int cantidad,int id)
{
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		for(i=0; i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY)
			{
				if(aArray[i].idPantalla == id)
				{
					retorno = i;
					break;
				}

			}

		}
	}

	return retorno;
}


int modificarPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla pantalla)
{
	int retorno;
	int i;

	for(i=0;i<cantidad;i++)
	{
		if(aArray[i].idPantalla == pantalla.idPantalla)
		{
			retorno = 0;
			strcpy(aArray[i].nombre, pantalla.nombre);
			break;
		}
	}

	return retorno;
}


int bajaPantallaPorId(struct sPantalla *aArray, int cantidad,int id)
{
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		retorno = 0;
		for(i=0; i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY)
			{
				if(aArray[i].idPantalla == id)
				{
					retorno = 0;
					aArray[i].status = STATUS_EMPTY;
					break;
				}
			}
		}


	}

	return retorno;
}



