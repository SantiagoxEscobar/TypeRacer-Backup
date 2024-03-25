#include "Menu.h"

Menu::Menu() //ctor
{

}
Menu::Menu(float width, float height)
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
    //Jugar
    _menu[0].setFont(_font);
    _menu[0].setFillColor(sf::Color::White);
    _menu[0].setString("Jugar");
    _menu[0].setCharacterSize(50);
    _menu[0].setPosition(650,230);
    //Como jugar
    _menu[1].setFont(_font);
    _menu[1].setFillColor(sf::Color::White);
    _menu[1].setString("Como Jugar");
    _menu[1].setCharacterSize(50);
    _menu[1].setPosition(570,290);
    //Nosotros
    _menu[2].setFont(_font);
    _menu[2].setFillColor(sf::Color::White);
    _menu[2].setString("Nosotros");
    _menu[2].setCharacterSize(50);
    _menu[2].setPosition(600,350);
    //Salir
    _menu[3].setFont(_font);
    _menu[3].setFillColor(sf::Color::White);
    _menu[3].setString("Salir");
    _menu[3].setCharacterSize(50);
    _menu[3].setPosition(680,410);

    _menuSelected = 0;
    _state = MenuState::Idle;
}

void Menu::cmd() //Cmd

{

    _state = MenuState::Idle;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _state = MenuState::Up;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _state = MenuState::Down;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        _state = MenuState::Select;
    }
}
void Menu::update()
{
    _menu[_menuSelected].setFillColor(sf::Color::White); //Inicio
    switch(_state)
    {
    case MenuState::Up:
        if(_clock.getElapsedTime().asMilliseconds() > 20)
        {
            _sound.play();
            _menuSelected--;
            if(_menuSelected < 0)
            {
                _menuSelected = 3;
            }
            _state = MenuState::Idle;
        }
        _clock.restart();
        break;
    case MenuState::Down:
        if(_clock.getElapsedTime().asMilliseconds() > 20)
        {
            _sound.play();
            _menuSelected++;
            if(_menuSelected > Max_menu-1)
            {
                _menuSelected = 0;
            }
            _state = MenuState::Idle;
        }
        _clock.restart();
        break;
    }
    _menu[_menuSelected].setFillColor(sf::Color::Green); //Select
}

void Menu::draw(sf::RenderWindow& window) //Draw Menu
{
    for (int i = 0; i< Max_menu; i++)
    {
        window.draw(_menu[i]);
    }
    window.draw(_sprite);
}

bool Menu::getState()
{
    if(_state == MenuState::Select)
    {
        return true;
    }
    return false;
}

int Menu::getSelected()
{
    return _menuSelected;
}

Menu::~Menu() //dtor
{

}
