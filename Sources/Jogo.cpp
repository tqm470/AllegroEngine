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
        sprite1 = new Sprite("Recursos/Actor1.png", 0);
        sprite2 = new Sprite("Recursos/Actor1.png", 1);
        fonte = new Fonte("Recursos/font/Quicksand.otf", 24);
        mouse = new Mouse();
        teclado = new Teclado();
    }
    catch( Bug e )
    {
        std::cout << "Jogo não pode ser iniciado!" << std::endl;
        e.Print();
        exit(1);
    }
    main = new Jogador(*sprite1, {200, 200}, *mouse, *teclado);
    secundario = new Personagem(*sprite2, {400, 200});
    lastFrameTime = al_get_time();
}

void Jogo::Atualizar()
{
    mouse->Atualizar();
    teclado->Atualizar();

    frameTime = al_get_time() - lastFrameTime;
    lastFrameTime = al_get_time();

    main->Atualizar( frameTime );
    secundario->Atualizar( frameTime );
}

void Jogo::Desenhar()
{
    

    main->Desenhar();
    secundario->Desenhar();
    
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