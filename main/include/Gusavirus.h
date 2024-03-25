#pragma once
#ifndef GUSAVIRUS_H
#define GUSAVIRUS_H
#include <SFML/Graphics.hpp>
#include "Keyword.h"

enum class  GusavirusState {Vivo, Muriendo, Muerto};

class Gusavirus: public sf::Drawable  // en progreso
{
private:
    sf::Sprite _sprite;
    sf::Sprite _spritemuerte;
    sf::Texture _texture;
    int _color;
    int x;
    int y;
    float _velocity = 2;
    float _frame;
    float _framemuerto=0;
    bool murio = false;
    bool muriendo = false;
    GusavirusState _state;

public:
    //Construcctor
    Gusavirus();
    //Sets
    void setmurio();
    void setvelocity(float vel){_velocity=vel;};
    void setmuriendo();
    void setposx(int posx);
    void setposy(int posy);
    //Gets
    bool getmurio();
    bool getmuriendo();
    int getposx();
    int getposy();
    //Cmd
    void cmd();
    //Update
    void update();
    //Enseño a windows a dibujar la clase en pantalla
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    //Seteo el color
    void SeeligeColor();
    //Respawn
    void respawn();
};

#endif // GUSAVIRUS_H

