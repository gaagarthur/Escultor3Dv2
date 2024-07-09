#include "putvoxel.hpp"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a) {

    this->x = x ; this->y = y ; this->z = z ;
    this->r = r ; this->g = g ; this->b = b ;
    this->a = a ;

}

PutVoxel::draw(Sculptor &t){

    t[x][y][z].show = true; // "Ligar" voxel nas coordenadas x y z
    t[x][y][z].a = a; // transparencia do voxel opaco
    t[x][y][z].r = r;
    t[x][y][z].g = g;
    t[x][y][z].b = b;

}
