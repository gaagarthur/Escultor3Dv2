#ifndef PUTBOX_HPP
#define PUTBOX_HPP
#include "figurageometrica.hpp"

class PutBox : public FiguraGeometrica{
    int x0, y0, z0, x1, y1, z1;
    float r, g, b;
public:
    PutBox();
    PutBox(int x0, int y0, int z0, int x1, int y1, int z1, float r, float g, float b, float a);
    void draw(Sculptor &t);
    ~PutBox();
};

#endif // PUTBOX_HPP
