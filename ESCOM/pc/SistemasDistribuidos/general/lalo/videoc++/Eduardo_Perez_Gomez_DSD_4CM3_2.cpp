/*
INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO

Proyecto 2: Mini video juego

Elaborado por: Eduardo Perez Gomez
Para la materia de: Diseño de sistemas distribuidos
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
#include <iostream>

using namespace std;

#define ANCHURA 800
#define ALTURA 600
bool tecla[6];

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

Agente::Agente(float b1, float b2, float x1, float x2, int r1, int c1[3]){
    x = b1;
    y = b2; //posicion
    vx = x1; //velocidad
    vy = x2;    
    r = r1;  //radio
    color[0] = c1[0]; //Color de la pelota
    color[1] = c1[1]; //Color de la pelota
    color[2] = c1[2]; //Color de la pelota
}

void Agente::setpx(float a) {
    x = a;
}

void Agente::setpy(float a) {
    y = a;
}

void Agente::setvx(float a) {
    vx = a;
}

void Agente::setvy(float a) {
    vy = a;
}

void Agente::setr(int a) {
    r = a;
}

float Agente::getpx() {
    return x;
}

float Agente::getpy() {
    return y;
}

float Agente::getvx() {
    return vx;
}

float Agente::getvy(){
    return vy;
}

int Agente::getr() {
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
        void muevePelotaD(Pelota &pe, Pelota &ag);
        void checaColisionesD(Pelota &pe, Pelota &ag);
        void calculaDireccionPelotaD(Pelota &pe, Pelota &ag);
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

Pelota::Pelota(float b1, float b2, float x1, float x2, int r1, int c1[3]){
    x = b1;
    y = b2; //posicion
    vx = x1; //velocidad
    vy = x2;    
    r = r1;  //radio
    color[0] = c1[0]; //Color de la pelota
    color[1] = c1[1]; //Color de la pelota
    color[2] = c1[2]; //Color de la pelota
}

void Pelota::setpx(float a) {
    x = a;
}

void Pelota::setpy(float a) {
    y = a;
}

void Pelota::setvx(float a) {
    vx = a;
} 

void Pelota::setvy(float a) {
    vy = a;
}

void Pelota::setr(int a) {
    r = a;
}

float Pelota::getpx() {
    return x;
}

float Pelota::getpy() {
    return y;
}

float Pelota::getvx() {
    return vx;
}

float Pelota::getvy(){
    return vy;
}

int Pelota::getr() {
    return r;
}

int main(int args, char *argv[]) {    
    srand(time(NULL));
    if(args < 2){
        cout << "./nameproyect <numero entero (cantidad de pelotitas)>" << endl; 
        return 0;
    }
    int i, x, j;
    int n = atoi(argv[1]); // numero de pelotas
    int rgb[3] = {59,131,189}; // azul para las pelotitas
    int rgb2[3] = {244, 70, 17}; //naranja para el proyectil
    int rgb3[3] = {0, 247, 0}; //verde para el agente 
    
    Agente jugador(ANCHURA/4, ALTURA, 0, 0, 30, rgb2); //delaramos el agente
    Pelota proyectil(ANCHURA/4, ALTURA-20, 0, 0, 10, rgb3); //declaramos proyectil
    vector <Pelota> pelotitas; //declaramos pelotitas con un vector

    for(i = 0; i < 6; i++)
        tecla[i] = false;   //Inicializa arreglo
    
    for(i = 0; i < n; i++){ //inicializa pelotas, con valores random
        Pelota aux(rand()%ANCHURA, rand()%ALTURA/2, 0, 0, rand()%30+5, rgb);
        pelotitas.push_back(aux);
    }

    gfx_open(ANCHURA, ALTURA, "Mini juego por Eduardo Perez Gomez");

    while(1) {
        if(gfx_event_waiting2()) {
            gfx_keyPress(tecla); //Obtiene la tecla que se ha presionado como siguiente evento
            jugador.mueveAgente(jugador,tecla);
            jugador.validaMovimientoAgente(jugador);            
        }
        proyectil.muevePelota(proyectil, jugador); //validamos proyectil - agente
        
        for(x=0; x<n; x++) //validamos proyectil - pelotitas
            proyectil.muevePelotaD(proyectil, pelotitas[x]);

        for(j=0; j<n; j++) {//Dibuja las pelotitas
            gfx_color(rgb[0], rgb[1], rgb[2]);
            gfx_fill_arc(pelotitas[j].getpx() - pelotitas[j].getr(), pelotitas[j].getpy() - pelotitas[j].getr(), 2 * pelotitas[j].getr(), 2 * pelotitas[j].getr(), 0, 360*64);
        }

        //Dibuja el proyectil
        gfx_color(rgb3[0], rgb3[1], rgb3[2]);
        gfx_fill_arc(proyectil.getpx() - proyectil.getr(), proyectil.getpy() - proyectil.getr(), 2*proyectil.getr(), 2*proyectil.getr(), 0, 360*64);
       
        //Dibuja al jugador 
        gfx_color(rgb2[0], rgb2[1], rgb2[2]);
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
    (pPelota.setvy(pPelota.getvy() + 0.08)); //Para simular la aceleración de la gravedad
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
void Agente::mueveAgente(Agente &pJugador, bool tecla[6]){

    if ( tecla[3] == 1 ){  // Si se presionó la tecla de mover a la izquierda
        pJugador.setpx(pJugador.getpx() - 10);
    }
    if ( tecla[5] == 1 ){  // Si se presionó la tecla de mover a la derecha
        pJugador.setpx(pJugador.getpx() + 10);
    }
    gfx_flush();
}

//Después de que se ha presionado una tecla, la función se asegura que el agente no se ha salido de la pantalla
void Agente::validaMovimientoAgente(Agente &pAgente){
    
    //Limita al agente por la orilla derecha
    if((pAgente.getpx()) > (ANCHURA - pAgente.getr())){
        pAgente.setpx(ANCHURA - pAgente.getr());
    }
    //Limita al agente por la orilla izquierda
    if((pAgente.getpx()) < (pAgente.getr())){
        pAgente.setpx(pAgente.getr());
    }
    
}//end func

// Actualiza la velocidad y la posición de la pelota considerando al proyectil y a las pelotas estaticas
void Pelota::muevePelotaD(Pelota &pPelota, Pelota &pAgente){
    //Checa para ver si la pelota colisiona con algo para cambiar su velocidad    
    checaColisionesD(pPelota, pAgente);
    (pPelota.setvy(pPelota.getvy() + 0.08)); //Para simular la aceleración de la gravedad
    (pPelota.setpx((pPelota.getpx()) + (pPelota.getvx()))); //Cambios para x recordando v=d/t 
    (pPelota.setpy((pPelota.getpy()) + (pPelota.getvy())));
    gfx_clear();
}

//checa los bordes de la pelota y actualiza su localización, el vector velocidad   cambia si la pelota choca con algo.
void Pelota::checaColisionesD(Pelota &pPelota, Pelota &pAgente){
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
        calculaDireccionPelotaD(pPelota,pAgente);
}

//Cambia la dirección de la pelota de acuerdo a las leyes de la física
void Pelota::calculaDireccionPelotaD(Pelota &Bola, Pelota &Jugador){ 
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

    //de colisionar con la pelota la elimina dejando su radio en 0
    Jugador.setr(0);
}
