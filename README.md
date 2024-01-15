# Route Generator

## Overview

The Route Generator project is designed to provide route generation capabilities through three distinct DLLs - Geometry, Pipe, and Transformation. Each DLL serves a specific purpose in the system:

### Geometry.dll

This DLL contains the `Point3D` class, representing a three-dimensional point with X, Y, and Z coordinates. It provides constructors, getter and setter methods for coordinate manipulation.

### Pipe.dll

The Pipe DLL exports the `Pipe` class, which manages the vertices and colors of a pipe. It has methods to retrieve the vertices and colors of the pipe, and it is designed to be utilized in a project requiring pipe-related functionalities.

### Transformation.dll

The Transformation DLL exports the `Transformations` class, offering methods for translating vertices in three-dimensional space. It includes functions for translating vertices along the X, Y, and Z axes.

## File Structure

The project is organized into three DLLs, each with its specific functionality:

1. **Geometry.dll**
   - `Point3D.h`: Header file defining the `Point3D` class with X, Y, and Z coordinates.
   - `Point3D.cpp`: Implementation file containing the constructors and methods of the `Point3D` class.

2. **Pipe.dll**
   - `Pipe.h`: Header file defining the `Pipe` class for managing pipe-related functionalities.
   - `Pipe.cpp`: Implementation file containing the methods of the `Pipe` class.

3. **Transformation.dll**
   - `Transformations.h`: Header file defining the `Transformations` class for translating vertices.
   - `Transformations.cpp`: Implementation file containing the methods of the `Transformations` class.

###  Software Tools
 
1. `C++`: The primary programming language for the application.
 
2. `QT`: The Qt framework is utilized for the development of the graphical user interface (GUI) components.
 
3. `OpenGL`: OpenGL is employed for rendering 3D graphics, enhancing the visualization capabilities of the application.
 
4. `Visual Studio`: The project is developed and built using the Visual Studio integrated development environment.
 
5. `Git`: Git is used for version control and collaborative development, allowing for easy tracking of changes and contributions

### Output
![RoutGeneratorOutput](https://github.com/AnkitDhayal/RouteGenerator/assets/149352781/d7045402-37e6-4c04-be5f-a95c3d794668)

