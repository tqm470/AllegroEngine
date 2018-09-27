#include "../Headers/Fonte.h"
#include "../Headers/Bug.h"


Fonte::Fonte( std::string path, int tam )
{
    fonte = al_load_ttf_font( path.c_str(), tam, 0 );
    if(fonte == NULL)
    {
        throw Bug("Erro ao carregar fonte! al_load_ttf_font retornou NULL.");
    }
}
Fonte::Fonte( ALLEGRO_FONT* fonte )
    :
    fonte(fonte)
{
    tam = al_get_font_line_height(fonte);
}

void Fonte::Escrever( std::string texto, Vec2<int> pos, ALLEGRO_COLOR cor ) const
{
    al_draw_text(fonte, cor, pos.x, pos.y, 0, texto.c_str());
}