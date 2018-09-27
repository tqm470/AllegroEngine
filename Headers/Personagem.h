#ifndef PERSONAGEM_CLASS
#define PERSONAGEM_CLASS
#include <allegro5/allegro.h>
#include "Imagem.h"
#include "Anime.h"

class Personagem
{
public:
    Personagem(Imagem& sprite, Vec2<float> pos);
    ~Personagem();
    void Atualizar( float dt );
    void SetDirection( const Vec2<float>& dir);
    void Desenhar() const;
private:
    enum class Sequencia
    {
        
        AndandoBaixo,
        AndandoEsquerda,
        AndandoDireita,
        AndandoCima,
        ParadoBaixo,
        ParadoEsquerda,
        ParadoDireita,
        ParadoCima,
        Contador
    };
protected:
    Imagem& sprite;
    Vec2<float> pos;
    Vec2<float> dir;
    float velocidade = 1.0f;
    std::vector<Anime> animations;
    Sequencia sequenciaAtual = Sequencia::ParadoBaixo;
};


#endif