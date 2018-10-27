#include "../Headers/Jogo.h"
#include "../Headers/Sprite.h"
#include "../Headers/Jogador.h"
#include <algorithm>
#include <sstream>
#include <cmath>


Jogo::Jogo(Janela& janela)
    :
    janela(janela)
{
    try
    {
        sprite1 = new Sprite( "Recursos/Actor1.png", 144, 192, 3 );
        sprite2 = new Sprite( "Recursos/Actor1.png", 142, 192, 1 );
        fogo = new Sprite( "Recursos/!Other2.png", 576 / 4, 768 / 2, 3 );

        fonte = new Fonte( "Recursos/font/Quicksand.otf", 24 );
        mouse = new Mouse();
        teclado = new Teclado();

        cena = new Cena();
    }
    catch( Bug e )
    {
        std::cout << "Jogo não pode ser iniciado!" << std::endl;
        e.Print();
        exit(1);
    }
    lastFrameTime = al_get_time();

    Jogador* main( new Jogador( *sprite1, {400, 300}, *mouse, *teclado, *cena ) );

    cena->CriarObjeto( main );
    
}

void Jogo::Atualizar()
{
    mouse->Atualizar();
    teclado->Atualizar();

    frameTime = al_get_time() - lastFrameTime;
    lastFrameTime = al_get_time();

    timer += frameTime;
    if(timer > 2.0f )
    {
        std::cout << frameTime << std::endl;
        timer = 0.0f;
    }

    cena->Atualizar( frameTime );
    
}

void Jogo::Desenhar()
{
    Vec2<float> mDir = ( mouse->GetPosition() - Vec2<float>(400.0f, 300.0f) ).Normalizado();
    cena->Desenhar();
}

Jogo::~Jogo()
{
    delete sprite1;
    delete sprite2;
    delete fonte;
    delete mouse;
    delete teclado;
    delete fogo;
    delete cena;
}