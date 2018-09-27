#include "../Headers/Allegro.h"

Allegro::Allegro()
{

}

void Allegro::Init()
{
    al_init();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
}