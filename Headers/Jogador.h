#ifndef JOGADOR_CLASS
#define JOGADOR_CLASS
#include "Personagem.h"
#include "Mouse.h"
#include "Teclado.h"

class Jogador : public Personagem
{
public:
    Jogador(const Imagem& sprite, const Vec2<float>& pos, const Mouse& mouse, const Teclado& teclado);
    void Atualizar( float dt ) override;
    void LerControles();
private:
    const Mouse& mouse;
    const Teclado& teclado;
};

#endif