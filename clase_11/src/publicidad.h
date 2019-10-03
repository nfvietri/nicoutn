#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_

#define QTY_PUBLICIDAD 1000
#define QTY_CARACTERES 50
#define QTY_PANTALLAS 100
#define QTY_CONTRATACIONES 1000
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sPublicidad{

	int idPublicidad;
	int status;

	char cuit[30];
	int cantidadDias;
	char nombreArchivo[50];
	int idPantalla;

};

int initLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad);

int altaPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad publicidad);

int imprimirArrayPublicidad(struct sPublicidad *aPublicidad, int cantidad);

int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad);

int listarPantallasPorCuit(struct sPublicidad *aPublicidad, struct sPantalla *aPantalla, int cantidad, char *cuit);

int imprimirPantallaPorId(struct sPantalla *aPantalla, int cantidad, int id);

int listarContrataciones(struct sPublicidad *aPublicidad, int cantidad, struct sPantalla *aPantalla);

int importeMasAltoFact(char *cuitMasAlto, struct sPublicidad *aPublicidad, int cantidad, struct sPantalla *aPantalla);

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);

#endif /* PUBLICIDAD_H_ */
