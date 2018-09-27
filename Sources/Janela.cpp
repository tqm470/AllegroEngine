#include "../Headers/Janela.h"
#include "../Headers/Bug.h"

Janela::Janela(int largura, int altura)
{
    janela = al_create_display( largura, altura );
    if(janela == NULL)
    {
        throw Bug("Erro ao criar a janela! al_create_display retornou NULL");
    }
}

Janela::~Janela()
{
    al_destroy_display( janela );
}

ALLEGRO_DISPLAY* Janela::GetJanela() const
{
    return janela;
}