/*
 ============================================================================
 Name        : clase_09.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#define QTY_EMPLEADOS 10

int main(void) {

	struct sEmpleado aEmpleados[QTY_EMPLEADOS];
	struct sEmpleado bEmpleado;
	int idEmpleado = 0;
	int opcion;

	initLugarLibreEmpleado(aEmpleados,QTY_EMPLEADOS);
	//imprimirArrayEmpleados(aEmpleados,QTY_EMPLEADOS);

	do{
	printf("Por favor, selecciona una opción: \n"
			"1-Alta empleado\n"
			"2-Modificar empleado\n"
			"3-Baja empleado\n"
			"4-Salir\n");

	scanf("%d",&opcion);


	switch(opcion)
	{
	case 1:	getString(bEmpleado.nombre,"Ingrese el nombre:","Error",2,10,3);
			getString(bEmpleado.apellido,"Ingrese el apellido:","Error",2,10,3);
			bEmpleado.idEmpleado = idEmpleado;
			bEmpleado.status = STATUS_NOT_EMPTY;
			idEmpleado++;
			altaEmpleadoPorId(aEmpleados,QTY_EMPLEADOS,bEmpleado);
			printf("Alta exitoso!\n");
			break;

	case 3: bajaEmpleadoPorId(aEmpleados,QTY_EMPLEADOS,1);
			printf("Baja exitosa!");

	}

	imprimirArrayEmpleados(aEmpleados,QTY_EMPLEADOS);

	}while(opcion != 4);

	return EXIT_SUCCESS;
}
