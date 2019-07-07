#ifndef COMMON_HH
#define COMMON_HH

#include <vector>
#include <GL/gl.h>

#define unpack2(vec2) vec2.x, vec2.y
#define unpack3(vec3) vec3.x, vec3.y, vec3.z

template <typename T> 
struct vec2_t {
    T x, y;
};

template <typename T>
struct vec3_t {
    T x, y, z;
};

typedef vec2_t<float> vec2f;
typedef vec3_t<float> vec3f;
typedef vec3f color3f;

typedef std::vector<vec2f> verts2f;
typedef std::vector<vec3f> verts3f;

inline void
DrawVertices2f(verts2f vertices, unsigned int polymode)
{
    glBegin(polymode);
    for(unsigned int i=0; i<vertices.size(); i++)
        glVertex2f(vertices.at(i).x, vertices.at(i).y);
    glEnd();
}

#endif