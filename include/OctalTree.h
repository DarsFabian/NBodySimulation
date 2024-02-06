#ifndef _OCTALTREE_
#define _OCTALTREE_

#include "./Body.h"

struct OctalTreeData
{
    union
    {
        Octree *oct_ptr;
        Body *body_ptr;
    };
    bool body;
};

class Octree
{
private:
    OctalTreeData data_array[8];

    void insert(OctalTreeData &data, unsigned char index);
    void find(OctalTreeData &data);
};

#endif