#include "../../include/Simulation.h"
#include <math.h>

#define G (6.67 / 1e11)

/**
 * @brief Returns the body exerted by a body on another body
 *
 * @param current_body_mass Current object's mass
 * @param other_body_mass Other object's mass
 * @param distance distance between the two bodies
 * @return float Represents the force in Newtons
 */
double calculate_force(double current_body_mass, double other_body_mass, double distance)
{
    return (G * current_body_mass * other_body_mass) / pow(distance, 2);
}

double get_distance(Vector3 &a_coord, Vector3 &b_coord)
{
    return sqrt(
        pow(b_coord.getX() - a_coord.getX(), 2) +
        pow(b_coord.getY() - a_coord.getY(), 2) +
        pow(b_coord.getZ() - a_coord.getZ(), 2));
}

Simulation::Simulation(unsigned int body_count, SimulationAlgorithm algoritm_to_use)
{
    switch (algoritm_to_use)
    {
    case SimulationAlgorithm::NAIVE:
        run_naive();
        break;
    case SimulationAlgorithm::BARNES_HUT:
        run_barnes_hut();
        break;
    }
};

void Simulation::run_naive()
{
    for (size_t current_body_index = 0; current_body_index < number_of_bodies; current_body_index++)
    {
        for (size_t other_body_index = 0; other_body_index < number_of_bodies; other_body_index++)
        {
            Body *current_body = &body_array[current_body_index];
            Body *other_body = &body_array[other_body_index];

            double distance = get_distance(
                current_body->getCoordinates(),
                other_body->getCoordinates());

            Vector3 direction = current_body->getCoordinates() - other_body->getCoordinates();

            double force_magnitude = calculate_force(
                current_body->getMass(),
                other_body->getMass(),
                distance);

            Vector3 force = *direction.normalized * force_magnitude;

            current_body->addForce(force);

            current_body->update();
        }
    }
}