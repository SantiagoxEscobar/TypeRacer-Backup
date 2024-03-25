#ifndef ICONOPLAY_H
#define ICONOPLAY_H

#include <iostream>

#include <SFML/Graphics.hpp>

enum class PlayState {Idle, Move};

class IconoPlay: public sf::Drawable
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

    bool _pos = false;

    PlayState _state;
public:
    IconoPlay();

    void setPosicion(bool pos);

    bool getPosicion();
    sf::Sprite getSprite();

    void cmd();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // ICONOPLAY_H
