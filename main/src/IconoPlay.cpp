#include "IconoPlay.h"

IconoPlay::IconoPlay() //ctor
{
    _texture.loadFromFile("Imagenes/SpriteIconos.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({170, 4, 75, 75});
    _sprite.setPosition(1341, 810);
    PlayState _state = PlayState::Idle;
}
void IconoPlay::setPosicion(bool pos)
{
    _pos = pos;
}
bool IconoPlay::getPosicion()
{
    return _pos;
}
sf::Sprite IconoPlay::getSprite()
{
    return _sprite;
}
void IconoPlay::cmd()
{
    _state = PlayState::Idle;

    if(_pos == true)
    {
        _state = PlayState::Move;
    }
}
void IconoPlay::update()
{
    switch(_state)
    {
    case PlayState::Idle:
        _sprite.setTextureRect({170, 4, 75, 75});
        break;
    case PlayState::Move:
        _sprite.setTextureRect({170, 83, 75, 75});
        break;
    }
}
void IconoPlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
