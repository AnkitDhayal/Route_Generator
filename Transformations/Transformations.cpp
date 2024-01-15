// Transformations.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Transformations.h"
#include "Point3D.h"
#include <vector>
Transformations::Transformations()
{

}
Transformations::~Transformations() {

}
std::vector<Point3D> Transformations::translate_X_Left(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setX(inVertices[i].X() - 1);
    }
    return inVertices;
}
void Transformations::translate_X_Right(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setX(inVertices[i].X() + 1);
    }
}
void Transformations::translate_Y_UP(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setY(inVertices[i].Y() + 1);
    }
}
void Transformations::translate_X_Down(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setY(inVertices[i].Y() - 1);
    }
}