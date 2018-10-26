#ifndef GAMEOBJECT_CLASS
#define GAMEOBJECT_CLASS
#include "Vec2.h"

class GameObject
{
public:
    GameObject( Vec2<float> pos )
        :
        pos(pos)
    {

    }
    virtual void Atualizar( const float frametime ) = 0;
    virtual void Desenhar() const = 0;
    bool operator< ( const GameObject& lhs ) const
    {
        return this->pos.y < lhs.pos.y;
    }
    bool operator> ( const GameObject& lhs ) const
    {
        return this->pos.y > lhs.pos.y;
    }        
public:
    bool deveDeletar = false;
    Vec2<float> pos;
};

#endif