#ifndef FIGURAGEOMETRICA_HPP
#define FIGURAGEOMETRICA_HPP
#include "sculptor.hpp"
#include <iostream>

class FiguraGeometrica{

public:
    FiguraGeometrica();
    virtual void draw(Sculptor &t)=0;
    virtual ~FiguraGeometrica(){}//{std::cout<<"destrutor FiguraGeometrica\n";}
};

#endif // FIGURAGEOMETRICA_HPP
