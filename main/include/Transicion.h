#ifndef TRANSICION_H
#define TRANSICION_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Transicion
{
private:
    sf::RenderWindow* _window;
    sf::RenderStates _state;

    sf::Font _font;
    sf::Text _tranNiv;
    sf::Clock _clock;
    sf::Music _gameover;
    sf::Music _win;
    float _tiempo;
    int _nivel;
public:
    Transicion();
    Transicion(int nivel, sf::Vector2u* resolucion, sf::RenderWindow* window);

    ~Transicion();
};

#endif // TRANSICION_H
