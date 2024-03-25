#ifndef EASTEREGG_H
#define EASTEREGG_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum class StateEasterEgg {Idle, View, NoView};

class EasterEgg: public sf::Drawable
{
   private:
    sf::Sprite _sprite;
    sf::Texture _texture;


    float _frame;
    float _frameNoView;

    bool _pos = false;
    bool _activar = false;
    bool _desactivar = false;

    StateEasterEgg _state;
public:
    EasterEgg();

    void setPosicion(bool pos);
    void setActivar(bool act);
    void setDesactivar(bool des);

    bool getPosicion();
    bool getActivar();
    bool getDesactivar();
    sf::Sprite getSprite();

    void cmd();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // EASTEREGG_H
