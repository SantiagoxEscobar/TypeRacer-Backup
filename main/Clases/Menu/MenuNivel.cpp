#include "MenuNivel.h"

MenuNivel::MenuNivel()
{

}
MenuNivel::MenuNivel(float width, float height) //ctor
{
    if(!_buffer.loadFromFile("Audio/Selectmenu.wav"))
    {
        cout << "Error al cargar el audio";
    }
    _sound.setBuffer(_buffer);

    if(!_font.loadFromFile("Fuentes/Retro Gaming.ttf"))
    {
        cout <<"No existe la fuente";
    }

    //Volver
    _menu[0].setFont(_font);
    _menu[0].setFillColor(sf::Color::White);
    _menu[0].setString("Volver");
    _menu[0].setCharacterSize(50);
    _menu[0].setPosition(638,230);
    //Nivel 1
    _menu[1].setFont(_font);
    _menu[1].setFillColor(sf::Color::White);
    _menu[1].setString("Nivel 1");
    _menu[1].setCharacterSize(50);
    _menu[1].setPosition(638,290);
    _menu[1].setColor(sf::Color(255,255,255,255));
    //Nivel 2
    _menu[2].setFont(_font);
    _menu[2].setFillColor(sf::Color::White);
    _menu[2].setString("Nivel 2");
    _menu[2].setCharacterSize(50);
    _menu[2].setPosition(638,350);
    _menu[2].setColor(sf::Color(255,255,255,255));
    //Nivel 3
    _menu[3].setFont(_font);
    _menu[3].setFillColor(sf::Color::White);
    _menu[3].setString("Nivel 3");
    _menu[3].setCharacterSize(50);
    _menu[3].setPosition(638,410);
    _menu[3].setColor(sf::Color(255,255,255,255));

    //Nivel 4
    _menu[4].setFont(_font);
    _menu[4].setFillColor(sf::Color::White);
    _menu[4].setString("Nivel 4");
    _menu[4].setCharacterSize(50);
    _menu[4].setPosition(638,290);
    _menu[4].setColor(sf::Color(0,0,0,0));

    //Nivel 5
    _menu[5].setFont(_font);
    _menu[5].setFillColor(sf::Color::White);
    _menu[5].setString("Nivel 5");
    _menu[5].setCharacterSize(50);
    _menu[5].setPosition(638,350);
    _menu[5].setColor(sf::Color(0,0,0,0));
    //Nivel 6
    _menu[6].setFont(_font);
    _menu[6].setFillColor(sf::Color::White);
    _menu[6].setString("Nivel 6");
    _menu[6].setCharacterSize(50);
    _menu[6].setPosition(638,410);
    _menu[6].setColor(sf::Color(0,0,0,0));
    //Nivel 7
    _menu[7].setFont(_font);
    _menu[7].setFillColor(sf::Color::White);
    _menu[7].setString("Nivel 7");
    _menu[7].setCharacterSize(50);
    _menu[7].setPosition(638,290);
    _menu[7].setColor(sf::Color(0,0,0,0));
    //Nivel 8
    _menu[8].setFont(_font);
    _menu[8].setFillColor(sf::Color::White);
    _menu[8].setString("Nivel 8");
    _menu[8].setCharacterSize(50);
    _menu[8].setPosition(638,350);
    _menu[8].setColor(sf::Color(0,0,0,0));
    //Nivel 9
    _menu[9].setFont(_font);
    _menu[9].setFillColor(sf::Color::White);
    _menu[9].setString("Nivel 9");
    _menu[9].setCharacterSize(50);
    _menu[9].setPosition(638,410);
    _menu[9].setColor(sf::Color(0,0,0,0));

    _menuSelected = 0;
    _state = MenuNivelState::Idle;
}
void MenuNivel::cmd() //Cmd
{
    _state = MenuNivelState::Idle;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _state = MenuNivelState::Up;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _state = MenuNivelState::Down;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        _state = MenuNivelState::Select;
    }
}

void MenuNivel::update()
{
    _menu[_menuSelected].setFillColor(sf::Color::White); //Inicio
    switch(_state)
    {
    case MenuNivelState::Up:
        if(_clock.getElapsedTime().asMilliseconds() > 20)
        {
            _sound.play();
            _menuSelected--;
            if(_menuSelected < 0)
            {
                _menu[1].setPosition(0,0);
                _menu[1].setColor(sf::Color(0,0,0,0));

                _menu[2].setPosition(0,0);
                _menu[2].setColor(sf::Color(0,0,0,0));

                _menu[3].setPosition(0,0);
                _menu[3].setColor(sf::Color(0,0,0,0));

                _menu[7].setPosition(638,290);
                _menu[7].setColor(sf::Color(255,255,255,255));

                _menu[8].setPosition(638,350);
                _menu[8].setColor(sf::Color(255,255,255,255));

                _menu[9].setPosition(638,410);
                _menu[9].setColor(sf::Color(255,255,255,255));

                _menuSelected = 9;
            }

            if(_menuSelected > 3 && _menuSelected < 7)
            {

                _menu[7].setPosition(0,0);
                _menu[7].setColor(sf::Color(0,0,0,0));

                _menu[8].setPosition(0,0);
                _menu[8].setColor(sf::Color(0,0,0,0));

                _menu[9].setPosition(0,0);
                _menu[9].setColor(sf::Color(0,0,0,0));

                _menu[4].setPosition(638,290);
                _menu[4].setColor(sf::Color(255,255,255,255));

                _menu[5].setPosition(638,350);
                _menu[5].setColor(sf::Color(255,255,255,255));

                _menu[6].setPosition(638,410);
                _menu[6].setColor(sf::Color(255,255,255,255));

            }

            if(_menuSelected > 0 && _menuSelected < 4)
            {

                _menu[4].setPosition(0,0);
                _menu[4].setColor(sf::Color(0,0,0,0));

                _menu[5].setPosition(0,0);
                _menu[5].setColor(sf::Color(0,0,0,0));

                _menu[6].setPosition(0,0);
                _menu[6].setColor(sf::Color(0,0,0,0));

                _menu[1].setPosition(638,290);
                _menu[1].setColor(sf::Color(255,255,255,255));

                _menu[2].setPosition(638,350);
                _menu[2].setColor(sf::Color(255,255,255,255));

                _menu[3].setPosition(638,410);
                _menu[3].setColor(sf::Color(255,255,255,255));

            }

            _state = MenuNivelState::Idle;
        }
        _clock.restart();
        break;
    case MenuNivelState::Down:
        if(_clock.getElapsedTime().asMilliseconds() > 20)
        {
            _sound.play();
            _menuSelected++;
            if(_menuSelected > Max_menunivel-1)
            {
                _menuSelected = 0;
            }
            if(_menuSelected > 3 && _menuSelected < 7)
            {
                _menu[1].setPosition(0,0);
                _menu[1].setColor(sf::Color(0,0,0,0));

                _menu[2].setPosition(0,0);
                _menu[2].setColor(sf::Color(0,0,0,0));

                _menu[3].setPosition(0,0);
                _menu[3].setColor(sf::Color(0,0,0,0));

                _menu[4].setPosition(638,290);
                _menu[4].setColor(sf::Color(255,255,255,255));

                _menu[5].setPosition(638,350);
                _menu[5].setColor(sf::Color(255,255,255,255));

                _menu[6].setPosition(638,410);
                _menu[6].setColor(sf::Color(255,255,255,255));

            }

            if(_menuSelected > 6 && _menuSelected < 10)
            {

                _menu[4].setPosition(0,0);
                _menu[4].setColor(sf::Color(0,0,0,0));

                _menu[5].setPosition(0,0);
                _menu[5].setColor(sf::Color(0,0,0,0));

                _menu[6].setPosition(0,0);
                _menu[6].setColor(sf::Color(0,0,0,0));

                _menu[7].setPosition(638,290);
                _menu[7].setColor(sf::Color(255,255,255,255));

                _menu[8].setPosition(638,350);
                _menu[8].setColor(sf::Color(255,255,255,255));

                _menu[9].setPosition(638,410);
                _menu[9].setColor(sf::Color(255,255,255,255));

            }

            if(_menuSelected > 0 && _menuSelected < 4)
            {

                _menu[7].setPosition(0,0);
                _menu[7].setColor(sf::Color(0,0,0,0));

                _menu[8].setPosition(0,0);
                _menu[8].setColor(sf::Color(0,0,0,0));

                _menu[9].setPosition(0,0);
                _menu[9].setColor(sf::Color(0,0,0,0));

                _menu[1].setPosition(638,290);
                _menu[1].setColor(sf::Color(255,255,255,255));

                _menu[2].setPosition(638,350);
                _menu[2].setColor(sf::Color(255,255,255,255));

                _menu[3].setPosition(638,410);
                _menu[3].setColor(sf::Color(255,255,255,255));

            }
            _state = MenuNivelState::Idle;
        }
        _clock.restart();
        break;
    }
    _menu[_menuSelected].setFillColor(sf::Color::Green); //Select
}

void MenuNivel::draw(sf::RenderWindow& window) //Draw Menu
{
    for (int i = 0; i< Max_menunivel; i++)
    {
        window.draw(_menu[i]);
    }
    window.draw(_sprite);
}

bool MenuNivel::getState()
{
    if(_state == MenuNivelState::Select)
    {
        return true;
    }
    return false;
}

int MenuNivel::getSelected()
{
    return _menuSelected;
}
MenuNivel::~MenuNivel()
{
    //dtor
}
