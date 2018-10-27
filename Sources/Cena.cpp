#include "../Headers/Cena.h"

void Cena::Atualizar( float frameTime )
{
    //objects.at( 0 )->Atualizar( frameTime );
    //for( auto i = objects.begin(); i < objects.end(); i++ )
    //{
    //    (*i)->Atualizar( frameTime );
    //}

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

