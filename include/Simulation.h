#include "./Body.h"

enum SimulationAlgorithm
{
    NAIVE = 0,
    BARNES_HUT
};

class Simulation
{
private:
    unsigned int uptime{0};
    unsigned int number_of_bodies;
    Body body_array[];

    Simulation(unsigned int body_count, SimulationAlgorithm algorithm_to_use);
    inline unsigned int getNumberOfBodies() { return this->number_of_bodies; };
    void run_barnes_hut();
    void run_naive();
    void naive_step();
};