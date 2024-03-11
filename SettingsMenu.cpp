//
// Created by evdok on 09.03.24.
//

#include "SettingsMenu.hpp"
#include "Functions.hpp"

void SettingsMenu (sf::RenderWindow &window, sf::Event ev) {

    bool isSettingMenu = 1, isMove = 0;

    sf::Font font;
    font.loadFromFile("../Halogen_0.ttf");

    sf::Text backToMenu("", font, 50);
    backToMenu.setFillColor(sf::Color::White);
    backToMenu.setString(L"Назад");
    backToMenu.setOrigin(backToMenu.getLocalBounds().width / 2, backToMenu.getLocalBounds().height / 2);
    backToMenu.setPosition(2 * backToMenu.getLocalBounds().width + 15, 2 * backToMenu.getLocalBounds().height + 15);

    sf::Text settingtext("", font, 90);
    settingtext.setFillColor(sf::Color::White);
    settingtext.setString(L"Настроек нет, но вы держитесь");
    settingtext.setPosition(sf::VideoMode::getDesktopMode().width / 2 - settingtext.getLocalBounds().width / 2, sf::VideoMode::getDesktopMode().height / 2 - settingtext.getLocalBounds().height / 2);

    sf::Text Epilepsy("", font, 50);
    Epilepsy.setFillColor(sf::Color::White);
    Epilepsy.setString(L"Epilepsy mode:");
    Epilepsy.setOrigin(Epilepsy.getLocalBounds().width / 2, Epilepsy.getLocalBounds().height / 2);
    Epilepsy.setPosition(2 * Epilepsy.getLocalBounds().width + 50, 2 * Epilepsy.getLocalBounds().height + 150);

    sf::Text EpilepsyVal("", font, 50);
    EpilepsyVal.setFillColor(sf::Color::White);
    if(epilepsy)
        EpilepsyVal.setString(L"On");
    else
        EpilepsyVal.setString(L"Off");
    EpilepsyVal.setOrigin(EpilepsyVal.getLocalBounds().width / 2, EpilepsyVal.getLocalBounds().height / 2);
    EpilepsyVal.setPosition(2 * Epilepsy.getLocalBounds().width + 250, 2 * Epilepsy.getLocalBounds().height + 146);

    while (isSettingMenu) {

        backToMenu.setFillColor(sf::Color::White);
        backToMenu.setCharacterSize(50);
        backToMenu.setPosition(backToMenu.getPosition().x, backToMenu.getPosition().y);
        backToMenu.setOrigin(backToMenu.getLocalBounds().width / 2, backToMenu.getLocalBounds().height / 2);

        if (EpilepsyVal.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x, window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
            EpilepsyVal.setCharacterSize(58);
            EpilepsyVal.setOrigin(EpilepsyVal.getLocalBounds().width / 2, EpilepsyVal.getLocalBounds().height / 2);
        } else{
            EpilepsyVal.setCharacterSize(50);
            EpilepsyVal.setOrigin(EpilepsyVal.getLocalBounds().width / 2, EpilepsyVal.getLocalBounds().height / 2);
        }


        window.clear(sf::Color(0, 0, 0));

        while (window.pollEvent(ev)) {

            if (ev.type == sf::Event::MouseButtonPressed) {
                if (ev.key.code == sf::Mouse::Left) {
                    if (backToMenu.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
                        isSettingMenu = false;
                    }

                    if(!epilepsy) {
                        if (EpilepsyVal.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                                   window.mapPixelToCoords(
                                                                           sf::Mouse::getPosition()).y)) {
                            EpilepsyVal.setString(L"On");
                            epilepsy = true;
                        }
                    } else if(EpilepsyVal.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                                     window.mapPixelToCoords(
                                                                             sf::Mouse::getPosition()).y)){
                        EpilepsyVal.setString(L"Off");
                        epilepsy = false;
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                isSettingMenu = false;
            }

            if (ev.type == sf::Event::MouseButtonPressed) {
                if (ev.key.code == sf::Mouse::Left) {
                    if (settingtext.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
                        settingtext.setFillColor(sf::Color(rand_uns(0, 255), rand_uns(0, 255), rand_uns(0, 255)));
                    }
                }
            }

            if (ev.type == sf::Event::MouseButtonPressed){
                if (ev.key.code == sf::Mouse::Left){
                    if(settingtext.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
                        isMove = 1;
                    }
                }
            }
            if (ev.type == sf::Event::MouseButtonReleased){
                if (ev.key.code == sf::Mouse::Left){
                    isMove = 0;
                }
            }

        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if (isMove == 1){
                settingtext.setPosition(sf::Mouse::getPosition().x - settingtext.getLocalBounds().width / 2, sf::Mouse::getPosition().y - settingtext.getLocalBounds().height * 0.64);
            }
        }


        if (backToMenu.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
            backToMenu.setFillColor(sf::Color(200, 255, 200));
            backToMenu.setCharacterSize(60);
            backToMenu.setOrigin(backToMenu.getLocalBounds().width / 2, backToMenu.getLocalBounds().height / 2);
        }

        window.draw(Epilepsy);
        window.draw(EpilepsyVal);
        window.draw(backToMenu);
        window.draw(settingtext);

        window.display();
    }
}
