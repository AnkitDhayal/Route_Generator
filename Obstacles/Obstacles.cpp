// Obstacles.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "framework.h"
#include "Obstacles.h"

// This is an example of an exported variable
OBSTACLES_API int nObstacles=0;

// This is an example of an exported function.
OBSTACLES_API int fnObstacles(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CObstacles::CObstacles()
{
    return;
}
