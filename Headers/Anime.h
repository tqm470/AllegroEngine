#ifndef ANIME_CLASS
#define ANIME_CLASS
#include "Sprite.h"
#include "Vec2.h"
#include "Cor.h"
#include <vector>

class Anime
{
public:
    Anime(int x, int y, int width, int height, int count, const Imagem& sprite, float delay);
    void Atualizar(float dt);
    void Desenhar(const Vec2<float>& pos) const;
    void DesenharRotacionado( const Vec2<float>& pos, const Vec2<float>& dir ) const;
    void DesenharRotacionado( const Vec2<float>& pos, const float& angulo ) const;
    //Anime& operator= ( const Anime& );
private:
    void Advance();
private:
    const Imagem& sprite;
    const Vec2<int> tam;
    int iCurFrame = 0;
    std::vector<Vec2<int>> frames;
    float delay;
    float curFrameTime = 0.0f;
};


#endif