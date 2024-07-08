#ifndef CUTVOXEL_HPP
#define CUTVOXEL_HPP
#include "figurageometrica.hpp"

class CutVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    CutVoxel();
    CutVoxel(int x, int y, int z);
    void draw(Sculptor &t);
    ~CutVoxel();
};

#endif // CUTVOXEL_HPP
