#include "../../include/OctalTree.h"

/**
 * @brief Destroy the Octree:: Octree object
 *
 */
Octree::~Octree()
{
    delete root;
}

/**
 * @brief Destroy the Octree:: Node:: Node object
 *
 */
Octree::Node::~Node()
{
    delete[] child_node_array;
    delete[] data.subtree;
}

void Octree::Node::calculate_center_of_mass()
{
    Vector3 centroid = Vector3(0, 0, 0);
    for (Node *node : child_node_array)
    {
        Body *current_body = node->data.body;

        if (node->content == Node::NodeContent::LEAF)
        {
            double x = centroid.getX();
            double y = centroid.getY();
            double z = centroid.getZ();

            centroid.setX(x + (current_body->getCoordinates().getX() * current_body->getMass()));
            centroid.setY(y + (current_body->getCoordinates().getY() * current_body->getMass()));
            centroid.setZ(z + (current_body->getCoordinates().getZ() * current_body->getMass()));

            mass += current_body->getMass();
        }
    }
}