#include"random_local.h"
void inicializa_random(long semilla){
 srandom(semilla);
}

double obtiene_siguiente_random(void){
 return random();
}
