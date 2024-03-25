#include "Gusavirus.h"
#include <iostream>

using namespace std;

//Construcctor
Gusavirus::Gusavirus()
{
    _velocity=2;
    _state = GusavirusState::Vivo;
    _frame=0;
    y=615;
    x=1600;
    SeeligeColor();

    _texture.loadFromFile("Imagenes/gusavirus.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({430,_color,108,65});
    _sprite.setPosition(x,y);
}

//Sets
void Gusavirus::setmurio()
{
    murio=true;
}

void Gusavirus::setmuriendo()
{
    muriendo=true;
}

void Gusavirus::setposx(int posx)
{
    x = posx;
}

void Gusavirus::setposy(int posy)
{
    y = posy;
}

//Gets
int Gusavirus::getposx()
{
    return x;
}

int Gusavirus::getposy()
{
    return y;
}

bool Gusavirus::getmurio()
{
    return murio;
}

bool Gusavirus::getmuriendo()
{
    return muriendo;
}

//Cmd
void Gusavirus::cmd()
{
    if(muriendo==false && murio==false)
    {
        _state = GusavirusState::Vivo;
    }
    if(muriendo==true && murio==false)
    {
        _state = GusavirusState::Muriendo;
    }
    if(murio==true && muriendo==true)
    {
        _state = GusavirusState::Muerto;
    }
}


//Update
void Gusavirus::update()
{
    switch (_state)
    {

    case GusavirusState::Vivo:
    {
        _frame+=0.08;

        if(_frame>4)
        {
            _frame=0;
        }
        _sprite.setTextureRect({440+int(_frame)*110,_color,108,62});

        if(x>278)
        {
            _sprite.setPosition((x),(y));
        }


        if(x<278)
        {
            _sprite.setScale(0.3,0.3);
            _sprite.setPosition(x,y+40);
        }

        if(x>145)
        {
            x-=1*_velocity;
        }

        if(x<=145 && y>=360)
        {
            y-=1*(_velocity-(_velocity*0.5));
            _sprite.setRotation(90);
            _sprite.setPosition(x+20,y+20);
        }

        if(y<360)
        {
            _sprite.setPosition(x+25,y+40);
        }
    }
    break;

    case GusavirusState::Muriendo:
    {
        _framemuerto+=0.3;

        if(_framemuerto>4.3)
        {
            _framemuerto=0;
            murio=true;
        }
        else
        {
            _sprite.setTextureRect({895+int(_framemuerto)*92,_color,92,62});
        }
    }
    break;

    case GusavirusState::Muerto:

        break;
    }

}

//Enseño a windows a dibujar la clase en pantalla
void Gusavirus::draw(sf::RenderTarget& target, sf::RenderStates _states)const
{
    target.draw(_sprite,_states);
}

//Seteo el color
void Gusavirus::SeeligeColor()
{
    int tam;
    int vec[7]= {8,78,148,221,293,367,440};
    tam = rand() % 8;
    _color = vec[tam];
}

//Respawn
void Gusavirus::respawn()
{
    _velocity=2;
    cout << "llego" << endl;
    SeeligeColor();
    y=615;
    x=1550;
    _sprite.setScale(1,1);
    _sprite.setRotation(0);
    _sprite.setPosition(x,y);
    murio=false;
    muriendo=false;
    _state = GusavirusState::Vivo;
}


