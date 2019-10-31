

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct {

	int idCliente;
	int status;

	char nombre[50];
	char direccion[50];
	char cuit[30];
	char localidad[50];

} Cliente;

Cliente* new_Cliente();
int cli_setNombre(Cliente* this, char* nombre);
int cli_setDireccion(Cliente* this, char* direccion);
int cli_setCuit(Cliente* this, char* cuit);
int cli_setLocalidad(Cliente* this, char* localidad);
int cli_setId(Cliente* this, int idCliente);


#endif /* CLIENTE_H_ */
