#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#else
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif

class Vertex
{
private:
    float x, y, z;
    float r, g, b;

public:
    // Public data members
    // Constructors
    Vertex();
    Vertex(float vx, float vy, float vz, float vr, float vg, float vb);

    // Member functions
    void vertexInformation() const;
    void setPosition(float sx, float sy, float sz);
    void setColor(float sr, float sg, float sb);
    float getR() const;
    float getG() const;
    float getB() const;
    float getX() const;
    float getY() const;
    float getZ() const;
};

#endif // VERTEX_H
