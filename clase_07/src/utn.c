#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utn.h"


int esNumerico(char array[])
{
	int i = 0;
	int retorno = 1;

	if(array != NULL)
	{
		while(array[i] != '\0')
		{
			if(array[i] < '0' || array [i] > '9')
			{
				retorno = 0;
			}

			i++;
		}
	}
	return retorno;
}

int esSoloLetras(char array[])
{
	int i = 0;
	int retorno = 1;

	if(array != NULL)
	{
		while(array[i] != '\0')
		{
			if(array[i] != ' ' && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z'))
			{
				retorno = 0;
			}
			i++;
		}
	}
	return retorno;
}

int esAlfanumerico(char array[])
{
	int i = 0;
	int retorno = 1;

	if(array != NULL)
	{
		while(array[i] != '\0')
		{
			if(array[i] != ' ' && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z') && (array[i] < '0' || array[i] > '9'))
			{
				retorno = 0;
			}
			i++;
		}
	}
	return retorno;
}

int esTelefono(char array[])
{
	int i = 0;
	int retorno = 1;
	int contadorGuiones = 0;
	if(array != NULL)
	{
		while(array != '\0')
		{
			if(array[i] != '-' && (array[i] < '0' || array[i] > '9'))
			{
				retorno = 0;
			}
			if(array[i] == '-')
			{
				contadorGuiones++;
			}
			i++;
		}

		if(contadorGuiones == 0 || contadorGuiones > 3){
			retorno = 0;
		}

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

int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad)
{
	int retorno;
	int i = 0;

	if(aNombres != NULL && cantidad > 0)
	{
		retorno = 0;
		for(i = 0;i<cantidad;i++)
		{
			printf("Nombre: %s\n", aNombres[i]);
		}
	}
	return retorno;

}

int ordenarArrayString(char aNombres[][QTY_CARACTERES], int cantidad)
{
	int retorno = -1;
	int i;
	int flagSwap;
	char auxiliar[QTY_CARACTERES];

	if(aNombres != NULL && cantidad>0)
	{
		retorno = 0;

		printf("---------------\n");

		do{

		flagSwap = 0;
		for(i=0;i<cantidad-1;i++)
		{
			if((strcmp(aNombres[i], aNombres[i+1])) > 0)
			{
				flagSwap = 1;
				strcpy(auxiliar, aNombres[i]);
				strcpy(aNombres[i],aNombres[i+1]);
				strcpy(aNombres[i+1], auxiliar);
			}
		}

		}while(flagSwap);
	}

	return retorno;
}
