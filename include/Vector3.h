#ifndef _VECTOR3_
#define _VECTOR3_

class Vector3
{
private:
    double x;
    double y;
    double z;

public:
    Vector3 *normalized{nullptr};
    double magnitude;

    Vector3(double a, double b, double c);
    Vector3();
    inline ~Vector3() { delete normalized; };

    inline double getX() { return this->x; };
    inline double getY() { return this->y; };
    inline double getZ() { return this->z; };

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    /**
     * @brief Normalize current vector
     *
     */
    void normalize();

    /**
     * @brief Calculates magnitude of current vector
     *
     */
    void get_magnitude();

    void update_attributes();

    Vector3 operator+(Vector3 const &other);
    Vector3 operator-(Vector3 const &other);
    Vector3 operator*(double scalar);
    Vector3 operator/(double scalar);
    void operator=(Vector3 const &other);
    void operator+=(Vector3 const &other);
    void operator-=(Vector3 const &other);
};

#endif