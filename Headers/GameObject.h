#ifndef GAMEOBJECT_CLASS
#define GAMEOBJECT_CLASS

class GameObject
{
public:
    virtual void Atualizar( const float frametime ) = 0;
    virtual void Desenhar() const = 0;
public:
    bool deveDeletar = false;
};

#endif