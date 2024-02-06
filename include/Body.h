#ifndef _BODY_
#define _BODY_

#include "./Vector3.h"

struct ColorComponents
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
};

class Body
{
protected:
    ColorComponents color;
    Vector3 coordinates;
    Vector3 velocity;
    double mass;
    double size;

public:
    Body();
    Body(ColorComponents &color, Vector3 &coordinates, Vector3 &velocity, double mass, double size);

    inline Vector3 getVelocity() { return this->velocity; };
    inline ColorComponents getColor() { return this->color; };
    inline Vector3 getCoordinates() { return this->coordinates; };
    inline double getMass() { return this->mass; };
    inline void addForce(Vector3 &vectorForce) { this->velocity += vectorForce; };
    void update();
    void update_color();
    void update_coordinates();
};

#endif