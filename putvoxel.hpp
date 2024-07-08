#ifndef PUTVOXEL_HPP
#define PUTVOXEL_HPP
#include "figurageometrica.hpp"

class PutVoxel : public FiguraGeometrica{
    int x, y, z;
    float r, g, b;
public:
    PutVoxel();
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    void draw(Sculptor &t);
    ~PutVoxel(){};
};

#endif // PUTVOXEL_HPP
