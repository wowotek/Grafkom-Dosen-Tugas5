import math
from PIL import Image

red_frame = []
white_frame = []
for n in range(1, 8):
    img = Image.open("bendera{}.png".format(n))
    w, h = img.size
    img = img.convert('RGB')

    red_vertices = []
    wht_vertices = []
    for i in range(w):
        for j in range(h):
            pos = (i, j)
            r, g, b = img.getpixel(pos)
            av = math.floor((r + g + b) / 3)
            if av == 170:
                red_vertices.append((i, j))
            if av == 0:
                wht_vertices.append((i, j))

    white_poly = []
    for i in range(3, len(wht_vertices), 4):
        white_poly.append(
            [(wht_vertices[i-3], wht_vertices[i-2]),
            (wht_vertices[i-1], wht_vertices[i])]
        )

    red_poly = []
    for i in range(3, len(red_vertices), 4):
        red_poly.append(
            [(red_vertices[i-3], red_vertices[i-2]),
            (red_vertices[i-1], red_vertices[i])]
        )

    red_frame.append(red_poly)
    white_frame.append(white_poly)

frame = 0
print("frames redAnim{")
for i in white_frame:
    print("    frame{")
    for j in i:
        print("        verts2f{")
        for k in j:
            for l in k:
                print("           vec2f{}{}, {}{}".format("{", l[0]+322, l[1]+200, "},"))
        print("        },")
    print("    },")
    frame += 1
print("};")