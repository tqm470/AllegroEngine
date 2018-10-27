#ifndef JOGADOR_CLASS
#define JOGADOR_CLASS
#include "Cena.h"
#include "Personagem.h"
#include "Mouse.h"
#include "Teclado.h"

class Jogador : public Personagem
{
public:
    Jogador(const Imagem& sprite, const Vec2<float>& pos, const Mouse& mouse, const Teclado& teclado, Cena& scena);
    void Atualizar( float dt ) override;
    void Cast( const Imagem& sprite, const Vec2<float>& dir, float velocidade, float alcance );
    void LerControles();
private:
    Cena& cena;
    float castCD = 0.0f;
    const Mouse& mouse;
    const Teclado& teclado;
};

#endif