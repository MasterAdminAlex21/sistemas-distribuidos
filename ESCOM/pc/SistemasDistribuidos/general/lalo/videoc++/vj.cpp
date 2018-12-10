/*
INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO

Proyecto 2: Mini video juego

Elaborado por: Eduardo Perez Gomez
Para la materia de: Diseño de sistemas distribuidos
*/

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Resolución de la pantalla
#define ANCHURA 800
#define ALTURA 600

#ifndef PELOTA_H_
#define PELOTA_H_

class Pelota{
private:
    float x;
    float y; //posicion

    float vx; //velocidad
    float vy;    

    int r;  //radio
    int color[3]; //Color de la pelota
public: 
    Pelota(float = 0.0, float = 0.0, float = 0.0, float = 0.0, int = 0, int = 0, int = 0, int = 0);
    void muevePelota(Pelota *pPelota, Agente* pJugador);
    float getPosX();
	float getPosY();
	float getVelX();
	float getVelY();
	int getRadio();
	int getColR();
	int getColR();
	int getColR();
	void setPosX(float);
	void setPosY(float);
	void setVelX(float);
	void setVelY(float);
	void setRadio(int);
	void setColR(int);
	void setColR(int);
	void setColR(int);
};

#endif

#ifndef AGENTE_H_
#define AGENTE_H_

class Agente{
private:
    float x;
    float y; //posicion
    
    float vx; //velocidad
    float vy;
    
    int r;  //radio
    int color[3]; //Color del agente
public: 
    Agente(float = 0.0, float = 0.0, float = 0.0, float = 0.0, int = 0, int = 0, int = 0, int = 0);
    void checaColisiones(Pelota *pPelota, Agente* pAgente);
    void mueveAgente(Agente *pJugador, bool tecla[6]);
    void validaMovimientoAgente(Agente *pAgente);
    void calculaDireccionPelota(Pelota *Ball, Agente *Player);
    float getPosX();
	float getPosY();
	float getVelX();
	float getVelY();
	int getRadio();
	int getColR();
	int getColR();
	int getColR();
	void setPosX(float);
	void setPosY(float);
	void setVelX(float);
	void setVelY(float);
	void setRadio(int);
	void setColR(int);
	void setColR(int);
	void setColR(int);
};

#endif

bool tecla[6];  //Arreglo para saber si una tecla de dirección se ha presionado

int main(){

    
    int numP, i;
 	
 	//creamos el agente
    Agente jugador(ANCHURA/4,ALTURA,0,0,25,87,1,2), *pJugador;
    pJugador = jugador;

    //creamos n pelotas estaticas
   	std::vector<Pelota> v;
   	numP = rand() % 15;
   	v.reserve(numP);

   	//asignamos posicion random
   	for (i = 0; i < numP; i++){
   		v[i](rand() % ANCHURA, rand() % ALTURA, 0 , 0, rand() % 25, 25,25,25);
   	}

   	//creamos pelota con movimiento
   	Pelota pelota(ANCHURA/2, 10,0,0,10,255,255,255), *pPelota;
   	pPelota = pelota;

	//Pelota pelota={ANCHURA/2, 10,0,0,10, {255,255,255}}, *pPelota;
    //Agente jugador={ANCHURA/4,ALTURA,0,0,25, {87,1,2}}, *pJugador;
    //int i;

    //pPelota=&pelota;
    //pJugador=&jugador;

    for(i=0;i<6;i++){
        tecla[i]=false;   //Inicializa arreglo
    }
    gfx_open(ANCHURA, ALTURA, "Micro Juego GFX por Eduardo Perez Gomez");
    while(1) {
        if(gfx_event_waiting2()) {

            gfx_keyPress(tecla); //Obtiene la tecla que se ha presionado como siguiente evento
            
            mueveAgente(pJugador,tecla);
            validaMovimientoAgente(pJugador);            
        }
        
        muevePelota(pPelota, pJugador);
        //Dibuja la pelota
        gfx_color(pelota.color[0],pelota.color[1],pelota.color[2]);
        gfx_fill_arc(pelota.x - pelota.r, pelota.y - pelota.r, 2*pelota.r, 2*pelota.r, 0, 360*64);

        //Dibuja al jugador 
        gfx_color(jugador.color[0],jugador.color[1],jugador.color[2]);
        gfx_fill_arc(jugador.x - jugador.r, jugador.y - jugador.r, 2*jugador.r, 2*jugador.r, 0, 180*64);
       
		gfx_flush();
        usleep(18000);
    }

}



//inicializa pelota
Pelota::Pelota(float b1, float b2, float x1, float x2, int r1, int c1, int c2, int c3){
    x = b1;
    y = b2; //posicion

    vx = x1; //velocidad
    vy = y2;    

    r = r1;  //radio
    color[0] = c1; //Color de la pelota
    color[1] = c2; //Color de la pelota
    color[2] = c2; //Color de la pelota
}

//get para Pelota
float Pelota::getPosX(){
	return this->x;
}

float Pelota::getPosY(){
	return this->y;
}

float Pelota::getVelX(){
	return this->vx;
}

float Pelota::getVelY(){
	return this->vy;
}

int Pelota::getRadio(){
	return this->r;
}

int Pelota::getColR(){
	return this->c[0];
}

int Pelota::getColR(){
	return this->c[1];
}

int Pelota::getColR(){
	return this->c[2];
}

//set para pelota
void Pelota::setPosX(float a){
	x = a;
}

void Pelota::setPosY(float a){
	y= a;
}

void Pelota::setVelX(float a){
	vx= a;
}

void Pelota::setVelY(float a){
	vy= a;
}

void Pelota::setRadio(int a){
	r= a;
}

void Pelota::setColR(int a){
	c[0]= a;
}

void Pelota::setColR(int a){
	c[1]= a;
}

void Pelota::setColR(int a){
	c[2]= a;
}

//get para Agente
float Agente::getPosX(){
	return this->x;
}

float Agente::getPosY(){
	return this->y;
}

float Agente::getVelX(){
	return this->vx;
}

float Agente::getVelY(){
	return this->vy;
}

int Agente::getRadio(){
	return this->r;
}

int Agente::getColR(){
	return this->c[0];
}

int Agente::getColR(){
	return this->c[1];
}

int Agente::getColR(){
	return this->c[2];
}

//set para agente
void Agente::setPosX(float a){
	x = a;
}

void Agente::setPosY(float a){
	y= a;
}

void Agente::setVelX(float a){
	vx= a;
}

void Agente::setVelY(float a){
	vy= a;
}

void Agente::setRadio(int a){
	r= a;
}

void Agente::setColR(int a){
	c[0]= a;
}

void Agente::setColR(int a){
	c[1]= a;
}

void Agente::setColR(int a){
	c[2]= a;
}



//inicializa agente
Agente::Agente(float b1, float b2, float x1, float x2, int r1, int c1, int c2, int c3){
    x = b1;
    y = b2; //posicion

    vx = x1; //velocidad
    vy = y2;    

    r = r1;  //radio
    color[0] = c1; //Color de la pelota
    color[1] = c2; //Color de la pelota
    color[2] = c2; //Color de la pelota
}

// Actualiza la velocidad y la posición de la pelota
void Pelota::muevePelota(Pelota *pPelota, Agente* pAgente){
    //Checa para ver si la pelota colisiona con algo para cambiar su velocidad    
    checaColisiones(pPelota, pAgente);
    pPelota.setVelY(pPelota.getVelY() + 0.08); //Para simular la aceleración de la gravedad
    pPelota.setPosX(pPelota.getPosX() + pPelota.getVelX()); //Cambios para x recordando v=d/t 
    pPelota.setPosY(pPelota.getPosY() + pPelota.getVelY());
    gfx_clear();
}

//checa los bordes de la pelota y actualiza su localización, el vector velocidad   cambia si la pelota choca con algo.
void Agente::checaColisiones(Pelota *pPelota, Agente* pAgente){
    float distContacto, agenteBolaDist;
    
    if((pPelota.getPosX() < pPelota.getRadio()) || (pPelota.getPosX() > (ANCHURA - pPelota.getRadio())))  // colision lateral cambia al vector velocidad en x
        pPelota.setVelY(-pPelota.getVelY());
    if(pPelota.getPosY() < pPelota.getRadio())   //colision en techo cambia el vector velocidad en y
        pPelota.setVelY(-pPelota.getVelY());
    if(pPelota.getPosY() >= (ALTURA - pPelota.getRadio()))   //colision en piso
        pPelota.setVelY(-pPelota.getVelY());
    
    //distancia entre el centro del agente y la pelota
    agenteBolaDist = sqrtf(powf(pAgente.getPosY() - pPelota.getPosY(),2) + powf(pAgente.getPosX() - pPelota.getPosX() ,2));
    //distancia minima permisible entre los centros del agente y la pelota
    distContacto = pAgente.getRadio() + pPelota.getRadio();
    //checa para ver si existe colision entre la pelota y el agente
    if(agenteBolaDist < distContacto)
        calculaDireccionPelota(pPelota,pAgente);
}


//Lee el arreglo tecla para realizar un movimiento a la izquierda o a la derecha dependiendo de la tecla que se presionó.
void Agente::mueveAgente(Agente *pJugador, bool tecla[6]){

    if ( tecla[3] == 1 ){  // Si se presionó la tecla de mover a la izquierda
        pJugador.setPosX( pJugador.getPosX() - 10 );
    }
    if ( tecla[5] == 1 ){  // Si se presionó la tecla de mover a la derecha
        pJugador.setPosX( pJugador.getPosX() + 10 );
    }
    gfx_flush();
}

//Después de que se ha presionado una tecla, la función se asegura que el agente no se ha salido de la pantalla
void Agente::validaMovimientoAgente(Agente *pAgente){
    
    //Limita al agente por la orilla derecha
    if((pAgente.getPosX()) > (ANCHURA - pAgente.getRadio())){
        pAgente.setPosX(ANCHURA - pAgente.getRadio());
    }
    //Limita al agente por la orilla izquierda
    if( (pAgente.getPosX()) < (pAgente.getRadio()) ){
        pAgente.setPosX(pAgente.getRadio());
    }
    
}//end func


//Cambia la dirección de la pelota de acuerdo a las leyes de la física
void Agente::calculaDireccionPelota(Pelota *Bola, Agente *Jugador){ 
    //la velocidad absoluta de la pelota se inicializa a 10 después de que choca con la raqueta debido
    //a que de no hacerlo se movería mas lento cada vez
    float velocidadAbsoluta = 10;
    float pendienteEntreCentros;
    float difCentrosX,difCentrosY;
    float anguloEntreCentros;

    difCentrosX = Bola.getPosX() - Jugador.getPosX();
    difCentrosY = Bola.getPosY() - Jugador.getPosY();
    //Aunque puede existir un denominador igual a cero, y pendiente infinita la función arco tangente si resuelve con argumento infinito
    pendienteEntreCentros = difCentrosY / difCentrosX ;
    anguloEntreCentros = atanf(pendienteEntreCentros);
    if(difCentrosX < 0 && difCentrosY < 0)
        anguloEntreCentros += acosf(-1.0); // Ajusta la restricción del angulo sumandole PI = 3.14159...
            
    Bola.setVelX( velocidadAbsoluta * cosf(anguloEntreCentros) );
    Bola.setVelY( velocidadAbsoluta * sinf(anguloEntreCentros));
}



//.H
#if defined(__cplusplus)
extern "C" {
#endif


#ifndef GFX_H
#define GFX_H

#include <X11/Xlib.h>
#include <stdbool.h>

/* Open a new graphics window. */
void gfx_open( int width, int height, const char *title );

/* Flush all previous output to the window. */
void gfx_flush();

/* Change the current drawing color. */
void gfx_color( int red, int green, int blue );

/* Clear the graphics window to the background color. */
void gfx_clear();

/* Change the current background color. */
void gfx_clear_color( int red, int green, int blue );

/* Check to see if an event is waiting. */
int gfx_event_waiting();

int gfx_event_waiting2();
/* Wait for the user to press a key or mouse button. */
char gfx_wait();

/* Return the X and Y coordinates of the last event. */
int gfx_xpos();
int gfx_ypos();

/* Return the X and Y dimensions of the screen (monitor). */
int gfx_xsize();
int gfx_ysize();

/* Display a string at (x,y) */
void gfx_text( int x, int y , char *text );

/* Draw a point at (x,y) */
void gfx_point( int x, int y );

/* Draw a line from (x1,y1) to (x2,y2) */
void gfx_line( int x1, int y1, int x2, int y2 );

/* Draw a circle centered at (xc,yc) with radius r */
void gfx_circle( int xc, int yc, int r);

/* Draw an ellipse centered at (xc,yc) with radii r1 and r2 */
void gfx_ellipse( int xc, int yc, int r1, int r2);

/* Draw a rectangle with top-left corner at (x,y) with positive width w and height h */
void gfx_rectangle( int x, int y, int w, int h );

/* Draw a filled rectangle; similar to gfx_rectangle, but its size is "one pixel in" at all four sides */
void gfx_fill_rectangle( int x, int y, int w, int h );

/* Dibuja un arco lleno */
void gfx_fill_arc( int x, int y, unsigned int width, unsigned int height, int angle1, int angle2);

/* Draw a polygon whose corners (num_pts of them) are in the pointsarr array (uses Xlib's XPoint struct) */
void gfx_polygon( XPoint *pointsarr, int num_pts );
 
/* Draw a triangle that goes through points (x1,y1), (x2,y2), (x3,y3) */
void gfx_triangle( int x1, int y1, int x2, int y2, int x3, int y3 );


bool gfx_keyPress(bool keys[6]);

#endif

#if defined(__cplusplus)
}
#endif
