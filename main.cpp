#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenu.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 900), "Minka", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    sf::Event event;
    sf::View view;
    view.reset(sf::FloatRect(0, 0, sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));

    menu(window, event, view);
//    std::cout << sf::VideoMode::getDesktopMode().width << " " << sf::VideoMode::getDesktopMode().height << std::endl;
//    std::cout << view.getCenter().x << std::endl;

    return 0;
}