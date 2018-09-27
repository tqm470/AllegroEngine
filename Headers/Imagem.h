#ifndef CLASS_IMAGEM
#define CLASS_IMAGEM
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "Vec2.h"


class Imagem
{
public:
    Imagem( const char* path );
    Imagem( ALLEGRO_BITMAP* imagem );
    Imagem( Vec2<int> tam );
    ALLEGRO_BITMAP* GetImagem() const;
    void Draw( Vec2<int> pos ) const;
    void DrawScaled( Vec2<int> pos, Vec2<int> size ) const;
    void DrawScaled( Vec2<int> pos, float size) const;
    int GetAltura() const;
    operator ALLEGRO_BITMAP*() const;
    int GetLargura() const;
    ~Imagem();
protected:
    int altura;
    int largura;
private:
    ALLEGRO_BITMAP* imagem;
};



#endif