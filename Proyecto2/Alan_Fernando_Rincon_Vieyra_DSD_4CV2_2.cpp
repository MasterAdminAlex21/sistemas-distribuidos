#include "gfx.h"
#include <unistd.h>
#include <iostream>
#include <vector>
#include <stdlib.h>       /* srand, rand */
#include <time.h>         /* time */
#include <cmath>          /* sin, cos */

#define X_SIZE 800        // Width of window.
#define Y_SIZE 600        // Height of window.
#define MIN_SIZE 10       // Minimum diametter of asteroid in pixels.
#define MAX_SIZE 100      // Maximum diametter of asteroid in pixels.
#define MIN_SPEED 12       // Minimum speed in px/s.
#define MAX_SPEED 200      // Maxmum speed in px/s.
#define TIME_SLEEP 41666  // Time for sleep in microseconds (24 imgs/seg.).

using namespace std;

/*  ########################################################################  */
/*  ##############################  INTERFACE  #############################  */
/*  ########################################################################  */
#ifndef POINT_H_
#define POINT_H_
class Point{
	private:
    double x;
    double y;
  public:
    Point();
    Point(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
};
#endif

#ifndef ASTEROID_H_
#define ASTEROID_H_
class Asteroid{
	private:
		vector<Point> points; // Points that describe the shape of the asteroid.
    Point position;       // Position x, y.
    double r;             // Radio of the asteroid,
    double direction;     // In degrees. [0, 2*pi]
    int speed;            // [MIN_SPEED, MAX_SPEED]
    bool direction_rt;    // Clockwise (true) or anticlockwise (false).
    double speed_rt;      // In degrees. [0, 2*pi]
    bool fixSize;
	public:
    /**
     * @Name: Asteroid
     * @Description: Constructor for generate an asteroid with shape randomly.
    */
		Asteroid();
    void init();
    void rotate();
    void move();
    void draw();
    bool isInside();
};

vector<Asteroid> asteroids;

/**
 * @Name: generateAsteroids
 * @Description: Method for generate 'n' asteroids randomly.
 * @Param: (integer) n Number of asteroids to draw.
 * @Return: (Void)
*/
void generateAsteroids(int n);
/**
 * @Name: rotateAsteroids
 * @Description: Method for rotate clockwise or anticlockwise every asteroid.
 * @Param: NULL
 * @Return: (Void)
*/
void rotateAsteroids();
/**
 * @Name: moveAsteroids
 * @Description: Method for move every asteroid in its direction and speed.
 * @Param: NULL
 * @Return: (Void)
*/
void moveAsteroids();
/**
 * @Name: drawAsteroids
 * @Description: Method for draw every asteroid depending of its values.
 * @Param: NULL
 * @Return: (Void)
*/
void drawAsteroids();
#endif

/*  ########################################################################  */
/*  ###########################  IMPLEMENTATION  ###########################  */
/*  ########################################################################  */
Point::Point() {
  setX(0);
  setY(0);
}

Point::Point(double x_, double y_) {
  x = x_;
  y = y_;
}

void Point::setX(double x_) {
  x = x_;
}

void Point::setY(double y_) {
  y = y_;
}

double Point::getX() {
  return x;
}

double Point::getY() {
  return y;
}

Asteroid::Asteroid() {
  init();
}

void Asteroid::init() {
  int nPoints = rand() % 6 + 6;  // [5, 11]
  double rotation = 2.0 * M_PI / nPoints;
  double point_rotation, x, y, rAux;
  r = (rand() % (MAX_SIZE + 1) + MIN_SIZE) / 2.0;  // Radio. [MIN_SIZE, MAX_SIZE]
  points.clear();

  for (int i = 0; i < nPoints; i++) {
    point_rotation = i * rotation;

    rAux = r * 0.01 * (rand() % 51 + 50);

    x = rAux * cos(point_rotation);
    y = rAux * sin(point_rotation);

    Point point(x, y);

    points.push_back(point);
  }

  position.setX( rand() % (X_SIZE + 1) );
  position.setY( rand() % (Y_SIZE + 1) );
  direction = ((rand() % 360 + 1) / 360.0) * (2.0 * M_PI);
  //speed = rand() % (MAX_SPEED + 1) + MIN_SPEED;
  speed = MIN_SPEED;
  speed += (1.0 - (r * 2.0 / MAX_SIZE)) * (MAX_SPEED - MIN_SPEED);
  direction_rt = (rand() % 2) ? true : false;
  speed_rt = ((rand() % 360 + 1) / 360.0) * (0.015 * M_PI);
}

void Asteroid::rotate() {
  double x, y;
  double theta = (direction_rt) ? 0 - speed_rt : speed_rt;

  for (int i = 0; i < points.size(); i++) {
    x = points[i].getX();
    y = points[i].getY();

    x = x * cos(theta) - y * sin(theta);
    y = x * sin(theta) + y * cos(theta);

    points[i].setX(x);
    points[i].setY(y);
  }
}

void Asteroid::move() {
  double x = position.getX();
  double y = position.getY();
  double d = speed / 24.0;  // 24 img./seg.

  x += d * cos(direction);
  y += d * sin(direction);

  if (!isInside()) {
    init();

    switch (rand() % 4) {
      case 0:
        x = 0;
        y = rand() % (Y_SIZE + 1);
        break;
      case 1:
        x = X_SIZE;
        y = rand() % (Y_SIZE + 1);
        break;
      case 2:
        x = rand() % (X_SIZE + 1);
        y = 0;
        break;
      case 3:
        x = rand() % (X_SIZE + 1);
        y = Y_SIZE;
        break;
    }
  }

  position.setX(x);
  position.setY(y);
}

void Asteroid::draw() {
  for (int i = 0; i < points.size(); i++) {
    Point a = points[i];
    Point b = (i < points.size() - 1) ? points[i + 1] : points[0];

    gfx_line(position.getX() + a.getX(),
      position.getY() + a.getY(),
      position.getX() + b.getX(),
      position.getY() + b.getY());
  }
}

bool Asteroid::isInside() {
  double x = position.getX();
  double y = position.getY();
  
  return (x <= X_SIZE + r && y <= Y_SIZE + r &&
    x >= - r && y >= - r);
}

void generateAsteroids(int n) {
  for (int i = 0; i < n; i++) {
    Asteroid asteroid;
    asteroids.push_back(asteroid);
  }
}

void rotateAsteroids() {
  for (int i = 0; i < asteroids.size(); i++) {
    asteroids[i].rotate();
  }
}

void moveAsteroids() {
  for (int i = 0; i < asteroids.size(); i++) {
    asteroids[i].move();
  }
}

void drawAsteroids() {
  for (int i = 0; i < asteroids.size(); i++) {
    asteroids[i].draw();
  }
}
/*  ########################################################################  */
/*  ##############################  PRINCIPAL  #############################  */
/*  ########################################################################  */
int main() {
  int n;

  srand (time(NULL));     // initialize random seed.

  cout << "Ingrese el numero de asteroides deseado: ";
  cin >> n;

  gfx_open(X_SIZE, Y_SIZE, "Asteroides - Alan Vieya - ESCOM - IPN");
  gfx_color(0,200,100);

  generateAsteroids(n);

  while (true) {
    gfx_clear();

    rotateAsteroids();
    moveAsteroids();
    drawAsteroids();    

    gfx_flush();
    usleep(TIME_SLEEP);
  }

  return 0;
} // */
