/*
 * pedido.h
 *
 *  Created on: 22 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_

typedef struct{

	int idPedido;
	int status;
	//------------

	int cantidadKilos;
	int cantidadHDPE;
	int cantidadLDPE;
	int cantidadPP;
	int idCliente;

} Pedido;

#endif /* PEDIDO_H_ */
