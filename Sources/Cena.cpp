#include "../Headers/Cena.h"
#include <algorithm>

void Cena::Atualizar( float frameTime )
{
    for( GameObject * x : objects )
    {
        x->Atualizar( frameTime );
    }

    for( auto i = objects.begin(); i < objects.end(); i++ )
    {
        if( (*i)->deveDeletar )
        {
            delete *i;
            objects.erase( i );
        }
    }
    

    std::sort(objects.begin(), objects.end(), 
    [](const GameObject* a, const GameObject* b)
    {
        if(*a < *b)
            return true;
        return false;
    });
}

void Cena::Desenhar() const
{
    for( GameObject* x : objects )
    {
        x->Desenhar( );
    }
}

void Cena::CriarObjeto( GameObject* objeto )
{
    objects.push_back( objeto );
}

