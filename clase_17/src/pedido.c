#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pedido.h"



Pedido* new_Pedido()
{
	return malloc(sizeof(Pedido));
}

void delete_Pedido(Pedido* this)
{
	free(this);
}

Pedido* new_PedidoConParametros(int cantidadKilos, int cantidadHDPE, int cantidadLDPE, int cantidadPP, int idCliente)
{
	Pedido* retorno = NULL;
	Pedido* this;
	this = new_Pedido();

	if(ped_setCantidadKilos(this,cantidadKilos) == 0 &&
       ped_setCantidadHDPE(this,cantidadHDPE) == 0 &&
	   ped_setCantidadLDPE(this,cantidadLDPE) == 0 &&
	   ped_setCantidadPP(this,cantidadPP) == 0 &&
	   ped_setIdCliente(this,idCliente) == 0)
	{
		retorno = this;
	} else {
		delete_Pedido(this);
	}

	return retorno;
}



int ped_setCantidadKilos(Pedido* this, int cantidadKilos)
{
	int retorno = -1;

	if(this != NULL && isValidCantidadKilos(cantidadKilos))
	{
		this->cantidadKilos = cantidadKilos;
		retorno = 0;
	}

	return retorno;
}


int ped_getCantidadKilos(Pedido *this, int* cantidadKilos)
{
	int retorno = -1;

	if(this != NULL && cantidadKilos != NULL)
	{
		*cantidadKilos = this->cantidadKilos;
		retorno = 0;
	}

	return retorno;
}


static int isValidCantidadKilos(int *cantidadKilos)
{
	return 1;
}



int ped_setCantidadHDPE(Pedido* this, int cantidadHDPE)
{
	int retorno = -1;

	if(this != NULL && isValidCantidadHDPE(cantidadHDPE))
	{
		this->cantidadHDPE = cantidadHDPE;
		retorno = 0;
	}

	return retorno;
}


int ped_getCantidadHDPE(Pedido *this, int* cantidadHDPE)
{
	int retorno = -1;

	if(this != NULL && cantidadHDPE != NULL)
	{
		*cantidadHDPE = this->cantidadHDPE;
		retorno = 0;
	}

	return retorno;
}


static int isValidCantidadHDPE(int *cantidadHDPE)
{
	return 1;
}




int ped_setCantidadLDPE(Pedido* this, int cantidadLDPE)
{
	int retorno = -1;

	if(this != NULL && isValidCantidadLDPE(cantidadLDPE))
	{
		this->cantidadLDPE = cantidadLDPE;
		retorno = 0;
	}


	return retorno;
}


int ped_getCantidadLDPE(Pedido *this, int* cantidadLDPE)
{
	int retorno = -1;

	if(this != NULL && cantidadLDPE != NULL)
	{
		*cantidadLDPE = this->cantidadLDPE;
		retorno = 0;
	}

	return retorno;
}


static int isValidCantidadLDPE(int *cantidadLDPE)
{
	return 1;
}




int ped_setCantidadPP(Pedido* this, int cantidadPP)
{
	int retorno = -1;

	if(this != NULL && isValidCantidadPP(cantidadPP))
	{
		this->cantidadPP = cantidadPP;
		retorno = 0;
	}

	return retorno;
}


int ped_getCantidadPP(Pedido *this, int* cantidadPP)
{
	int retorno = -1;

	if(this != NULL && cantidadPP != NULL)
	{
		*cantidadPP = this->cantidadPP;
		retorno = 0;
	}

	return retorno;
}


static int isValidCantidadPP(int *cantidadPP)
{
	return 1;
}




int ped_setIdCliente(Pedido* this, int idCliente)
{
	int retorno = -1;

	if(this != NULL && isValidIdCliente(idCliente))
	{
		this->idCliente = idCliente;
		retorno = 0;
	}

	return retorno;
}


int ped_getIdCliente(Pedido *this, int* idCliente)
{
	int retorno = -1;

	if(this != NULL && idCliente != NULL)
	{
		*idCliente = this->idCliente;
		retorno = 0;
	}

	return retorno;
}


static int isValidIdCliente(int *idCliente)
{
	return 1;
}
