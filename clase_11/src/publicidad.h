#define QTY_PUBLICIDAD 1000
#define QTY_CARACTERES 50

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

int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad);

int altaPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad pantalla);

int imprimirArrayPublicidad(struct sPublicidad *aPublicidad, int cantidad);



static int generarId(void);
