#include "Aplicacion.h"

Aplicacion::Aplicacion(sf::Vector2u resolucion) // ctor
{
    //Inicializacion programa
    sf::RenderWindow _window(sf::VideoMode(resolucion.x,resolucion.y), "TYPERACER", sf::Style::Default);
    _window.setFramerateLimit(60);

    //set fondo
    sf::RectangleShape fondo;
    fondo.setSize(sf::Vector2f(resolucion.x,resolucion.y));
    sf::Texture menuTexture;
    menuTexture.loadFromFile("Imagenes/FondoMain.jpg");
    fondo.setTexture(&menuTexture);

    if(!_musicmenu.openFromFile("Audio/menu.menu.wav"))
    {
        cout << "Error al cargar el audio";
    }
    _musicmenu.play();
    _musicmenu.setLoop(true);

    if(!_buffer1.loadFromFile("Audio/Menuenter.wav"))
    {
        cout << "Error al cargar el audio";
    }
    _sound1.setBuffer(_buffer1);

    //inicializar menu
    Menu menu(_window.getSize().x, _window.getSize().y);

    //Game Loop (update del juego)
    while(_window.isOpen())
    {
        while(_window.pollEvent(_event))
        {
            if(_event.type == sf::Event::Closed)
            {
                _window.close();
            }
            if(_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Enter)
            {
                _sound1.play();
                if(menu.getState())
                {
                    int x = menu.getSelected();

                    switch(x)
                    {
                    case 0:  //Jugar
                    {
                        //inicializar menu Niveles
                        MenuNivel _menuNivel(_window.getSize().x, _window.getSize().y);

                        bool closeMenuNivel = false;

                        while(_window.isOpen())

                        {
                            sf::Event event2;
                            while(_window.pollEvent(event2))
                            {

                                if(event2.type == sf::Event::Closed)
                                {
                                    _window.close();
                                }
                                if(event2.type == sf::Event::KeyReleased && event2.key.code == sf::Keyboard::Enter)
                                {

                                    if(_menuNivel.getState())
                                    {
                                        int y = _menuNivel.getSelected();

                                        if(y == 0)
                                        {
                                            _sound1.play();
                                            closeMenuNivel = true;
                                            break;
                                        }
                                        else
                                        {
                                            _nivel = y;
                                            _musicmenu.pause();
                                            Transicion transicion(_nivel, &resolucion, &_window); //Pantalla de transicion
                                            Gameplay gameplay(_nivel, &resolucion, &_window); //Entrar al nivel seleccionado
                                            _nivel=gameplay.getnivel();
                                            cout<<_nivel<<endl;

                                            //operador de gameplay
                                            if(gameplay.getGameOver() == true) //Pierde el nivel
                                            {
                                                Transicion transicion(_nivel, &resolucion, &_window); //transicion juego ganaste
                                                gameplay.setGameOver(false);
                                                break;
                                            }
                                            _musicmenu.play();
                                        }
                                    }
                                }
                            }
                            if(closeMenuNivel)
                            {
                                break;
                            }
                            _menuNivel.cmd();
                            _menuNivel.update();

                            _window.clear();

                            _window.draw(fondo);
                            _menuNivel.draw(_window);

                            _window.display();
                        }
                    }
                    break;
                    case 1: //Como Jugar
                    {
                        sf::RectangleShape fondo;
                        fondo.setSize(sf::Vector2f(resolucion.x,resolucion.y));
                        sf::Texture menuTexture;
                        menuTexture.loadFromFile("Imagenes/ComoJugar.jpg");
                        fondo.setTexture(&menuTexture);

                        bool closeComoJugar = false;

                        while(_window.isOpen())
                        {
                            sf::Event event3;
                            while(_window.pollEvent(event3))
                            {
                                if(event3.type == sf::Event::Closed)
                                {
                                    _window.close();
                                }
                                if (event3.type == sf::Event::KeyReleased)
                                {
                                    _sound1.play();
                                    closeComoJugar = true;
                                }
                            }
                            if(closeComoJugar)
                            {
                                break;
                            }
                            _window.clear();
                            _window.draw(fondo);
                            _window.display();
                        }
                    }
                    break;
                    case 2: //Nosotros
                    {
                        sf::RectangleShape fondo;
                        fondo.setSize(sf::Vector2f(resolucion.x,resolucion.y));
                        sf::Texture menuTexture;
                        menuTexture.loadFromFile("Imagenes/Nosotros.jpg");
                        fondo.setTexture(&menuTexture);

                        bool closeNosotros = false;

                        while(_window.isOpen())
                        {
                            sf::Event event4;
                            while(_window.pollEvent(event4))
                            {
                                if(event4.type == sf::Event::Closed)
                                {
                                    _window.close();
                                }
                                if (event4.type == sf::Event::KeyReleased)
                                {
                                    _sound1.play();
                                    closeNosotros = true;
                                }
                            }
                            if(closeNosotros)
                            {
                                break;
                            }
                            _window.clear();
                            _window.draw(fondo);
                            _window.display();
                        }
                    }

                    break;
                    case 3: //Salir
                        _window.close();
                        break;
                    }
                }
            }
        }
        //CMD - Joy
        menu.cmd();

        //Update - Actualiza los estados del juego
        menu.update();

        _window.clear();

        //Draw
        _window.draw(fondo);
        menu.draw(_window);

        //Display - Flip
        _window.display();
    }
}
Aplicacion::Aplicacion(){}
Aplicacion::~Aplicacion() //dtor
{

}
