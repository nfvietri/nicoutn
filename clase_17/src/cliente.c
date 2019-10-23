#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cliente.h"


Cliente* new_Cliente()
{
	return malloc(sizeof(Cliente));
}

void delete_Cliente(Cliente* this)
{
	free(this);
}

Cliente* new_ClienteParametros(int idCliente, int status, char nombre, char direccion, char cuit, char localidad)
{
	Cliente* retorno = NULL;
	Cliente* this;
	this = new_Cliente();

	if(this!=NULL)
	{
		if(cli_setNombre(this,nombre) == 0 &&
		   cli_setDireccion(this,direccion) == 0 &&
		   cli_setCuit(this,cuit) == 0 &&
		   cli_setLocalidad(this,localidad) == 0)
		{
			retorno = this;
		} else {
			delete_Cliente(this);
		}
	}

	return retorno;
}




int



int cli_setNombre(Cliente *this, char nombre)
{
	int retorno = -1;

	if(this!=NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int cli_getNombre(Cliente *this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}

static int isValidNombre(char *nombre)
{
	return 1;
}


int cli_setDireccion(Cliente *this, char direccion)
{
	int retorno = -1;

	if(this!=NULL && isValidDireccion(direccion))
	{
		strcpy(this->direccion, direccion);
		retorno = 0;
	}

	return retorno;
}

int cli_getDireccion(Cliente *this, char* direccion)
{
	int retorno = -1;

	if(this != NULL && direccion != NULL)
	{
		strcpy(direccion,this->direccion);
		retorno = 0;
	}

	return retorno;
}

static int isValidDireccion(char *direccion)
{
	return 1;
}


int cli_setCuit(Cliente *this, char cuit)
{
	int retorno = -1;

	if(this!=NULL && isValidCuit(cuit))
	{
		strcpy(this->cuit, cuit);
		retorno = 0;
	}

	return retorno;
}

int cli_getCuit(Cliente *this, char* cuit)
{
	int retorno = -1;

	if(this != NULL && cuit != NULL)
	{
		strcpy(cuit,this->cuit);
		retorno = 0;
	}

	return retorno;
}

static int isValidCuit(char *cuit)
{
	return 1;
}


int cli_setLocalidad(Cliente *this, char localidad)
{
	int retorno = -1;

	if(this!=NULL && isValidLocalidad(localidad))
	{
		strcpy(this->localidad, localidad);
		retorno = 0;
	}

	return retorno;
}

int cli_getLocalidad(Cliente *this, char* localidad)
{
	int retorno = -1;

	if(this != NULL && localidad != NULL)
	{
		strcpy(localidad,this->localidad);
		retorno = 0;
	}

	return retorno;
}

static int isValidLocalidad(char *localidad)
{
	return 1;
}







