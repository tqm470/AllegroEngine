#include "../Headers/Anime.h"

Anime::Anime(int x, int y, int width, int height, int count, const Imagem& sprite, float delay)
    :
    sprite(sprite),
    delay(delay)
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