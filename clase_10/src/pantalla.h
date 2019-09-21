

#define QTY_PANTALLAS 100
#define QTY_CONTRATACIONES 1000
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sPantalla{

	int idPantalla;
	int status;

	char tipo;
	char nombre[50];
	char direccion[50];

};

int initLugarLibrePantalla(struct sPantalla *aArray, int cantidad);

int imprimirArrayPantallas(struct sPantalla *aPantalla, int cantidad);

int buscarLugarLibrePantalla(struct sPantalla *aArray, int cantidad);

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);

int altaPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla pantalla);

int buscarPantallaPorId(struct sPantalla *aArray, int cantidad,int id);

int bajaPantallaPorId(struct sPantalla *aArray, int cantidad,int id);

int modificarEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado);

int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

static int generarId(void);

