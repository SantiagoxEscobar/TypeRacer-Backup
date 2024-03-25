#include "Leo.h"

Leo::Leo() //ctor
{
    _frame = 1;
    _frameGolpe = 0;
    _frameMuerto = 0;

    _texture.loadFromFile("Imagenes/SpriteLeo.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({10, 10, 144, 120});
    _sprite.setPosition(30, 330);
    LeoState _state = LeoState::Idle;

    if(!_teclado.openFromFile("Audio/tecla.wav"))
    {
        std::cout<<"No se cargo audio teclado";
    }
}
//Sets
void Leo::setGolpe(bool golpe)
{

    _golpe = golpe;
}
void Leo::setMuriendo(bool muriendo)
{
    _muriendo = muriendo;
}
//Gets
bool Leo::getGolpe()
{
    return _golpe;
}
bool Leo::getMuriendo()
{
    return _muriendo;
}
float Leo::getframemuerto()
{
    return _frameMuerto;
}
//Cmd
void Leo::cmd()
{
    _state = LeoState::Idle;

    for (int i = 0; i < sf::Keyboard::KeyCount; i++) //Tocando cualquier tecla cambia de estado
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i)))
        {
            _state = LeoState::Move;
        }
    }
    if(_golpe == true && _muriendo == false)
    {
        _state = LeoState::kick;
    }
    if(_muriendo == true)
    {
        _state = LeoState::death;
    }
}
void Leo::update() //comprueba estado y ejecuta el movimiento si es asi
{
    switch(_state)
    {
    case LeoState::Idle:
        _sprite.setTextureRect({10, 10, 144, 120});
        break;
    case LeoState::Move:
        if(_clock.getElapsedTime().asMilliseconds() > 20)
        {
            _frame += 2;
            _teclado.play();

            if(_frame >= 3)
            {
                _frame = 0;
            }
            _sprite.setTextureRect({164 + int(_frame) * 154, 10, 144, 120});
        }
        _clock.restart();
        break;
    case LeoState::kick:
        _frameGolpe += 0.18;

        if(_frameGolpe > 2)
        {
            _frameGolpe = 0;
        }
        _sprite.setTextureRect({626 + int(_frameGolpe) * 154, 10, 144, 120});
        break;
    case LeoState::death:
    {
        _frameMuerto += 0.05;

        if(_frameMuerto < 6)
        {
            _sprite.setTextureRect({10+ int(_frameMuerto) * 154, 142, 144, 120});
        }
    }
    break;
    }
}
void Leo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

