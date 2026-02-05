#include "polygon.h"
#include <random>

// Implement a C++ program that declares and initializes a vector of P polygons
// that have random (x,y,z) point coordinates between [-1..1] and random color
// values between [0..1]. To verify/debug this code, you should loop over this
// vector and call “display” for each polygon. This should print the random polygon
// values

std::vector<Polygon> polygons;

float theta = 0.0f;
int xangle = 0;
int yangle = 0;
int zangle = 0;
int xpos = 0;
int ypos = 0;
int zpos = 0;

std::vector<Polygon> testPolygons(int n, int m)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> position(-1.0f, 1.0f);
    std::uniform_real_distribution<float> color(0.0f, 1.0f);

    std::vector<Polygon> polys;
    polys.reserve(m);

    for (int polyIdx = 0; polyIdx < m; polyIdx++)
    {
        std::vector<Vertex> verts;
        verts.reserve(n);

        for (int vertIdx = 0; vertIdx < n; vertIdx++)
        {
            Vertex v(position(gen), position(gen), position(gen), color(gen), color(gen), color(gen));
            verts.push_back(v);
        }

        polys.emplace_back(verts);
    }

    return polys;
}

// std::vector<Polygon> testPolygons(int n, int m)
// {
//     std::random_device rd;  // random number from hardware for position
//     std::mt19937 gen(rd()); // seed the genrator

//     // now to actually set the range of "randomness"
//     std::uniform_real_distribution<float> position(-1.0f, 1.0f);
//     std::uniform_real_distribution<float> color(0.0f, 1.0f);

//     std::vector<Vertex> verts;
//     std::vector<Polygon> polys;

//     for (int i = 0; i < m; i++)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             Vertex v(position(gen), position(gen), position(gen), color(gen), color(gen), color(gen));
//             verts.push_back(v);
//         }
//         Polygon p(verts);
//         polys.push_back(p);
//     }

//     return polys;
// }

void allInformation(std::vector<Polygon> polys)
{
    int count = 1;           // track what vertex we are on
    for (Polygon &p : polys) // iterate thru each polygon in the vector
    {
        std::cout << "Polygon (" << count << "):" << std::endl; // output the specific polygon we are at
        p.polygonInformation();                                 // print that polygon's information
        count++;
    }
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void display()
{
    // Incrementally rotate objects
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(xpos / 500.0, ypos / 500.0, zpos / 500.0);
    glRotatef(xangle * theta, 1.0, 0.0, 0.0);
    glRotatef(yangle * theta, 0.0, 1.0, 0.0);
    glRotatef(zangle * theta, 0.0, 0.0, 1.0);
    theta += 5;
    for (Polygon &p : polygons) // iterate thru each polygon in the vector of polygons
    {
        p.display();
    }

    glFlush();
}

int main(int argc, char *argv[])
{
    polygons = testPolygons(8, 20);
    // allInformation(polygons);
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(250, 250);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Square");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}