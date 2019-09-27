#include <stdlib.h>
#include <stdio.h>
#include "publicidad.h"
#include <string.h>


int initLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad){
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

int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad){
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].status == STATUS_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad publicidad)
{
	int retorno = -1;
	int index;

	if(buscarLugarLibrePublicidad(aArray,QTY_PUBLICIDAD) != -1)
	{
		index = buscarLugarLibrePublicidad(aArray,cantidad);
		aArray[index] = publicidad;
		aArray[index].status = STATUS_NOT_EMPTY;
		aArray[index].idPublicidad = generarId();
		retorno = 0;

	}

	return retorno;
}


int imprimirArrayPublicidad(struct sPublicidad *aPublicidad, int cantidad){
	int i;
	int retorno = -1;
	if(aPublicidad != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Status: %d - IdPublicidad: %d - Nombre archivo: %s - IdPantalla: %d\n",aPublicidad[i].status, aPublicidad[i].idPublicidad,aPublicidad[i].nombreArchivo,aPublicidad[i].idPantalla);
		}
	}
	return retorno;
}

static int generarId(void)
{
	static int id = -1;
	id++;
	return id;
}
