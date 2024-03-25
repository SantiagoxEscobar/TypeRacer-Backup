#ifndef VIDA_H
#define VIDA_H

#include <SFML/Graphics.hpp>

class Vida: public sf::Drawable
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

    int _vida;

public:
    Vida();

    void setVIda(int vida);
    int getVida();

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    ~Vida();
};

#endif // VIDA_H
