#include "../Headers/Jogo.h"
#include "../Headers/Sprite.h"
#include "../Headers/Jogador.h"
#include <sstream>


Jogo::Jogo(Janela& janela)
    :
    janela(janela),
    imgPos(100, 100)
{
    try
    {
        sprite1 = new Sprite( "Recursos/Actor1.png", 144, 192, 3 );
        sprite2 = new Sprite( "Recursos/Actor1.png", 142, 192, 1 );
        fogo = new Sprite( "Recursos/!Other2.png", 576 / 4, 768 / 2, 3 );

        fonte = new Fonte( "Recursos/font/Quicksand.otf", 24 );
        mouse = new Mouse();
        teclado = new Teclado();
    }
    catch( Bug e )
    {
        std::cout << "Jogo não pode ser iniciado!" << std::endl;
        e.Print();
        exit(1);
    }
    main = new Jogador( *sprite1, {200, 200}, *mouse, *teclado );
    secundario = new Personagem( *sprite2, {400, 200} );
    lastFrameTime = al_get_time();

    foguinho = new Anime( 0, fogo->GetAltura() / 2, fogo->GetLargura() /3, fogo->GetAltura() / 4,
                             3, *fogo, 0.16f );
}

void Jogo::Atualizar()
{
    mouse->Atualizar();
    teclado->Atualizar();

    frameTime = al_get_time() - lastFrameTime;
    lastFrameTime = al_get_time();

    foguinho->Atualizar( frameTime );

    main->Atualizar( frameTime );
    secundario->Atualizar( frameTime );
}

void Jogo::Desenhar()
{
    
    foguinho->Desenhar( {200, 400} );
    secundario->Desenhar();
    main->Desenhar();
    
    
}

Jogo::~Jogo()
{
    delete sprite1;
    delete sprite2;
    delete fonte;
    delete mouse;
    delete teclado;
    delete main;
}