#include "SocketDatagrama.h"
#ifndef SOLICITUD_H_
#define SOLICITUD_H_
class Solicitud
{
	public:
		Solicitud();
		int doOperation(char *IP, int puerto,int rid,int n, char*filedata);
	private:
		SocketDatagrama *socketlocal;
};
#endif