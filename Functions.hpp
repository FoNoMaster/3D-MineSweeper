//
// Created by evdok on 09.03.24.
//

#ifndef MINKA_FUNCTIONS_HPP
#define MINKA_FUNCTIONS_HPP

#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Class.hpp"

inline bool epilepsy = false;


int rand_uns(int min, int max);
void viewMap(float time, sf::View& view);

std::vector<Rectangle> reroll_data(int x_size, int y_size, int z_size);

void generate_bombs(std::vector<Rectangle>& data, int bombPercentage, int unusable, int x_size, int y_size, int z_size, sf::Font& font);

void open_numbers(std::vector<Rectangle>& data, int x_size, int y_size, int z_size, std::vector<int>& op);

#endif //MINKA_FUNCTIONS_HPP
