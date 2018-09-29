#ifndef SPRITE_CLASS
#define SPRITE_CLASS
#include "Bug.h"
#include "Imagem.h"
#include "Cor.h"
#include <string>



class Sprite : public Imagem
{
    public:
    Sprite( const std::string path, const int spriteWidth, const int spriteHeight, const int n )
        :
        Imagem({ spriteWidth, spriteHeight })
    {
        Imagem* x;

        try
        {
            x = new Imagem(path.c_str());
        }
        catch( Bug e)
        {
            std::cout << "Erro ao carregar sprite! Imagem em: " << path << " retornou NULL" << std::endl;
        }

        al_set_target_bitmap( *this );
        al_clear_to_color( al_map_rgba(0, 0, 0, 0) );
        int w = n <= 3 ? 0 : 1;
        al_draw_bitmap_region(*x,largura * (n % 4), altura * w, largura, altura, 0, 0, 0);
        al_set_target_backbuffer( al_get_current_display() );
        delete x;
    }

};

#endif