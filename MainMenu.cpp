#include "MainMenu.hpp"
#include "Functions.hpp"
#include "SettingsMenu.hpp"
#include "Game.hpp"



void menu (sf::RenderWindow &window, sf::Event ev, sf::View &view) {

    int r = rand_uns(0, 255), g = rand_uns(0, 255), b = rand_uns(0, 255);

    sf::Clock clock;


    bool isMenu = 1;


    sf::Font font;
    font.loadFromFile("../Halogen_0.ttf");



    sf::Text menu1("", font, 90);
    menu1.setFillColor(sf::Color::White);
    menu1.setPosition(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 - 120);
    menu1.setString(L"Играть");
    menu1.setOrigin(menu1.getLocalBounds().width / 2, menu1.getLocalBounds().height / 2);

    sf::Text menu2("", font, 90);
    menu2.setFillColor(sf::Color::White);
    menu2.setPosition(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
    menu2.setString(L"Настройки");
    menu2.setOrigin(menu2.getLocalBounds().width / 2, menu2.getLocalBounds().height / 2);

    sf::Text menu3 ("", font, 90);
    menu3.setFillColor(sf::Color::White);
    menu3.setPosition(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2 + 120);
    menu3.setString(L"Выход");
    menu3.setOrigin(menu3.getLocalBounds().width / 2, menu3.getLocalBounds().height / 2);




    //////////////////////////////МЕНЮ///////////////////
    while (isMenu) {

        menu1.setFillColor(sf::Color::White);
        menu2.setFillColor(sf::Color::White);
        menu3.setFillColor(sf::Color::White);
        menu1.setCharacterSize(90);
        menu2.setCharacterSize(90);
        menu3.setCharacterSize(90);

        menu1.setOrigin(menu1.getLocalBounds().width / 2, menu1.getLocalBounds().height / 2);
        menu2.setOrigin(menu2.getLocalBounds().width / 2, menu2.getLocalBounds().height / 2);
        menu3.setOrigin(menu3.getLocalBounds().width / 2, menu3.getLocalBounds().height / 2);

//        menu1.setPosition(menu1.getPosition().x, menu1.getPosition().y);
//        menu2.setPosition(menu2.getPosition().x, menu2.getPosition().y);
//        menu3.setPosition(menu3.getPosition().x, menu3.getPosition().y);

        if (clock.getElapsedTime().asMilliseconds() > 2) {
            int slychai = rand_uns(1, 3);
            if (slychai == 1) {
                r = r + rand_uns(-1, 1);
                if (r <= 0)
                    r = 1;
                if (r >= 255)
                    r = 254;
            }
            if (slychai == 2) {
                g = g + rand_uns(-1, 1);
                if (g <= 0)
                    g = 1;
                if (g >= 255)
                    g = 254;
            }
            if (slychai == 3) {
                b = b + rand_uns(-1, 1);
                if (b <= 0)
                    b = 1;
                if (b >= 255)
                    b = 254;
            }
            clock.restart();
        }

//        r = r + rand_uns(-1, 1);
//        g = g + rand_uns(-1, 1);
//        b = b + rand_uns(-1, 1);
//        if (r > 255)
//            r = 255;
//        if (g > 255)
//            g = 255;
//        if (b > 255)
//            b = 255;
//        if (r < 0)
//            r = 0;
//        if (g < 0)
//            g = 0;
//        if (b < 0)
//            b = 0;




        while (window.pollEvent(ev)) {

            if (ev.type == sf::Event::MouseButtonPressed) {
                if (ev.key.code == sf::Mouse::Left) {
                    if (menu1.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
                        game(window, ev, view);
                        view.reset(sf::FloatRect(0, 0, sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
                        window.setView(view);
                    }
                }
            }

            if (ev.type == sf::Event::MouseButtonPressed) {
                if (ev.key.code == sf::Mouse::Left) {
                    if (menu2.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
                        SettingsMenu(window, ev);
                    }
                }
            }

            if (ev.type == sf::Event::MouseButtonPressed) {
                if (ev.key.code == sf::Mouse::Left) {
                    if (menu3.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
                        window.close();
                        isMenu = false;
                    }
                }
            }
        }


        if (menu1.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
            menu1.setFillColor(sf::Color(200, 255, 200));
            menu1.setCharacterSize(100);
            menu1.setOrigin(menu1.getLocalBounds().width / 2, menu1.getLocalBounds().height / 2);
        }
        if (menu2.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
            menu2.setFillColor(sf::Color(200, 255, 200));
            menu2.setCharacterSize(100);
            menu2.setOrigin(menu2.getLocalBounds().width / 2, menu2.getLocalBounds().height / 2);
        }
        if (menu3.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
            menu3.setFillColor(sf::Color(200, 255, 200));
            menu3.setCharacterSize(100);
            menu3.setOrigin(menu3.getLocalBounds().width / 2, menu3.getLocalBounds().height / 2);
        }


        window.clear(sf::Color(r, g, b));
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);

        window.display();
    }
    ////////////////////////////////////////////////////
}
