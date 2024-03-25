#ifndef MENU_H
#define MENU_H
#define Max_menu 4

#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

enum class MenuState {Idle, Up, Down, Select};

class Menu
{
private:
    sf::Font _font;
    sf::Text _menu[Max_menu];
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Clock _clock;
    sf::SoundBuffer _buffer;
    sf::Sound _sound;

    int _menuSelected;
    MenuState _state;

public:
    Menu();
    Menu(float width, float height);

    void cmd();
    void update();
    void draw(sf::RenderWindow& window);

    int getSelected();
    bool getState();
    ~Menu();

};
//Funciones menu
//void Aplicacion();
#endif // MENU_H
