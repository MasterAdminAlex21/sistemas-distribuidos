#include <bits/stdc++.h>
#include "archivo.h"
#include "LeerDirectorio.h"
using namespace std;

int main() {
	string CARPETA = "libros_pruebas/";
	
	LeerDirectorio folder("./" + CARPETA);
	auto libros = folder.evaluar();
	sort(libros.begin(), libros.end());

	for (const auto& nombre : libros) {
		cout << nombre << endl;
	}

	Archivo a(CARPETA + libros[0]);
	Archivo b(CARPETA + libros[1]);

	auto ans = a.maxima_coincidencia(b);
	cout << "\n\nCadena(s) entre el archivo " << a.getNombre() << " y " << b.getNombre() 
		 << " con el mayor numero de tokens(" << ans.second << "):\n\n";

	int cont = 1;
	for (const auto& cad : ans.first)
		cout << "CADENA " << cont++ << '<' << cad << ">\n";

	return 0;
}
