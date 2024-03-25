#include "Vida.h"

Vida::Vida() //ctor
{
    _texture.loadFromFile("Imagenes/SpriteVida.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({0, 0, 159, 45});
    _sprite.setPosition(21, 16);

    _vida = 3;
}
void Vida::setVIda(int vida)
{
    _vida = vida;
}
int Vida::getVida()
{
    return _vida;
}
void Vida::update()
{
    switch(_vida)
    {
    case 3:
        _sprite.setTextureRect({0, 0, 159, 45});
        break;
    case 2:
        _sprite.setTextureRect({0, 50, 159, 45});
        break;
    case 1:
        _sprite.setTextureRect({0, 100, 159, 45});
        break;
    case 0:
        _sprite.setTextureRect({0, 150, 159, 45});
        break;
    }
}
void Vida::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
Vida::~Vida() //dtor
{

}
