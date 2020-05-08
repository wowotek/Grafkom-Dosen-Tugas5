#include "scene.hh"
#include <cstdlib>

#include "common.hh"

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

frames redAnim{
    frame{
        verts2f{
           vec2f{322, 200},
           vec2f{322, 222},
           vec2f{337, 222},
           vec2f{337, 200},
        },
        verts2f{
           vec2f{338, 203},
           vec2f{338, 225},
           vec2f{353, 225},
           vec2f{353, 203},
        },
        verts2f{
           vec2f{354, 200},
           vec2f{354, 222},
           vec2f{369, 222},
           vec2f{369, 200},
        },
        verts2f{
           vec2f{370, 203},
           vec2f{370, 225},
           vec2f{382, 225},
           vec2f{382, 203},
        },
    },
    frame{
        verts2f{
           vec2f{322, 203},
           vec2f{322, 225},
           vec2f{326, 225},
           vec2f{326, 203},
        },
        verts2f{
           vec2f{327, 200},
           vec2f{327, 222},
           vec2f{342, 222},
           vec2f{342, 200},
        },
        verts2f{
           vec2f{343, 203},
           vec2f{343, 225},
           vec2f{358, 225},
           vec2f{358, 203},
        },
        verts2f{
           vec2f{359, 200},
           vec2f{359, 222},
           vec2f{374, 222},
           vec2f{374, 200},
        },
        verts2f{
           vec2f{375, 203},
           vec2f{375, 225},
           vec2f{382, 225},
           vec2f{382, 203},
        },
    },
    frame{
        verts2f{
           vec2f{322, 203},
           vec2f{322, 225},
           vec2f{331, 225},
           vec2f{331, 203},
        },
        verts2f{
           vec2f{332, 200},
           vec2f{332, 222},
           vec2f{347, 222},
           vec2f{347, 200},
        },
        verts2f{
           vec2f{348, 203},
           vec2f{348, 225},
           vec2f{363, 225},
           vec2f{363, 203},
        },
        verts2f{
           vec2f{364, 200},
           vec2f{364, 222},
           vec2f{379, 222},
           vec2f{379, 200},
        },
        verts2f{
           vec2f{380, 203},
           vec2f{380, 225},
           vec2f{382, 225},
           vec2f{382, 203},
        },
    },
    frame{
        verts2f{
           vec2f{322, 203},
           vec2f{322, 225},
           vec2f{336, 225},
           vec2f{336, 203},
        },
        verts2f{
           vec2f{337, 200},
           vec2f{337, 222},
           vec2f{352, 222},
           vec2f{352, 200},
        },
        verts2f{
           vec2f{353, 203},
           vec2f{353, 225},
           vec2f{368, 225},
           vec2f{368, 203},
        },
        verts2f{
           vec2f{369, 200},
           vec2f{369, 222},
           vec2f{382, 222},
           vec2f{382, 200},
        },
    },
    frame{
        verts2f{
           vec2f{322, 200},
           vec2f{322, 222},
           vec2f{325, 222},
           vec2f{325, 200},
        },
        verts2f{
           vec2f{326, 203},
           vec2f{326, 225},
           vec2f{341, 225},
           vec2f{341, 203},
        },
        verts2f{
           vec2f{342, 200},
           vec2f{342, 222},
           vec2f{357, 222},
           vec2f{357, 200},
        },
        verts2f{
           vec2f{358, 203},
           vec2f{358, 225},
           vec2f{373, 225},
           vec2f{373, 203},
        },
        verts2f{
           vec2f{374, 200},
           vec2f{374, 222},
           vec2f{382, 222},
           vec2f{382, 200},
        },
    },
    frame{
        verts2f{
           vec2f{322, 200},
           vec2f{322, 222},
           vec2f{330, 222},
           vec2f{330, 200},
        },
        verts2f{
           vec2f{331, 203},
           vec2f{331, 225},
           vec2f{346, 225},
           vec2f{346, 203},
        },
        verts2f{
           vec2f{347, 200},
           vec2f{347, 222},
           vec2f{362, 222},
           vec2f{362, 200},
        },
        verts2f{
           vec2f{363, 203},
           vec2f{363, 225},
           vec2f{378, 225},
           vec2f{378, 203},
        },
        verts2f{
           vec2f{379, 200},
           vec2f{379, 222},
           vec2f{382, 222},
           vec2f{382, 200},
        },
    },
    frame{
        verts2f{
           vec2f{322, 200},
           vec2f{322, 222},
           vec2f{334, 222},
           vec2f{334, 200},
        },
        verts2f{
           vec2f{335, 203},
           vec2f{335, 225},
           vec2f{350, 225},
           vec2f{350, 203},
        },
        verts2f{
           vec2f{351, 200},
           vec2f{351, 222},
           vec2f{366, 222},
           vec2f{366, 200},
        },
        verts2f{
           vec2f{367, 203},
           vec2f{367, 225},
           vec2f{382, 225},
           vec2f{382, 203},
        },
    },
};

frames whiteAnim{
    frame{
        verts2f{
           vec2f{322, 200 + 22},
           vec2f{322, 222 + 22},
           vec2f{337, 222 + 22},
           vec2f{337, 200 + 22},
        },
        verts2f{
           vec2f{338, 203 + 22},
           vec2f{338, 225 + 22},
           vec2f{353, 225 + 22},
           vec2f{353, 203 + 22},
        },
        verts2f{
           vec2f{354, 200 + 22},
           vec2f{354, 222 + 22},
           vec2f{369, 222 + 22},
           vec2f{369, 200 + 22},
        },
        verts2f{
           vec2f{370, 203 + 22},
           vec2f{370, 225 + 22},
           vec2f{382, 225 + 22},
           vec2f{382, 203 + 22},
        },
    },
    frame{
        verts2f{
           vec2f{322, 203 + 22},
           vec2f{322, 225 + 22},
           vec2f{326, 225 + 22},
           vec2f{326, 203 + 22},
        },
        verts2f{
           vec2f{327, 200 + 22},
           vec2f{327, 222 + 22},
           vec2f{342, 222 + 22},
           vec2f{342, 200 + 22},
        },
        verts2f{
           vec2f{343, 203 + 22},
           vec2f{343, 225 + 22},
           vec2f{358, 225 + 22},
           vec2f{358, 203 + 22},
        },
        verts2f{
           vec2f{359, 200 + 22},
           vec2f{359, 222 + 22},
           vec2f{374, 222 + 22},
           vec2f{374, 200 + 22},
        },
        verts2f{
           vec2f{375, 203 + 22},
           vec2f{375, 225 + 22},
           vec2f{382, 225 + 22},
           vec2f{382, 203 + 22},
        },
    },
    frame{
        verts2f{
           vec2f{322, 203 + 22},
           vec2f{322, 225 + 22},
           vec2f{331, 225 + 22},
           vec2f{331, 203 + 22},
        },
        verts2f{
           vec2f{332, 200 + 22},
           vec2f{332, 222 + 22},
           vec2f{347, 222 + 22},
           vec2f{347, 200 + 22},
        },
        verts2f{
           vec2f{348, 203 + 22},
           vec2f{348, 225 + 22},
           vec2f{363, 225 + 22},
           vec2f{363, 203 + 22},
        },
        verts2f{
           vec2f{364, 200 + 22},
           vec2f{364, 222 + 22},
           vec2f{379, 222 + 22},
           vec2f{379, 200 + 22},
        },
        verts2f{
           vec2f{380, 203 + 22},
           vec2f{380, 225 + 22},
           vec2f{382, 225 + 22},
           vec2f{382, 203 + 22},
        },
    },
    frame{
        verts2f{
           vec2f{322, 203 + 22},
           vec2f{322, 225 + 22},
           vec2f{336, 225 + 22},
           vec2f{336, 203 + 22},
        },
        verts2f{
           vec2f{337, 200 + 22},
           vec2f{337, 222 + 22},
           vec2f{352, 222 + 22},
           vec2f{352, 200 + 22},
        },
        verts2f{
           vec2f{353, 203 + 22},
           vec2f{353, 225 + 22},
           vec2f{368, 225 + 22},
           vec2f{368, 203 + 22},
        },
        verts2f{
           vec2f{369, 200 + 22},
           vec2f{369, 222 + 22},
           vec2f{382, 222 + 22},
           vec2f{382, 200 + 22},
        },
    },
    frame{
        verts2f{
           vec2f{322, 200 + 22},
           vec2f{322, 222 + 22},
           vec2f{325, 222 + 22},
           vec2f{325, 200 + 22},
        },
        verts2f{
           vec2f{326, 203 + 22},
           vec2f{326, 225 + 22},
           vec2f{341, 225 + 22},
           vec2f{341, 203 + 22},
        },
        verts2f{
           vec2f{342, 200 + 22},
           vec2f{342, 222 + 22},
           vec2f{357, 222 + 22},
           vec2f{357, 200 + 22},
        },
        verts2f{
           vec2f{358, 203 + 22},
           vec2f{358, 225 + 22},
           vec2f{373, 225 + 22},
           vec2f{373, 203 + 22},
        },
        verts2f{
           vec2f{374, 200 + 22},
           vec2f{374, 222 + 22},
           vec2f{382, 222 + 22},
           vec2f{382, 200 + 22},
        },
    },
    frame{
        verts2f{
           vec2f{322, 200 + 22},
           vec2f{322, 222 + 22},
           vec2f{330, 222 + 22},
           vec2f{330, 200 + 22},
        },
        verts2f{
           vec2f{331, 203 + 22},
           vec2f{331, 225 + 22},
           vec2f{346, 225 + 22},
           vec2f{346, 203 + 22},
        },
        verts2f{
           vec2f{347, 200 + 22},
           vec2f{347, 222 + 22},
           vec2f{362, 222 + 22},
           vec2f{362, 200 + 22},
        },
        verts2f{
           vec2f{363, 203 + 22},
           vec2f{363, 225 + 22},
           vec2f{378, 225 + 22},
           vec2f{378, 203 + 22},
        },
        verts2f{
           vec2f{379, 200 + 22},
           vec2f{379, 222 + 22},
           vec2f{382, 222 + 22},
           vec2f{382, 200 + 22},
        },
    },
    frame{
        verts2f{
           vec2f{322, 200 + 22},
           vec2f{322, 222 + 22},
           vec2f{334, 222 + 22},
           vec2f{334, 200 + 22},
        },
        verts2f{
           vec2f{335, 203 + 22},
           vec2f{335, 225 + 22},
           vec2f{350, 225 + 22},
           vec2f{350, 203 + 22},
        },
        verts2f{
           vec2f{351, 200 + 22},
           vec2f{351, 222 + 22},
           vec2f{366, 222 + 22},
           vec2f{366, 200 + 22},
        },
        verts2f{
           vec2f{367, 203 + 22},
           vec2f{367, 225 + 22},
           vec2f{382, 225 + 22},
           vec2f{382, 203 + 22},
        },
    },
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
            (float)(rand() % 101) / 100,
            (float)(rand() % 101) / 100,
            (float)(rand() % 101) / 100
        };
}

float frameCount = 0;
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
   frame redFlag = redAnim.at(int(frameCount));
   frame whiteFlag = whiteAnim.at(int(frameCount));
   for(unsigned int j=0; j<redFlag.size(); j++){
      verts2f redFlagVert = redFlag.at(j);
      glColor3f(unpack3(flagColors.at(0)));
      DrawVertices2f(redFlagVert, GL_POLYGON);

      verts2f whiteFlagVert = whiteFlag.at(j);
      glColor3f(unpack3(flagColors.at(1)));
      DrawVertices2f(whiteFlagVert, GL_QUADS);
   }

   // Badan Kapal
   glColor3f(unpack3(shipHullColor));
   DrawVertices2f(shipHullVertices, GL_POLYGON);
   glColor3f(0, 0, 0);
   DrawVertices2f(shipHullVertices, GL_LINE_LOOP);

   frameCount += 0.25;
   if(frameCount >= 7) {
      frameCount = 0;
   }
}
