#include "Transicion.h"

using namespace std;

Transicion::Transicion() //ctor
{

}
Transicion::Transicion(int nivel, sf::Vector2u* resolucion, sf::RenderWindow* window)
{
    _nivel = nivel;
    _tiempo = 0;
    _window = window;
    string strNivel = std::to_string(_nivel);

    if(!_font.loadFromFile("Fuentes/Retro Gaming.ttf"))
    {
        cout <<"No existe la fuente";
    }
    if (!_gameover.openFromFile ("Audio/gameover.wav")){
        cout << "No se cargo audio Game over";
    }
    if (!_win.openFromFile ("Audio/win.wav")){
        cout<<"No se cargo audio Win";
    }
    //set fondo
    sf::RectangleShape fondo;
    fondo.setSize(sf::Vector2f(resolucion->x, resolucion->y));
    sf::Texture menutextura;
    menutextura.loadFromFile("Imagenes/Escenario.jpg");
    fondo.setTexture(&menutextura);

    //set rectangulo Negro
    sf::RectangleShape rectangulo(sf::Vector2f(153, 110));
    rectangulo.setFillColor(sf::Color::Black);
    rectangulo.setPosition(125, 575);

    //Transicion dependiendo del retorno de gameplay
    if(nivel <= 0)
    {
        _tranNiv.setFont(_font);
        _tranNiv.setFillColor(sf::Color::White);
        _tranNiv.setString("Perdiste");
        _tranNiv.setCharacterSize(75);
        _tranNiv.setPosition(530,250);
        _tiempo = 9;

        _gameover.play();
    }
    else if(nivel <= 9)
    {
        _tranNiv.setFont(_font);
        _tranNiv.setFillColor(sf::Color::White);
        _tranNiv.setString("Nivel " + strNivel);
        _tranNiv.setCharacterSize(75);
        _tranNiv.setPosition(580,250);
        _tiempo = 2;
    }
    else
    {
        _tranNiv.setFont(_font);
        _tranNiv.setFillColor(sf::Color::White);
        _tranNiv.setString("Ganaste");
        _tranNiv.setCharacterSize(150);
        _tranNiv.setPosition(350,300);
        _tiempo = 7.5;

        _win.play();
    }
    while(_window->isOpen())
    {
        sf::Event event;
        while(_window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                _window->close();
            }
        }
        if(_clock.getElapsedTime().asSeconds()>_tiempo)
        {
            break;
        }
        _window->clear();

        //Draw
        _window->draw(fondo);
        _window->draw(rectangulo);
        _window->draw(_tranNiv);

        //Display - Flip
        _window->display();
    }
    cout << "Cambio de escena - Entrando al gameplay" << endl;
}
Transicion::~Transicion() //dtor
{

}
