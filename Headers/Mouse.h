#ifndef MOUSE_CLASS
#define MOUSE_CLASS
#include <allegro5/allegro.h>
#include "Vec2.h"
#include "Bug.h"

class Mouse
{
public:
    Mouse();
    void Atualizar();
    Vec2<int> GetPosition();
    bool Botao(int botao);
    ~Mouse();
private:
    ALLEGRO_MOUSE_STATE estado;
};

#endif