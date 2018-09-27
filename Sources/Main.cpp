#include <iostream>
#include "../Headers/Allegro.h"
#include "../Headers/Janela.h"
#include "../Headers/Jogo.h"

int main(int argc, char **argv)
{
    Allegro::Init();
    Janela mainWindow(800, 600);
    Jogo game(mainWindow);
    while(true)
    {
        al_clear_to_color(al_map_rgb(60, 60, 60));
        game.Atualizar();
        game.Desenhar();
        al_flip_display();
    }
}