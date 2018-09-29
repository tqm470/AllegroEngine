#ifndef JOGO_CLASS
#define JOGO_CLASS
#include "Janela.h"
#include "Imagem.h"
#include "Fonte.h"
#include "Mouse.h"
#include "Personagem.h"
#include "Teclado.h"


class Jogo
{
public:
    Jogo(Janela& janela);
    ~Jogo();
    void Atualizar();
    void Desenhar();
private:
    float lastFrameTime = 0.0f;
    float frameTime = 0.0f;
    float timer = 0.0f;

    Janela& janela;
    Imagem* sprite1;
    Imagem* sprite2;
    Imagem* fogo;
    Anime* foguinho;
    Personagem* main;
    Personagem* secundario;
    Fonte* fonte;
    Mouse* mouse;
    Teclado* teclado;
    Vec2<int> imgPos;
};

#endif