#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pedido.h"


typedef struct{

	int idPedido;
	int status;
	//------------

	int cantidadKilos;
	int idCliente;

} Pedido;


Pedido* new_Pedido()
{
	return malloc(sizeof(Pedido));
}

void delete_Pedido(Pedido* this)
{
	free(this);
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

static int isValidCantidadKilos(int *cantidadKilos)
{
	return 1;
}
