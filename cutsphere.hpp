#ifndef CUTSPHERE_HPP
#define CUTSPHERE_HPP
#include "figurageometrica.hpp"

class CutSphere : public FiguraGeometrica{

    int xcenter, ycenter, zcenter, radius;

public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &t);
    ~CutSphere();
};

#endif // CUTSPHERE_HPP
