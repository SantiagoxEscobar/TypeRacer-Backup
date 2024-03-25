#ifndef ICONOPAUSAR_H
#define ICONOPAUSAR_H

#include <iostream>

#include <SFML/Graphics.hpp>

enum class PausarState {Idle, Move};

class IconoPausar: public sf::Drawable
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

    bool _pos = false;

    PausarState _state;
public:
    IconoPausar();

    void setPosicion(bool pos);

    bool getPosicion();
    sf::Sprite getSprite();

    void cmd();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // ICONOPAUSAR_H
