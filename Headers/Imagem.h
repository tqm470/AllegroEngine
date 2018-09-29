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
    Imagem( const Vec2<int> tam );
    ALLEGRO_BITMAP* GetImagem() const;
    void Draw( Vec2<int> pos ) const;
    void DrawScaled( const Vec2<float> pos, const Vec2<int> size ) const;
    void DrawScaled( const Vec2<float> pos, const float size ) const;
    void DrawRotated( const Vec2<float> pos, const double angulo ) const;
    void DrawRotated( const Vec2<float> pos, const Vec2<float> dir ) const;
    const int GetAltura() const;
    operator ALLEGRO_BITMAP*() const;
    const int GetLargura() const;
    ~Imagem();
protected:
    int altura;
    int largura;
private:
    const ALLEGRO_BITMAP* imagem;
};


#endif