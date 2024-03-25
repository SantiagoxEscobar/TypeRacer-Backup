#pragma once
#ifndef ANONYMOUS_H
#define ANONYMOUS_H

#include <SFML/Graphics.hpp>

enum class AnonymousState {Idle, Move, kick, death};

class Anonymous: public sf::Drawable // en progreso
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

    float _frame;
    float _frameGolpe;
    float _frameMuerto;

    bool _golpe = false;
    bool _muriendo = false;
    bool _desaparece = false;

    AnonymousState _state;
public:
    Anonymous();

    //Sets
    void setGolpe(bool golpe);
    void setMuriendo(bool muriendo);
    //Gets
    bool getGolpe();
    bool getMuriendo();
    float getframemuerto();

    void cmd();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    ~Anonymous();
};

#endif // ANONYMOUS_H
