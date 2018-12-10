#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

#include "gfxModified.h"

const int ANCHURA = 800;
const int ALTURA = 600;

class Agente{

public:
    Agente(float xx, float yy, float vxx, float vyy, float rr, vector <int>& col) : x(xx), y(yy), vx(vxx), vy(vyy), r(rr), color(col){}
    float getX();
    float getY();
    float getVX();
    float getVY();
    int getR();
    int getColor(int);
    void mueveAgente(bool tecla[6]);
    void validaMovimientoAgente();

private:
    float x;
    float y;
    float vx;
    float vy;    
    int r;
    vector <int> color;
};

class Pelota{

public:
    Pelota(float xx, float yy, float vxx, float vyy, float rr, vector <int>& col) : x(xx), y(yy), vx(vxx), vy(vyy), r(rr), color(col){}
    float getX();
    float getY();
    float getVX();
    float getVY();
    int getR();
    int getColor(int);
    void muevePelota(Agente);
    void checaColisiones(Agente);
    void calculaDireccionPelota(Agente);

private:
    float x;
    float y; 
    float vx;
    float vy;    
    int r;
    vector <int> color;
};


float Agente :: getX(){
    return x;
}

float Agente :: getY(){
    return y;
}

float Agente :: getVX(){
    return vx;
}

float Agente :: getVY(){
    return vy;
}

int Agente :: getR(){
    return r;
}

int Agente :: getColor(int pos){
    return color[pos];
}

void Agente :: mueveAgente(bool tecla[6]){

    if (tecla[3] == 1)
        x -= 10;
    
    if (tecla[5] == 1)
        x += 10;
    
    gfx_flush();
}

void Agente :: validaMovimientoAgente(){
    if(x >ANCHURA - r)
        x = (ANCHURA - r);
    
    if(x < r)
       x = r;
       
}

float Pelota :: getX(){
    return x;
}

float Pelota :: getY(){
    return y;
}

float Pelota :: getVX(){
    return vx;
}

float Pelota :: getVY(){
    return vy;
}

int Pelota :: getR(){
    return r;
}

int Pelota :: getColor(int pos){
    return color[pos];
}


void Pelota :: muevePelota(Agente pAgente){ 
    checaColisiones(pAgente);
    vy += .08;
    x += vx;
    y += vy;
    gfx_clear();
}

void Pelota :: checaColisiones(Agente pAgente){
    float distContacto, agenteBolaDist;
    
    if(x < r || x > ANCHURA - r)
        vx = -vx;
    if(y < r)
        vy = -vy;
    if(y >= ALTURA - r)
        vy = -vy;

    agenteBolaDist = sqrtf(powf(pAgente.getY() - y,2) + powf(pAgente.getX() - x, 2));
    distContacto = pAgente.getR() + r;
    if(agenteBolaDist < distContacto)
        calculaDireccionPelota(pAgente);
}

void Pelota :: calculaDireccionPelota(Agente Jugador){ 
    float velocidadAbsoluta = 10;
    float pendienteEntreCentros;
    float difCentrosX,difCentrosY;
    float anguloEntreCentros;

    difCentrosX = x - Jugador.getX();
    difCentrosY = y - Jugador.getY();

    pendienteEntreCentros = difCentrosY / difCentrosX ;
    anguloEntreCentros = atanf(pendienteEntreCentros);
    if(difCentrosX < 0 && difCentrosY < 0)
        anguloEntreCentros += acosf(-1.0);
            
    vx = velocidadAbsoluta * cosf(anguloEntreCentros);
    vy = velocidadAbsoluta * sinf(anguloEntreCentros);
}


bool tecla[6];

int main(int args, char *argv[]){
    srand(time(NULL));

    int N = atoi(argv[1]);

    vector <int> colorAux;
    colorAux.push_back(87);
    colorAux.push_back(1);
    colorAux.push_back(2);

    Agente jugador(ANCHURA / 4, ALTURA, 0, 0, 25, colorAux);

    colorAux[0] = colorAux[1] = colorAux[2] = 255;
    vector <Pelota> canasta;

    for(int i = 0; i < N; i++){
        int x = rand() % ANCHURA;
        int y = rand() % ALTURA;
        int r = rand() % 30 + 3;
        while((x - jugador.getX()) * (x - jugador.getX()) + (y - jugador.getY()) * (y - jugador.getY()) <= r + jugador.getR()){
            x = rand() % ANCHURA;
            y = rand() % (ALTURA - 30);
            r = rand() % 30 + 3;
        }     
        Pelota tmp(x, y, 0, 0, r, colorAux);
        canasta.push_back(tmp);
    }
    


    fill(tecla, tecla + 6, false);
    gfx_open(ANCHURA, ALTURA, "Juego Edgar Augusto Santigo Nieves");

    while(1) {
        if(gfx_event_waiting2()) {
            gfx_keyPress(tecla);
            
            jugador.mueveAgente(tecla);
            jugador.validaMovimientoAgente();            
        }
        for(int i = 0; i < N; i++){
            canasta[i].muevePelota(jugador);
        }
        for(int i = 0; i < N; i++){
            gfx_color(canasta[i].getColor(0),canasta[i].getColor(1),canasta[i].getColor(2));
            gfx_fill_arc(canasta[i].getX() - canasta[i].getR(), canasta[i].getY() - canasta[i].getR(), 2*canasta[i].getR(), 2 * canasta[i].getR(), 0, 360*64);
        }
        gfx_color(jugador.getColor(0),jugador.getColor(1),jugador.getColor(2));
        gfx_fill_arc(jugador.getX() - jugador.getR(), jugador.getY() - jugador.getR(), 2*jugador.getR(), 2*jugador.getR(), 0, 180*64);
       
		gfx_flush();
        usleep(18000);
    }

}
