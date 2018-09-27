#ifndef FONTE_CLASS
#define FONTE_CLASS
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include "Vec2.h"

class Fonte
{
public:
    Fonte(std::string path, int tam);
    Fonte(ALLEGRO_FONT* fonte);
    void Escrever(std::string, Vec2<int> pos, ALLEGRO_COLOR cor) const;
private:
    ALLEGRO_FONT* fonte;
    int tam;
};

#endif