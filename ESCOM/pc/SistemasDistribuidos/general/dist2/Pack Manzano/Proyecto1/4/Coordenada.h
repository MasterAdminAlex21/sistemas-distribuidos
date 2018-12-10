#ifndef COORDENADA_H_
#define COORDENADA_H_
class Coordenada{
private:
	double x;
	double y;
	double z;
public:
    Coordenada(double = 0, double = 0, double = 0);
    const double obtenerX() const;
    const double obtenerY() const;
    const double obtenerZ() const;
    bool operator< (const Coordenada &uno) const;
 };
#endif