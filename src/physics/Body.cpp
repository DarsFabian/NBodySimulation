#include "../../include/Body.h"

void Body::update()
{
    // ? update_color(); NOT IMPLEMENTED
    update_coordinates();
}

void Body::update_coordinates()
{
    coordinates += velocity;
}