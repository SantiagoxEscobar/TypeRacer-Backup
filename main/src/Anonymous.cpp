#include "Anonymous.h"

Anonymous::Anonymous() //ctor
{
    _frame = 0;
    _frameMuerto = 0;

    _texture.loadFromFile("Imagenes/SpriteAnonymous.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({0, 0, 300, 390});
    _sprite.setPosition(563, 61);
    AnonymousState _state = AnonymousState::Idle;
}
//Sets
void Anonymous::setGolpe(bool golpe)
{
    _golpe = golpe;
}
void Anonymous::setMuriendo(bool muriendo)
{
    _muriendo = muriendo;
}
//Gets
bool Anonymous::getGolpe()
{
    return _golpe;
}
bool Anonymous::getMuriendo()
{
    return _muriendo;
}
float Anonymous::getframemuerto()
{
    return _frameMuerto;
}
void Anonymous::cmd()
{
    _state = AnonymousState::Move;


    if(_golpe == true && _muriendo == false)
    {
        _state = AnonymousState::kick;
    }
    if(_muriendo == true)
    {
        _state = AnonymousState::death;
    }
}
void Anonymous::update()
{
    switch(_state)
    {
    case AnonymousState::Idle:
        _sprite.setTextureRect({0, 0, 300, 390});
        break;
    case AnonymousState::Move:
        _frame += 0.05;

        if(_frame > 9)
        {
            _frame = 0;
        }
        _sprite.setTextureRect({300 + int(_frame) * 300, 0, 300, 390});
        break;
    case AnonymousState::kick:
        _frame += 0.3;

        if(_frame > 9)
        {
            _frame = 0;
        }
        _sprite.setTextureRect({300 + int(_frame) * 300, 390, 300, 390});
        break;
    case AnonymousState::death:
    {
        _frameMuerto += 0.08;

        if(_frameMuerto < 11)
        {
            _sprite.setTextureRect({0 + int(_frameMuerto) * 300, 780, 300, 390});
        }
    }
    break;
    }
}
void Anonymous::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
Anonymous::~Anonymous() //dtor
{

}
