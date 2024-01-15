// Pipe.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "framework.h"
#include "Pipe.h"
#include <vector>

Pipe::Pipe(std::vector<float> inVertices, std::vector<float> inColor) :
	mVertices(inVertices),
	mColor(inColor)
{

}
Pipe::~Pipe() {

}
std::vector<float> Pipe::getVertices() {
	return mVertices;
}
std::vector<float> Pipe::getColors() {
	return mColor;
}