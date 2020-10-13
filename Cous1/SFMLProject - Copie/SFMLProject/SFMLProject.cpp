// SFMLProject.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>     //ajoute une en tete/header appelé iostream
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");  //Taille de la fenêtre
    sf::RectangleShape shape(sf::Vector2f(300.0f, 500));    //Taille de la forme
    shape.setFillColor(sf::Color::Red);  //Couleur de la forme
    auto mousePos = sf::Mouse::getPosition();
    shape.setOrigin(650,500);
   // shape.setPosition(400, 300);
   // sf::Text text("Poste", sf::Font()); 
   
    while (window.isOpen())   //Tant que la fenetre est ouverte
    {
        sf::Event event;
        while (window.pollEvent(event))  
        {
            auto pos = shape.getPosition();
            if (event.type == sf::Event::Closed) 
                window.close();   
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::X)
                    shape.setFillColor(sf::Color::Green);
                if (event.key.code == sf::Keyboard::C)
                    shape.setFillColor(sf::Color::Red);
                if (event.key.code == sf::Keyboard::W)
                    shape.setFillColor(sf::Color(255, 255, 255));
                if (event.key.code == sf::Keyboard::Z)
                {
                    pos.y -= 1.0f;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    pos.y += 1.0f;
                }
                if (event.key.code == sf::Keyboard::Q)
                {
                    pos.x -= 1.0f;
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    pos.x += 1.0f;
                }
                shape.setPosition(pos);
            }

            else if (event.type == sf::Event::MouseMoved)
            {
                mousePos = sf::Mouse::getPosition();
                //sf::Mouse::setPosition(sf::Vector2f(mousePos), window);
                shape.setPosition(sf::Vector2f(mousePos));
            }

            else if (event.type == sf::Event::MouseWheelScrolled)
            {
                
               float a = shape.getSize().x;
               float b = shape.getSize().y;
             
               
               a += event.mouseWheel.delta*2;
               b += event.mouseWheelScroll.delta;
               
               shape.setSize(sf::Vector2f(a, b));
                   
                  
            }
            /*if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.key.code == sf::Mouse::Right)
                {
                    auto mousePos = sf::Mouse::getPosition();
                    sf::Mouse::setPosition(mousePos, window);
                    auto vrc2 = sf::Vector2f(mousePos);
                    shape.setPosition(mousePos);
                }
            }*/
        }
        
        window.clear();    //effacer la fenetre au cas ou
        window.draw(shape);  //dessine la forme
      //  window.draw(text);
       
        window.display();    //Appele le 2eme buffer pour la synchronisation verticale et eviter le cisaillement
    }

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
