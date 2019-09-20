#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "pantalla.h"
#include <string.h>

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
			printf("Status: %d - Id: %d - Nombre: %s \n",aPantalla[i].status, aPantalla[i].idPantalla,aPantalla[i].nombre);
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

	}

	return retorno;
}


int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
			{
				printf("%s",pMensaje);
				__fpurge(stdin);
				fgets(buffer,sizeof(buffer),stdin);
				buffer[strlen(buffer)-1] = '\0';
				if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
				{
					strncpy(pResultado,buffer,maximo+1);
					retorno = 0;
					break;
				}
				printf("%s",pMensajeError);
				reintentos--;
			}while(reintentos >= 0);
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


int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = -1;
	int buffer;
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin); // fflush
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = 0;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}


static int generarId(void)
{
	static int id = 0;
	id++;
	return id;
}
