#include "EasterEgg.h"


EasterEgg::EasterEgg() //ctor
{
    _frame = 0;
    _frameNoView = 0;
    _texture.loadFromFile("Imagenes/Easteregg.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({0, 0, 100, 100});//lo colocotrasparente
    _sprite.setPosition(1080, 275);
    StateEasterEgg _state = StateEasterEgg::Idle;


}
void EasterEgg::setPosicion(bool pos)
{
    _pos = pos;
}
void EasterEgg::setActivar(bool act)
{
    _activar = act;
}

void EasterEgg::setDesactivar(bool des)
{
    _desactivar = des;
}
bool EasterEgg::getPosicion()
{
    return _pos;
}
bool EasterEgg::getActivar()
{
    return _activar;
}
bool EasterEgg::getDesactivar()
{
    return _desactivar;
}
sf::Sprite EasterEgg::getSprite()
{
    return _sprite;
}
void EasterEgg::cmd()
{
    _state = StateEasterEgg::Idle;

    if(_activar == true)
    {
        _state = StateEasterEgg::View;
    }
    if(_desactivar == true)
    {
        _state = StateEasterEgg::NoView;
    }
}
void EasterEgg::update()
{
    switch(_state)
    {
    case StateEasterEgg::Idle:
        _sprite.setTextureRect({0, 0, 100, 100});

        break;
    case StateEasterEgg::View:
        _frame += 0.2;
        if(_frame < 8)
        {
            _sprite.setTextureRect({int(_frame) * 100, 0, 100, 100});
        }
        break;
    case StateEasterEgg::NoView:
        _frameNoView += 0.2;
        if(_frameNoView < 8)
        {
            _sprite.setTextureRect({int(_frameNoView) * 100, 100, 100, 100});
        }
        else
        {
            _desactivar = false;
        }
        break;
    }
}
void EasterEgg::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
