#ifndef PANTALLA_H_
#define PANTALLA_H_


#define QTY_PANTALLAS 100
#define QTY_CONTRATACIONES 1000
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sPantalla{

	int idPantalla;
	int status;

	int tipo;
	char nombre[50];
	char direccion[50];
	float precio;

};



int initLugarLibrePantalla(struct sPantalla *aArray, int cantidad);

int imprimirArrayPantallas(struct sPantalla *aPantalla, int cantidad);

int buscarLugarLibrePantalla(struct sPantalla *aArray, int cantidad);


int altaPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla pantalla);

int buscarPantallaPorId(struct sPantalla *aArray, int cantidad,int id);

int bajaPantallaPorId(struct sPantalla *aArray, int cantidad,int id);

int modificarPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla pantalla);



#endif /* PANTALLA_H_ */
