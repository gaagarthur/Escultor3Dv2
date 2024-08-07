#include <iostream>
#include "sculptor.hpp"
#include "figurageometrica.hpp"
#include "putvoxel.hpp"
#include "cutvoxel.hpp"
#include "putbox.hpp"
#include "cutbox.hpp"
#include "putsphere.hpp"
#include "cutsphere.hpp"
#include <fstream>
#include <queue>
#include <string>

int main(void){
    std::string linha, temp, Dir_results, Dir_FiguraCodificada, Dir_files;
    std::queue<std::string> que;
    const char SPACE=32;
    std::ifstream file;
    std::ofstream rewrite;
    FiguraGeometrica *pfig;


    Dir_files = "D:/Documents/Projects/Escultor3Dv2/files"; // Para utilizar em outra maquina, trocar path para o diretorio "files"
                                                            // Utilizar " / " no path

    Dir_results = Dir_files + "/results.txt";
    Dir_FiguraCodificada = Dir_files + "/FiguraCodificada.txt";


    file.open(Dir_FiguraCodificada);
    if(file.is_open()){
        while(!file.eof()){
            std::getline (file,linha,SPACE);
            que.push(linha);
        }
        file.close();
    }

    rewrite.open(Dir_results);
    if(rewrite.is_open()){
        while(!que.empty()){
            rewrite<<que.front()<<std::endl;
            que.pop();
        }
    }

    file.open(Dir_results);
    if(file.is_open()){
        while(!file.eof()){

            std::getline (file,linha);


            if(linha.compare("dim")==0){
                que.push("D");
                //std::cout<<"passou D\n";
            }else if(linha.compare("putvoxel")==0){
                que.push("V");
                //std::cout<<"passou V\n";
            }else if(linha.compare("putbox")==0){
                que.push("B");
                //std::cout<<"passou B\n";
            }else if(linha.compare("putsphere")==0){
                que.push("S");
                //std::cout<<"passou S\n";
            }else if(linha.compare("cutvoxel")==0){
                que.push("v");
                //std::cout<<"passou v\n";
            }else if(linha.compare("cutbox")==0){
                que.push("b");
                //std::cout<<"passou b\n";
            }else if(linha.compare("cutsphere")==0){
                que.push("s");
                //std::cout<<"passou s\n";
            }else if(linha.compare("putellipsoid")==0){
                que.push("E");
                //std::cout<<"passou E\n";
            }else if(linha.compare("cutellipsoid")==0){
                que.push("e");
                //std::cout<<"passou e\n";
            }else{
                que.push(linha);
                //std::cout<<"passou DEFAULT\n";
                //std::cout<<linha.front()<<" "<<linha.back()<<"\n";
            }
        }
        file.close();
    }

   /*
    int j = que.size(), h=1;
    std::ofstream output;
    output.open("D:/Documents/Projects/Escultor3Dv2/files/results.txt");
    if(output.is_open()){
        for (int i=0; i<j; i++){
            output<<que.front()<<std::endl;
            que.pop();
        }
    }*/

    que.pop();//remove dim
    int x = std::stoi(que.front()); que.pop();
    int y = std::stoi(que.front()); que.pop();
    int z = std::stoi(que.front()); que.pop();
    //std::cout<<x<<" "<<y<<" "<<z<<"\n";
    Sculptor t(x,y,z);

    while (que.size()!=0){
        int X1=0, Y1=0, Z1=0, X0=0, Y0=0, Z0=0, RADIUS=0;
        float R=0.0, G=0.0, B=0.0, A=0.0;
        temp = que.front(); que.pop();
        char i=*temp.begin();
        switch(i){
        case 'V':
            X0 = std::stoi(que.front()); que.pop();
            Y0 = std::stoi(que.front()); que.pop();
            Z0 = std::stoi(que.front()); que.pop();
            R = std::stof(que.front()); que.pop();
            G = std::stof(que.front()); que.pop();
            B = std::stof(que.front()); que.pop();
            A = std::stof(que.front()); que.pop();
            pfig = new PutVoxel(X0,Y0,Z0,R,G,B,A);
            pfig->draw(t);
            delete pfig;
            break;

        case 'B':
            X0 = std::stoi(que.front()); que.pop();
            X1 = std::stoi(que.front()); que.pop();
            Y0 = std::stoi(que.front()); que.pop();
            Y1 = std::stoi(que.front()); que.pop();
            Z0 = std::stoi(que.front()); que.pop();
            Z1 = std::stoi(que.front()); que.pop();
            R = std::stof(que.front()); que.pop();
            G = std::stof(que.front()); que.pop();
            B = std::stof(que.front()); que.pop();
            A = std::stof(que.front()); que.pop();
            pfig = new PutBox(X0,Y0,Z0,X1,Y1,Z1,R,G,B,A);
            pfig->draw(t);
            delete pfig;
            break;

        case 'S':
            X0 = std::stoi(que.front()); que.pop();
            Y0 = std::stoi(que.front()); que.pop();
            Z0 = std::stoi(que.front()); que.pop();
            RADIUS = std::stoi(que.front()); que.pop();
            R = std::stof(que.front()); que.pop();
            G = std::stof(que.front()); que.pop();
            B = std::stof(que.front()); que.pop();
            A = std::stof(que.front()); que.pop();
            pfig = new PutSphere(X0,Y0,Z0,RADIUS,R,G,B,A);
            pfig->draw(t);
            delete pfig;
            break;

        case 'v':
            X0 = std::stoi(que.front()); que.pop();
            Y0 = std::stoi(que.front()); que.pop();
            Z0 = std::stoi(que.front()); que.pop();
            pfig = new CutVoxel(X0,Y0,Z0);
            pfig->draw(t);
            delete pfig;
            break;
        case 'b':
            X0 = std::stoi(que.front()); que.pop();
            X1 = std::stoi(que.front()); que.pop();
            Y0 = std::stoi(que.front()); que.pop();
            Y1 = std::stoi(que.front()); que.pop();
            Z0 = std::stoi(que.front()); que.pop();
            Z1 = std::stoi(que.front()); que.pop();
            pfig = new CutBox(X0,Y0,Z0,X1,Y1,Z1);
            pfig->draw(t);
            delete pfig;
            break;

        case 's':
            X0 = std::stoi(que.front()); que.pop();
            Y0 = std::stoi(que.front()); que.pop();
            Z0 = std::stoi(que.front()); que.pop();
            RADIUS = std::stoi(que.front()); que.pop();
            pfig = new CutSphere(X0,Y0,Z0,RADIUS);
            pfig->draw(t);
            delete pfig;
            break;

        case 'E':
            /*X0 = std::stoi(que.front()); que.pop();//xcenter
            Y0 = std::stoi(que.front()); que.pop();//ycenter
            Z0 = std::stoi(que.front()); que.pop();//zcenter
            X1 = std::stoi(que.front()); que.pop();//xradius
            Y1 = std::stoi(que.front()); que.pop();//yradius
            Z1 = std::stoi(que.front()); que.pop();//zradius
            R = std::stof(que.front()); que.pop();
            G = std::stof(que.front()); que.pop();
            B = std::stof(que.front()); que.pop();
            A = std::stof(que.front()); que.pop();
            pfig = new PutEllipsoid(X0,Y0,Z0,X1,Y1,Z1,R,G,B,A);
            pfig->draw(t);
            delete pfig;*/
            break;

        case 'e':
            /*X0 = std::stoi(que.front()); que.pop();//xcenter
            Y0 = std::stoi(que.front()); que.pop();//ycenter
            Z0 = std::stoi(que.front()); que.pop();//zcenter
            X1 = std::stoi(que.front()); que.pop();//xradius
            Y1 = std::stoi(que.front()); que.pop();//yradius
            Z1 = std::stoi(que.front()); que.pop();//zradius
            pfig = new Ellipsoid(X0,Y0,Z0,X1,Y1,Z1);
            pfig->draw(t);
            delete pfig;*/
            break;

        default:
            std::cout<<que.size()<<"\n";
        }

    }

    t.writeOFF("Santa.off");




}



