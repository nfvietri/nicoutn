#define QTY_CARACTERES 50

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);

int esNumerico(char array[]);

int esSoloLetras(char array[]);

int esAlfanumerico(char array[]);

int esTelefono(char array[]);

int imprimirArrayString(char array[][QTY_CARACTERES], int cantidad);

int ordenarArrayString(char arrayNombres[][QTY_CARACTERES],char arrayDNI[][QTY_CARACTERES], int cantidad);


