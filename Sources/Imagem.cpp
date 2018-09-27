#include "../Headers/Imagem.h"
#include "../Headers/Bug.h"

Imagem::Imagem( const char* path ) 
{
    imagem = al_load_bitmap(path);
    if(imagem == NULL)
    {
        throw Bug("Erro ao construir imagem! al_load_bitmap retornou NULL");
    }
    altura = al_get_bitmap_height(imagem);
    largura = al_get_bitmap_width(imagem);
}

Imagem::Imagem( ALLEGRO_BITMAP* imagem)
{
    if(imagem == NULL)
    {
        throw Bug("Erro ao construir imagem! construtor recebeu ponteiro NULL");
    }
    this->imagem = imagem;
    altura = al_get_bitmap_height( *this );
    largura = al_get_bitmap_width( *this );
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
    return imagem;
}

Imagem::operator ALLEGRO_BITMAP*() const
{
    return imagem;
}

void Imagem::Draw( Vec2<int> pos ) const
{
    al_draw_bitmap(imagem, pos.x, pos.y, 0);
}

void Imagem::DrawScaled( Vec2<int> pos, Vec2<int> tam ) const
{
    al_draw_scaled_bitmap( imagem, 0, 0, largura, altura, pos.x, pos.y, tam.x, tam.y, 0 );
}

void Imagem::DrawScaled( Vec2<int> pos, float tam ) const
{
    al_draw_scaled_bitmap( imagem, 0, 0, largura, altura, pos.x, pos.y, largura * tam, altura * tam, 0 );
}

int Imagem::GetAltura() const
{
    return altura;
}

int Imagem::GetLargura() const
{
    return largura;
}

Imagem::~Imagem()
{
    al_destroy_bitmap(imagem);
}