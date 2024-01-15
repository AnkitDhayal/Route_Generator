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
