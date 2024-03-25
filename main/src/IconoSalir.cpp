#include "IconoSalir.h"

IconoSalir::IconoSalir() //ctor
{
    _texture.loadFromFile("Imagenes/SpriteIconos.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({254, 4, 62, 75});
    _sprite.setPosition(1427, 810);
    SalirState _state = SalirState::Idle;
}
void IconoSalir::setPosicion(bool pos)
{
    _pos = pos;
}
bool IconoSalir::getPosicion()
{
    return _pos;
}
sf::Sprite IconoSalir::getSprite()
{
    return _sprite;
}
void IconoSalir::cmd()
{
    _state = SalirState::Idle;

    if(_pos == true)
    {
        _state = SalirState::Move;
    }
}
void IconoSalir::update()
{
    switch(_state)
    {
    case SalirState::Idle:
        _sprite.setTextureRect({254, 4, 62, 75});
        break;
    case SalirState::Move:
        _sprite.setTextureRect({254, 83, 62, 75});
        break;
    }
}
void IconoSalir::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
