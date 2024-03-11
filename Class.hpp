//
// Created by evdok on 10.03.24.
//

#ifndef MINKA_CLASS_HPP
#define MINKA_CLASS_HPP

#include <SFML/Graphics.hpp>

class Rectangle{
public:
    sf::RectangleShape data_;
    sf::CircleShape bombs_;
    sf::CircleShape flags_;
    sf::Text text_;
    int bombs_near = 0;
    bool have_bomb = false, activated_bomb = false;
    bool have_flag = false;
    bool number_is_open = false;
    bool touched = false;

    Rectangle();

};

#endif //MINKA_CLASS_HPP
