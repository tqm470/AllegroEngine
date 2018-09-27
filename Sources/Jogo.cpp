#include "../Headers/Jogo.h"
#include "../Headers/Sprite.h"
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
    main = new Personagem(*sprite1, {200, 200});
    secundario = new Personagem(*sprite2, {400, 200});
    lastFrameTime = al_get_time();
}

void Jogo::Atualizar()
{
    mouse->Atualizar();
    teclado->Atualizar();

    frameTime = al_get_time() - lastFrameTime;
    lastFrameTime = al_get_time();

    Vec2<float> dir = { 0.0f, 0.0f };

    if( teclado->Tecla( ALLEGRO_KEY_UP ) )
    {
        dir = { 0.0f, -1.0f };
    }
    else if( teclado->Tecla( ALLEGRO_KEY_DOWN ) )
    {
        dir = { 0.0f, 1.0f };
    }
    else if( teclado->Tecla( ALLEGRO_KEY_LEFT ) )
    {
        dir = { -1.0f, 0.0f };
    }
    else if( teclado->Tecla( ALLEGRO_KEY_RIGHT ) )
    {
        dir = { 1.0f, 0.0f };
    }

    main->SetDirection( dir );
    dir = {0.0f , 0.0f};

    if( teclado->Tecla( ALLEGRO_KEY_W ) )
    {
        dir = { 0.0f, -1.0f };
    }
    else if( teclado->Tecla( ALLEGRO_KEY_S ) )
    {
        dir = { 0.0f, 1.0f };
    }
    else if( teclado->Tecla( ALLEGRO_KEY_A ) )
    {
        dir = { -1.0f, 0.0f };
    }
    else if( teclado->Tecla( ALLEGRO_KEY_D ) )
    {
        dir = { 1.0f, 0.0f };
    }

    secundario->SetDirection( dir );

    
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