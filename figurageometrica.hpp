#ifndef FIGURAGEOMETRICA_HPP
#define FIGURAGEOMETRICA_HPP
#include "sculptor.hpp"

class FiguraGeometrica{

public:
    FiguraGeometrica();
    virtual void draw(Sculptor &t)=0;
    virtual ~FiguraGeometrica();
};

#endif // FIGURAGEOMETRICA_HPP
