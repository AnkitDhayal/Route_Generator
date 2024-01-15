// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the Pipe_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// Pipe_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include <vector>
#include "pch.h"
// This class is exported from the dll
class PIPE_API Pipe {
public:
	Pipe(std::vector<float> inVertices, std::vector<float> inColor);
	~Pipe();
public:
	std::vector<float> getVertices();
	std::vector<float> getColors();

private:
	std::vector<float> mVertices;
	std::vector<float> mColor;
};
