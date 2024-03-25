#ifndef APLICACION_H
#define APLICACION_H

#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Gameplay.h"
#include "Menu.h"
#include "MenuNivel.h"
#include "Transicion.h"
#include "scode.h"

class Aplicacion
{
private:
    sf::RenderWindow _window;
    sf::RenderStates _state;
    sf::Event _event;

    int _nivel;

    sf::Music _musicmenu;
    sf::SoundBuffer _buffer1;
    sf::Sound _sound1;
public:
    Aplicacion();
    Aplicacion(sf::Vector2u resolucion);
    void setnivel(int n){_nivel=n;}
    void transicionNivel(int nivel);

    ~Aplicacion();
};

#endif // APLICACION_H
