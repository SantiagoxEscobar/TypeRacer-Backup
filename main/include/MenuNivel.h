#ifndef MENUNIVEL_H
#define MENUNIVEL_H
#define Max_menunivel 10

#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

enum class MenuNivelState {Idle, Up, Down, Select};

class MenuNivel //Modificar
{
private:
    sf::Font _font;
    sf::Text _menu[Max_menunivel];
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Clock _clock;
    sf::SoundBuffer _buffer;
    sf::Sound _sound;

    int _menuSelected;
    MenuNivelState _state;

public:
    MenuNivel();
    MenuNivel(float width, float height);
    void cmd();
    void update();
    void draw(sf::RenderWindow& window);
    void ordenmenus();

    int getSelected();
    bool getState();

    ~MenuNivel();
};

#endif // MENUNIVEL_H
