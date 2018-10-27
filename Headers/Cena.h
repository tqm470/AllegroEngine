#ifndef CENA_CLASS
#define CENA_CLASS
#include <vector>
#include <memory>
#include "Personagem.h"
#include "Projetil.h"
#include "Mouse.h"
#include "Teclado.h"

class GameObject;

class Cena
{
public:
    Cena() = default;
    void Atualizar( float dt );
    void Desenhar() const;
    void CriarObjeto( GameObject* objeto );
private:
    std::vector<GameObject*> objects;
};

#endif