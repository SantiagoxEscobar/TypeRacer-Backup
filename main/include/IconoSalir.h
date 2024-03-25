#ifndef ICONOSALIR_H
#define ICONOSALIR_H

#include <iostream>

#include <SFML/Graphics.hpp>

enum class SalirState {Idle, Move};

class IconoSalir: public sf::Drawable
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

    bool _pos = false;

    SalirState _state;
public:
    IconoSalir();

    void setPosicion(bool pos);

    bool getPosicion();
    sf::Sprite getSprite();

    void cmd();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // ICONOSALIR_H
