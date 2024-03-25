#ifndef NIVEL_H
#define NIVEL_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Nivel: public sf::Drawable
{
private:
    sf::Font _font;
    sf::Text _nivNiv;

    int _nivel;
public:
    Nivel();
    Nivel(int nivel);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    ~Nivel();
};

#endif // NIVEL_H
