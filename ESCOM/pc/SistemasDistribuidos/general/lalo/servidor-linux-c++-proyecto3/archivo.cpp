#include "archivo.h"
using namespace std;

Archivo::Archivo(const string &A) {
   nombre = A;

   string lectura;
   ifstream flujo(nombre.c_str());

   if (flujo.is_open())
      while (getline(flujo, lectura))
         contenido += lectura;
   else
      cout << "El archivo no existe\n";
}

string Archivo::getNombre() {
   return nombre;
}

void Archivo::division_tokens(vector<string> &dest) {
   stringstream ss(contenido);
   string cad;

   while (ss >> cad)
      dest.push_back(cad);
}

pair< vector<int>, int> Archivo::maxima_coincidencia(Archivo b) {
   vector<string> primerTokens, segundoTokens;

   division_tokens(primerTokens);
   b.division_tokens(segundoTokens);

   vector< pair<int, int> > respuestas; 

   for (int i = 0; i < primerTokens.size(); ++i) {
      int j = 0;
      int ini = i;
      while (j < segundoTokens.size()) {
         bool match = false;
         while (ini < primerTokens.size() && j < segundoTokens.size() && primerTokens[ini] == segundoTokens[j])
            ini++, j++, match = true;
         if (ini > i)
            respuestas.push_back(make_pair(ini - i, i));
         ini = i;
         if (!match)
            j++;
      }
   }

   sort(respuestas.begin(), respuestas.end(), greater< pair<int, int> >());
   /*
   int maxi = respuestas[0].first;
   vector<string> frases;

   for (int i = 0; i < respuestas.size() && maxi == respuestas[i].first; ++i) {
      string valido = "";
      for (int j = 0; j < maxi; ++j)
         valido += primerTokens[respuestas[i].second + j] + " ";
      frases.push_back(valido);
   }
   */

   int maxi = respuestas[0].first;
   vector<int> frases;

   for (int i = 0; i < respuestas.size() && maxi == respuestas[i].first; ++i)
      frases.push_back(respuestas[i].second);

   return make_pair(frases, maxi);
}
