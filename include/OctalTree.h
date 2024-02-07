#ifndef _OCTALTREE_
#define _OCTALTREE_

#include "./Body.h"
#include "./Vector3.h"

class Node;
class Octree
{

public:
    Octree();
    ~Octree();

private:
    Node *root;

    class Node
    {

        friend class Octree;

    private:
        /**
         * @brief Defines the content of the node
         *
         */
        enum NodeContent
        {
            NULL = 0,
            LEAF = 1,
            INTERNAL = 2,
        };

        /**
         * @brief Defines the position of the node in the 3d space
         *
         */
        enum ArrayPosition
        {
            FL_TOP_LEFT = 0,
            FL_TOP_RIGHT,
            FL_BOT_LEFT,
            FL_BOT_RIGHT,

            SL_TOP_LEFT,
            SL_TOP_RIGHT,
            SL_BOT_LEFT,
            SL_BOT_RIGHT
        };

        Vector3 center_of_mass;
        double mass;
        NodeContent content;
        Node *child_node_array[8]{nullptr};
        union
        {
            Node *subtree[8];
            Body *body;
        } data;

        Node();
        ~Node();

        void calculate_center_of_mass();
    };
};

#endif