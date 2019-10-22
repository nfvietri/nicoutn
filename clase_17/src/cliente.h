

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct {

	int idCliente;
	int status;
	//------
	char nombre[50];
	char direccion[50];
	char cuit[30];
	char localidad[50];

} Cliente;


#endif
