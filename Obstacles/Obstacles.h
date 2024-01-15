// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the OBSTACLES_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// OBSTACLES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#pragma once
#include "pch.h"
#include <vector>

// This class is exported from the dll
class OBSTACLES_API CObstacles {
public:
	CObstacles(void);
	// TODO: add your methods here.


};

extern OBSTACLES_API int nObstacles;

OBSTACLES_API int fnObstacles(void);
