#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Score: public sf::Drawable
{
private:
    sf::Font _font;
    sf::Text _scoreNiv;

    int _score;

public:
    Score();

    int getScore();
    void sumarScore();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    ~Score();
};

#endif // SCORE_H
