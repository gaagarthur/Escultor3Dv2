#ifndef CUTVOXEL_HPP
#define CUTVOXEL_HPP
#include "figurageometrica.hpp"

class CutVoxel : public FiguraGeometrica{

    int x, y, z;

public:
    CutVoxel(int x, int y, int z);
    void draw(Sculptor &t);
    ~CutVoxel(){}//{std::cout<<"destrutor CutVoxel\n";}
};

#endif // CUTVOXEL_HPP
