#include "pant.h"
#include "publicidad.h"
#include <stdlib.h>
#include <stdio.h>

#include <string.h>



static int generarId(void)
{
	static int id = -1;
	id++;
	return id;
}



int initLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad){
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0; i<cantidad; i++)
		{
			aArray[i].status = 0;
		}
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
			if(aPublicidad[i].status != 0)
			{
				printf("Status: %d "
								"// IdPublicidad: %d "
								"// Cuit: %s"
								"// Cantidad de días: %d"
								"// Nombre del Archivo: %s"
								"// IdPantalla: %d"
								"\n",aPublicidad[i].status,
								aPublicidad[i].idPublicidad,
								aPublicidad[i].cuit,
								aPublicidad[i].cantidadDias,
								aPublicidad[i].nombreArchivo,
								aPublicidad[i].idPantalla);
			}

		}
	}
	return retorno;
}

int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad)
{
	int index = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		for(i=0; i<cantidad; i++)
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

int listarPantallasPorCuit(struct sPublicidad *aPublicidad, struct sPantalla *aPantalla, int cantidad, char *cuit)
{
	int retorno = -1;
	int i;

	for(i=0;i<cantidad;i++)
	{
		if(aPublicidad[i].status != 0){

			if(strncmp(aPublicidad[i].cuit, cuit, 50) == 0)
					{
						retorno = 0;
						imprimirPantallaPorId(aPantalla, cantidad, aPublicidad[i].idPantalla);
					}
		}


	}


	return retorno;
}

int imprimirPantallaPorId(struct sPantalla *aPantalla, int cantidad, int id)
{
	int retorno = -1;
	int i;

	for(i=0;i<cantidad;i++)
	{
		if(aPantalla[i].idPantalla == id)
		{
			retorno = 0;
			printf("Id: %d // Nombre: %s // A pagar: %f \n", aPantalla[i].idPantalla, aPantalla[i].nombre, aPantalla[i].precio);
		}
	}


	return retorno;
}

int listarContrataciones(struct sPublicidad *aPublicidad, int cantidad, struct sPantalla *aPantalla)
{
	int retorno = -1;
	int i;
	int index;

	for(i=0;i<cantidad;i++)
	{
		if(aPublicidad[i].status != 0)
		{
			retorno = 0;
			index = aPublicidad[i].idPantalla;
			printf("Nombre pantalla: %s // Nombre del video: %s // Cantidad de días: %d // Cuit cliente: %s\n",
					aPantalla[index].nombre,
					aPublicidad[i].nombreArchivo,
					aPublicidad[i].cantidadDias,
					aPublicidad[i].cuit);
		}
	}



	return retorno;
}


int importeMasAltoFact(char *cuitMasAlto, struct sPublicidad *aPublicidad, int cantidad, struct sPantalla *aPantalla)
{
	int retorno = -1;
	int i;
	int index;


	for(i=0;i<cantidad;i++)
	{
		index = aPublicidad[i].idPantalla;
		if(aPantalla[index].precio > aPantalla[index+1].precio)
		{

			cuitMasAlto = aPublicidad[index].cuit;

		}
	}




	return retorno;
}
