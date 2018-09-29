#include "../Headers/Imagem.h"
#include "../Headers/Bug.h"

Imagem::Imagem( const char* path ) 
{
    imagem = al_load_bitmap(path);
    if(imagem == NULL)
    {
        throw Bug("Erro ao construir imagem! al_load_bitmap retornou NULL");
    }
    altura = al_get_bitmap_height( (ALLEGRO_BITMAP*)imagem );
    largura = al_get_bitmap_width( (ALLEGRO_BITMAP*)imagem );
}

Imagem::Imagem( ALLEGRO_BITMAP* imagem)
{
    if(imagem == NULL)
    {
        throw Bug("Erro ao construir imagem! construtor recebeu ponteiro NULL");
    }
    this->imagem = imagem;
    altura = al_get_bitmap_height( imagem );
    largura = al_get_bitmap_width( imagem );
}

Imagem::Imagem( Vec2<int> tam )
{
    imagem = al_create_bitmap(tam.x, tam.y);
    if(imagem == NULL)
    {
        throw Bug("Erro ao cirar imagem. al_create_bitmap retornou NULL");
    }
    altura = al_get_bitmap_height( *this );
    largura = al_get_bitmap_width( *this );
}

ALLEGRO_BITMAP* Imagem::GetImagem() const
{
    return (ALLEGRO_BITMAP*)imagem;
}

Imagem::operator ALLEGRO_BITMAP*() const
{
    return (ALLEGRO_BITMAP*)imagem;
}

void Imagem::Draw( Vec2<int> pos ) const
{
    al_draw_bitmap((ALLEGRO_BITMAP*)imagem, pos.x, pos.y, 0);
}

void Imagem::DrawScaled( const Vec2<float> pos, const Vec2<int> tam ) const
{
    al_draw_scaled_bitmap( *this, 0, 0, largura, altura, pos.x, pos.y, tam.x, tam.y, 0 );
}

void Imagem::DrawScaled( const Vec2<float> pos, const float tam ) const
{
    al_draw_scaled_bitmap( *this, 0, 0, largura, altura, pos.x, pos.y, largura * tam, altura * tam, 0 );
}

void Imagem::DrawRotated( const Vec2<float> pos, const Vec2<float> dir ) const
{
    al_draw_rotated_bitmap( *this, largura / 2, altura / 2, pos.x, pos.y, 
                            -(std::atan2(dir.x, dir.y)), 0);
}

const int Imagem::GetAltura() const
{
    return altura;
}

const int Imagem::GetLargura() const
{
    return largura;
}

Imagem::~Imagem()
{
    al_destroy_bitmap( *this );
}