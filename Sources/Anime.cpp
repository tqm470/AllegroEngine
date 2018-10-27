#include "../Headers/Anime.h"

Anime::Anime(int x, int y, int width, int height, int count, const Imagem& sprite, float delay)
    :
    sprite(sprite),
    delay(delay),
    tam({ width, height })
{
    for(int i = 0; i < count; i++ )
    {
        frames.emplace_back(x + i * width, y);
    }
}

void Anime::Desenhar( const Vec2<float>& pos ) const
{
    al_draw_bitmap_region(sprite, frames[iCurFrame].x, frames[iCurFrame].y,
                             sprite.GetLargura() / 3, sprite.GetAltura() / 4, pos.x, pos.y, 0);
}

void Anime::DesenharRotacionado( const Vec2<float>& pos, const Vec2<float>& dir ) const
{
    Imagem *x;
    try
    {
        x = new Imagem( tam );
    }
    catch( Bug e )
    {
        std::cout << "Ocorreu um erro ao tentar criar a superficie da função de rotação!" << std::endl;
    }
    al_set_target_bitmap( *x );
    al_clear_to_color( al_map_rgba( 0, 0, 0, 0 ) );
    this->Desenhar( {0.0f, 0.0f} );
    al_set_target_backbuffer( al_get_current_display() );
    al_draw_rotated_bitmap( *x, tam.x / 2, tam.y /2, pos.x, pos.y, -std::atan2( dir.x, dir.y ), 0);
    delete x;
}

void Anime::DesenharRotacionado( const Vec2<float>& pos, const float& angulo ) const
{
    Imagem *x;
    try
    {
        x = new Imagem( tam );
    }
    catch( Bug e )
    {
        std::cout << "Ocorreu um erro ao tentar criar a superficie da função de rotação!" << std::endl;
    }
    al_set_target_bitmap( *x );
    al_clear_to_color( al_map_rgba( 0, 0, 0, 0 ) );
    this->Desenhar( {0.0f, 0.0f} );
    al_set_target_backbuffer( al_get_current_display() );
    al_draw_rotated_bitmap( *x, tam.x / 2, tam.y /2, pos.x, pos.y, angulo, 0);
    delete x;
}

void Anime::Atualizar(float dt)
{
    curFrameTime += dt;
    while( curFrameTime > delay )
    {
        Advance();
        curFrameTime -= delay;
    }

}

void Anime::Advance()
{
    if( ++iCurFrame >= frames.size() )
    {
        iCurFrame = 0;
    }
}