#include "../../include/Body.h"
#include <math.h>

Vector3::Vector3(double a, double b, double c) : x(a), y(b), z(c)
{
    normalized = new Vector3();
    update_attributes();
}

void Vector3::get_magnitude()
{
    this->magnitude = sqrt((x * x) + (y * y) + (z * z));
};

void Vector3::normalize()
{
    normalized->x = x / magnitude;
    normalized->y = y / magnitude;
    normalized->z = z / magnitude;
}

void Vector3::update_attributes()
{
    get_magnitude();
    normalize();
}

void Vector3::setX(double x)
{
    this->x = x;
    update_attributes();
}

void Vector3::setY(double y)
{
    this->y = y;
    update_attributes();
}

void Vector3::setZ(double z)
{
    this->z = z;
    update_attributes();
}

Vector3 Vector3::operator+(Vector3 const &other)
{
    Vector3 new_vector;

    new_vector.x = this->x + other.x;
    new_vector.y = this->y + other.y;
    new_vector.z = this->z + other.z;

    return new_vector;
}

void Vector3::operator=(Vector3 const &other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;

    update_attributes();
}

Vector3 Vector3::operator-(Vector3 const &other)
{
    Vector3 new_vector;

    new_vector.x = this->x - other.x;
    new_vector.y = this->y - other.y;
    new_vector.z = this->z - other.z;

    return new_vector;
}

Vector3 Vector3::operator*(double scalar)
{
    Vector3 new_vector;

    new_vector.x = this->x * scalar;
    new_vector.y = this->y * scalar;
    new_vector.z = this->z * scalar;

    return new_vector;
}

Vector3 Vector3::operator/(double scalar)
{
    Vector3 new_vector;

    new_vector.x = this->x / scalar;
    new_vector.y = this->y / scalar;
    new_vector.z = this->z / scalar;

    return new_vector;
}

void Vector3::operator+=(Vector3 const &other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;

    update_attributes();
}

void Vector3::operator-=(Vector3 const &other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;

    update_attributes();
}