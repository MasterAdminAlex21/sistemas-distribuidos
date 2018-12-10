#ifndef HEADER_H_
#define HEADER_H_

struct registro{
	string celular;
	string CURP;
	string partido;
};

struct peticion{
	int tipo;
	string buscar;
};

struct voto{
	string partido;
	int num;
};

struct respuesta{
	int tipo;
	voto v[10];
	string partido;
};

#endif