#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ArchivosEditor.h"
#include "Archivos.h"

#include "Leo.h"
#include "Gusavirus.h"
#include "Anonymous.h"
#include "Keyword.h"
#include "Score.h"
#include "Nivel.h"
#include "Vida.h"
#include "Aplicacion.h"
#include "IconoSalir.h"
#include "IconoPausar.h"
#include "IconoPlay.h"
#include "EasterEgg.h"

class Gameplay
{
private:
    sf::RenderWindow* _window;
    sf::RenderStates _state;
    sf::Vector2u* _resolucion;
    sf::Clock _clock;
    sf::Clock _clock2;
    sf::Clock _clock3;
    int _cantE;
    int _enemigosActivos;
    int _score;
    int _nivel;
    bool _gameover=false;
    bool _levelUp=false;

    sf::Font _font;
    sf::Text _textPan;
    sf::Text _textPan2;
    sf::Music _jugando;
    sf::Music _aplastar;
    sf::Music _ouch;
    sf::Music _easteregg;

    std::string _textoPantalla;
    char _nombre[30];
    char _caracter;
    bool verifica = true;
    int auxTam = 0;

public:
    Gameplay();
    Gameplay(int nivel, sf::Vector2u* resolucion, sf::RenderWindow* window);

    void setnombre();
    void Renderizar();
    void logicajuego();
    void procesar_eventos();
    void gameLoop();

    void setnivel(int n){_nivel=n;}
    void setGameOver(bool go)
    {
        _gameover=go;
    }

    int getcantEnemigos();
    int getLevelUp()
    {
        return _nivel;
    }
    int getnivel(){return _nivel; }
    bool getGameOver()
    {
        return _gameover;
    }
};

#endif // GAMEPLAY_H

