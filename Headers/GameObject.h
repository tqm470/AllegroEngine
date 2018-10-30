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
    virtual Vec2<float> GetPos() const = 0;

    bool operator< ( const GameObject& lhs ) const
    {
        return this->GetPos().y < lhs.GetPos().y;
    }

    bool operator> ( const GameObject& lhs ) const
    {
        return this->GetPos().y > lhs.GetPos().y;
    }

    bool deveDeletar = false;     
protected:
    Vec2<float> pos;
};

#endif