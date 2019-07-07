#include "scene.hh"
#include <cstdlib>

// Badan Kapal
color3f shipHullColor{0.65, 0.42, 0.03};
verts2f shipHullVertices{
    vec2f{180, 320},
    vec2f{460, 320},
    vec2f{420, 400},
    vec2f{220, 400}
};

// Tiang Bendera
color3f flagPoleColor{0.5, 0.5, 0.5};
verts2f flagPoleVertices{
    vec2f{318, 320},
    vec2f{322, 320},
    vec2f{322, 200},
    vec2f{318, 200}
};

// Bendera
verts3f flagColors{
    color3f{1, 0, 0},    // Merah
    color3f{1, 1, 1}     // Putih
};
verts2f flagRedVertices{
    vec2f{322, 200},
    vec2f{382, 200},
    vec2f{382, 222.5},
    vec2f{322, 222.5}
};
verts2f flagWhiteVertices{
    vec2f{322, 222.5},
    vec2f{382, 222.5},
    vec2f{382, 245},
    vec2f{322, 245}
};
verts2f flagOutlineVertices{
    vec2f{322, 200},
    vec2f{382, 200},
    vec2f{382, 245},
    vec2f{322, 245}
};

void
RandomizeShipHullColor(void)
{
    for(int i=0; i<rand() % 1000; i++)
        shipHullColor = color3f{
            (float)((rand() % 101)/100),
            (float)((rand() % 101)/100),
            (float)((rand() % 101)/100)
        };
}

void
DrawShip(void)
{
    // Riak Air
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    for(int i=0; i<100; i+=25){
        glVertex2f(180 + (i/2), 405 + i);
        glVertex2f(460 - (i/2), 405 + i);
    }
    glEnd();

    // Tiang Bendera
    glColor3f(unpack3(flagPoleColor));
    DrawVertices2f(flagPoleVertices, GL_POLYGON);
    glColor3f(0, 0, 0);
    DrawVertices2f(flagPoleVertices, GL_LINE_LOOP);

    // Bendera
    glColor3f(unpack3(flagColors.at(0)));
    DrawVertices2f(flagRedVertices, GL_POLYGON);
    glColor3f(unpack3(flagColors.at(1)));
    DrawVertices2f(flagWhiteVertices, GL_POLYGON);
    glColor3f(0, 0, 0);
    DrawVertices2f(flagOutlineVertices, GL_LINE_LOOP);

    // Badan Kapal
    glColor3f(unpack3(shipHullColor));
    DrawVertices2f(shipHullVertices, GL_POLYGON);
    glColor3f(0, 0, 0);
    DrawVertices2f(shipHullVertices, GL_LINE_LOOP);
}