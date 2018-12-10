//#define TAM_MAX_DATA 4000
#define TAM_MAX_DATA 4000
typedef struct
{
	//int messageType;      //0= Solicitud, 1 = Respuesta
	unsigned int requestId; //Identificador del mensaje
	char IP[16];
	int puerto;
	int n;
	char arguments[TAM_MAX_DATA];

} mensaje;