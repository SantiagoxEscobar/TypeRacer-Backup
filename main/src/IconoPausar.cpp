#include "IconoPausar.h"

IconoPausar::IconoPausar() //ctor
{
    _texture.loadFromFile("Imagenes/SpriteIconos.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({87, 4, 75, 75});
    _sprite.setPosition(1258, 810);
    PausarState _state = PausarState::Idle;
}
void IconoPausar::setPosicion(bool pos)
{
    _pos = pos;
}
bool IconoPausar::getPosicion()
{
    return _pos;
}
sf::Sprite IconoPausar::getSprite()
{
    return _sprite;
}
void IconoPausar::cmd()
{
    _state = PausarState::Idle;

    if(_pos == true)
    {
        _state = PausarState::Move;
    }
}
void IconoPausar::update()
{
    switch(_state)
    {
    case PausarState::Idle:
        _sprite.setTextureRect({87, 4, 75, 75});
        break;
    case PausarState::Move:
        _sprite.setTextureRect({87, 83, 75, 75});
        break;
    }
}
void IconoPausar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
