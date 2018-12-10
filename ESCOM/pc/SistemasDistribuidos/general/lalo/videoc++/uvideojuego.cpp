/* Para compilar use:
gcc gfxModified.c -c
gcc final_ukranio1.c -c
gcc final_ukranio1.o gfxModified.o -o final_ukranio1 -lX11 -lm

libreria original gfx:
https://www3.nd.edu/~dthain/courses/cse20211/fall2013/gfx/
Tomado de: https://github.com/PatMyron/slime-volleyball
Originally created by Patrick Myron and Anna McMahon
Further Modified by Ukranio Coronilla
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include "gfxModified.h"

using namespace std;

//Resolución de la pantalla
#define ANCHURA 800
#define ALTURA 600

bool tecla[6];  //Arreglo para saber si una tecla de dirección se ha presionado

class Agente{
    private:
        float x;
        float y; //posicion
    
        float vx; //velocidad
        float vy;
        
        int r;  //radio
        int color[3]; //Color del agente
    public:
        Agente(float, float, float, float, int, int[3]);
        void  mueveAgente(Agente &ag, bool*);
        void  validaMovimientoAgente(Agente &ag);
        void setpx(float);
        void setpy(float);
        void setvx(float);
        void setvy(float);
        void setr(int);
        float getpx();
        float getpy();
        float getvx();
        float getvy();
        int getr();
};

Agente :: Agente(float px, float py, float vxx, float vyy, int rr, int colorr[3]){
    x = px;
    y = py;
    vx = vxx;
    vy = vyy;
    r = rr;
    color[0] = colorr[0];
    color[1] = colorr[1];
    color[2] = colorr[2];
}

void Agente :: setpx(float a) {
    x = a;
}

void Agente :: setpy(float a) {
    y = a;
}

void Agente :: setvx(float a) {
    vx = a;
}

void Agente :: setvy(float a) {
    vy = a;
}

void Agente :: setr(int a) {
    r = a;
}

float Agente :: getpx() {
    return x;
}

float Agente :: getpy() {
    return y;
}

float Agente :: getvx() {
    return vx;
}

float Agente :: getvy(){
    return vy;
}

int Agente :: getr() {
    return r;
}


class Pelota{
    private:
        float x;
        float y; //posicion

        float vx; //velocidad
        float vy;    

        int r;  //radio
        int color[3];//Color de la pelota
    public:
        Pelota(float, float, float, float, int, int[3]);
        void muevePelota(Pelota &pe, Agente &ag);
        void checaColisiones(Pelota &pe, Agente &ag);
        void calculaDireccionPelota(Pelota &pe, Agente &ag);
        void setpx(float);
        void setpy(float);
        void setvx(float);
        void setvy(float);
        void setr(int);
        float getpx();
        float getpy();
        float getvx();
        float getvy();
        int getr();
};

Pelota :: Pelota(float px, float py, float vxx, float vyy, int rr, int colorr[3]){
    x = px;
    y = py;
    vx = vxx;
    vy = vyy;
    r = rr;
    color[0] = colorr[0];
    color[1] = colorr[1];
    color[2] = colorr[2];
}

void Pelota :: setpx(float a) {
    x = a;
}

void Pelota :: setpy(float a) {
    y = a;
}

void Pelota :: setvx(float a) {
    vx = a;
} 

void Pelota :: setvy(float a) {
    vy = a;
}

void Pelota :: setr(int a) {
    r = a;
}

float Pelota :: getpx() {
    return x;
}

float Pelota :: getpy() {
    return y;
}

float Pelota :: getvx() {
    return vx;
}

float Pelota :: getvy(){
    return vy;
}

int Pelota :: getr() {
    return r;
}


int main(int args, char *argv[]) {
    
    srand(time(NULL));
    int n = atoi(argv[1]);

    int col[3] = {255,255,255}; 
    int col2[3] = {87, 1, 2};
	
    Agente jugador(ANCHURA/4, ALTURA, 0, 0, 25, col2);
    vector <Pelota> balones;

    int i;

    for(i = 0; i < 6; i++)
        tecla[i] = false;   //Inicializa arreglo
    
    for(i = 0; i < n; i++){
        Pelota pel(rand()%ANCHURA, rand()%ALTURA, 0, 0, rand()%25 + 5, col);
        balones.push_back(pel);
    }


    gfx_open(ANCHURA, ALTURA, "Juego Pelotas");

    while(1) {
        if(gfx_event_waiting2()) {

            gfx_keyPress(tecla); //Obtiene la tecla que se ha presionado como siguiente evento
            
            jugador.mueveAgente(jugador,tecla);
            jugador.validaMovimientoAgente(jugador);            
        }
        
        for(int k = 0; k < n; k++)//muevePelota(pPelota, pJugador);
            balones[k].muevePelota(balones[k], jugador);

        for(int l = 0; l < n; l++) {//Dibuja la pelota
            gfx_color(col[0], col[1], col[2]);
            gfx_fill_arc(balones[l].getpx() - balones[l].getr(), balones[l].getpy() - balones[l].getr(), 2 * balones[l].getr(), 2 * balones[l].getr(), 0, 360*64);
        }

        //Dibuja al jugador 
        gfx_color(col2[0], col2[1], col2[2]);
        gfx_fill_arc(jugador.getpx() - jugador.getr(), jugador.getpy() - jugador.getr(), 2*jugador.getr(), 2*jugador.getr(), 0, 180*64);
       
		gfx_flush();
        usleep(18000);
    }
    return 0;
}

// Actualiza la velocidad y la posición de la pelota
void Pelota :: muevePelota(Pelota &pPelota, Agente &pAgente){
    //Checa para ver si la pelota colisiona con algo para cambiar su velocidad    
    checaColisiones(pPelota, pAgente);
    (pPelota.setvy(pPelota.getvy() + .08)); //Para simular la aceleración de la gravedad
    (pPelota.setpx((pPelota.getpx()) + (pPelota.getvx()))); //Cambios para x recordando v=d/t 
    (pPelota.setpy((pPelota.getpy()) + (pPelota.getvy())));
    gfx_clear();
}

//checa los bordes de la pelota y actualiza su localización, el vector velocidad   cambia si la pelota choca con algo.
void Pelota :: checaColisiones(Pelota &pPelota, Agente &pAgente){
    float distContacto, agenteBolaDist;
    
    if((pPelota.getpx() < pPelota.getr()) || (pPelota.getpx() > (ANCHURA - pPelota.getr())))  // colision lateral cambia al vector velocidad en x
        pPelota.setvx(-pPelota.getvx());
    if(pPelota.getpy() < pPelota.getr())   //colision en techo cambia el vector velocidad en y
        pPelota.setvy(-pPelota.getvy());
    if(pPelota.getpy() >= (ALTURA - pPelota.getr()))   //colision en piso
        pPelota.setvy(-pPelota.getvy());
    
    //distancia entre el centro del agente y la pelota
    agenteBolaDist=sqrtf(powf(pAgente.getpy() - pPelota.getpy(),2)+powf(pAgente.getpx() - pPelota.getpx(),2));
    //distancia minima permisible entre los centros del agente y la pelota
    distContacto = pAgente.getr() + pPelota.getr();
    //checa para ver si existe colision entre la pelota y el agente
    if(agenteBolaDist < distContacto)
        calculaDireccionPelota(pPelota,pAgente);
}

//Cambia la dirección de la pelota de acuerdo a las leyes de la física
void Pelota :: calculaDireccionPelota(Pelota &Bola, Agente &Jugador){ 
    //la velocidad absoluta de la pelota se inicializa a 10 después de que choca con la raqueta debido
    //a que de no hacerlo se movería mas lento cada vez
    float velocidadAbsoluta = 10;
    float pendienteEntreCentros;
    float difCentrosX,difCentrosY;
    float anguloEntreCentros;

    difCentrosX = Bola.getpx() - Jugador.getpx();
    difCentrosY = Bola.getpy() - Jugador.getpy();
    //Aunque puede existir un denominador igual a cero, y pendiente infinita la función arco tangente si resuelve con argumento infinito
    pendienteEntreCentros = difCentrosY / difCentrosX ;
    anguloEntreCentros = atanf(pendienteEntreCentros);
    if(difCentrosX < 0 && difCentrosY < 0)
        anguloEntreCentros += acosf(-1.0); // Ajusta la restricción del angulo sumandole PI = 3.14159...
            
    Bola.setvx(velocidadAbsoluta * cosf(anguloEntreCentros));
    Bola.setvy(velocidadAbsoluta * sinf(anguloEntreCentros));
}

//Lee el arreglo tecla para realizar un movimiento a la izquierda o a la derecha dependiendo de la tecla que se presionó.
void Agente :: mueveAgente(Agente &pJugador, bool tecla[6]){

    if ( tecla[3] == 1 ){  // Si se presionó la tecla de mover a la izquierda
        pJugador.setpx(pJugador.getpx() - 10);
    }
    if ( tecla[5] == 1 ){  // Si se presionó la tecla de mover a la derecha
        pJugador.setpx(pJugador.getpx() + 10);
    }
    gfx_flush();
}

//Después de que se ha presionado una tecla, la función se asegura que el agente no se ha salido de la pantalla
void Agente :: validaMovimientoAgente(Agente &pAgente){
    
    //Limita al agente por la orilla derecha
    if((pAgente.getpx()) > (ANCHURA - pAgente.getr())){
        pAgente.setpx(ANCHURA - pAgente.getr());
    }
    //Limita al agente por la orilla izquierda
    if((pAgente.getpx()) < (pAgente.getr())){
        pAgente.setpx(pAgente.getr());
    }
    
}//end func

