#include "Gameplay.h"
#include <iostream>
using namespace std;

//Constructor
Gameplay::Gameplay(){}

//Constructor 2
Gameplay::Gameplay(int nivel, sf::Vector2u* resolucion, sf::RenderWindow* window)
{
    _window = window;
    _resolucion = resolucion;
    _nivel = nivel;

    //int cantenem = 0;

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

    //musica y sonidos
    if(!_font.loadFromFile("Fuentes/Retro Gaming.ttf"))
    {
        cout << "No existe la fuente";
    }
    if (!_jugando.openFromFile("Audio/jugaaando.wav"))
    {
        cout << "No se cargó el audio jugando";
    }
    _jugando.setLoop(true);
    _jugando.play();

    if (!_aplastar.openFromFile("Audio/aplastar.aplastar.wav"))
    {
        cout << "No se cargó el audio aplastar";
    }
    if(!_ouch.openFromFile("Audio/ouch.wav"))
    {
        std::cout<<"No se cargo audio ouch";
    }

    if (!_easteregg.openFromFile ("Audio/easteregg.wav")){
            cout << "No se cargo audio easter";
    }

    //TextoPantalla
    _textPan.setFont(_font);
    _textPan.setFillColor(sf::Color::Black);
    _textPan.setCharacterSize(30);
    _textPan.setPosition(241,747);

    //llamo clases
    Nivel Niv(_nivel);
    Leo Jug;
    Anonymous Eny;
    Gusavirus Gus;
    Keyword palabra;
    Score Sco;
    Vida Vid;
    IconoSalir Sal;
    IconoPausar Pau;
    IconoPlay Pla;
    EasterEgg Eas;

    //Archivo de Keywords
    setnombre();
    ArchivosEditor archEditor(_nombre);
    int cantRegistros = archEditor.contarRegistros();

    Archivos vec[30];
    if(cantRegistros > 0)
    {
        for(int i=0; i<30; i++)
        {
            vec[i] = archEditor.leerRegistro(i);
        }
    }

    //muestro palabra Gusavirus por pantalla
    sf::Text text;
    palabra.setP(vec[rand()%29].getKeyword());

    text.setFont(_font);
    text.setFillColor(sf::Color::White);
    text.setString(palabra.getP());
    text.setCharacterSize(20);
    text.setPosition(Gus.getposx(),Gus.getposy());

    cout << "Keyword: ";
    cout << palabra.getP(); //Keyword del Gusavirus
    cout << endl;

    if(_nivel<5)
    {
        Gus.setvelocity(2);
    }
    //Bandera para pausar juego
    bool EstadoPausa = false;

    //Game Loop
    while(_window->isOpen())
    {
        sf::Event event;
        while(_window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                _window->close();
            }
            if (event.type == sf::Event::MouseButtonPressed) //si se presiona un click
            {
                if (event.mouseButton.button == sf::Mouse::Left && Eas.getPosicion()==true)
                {
                    Eas.setActivar(true);
                    _easteregg.play();
                    _clock3.restart();
                }
                if (event.mouseButton.button == sf::Mouse::Left && Sal.getPosicion()==true)
                {
                    return;
                }
                if (event.mouseButton.button == sf::Mouse::Left && Pau.getPosicion()==true)
                {
                    EstadoPausa = true;
                    _jugando.pause();
                    text.setFillColor(sf::Color::Transparent);
                }
                if (event.mouseButton.button == sf::Mouse::Left && Pla.getPosicion()==true)
                {
                    EstadoPausa = false;
                    _jugando.play();
                    text.setFillColor(sf::Color::White);
                }
            }
            if(event.type == sf::Event::MouseMoved) //localizacion de cursor
            {
                if(Eas.getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                {
                    Eas.setPosicion(true);
                }
                else
                {
                    Eas.setPosicion(false);
                }
                if(Sal.getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                {
                    Sal.setPosicion(true);
                }
                else
                {
                    Sal.setPosicion(false);
                }
                if(Pau.getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                {
                    Pau.setPosicion(true);
                }
                else
                {
                    Pau.setPosicion(false);
                }
                if(Pla.getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                {
                    Pla.setPosicion(true);
                }
                else
                {
                    Pla.setPosicion(false);
                }
            }
            if(!EstadoPausa) //Pausa mecanicas dependiendo la bandera pausa

            {
                if(event.type == sf::Event::TextEntered)
                {
                    if(event.text.unicode == 8 || event.text.unicode == 13) //Backspace y Enter
                    {

                        //Se puede agregar restricciones o no
                    }
                    else if(event.text.unicode == 27) //Escape
                    {
                        return; //Salir de la partida
                    }
                    else if(event.text.unicode < 128)
                    {

                        //Agregar caracter
                        _textoPantalla = _textPan.getString();
                        _textoPantalla += static_cast<char>(event.text.unicode);
                        _textPan.setString(_textoPantalla);

                        //Comparacion - Mecanica principal del juego
                        if(verifica && auxTam < palabra.getTam()-1)
                        {
                            _caracter = static_cast<char>(event.text.unicode);
                            cout << _caracter;

                            int comparacion = palabra.getP()[auxTam] - _caracter;
                            if(comparacion != 0)
                            {
                                verifica = false;
                                _textPan.setString("");
                                _caracter = 0;
                                auxTam = 0;
                            }
                            else
                            {
                                auxTam++;
                            }
                        }
                        if(!verifica)
                        {
                            cout << endl;
                            cout << "VUELVE A INTENTARLO... \n"; //Agregar en pantalla de juego
                            verifica = true;

                            _textPan2.setFont(_font);
                            _textPan2.setFillColor(sf::Color::Black);
                            _textPan2.setString("Error al ingresar datos...");
                            _textPan2.setCharacterSize(36);
                            _textPan2.setPosition(32,827);
                            //si erra leo gusavirus aumenta la vel
                            if(nivel<5)
                            {
                                Gus.setvelocity(6);
                            }
                            else
                            {
                                Gus.setvelocity(4);
                            }
                        }
                        else
                        {
                            verifica = true;
                        }
                        if(verifica && auxTam == palabra.getTam()-1)
                        {
                            _aplastar.play();
                            cout << endl;
                            cout << "VIRUS HECHO PELOTA" << endl;

                            _textPan2.setFont(_font);
                            _textPan2.setFillColor(sf::Color::Black);
                            _textPan2.setString("Datos correctamente ingresados...");
                            _textPan2.setCharacterSize(36);
                            _textPan2.setPosition(32,827);

                            Gus.setmuriendo();
                            Sco.sumarScore();
                            Eny.setGolpe(true);
                            _clock2.restart();

                            _textPan.setString("");
                            _caracter = 0;
                            auxTam = 0;
                        }
                    }
                }
            }

        }
        text.setPosition(Gus.getposx(),Gus.getposy());

        //si el gusano llega a leo el gusano respawnea y leo pierde vida
        if(Gus.getposy() < 360 )
        {
            Gus.setposy(1500);
            cout<<"ee"<<endl;
            Gus.setmuriendo();
            text.setString("");

            for(int i=0; i<=3; i++)
            {
                if(Vid.getVida() == i)
                {
                    Vid.setVIda(i-1);
                    Jug.setGolpe(true);
                    _ouch.play();
                    _clock.restart();
                }
            }
        }
        //timer para que leo titile
        if(_clock.getElapsedTime().asSeconds() > 2 && Jug.getGolpe() == true)
        {
            Jug.setGolpe(false);
        }
        //timer para que Anonymous se enoje
        if(_clock2.getElapsedTime().asSeconds() > 1 && Eny.getGolpe() == true)
        {
            Eny.setGolpe(false);
        }
        //timer para EasterEgg
        if(_clock3.getElapsedTime().asSeconds() > 2 && Eas.getActivar() == true)
        {
            Eas.setActivar(false);
            Eas.setDesactivar(true);
        }
        //si el gusano muere se le asigna otra palabra
        if(Gus.getmurio()==true)
        {
            Gus.respawn();
            palabra.setP(vec[rand()%29].getKeyword());
            text.setPosition(Gus.getposx(),Gus.getposy());
            text.setString(palabra.getP());
            _textPan.setString("");
            _caracter = 0;
            auxTam = 0;
        }

        //Si se llega a 1000 puntos gana el nivel
        if(Sco.getScore()>=1000)
        {
            Eny.setMuriendo(true);
            if(Eny.getframemuerto()>11.5)
            {
                setnivel(10);
                _gameover=true;
                _jugando.pause();
                break;
            }
        }
        //si leo se queda sin vidas muere
        if(Vid.getVida()<=0)
        {
            Jug.setMuriendo(true);
            if(Jug.getframemuerto()>5.5)
            {
                setnivel(0);
                _gameover=true;
                _jugando.pause();
                break;
            }
        }

        //CMD
        Jug.cmd();
        Eny.cmd();
        Gus.cmd();
        Sal.cmd();
        Pau.cmd();
        Pla.cmd();
        Eas.cmd();

        //Update - Actualiza los estados del juego
        if(!EstadoPausa)
        {
            Jug.update();
            Eny.update();
            Gus.update();
            Vid.update();
            Eas.update();
        }
        Sal.update();
        Pau.update();
        Pla.update();

        _window->clear();

        //Draw
        _window->draw(fondo);
        _window->draw(Sal);
        _window->draw(Pau);
        _window->draw(Pla);
        _window->draw(Niv);
        _window->draw(Sco);
        _window->draw(Vid);
        _window->draw(Jug);
        _window->draw(Eny);
        _window->draw(Gus);
        _window->draw(rectangulo);
        _window->draw(text);
        _window->draw(_textPan);
        _window->draw(_textPan2);
        _window->draw(Eas);

        //Display - Flip
        _window->display();
    }
}
/*void Gameplay::compararKeyWord(Keyword* kw)
{
    Keyword* keyword = kw;
    thread t([this, keyword]()
    {
        cout << keyword->getP(); //Keyword del Gusavirus
        cout << endl;

        while(!_exitoPalabra) //forma de aplicar la mecanica
        {
            cout << "A" << endl;
            bool verifica = true;
            int auxTam = 0;

            while(verifica && auxTam < keyword->getTam()-1)
            {
                cout << "A" << endl;
                cout << _caracter << endl;

                _caracter = getch();
                std::cout << _caracter;

                int comparacion = keyword->getP()[auxTam] - _caracter;
                if(comparacion != 0)
                {
                    verifica = false;
                    _caracter = NULL;
                }
                auxTam++;
            }
            std::cout << std::endl << std::endl;

            if(!verifica)
            {
                std::cout << "VUELVE A INTENTARLO \n";
                std::cout << std::endl;
            }
            else
            {
                _exitoPalabra = 1;
                std::cout<< "EXCELENTE \n\n";
            }
        }
    });
    t.detach();
}*/
void Gameplay::logicajuego()  ///Maneja la logica del juego
{
    /*
    //respaw si muere;
    if(compararKeyWord()==true){Gus.setmuriendo();score+=100;}
    //si murio respawnea
    if(Gus[cantenem].getmurio()==true && Gus[cantenem-1]){Gus[cantenem].respawn(); palabra[cantenem].reasignaP();}//codear la funcion respawn
    //si llega a x punto aparece 1 enemigo mas
    if(Gus[cantenem].getposx()==900){Gus[cantenem+1];palabra[cantenem+1].reasignaP();}
    //si gusavirus llega a leo baja vida y respawn
    if(Gus[cantenem].getposy()== 330){vida--;Gus[cantenem].respawn();palabra[cantenem]reasignaP()}//330=posy de leo
    //si leo erra palabra le incrementa la velocidad al gusano
    //si leo junta 1000puntos termina nivel
    if(score==1000){nivel.sumarnivel();}/*si sube de nivel tiene q haber transicion y mueren todos los gusanos en
                                        pantalla*/
    /*
    //si vidas=0 leo muere y gameover
    if(vida==0){gameover}
    //si toca la puerta aparece foto de braian diciendo tremendo
    */
    /*funcion que restree donde se hace click si es en la parte de la puerta aparece*/
}

/*void Gameplay::Renderizar()///En esta funcion van todos los draws
{
    _window->clear();

    //Draw
    _window->draw(fondo);
    _window->draw(Pj);
    _window->draw(Eny);
    for(int i=0;i<canE;i++)
        {
            _window->draw(Gus[i]);

        }
    _window->draw(text);

    //Display - Flip
    _window->display();
}*/

void Gameplay::setnombre()
{
    switch (_nivel)
    {
    case 1:
        strcpy(_nombre,"Archivos/nivel1.dat");
        break;
    case 2:
        strcpy(_nombre,"Archivos/nivel2.dat");
        break;
    case 3:
        strcpy(_nombre,"Archivos/nivel3.dat");
        break;
    case 4:
        strcpy(_nombre,"Archivos/nivel4.dat");
        break;
    case 5:
        strcpy(_nombre,"Archivos/nivel5.dat");
        break;
    case 6:
        strcpy(_nombre,"Archivos/nivel6.dat");
        break;
    case 7:
        strcpy(_nombre,"Archivos/nivel7.dat");
        break;
    case 8:
        strcpy(_nombre,"Archivos/nivel8.dat");
        break;
    case 9:
        strcpy(_nombre,"Archivos/nivel9.dat");
        break;
    }
}
