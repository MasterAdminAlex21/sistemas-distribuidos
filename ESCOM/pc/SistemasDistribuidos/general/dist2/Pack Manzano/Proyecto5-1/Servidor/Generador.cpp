#include "Generador.h"

Generador::Generador( int n_, int opc_ ){
	j = 1;
	n = n_;
	opc = opc_;
	srand(getpid());

	partidos[0] = "PRI";
	partidos[1] = "PAN";
	partidos[2] = "PRD";
	partidos[3] = "P_T";
	partidos[4] = "VDE";
	partidos[5] = "MVC";
	partidos[6] = "NVA";
	partidos[7] = "MOR";
	partidos[8] = "HUM";
	partidos[9] = "ENC";

	string nombre = "";
	nombre += (char)(n + 48);
	nombre += ".txt";
	arc = new Archivo( nombre.c_str(), O_WRONLY|O_TRUNC|O_CREAT, 0666 );

	fraude = (int)((double)n / ( (double)(n * PORCENTAJE) / 100.0 ));

	reg.celular = generaTel();
	reg.CURP = generaCurp();
	reg.partido = partidos[ rand()%10 ];

	//printf("Tamaño de registro = %lu\n", sizeof(registro));
}

void Generador::genera(){
	switch(opc){
		case 1: //Opcion 1
			reg.celular = generaTel();
			reg.CURP = generaCurp();
			reg.partido = partidos[ rand()%10 ];
			arc->escribe( (char *) &reg, sizeof(registro) );
		break;
		case 2: //Opcion 2 fraude con telefono, mismo telefono, distinta CURP en 10% de los casos
			if( j % fraude != 0)
				reg.celular = generaTel();
			reg.CURP = generaCurp();
			reg.partido = partidos[ rand()%10 ];
			arc->escribe( (char *) &reg, sizeof(registro) );
		break;
		case 3: //Opcion 3 fraude con CURP, distinto telefono, misma CURP en 10% de los casos
			for(int j = 0; j < n; j++){
				reg.celular = generaTel();
				if( j % fraude != 0)
					reg.CURP = generaCurp();
				reg.partido = partidos[ rand()%10 ];
				arc->escribe( (char *) &reg, sizeof(registro) );
			}
		break;
		default:
			printf("Opción incorrecta\n");
			exit(0);
	}
	cout << reg.celular << " " << reg.CURP << " " << reg.partido << endl;
}

string Generador::generaTel(){
	string tel;
	do{
		tel = "";
		for( int i = 0; i < 9; i++ ){
			tel += (char) (rand()%10 + 48);
		}
		tel += (char)(n + 48);
	}
	while( telefono.count( tel ) != 0 );
	telefono.insert( tel );
	return tel;
}

string Generador::generaCurp(){
	string cur;
	do{
		cur = "";
		for( int i = 0; i < 4; i++ ){
			cur += (char) (rand()%26 + 65);
		}
		for( int i = 0; i < 6; i++ ){
			cur += (char) (rand()%10 + 48);
		}
		for( int i = 0; i < 6; i++ ){
			cur += (char) (rand()%26 + 65);
		}
		cur += (char) (rand()%10 + 48);
		cur += (char) (n + 48);
	}
	while( curp.count( cur ) != 0 );
	curp.insert( cur );
	return cur;
}