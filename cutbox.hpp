#ifndef CUTBOX_HPP
#define CUTBOX_HPP
#include "figurageometrica.hpp"

class CutBox : public FiguraGeometrica{

    int x0, y0, z0, x1, y1, z1;

public:
    CutBox(int x0, int y0, int z0, int x1, int y1, int z1);
    void draw(Sculptor &t);
    ~CutBox(){}//{std::cout<<"destrutor CutBox\n";}
};

#endif // CUTBOX_HPP
