//
// Created by evdok on 10.03.24.
//

#include "Game.hpp"
#include "Functions.hpp"
#include "Class.hpp"

void game (sf::RenderWindow &window, sf::Event ev, sf::View &view){
    sf::Clock clock;
    float time;

    bool win = false, lose = false;
    bool first_touch = true;
    int touched_rect_left = 0, touched_rect_right = 0;
    bool isGame = true;
    int layer = 1, x_size = 5, y_size = 5, z_size = 5;

    sf::RectangleShape border;
    border.setSize(sf::Vector2f(84 * static_cast<float>(x_size), 84 * static_cast<float>(y_size)));
    border.setFillColor(sf::Color(190, 225, 200));
    border.setOutlineThickness(4);
    border.setOutlineColor(sf::Color(100, 100, 100));
    border.setOrigin(42, 42);
    border.setPosition(400, 300);

    std::vector<Rectangle> data(125);
    data = reroll_data(x_size, y_size, z_size);

    sf::Font font;
    font.loadFromFile("../../../../../usr/share/fonts/truetype/freefont/FreeMonoBold.ttf");


    sf::Text Time("", font, 50);
    Time.setFillColor(sf::Color::Black);
    Time.setString(L"Time:");
    Time.setOrigin(Time.getLocalBounds().width / 2, Time.getLocalBounds().height / 2);
    Time.setPosition(2 * Time.getLocalBounds().width + 15 + 450, 2 * Time.getLocalBounds().height + 115);

    sf::Text timego("", font, 50);
    timego.setFillColor(sf::Color::Black);
    timego.setString(L"0");
    timego.setOrigin(timego.getLocalBounds().width / 2, timego.getLocalBounds().height / 2);
    timego.setPosition(2 * Time.getLocalBounds().width + 430 + Time.getLocalBounds().width, 2 * Time.getLocalBounds().height + 120);
    float time_show = 0;


    sf::Text textBombs("", font, 50);
    textBombs.setFillColor(sf::Color::Black);
    textBombs.setString(L"Bombs:  %");
    textBombs.setOrigin(textBombs.getLocalBounds().width / 2, textBombs.getLocalBounds().height / 2);
    textBombs.setPosition(2 * textBombs.getLocalBounds().width + 15 + 500, 2 * textBombs.getLocalBounds().height + 15);
    int bombPercentage = 20;
    sf::Text valbomb("", font, 50);
    valbomb.setFillColor(sf::Color::Black);
    valbomb.setString(L"20");
    valbomb.setOrigin(valbomb.getLocalBounds().width / 2, valbomb.getLocalBounds().height / 2);
    valbomb.setPosition(2 * textBombs.getLocalBounds().width + textBombs.getLocalBounds().width + 326, 2 * textBombs.getLocalBounds().height + 20);

    sf::Text textLayer("", font, 50);
    textLayer.setFillColor(sf::Color::Black);
    textLayer.setString(L"Layer:");
    textLayer.setOrigin(textLayer.getLocalBounds().width / 2, textLayer.getLocalBounds().height / 2);
    textLayer.setPosition(2 * textLayer.getLocalBounds().width + 15, 2 * textLayer.getLocalBounds().height + 100);

    sf::Text vLayer("", font, 50);
    vLayer.setFillColor(sf::Color::Black);
    vLayer.setString(L"1");
    vLayer.setOrigin(vLayer.getLocalBounds().width / 2, vLayer.getLocalBounds().height / 2);
    vLayer.setPosition(2 * textLayer.getLocalBounds().width + textLayer.getLocalBounds().width, 2 * textLayer.getLocalBounds().height + 100);

    sf::Text x_number("", font, 50);
    x_number.setFillColor(sf::Color::Black);
    x_number.setString(L"X:");
    x_number.setOrigin(x_number.getLocalBounds().width / 2, x_number.getLocalBounds().height / 2);
    x_number.setPosition(2 * x_number.getLocalBounds().width + 15, 2 * x_number.getLocalBounds().height + 15);

    sf::Text X("", font, 50);
    X.setFillColor(sf::Color::Black);
    X.setString(L"5");
    X.setOrigin(X.getLocalBounds().width / 2, X.getLocalBounds().height / 2);
    X.setPosition(2 * x_number.getLocalBounds().width + 15 + x_number.getLocalBounds().width, 2 * x_number.getLocalBounds().height + 20);
    int xval = 5, yval = 5, zval = 5;


    sf::Text y_number("", font, 50);
    y_number.setFillColor(sf::Color::Black);
    y_number.setString(L"Y:");
    y_number.setOrigin(y_number.getLocalBounds().width / 2, y_number.getLocalBounds().height / 2);
    y_number.setPosition(2 * y_number.getLocalBounds().width + 200, 2 * y_number.getLocalBounds().height + 15);

    sf::Text Y("", font, 50);
    Y.setFillColor(sf::Color::Black);
    Y.setString(L"5");
    Y.setOrigin(y_number.getLocalBounds().width / 2, y_number.getLocalBounds().height / 2);
    Y.setPosition(2 * y_number.getLocalBounds().width + 210 + y_number.getLocalBounds().width, 2 * y_number.getLocalBounds().height + 20);


    sf::Text z_number("", font, 50);
    z_number.setFillColor(sf::Color::Black);
    z_number.setString(L"Z:");
    z_number.setOrigin(z_number.getLocalBounds().width / 2, z_number.getLocalBounds().height / 2);
    z_number.setPosition(2 * z_number.getLocalBounds().width + 385, 2 * z_number.getLocalBounds().height + 15);

    sf::Text Z("", font, 50);
    Z.setFillColor(sf::Color::Black);
    Z.setString(L"5");
    Z.setOrigin(z_number.getLocalBounds().width / 2, z_number.getLocalBounds().height / 2);
    Z.setPosition(2 * z_number.getLocalBounds().width + 400 + z_number.getLocalBounds().width, 2 * z_number.getLocalBounds().height + 20);


    sf::Text change("", font, 50);
    change.setFillColor(sf::Color::Black);
    change.setString(L"Reroll bombs");
    change.setOrigin(change.getLocalBounds().width / 2, change.getLocalBounds().height / 2);
    change.setPosition(2 * change.getLocalBounds().width + 700, 2 * change.getLocalBounds().height + 15);


    while(isGame){

        while (window.pollEvent(ev)) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                isGame = false;
            }

            if (ev.type == sf::Event::KeyPressed) {
                if(ev.key.code == sf::Keyboard::F) {
                    layer++;
                    if (layer > z_size)
                        layer = z_size;
                    std::string str = std::to_string(layer);
                    vLayer.setString(str);
                }
            }
            if (ev.type == sf::Event::KeyPressed) {
                if(ev.key.code == sf::Keyboard::V) {
                    layer--;
                    if (layer <= 0)
                        layer = 1;
                    std::string str = std::to_string(layer);
                    vLayer.setString(str);
                }
            }

            if (ev.type == sf::Event::MouseWheelScrolled)
            {
                if (ev.mouseWheelScroll.delta < 0)
                    view.zoom(1.1f);
                else if (ev.mouseWheelScroll.delta > 0)
                    view.zoom(0.9f);
            }

            if (ev.type == sf::Event::MouseButtonReleased) {
                if (ev.key.code == sf::Mouse::Right) {
                    for(int i = 0; i < x_size * y_size; i++){
                        if(data[(layer - 1) * x_size * y_size + i].data_.getGlobalBounds().contains(
                                window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                            if(touched_rect_right == (layer - 1) * x_size * y_size + i) {
                                if(data[(layer - 1) * x_size * y_size + i].have_flag)
                                    data[(layer - 1) * x_size * y_size + i].have_flag = false;
                                else
                                    data[(layer - 1) * x_size * y_size + i].have_flag = true;
                            }
                        }
                    }
                }

                if (ev.key.code == sf::Mouse::Left) {
                    for(int i = 0; i < x_size * y_size; i++){
                        if(!data[(layer - 1) * x_size * y_size + i].data_.getGlobalBounds().contains(
                                window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                            if (!data[(layer - 1) * x_size * y_size + i].touched && !data[(layer - 1) * x_size * y_size + i].number_is_open)
                                data[(layer - 1) * x_size * y_size + i].data_.setFillColor(sf::Color(150, 150, 150));
                        } else{
                            if(first_touch) {
                                generate_bombs(data, bombPercentage, (layer - 1) * x_size * y_size + i, x_size, y_size, z_size, font);

                                for(int ii = 0; ii < x_size * y_size * z_size; ii++){
                                    if(data[ii].bombs_near > 0){
                                        data[ii].text_.setFont(font);
                                        std::string str = std::to_string(data[ii].bombs_near);
                                        data[ii].text_.setString(str);
                                        data[ii].text_.setCharacterSize(50);
                                        data[ii].text_.setOrigin(data[ii].text_.getGlobalBounds().width / 2, data[ii].text_.getGlobalBounds().height / 2);
                                        data[ii].text_.setPosition(data[ii].data_.getPosition().x, data[ii].data_.getPosition().y - 15);
                                        data[ii].text_.setFillColor(sf::Color::Black);
                                    }
                                }
                                    first_touch = false;
                            }
                            if(touched_rect_left == (layer - 1) * x_size * y_size + i) {

                                if(data[(layer - 1) * x_size * y_size + i].number_is_open){
                                    int count_bombs = 0, count_flags_in_bombs = 0, count_flags = 0;
                                    int j = (layer - 1) * x_size * y_size + i, jjj = 0;
                                    int zit = j / (x_size * y_size), tmp = j % (x_size * y_size), yit = tmp / x_size, xit = tmp % x_size;

                                    for(int kk = -1; kk < 2; kk++){
                                        if(kk + zit >= z_size)
                                            break;
                                        if(kk + zit < 0)
                                            kk++;

                                        for (int jj = -1; jj < 2; jj++){
                                            if(jj + yit >= y_size)
                                                break;
                                            if(jj + yit < 0)
                                                jj++;

                                            for (int ii = -1; ii < 2; ii++){
                                                if(ii + xit >= x_size)
                                                    break;
                                                if(ii + xit < 0)
                                                    ii++;


                                                if(data[(zit + kk) * x_size * y_size + (yit + jj) * x_size + xit + ii].have_bomb) {
                                                    count_bombs++;
                                                    if(data[(zit + kk) * x_size * y_size + (yit + jj) * x_size + xit + ii].have_flag)
                                                        count_flags_in_bombs++;
                                                }
                                                if(data[(zit + kk) * x_size * y_size + (yit + jj) * x_size + xit + ii].have_flag)
                                                    count_flags++;


                                            }

                                        }

                                    }

                                    if(count_bombs == count_flags){
                                        if(count_flags_in_bombs == count_flags) {
                                            for (int kk = -1; kk < 2; kk++) {
                                                if (kk + zit >= z_size)
                                                    break;
                                                if (kk + zit < 0)
                                                    kk++;

                                                for (int jj = -1; jj < 2; jj++) {
                                                    if (jj + yit >= y_size)
                                                        break;
                                                    if (jj + yit < 0)
                                                        jj++;

                                                    for (int ii = -1; ii < 2; ii++) {
                                                        if (ii + xit >= x_size)
                                                            break;
                                                        if (ii + xit < 0)
                                                            ii++;

                                                        if (!data[(zit + kk) * x_size * y_size + (yit + jj) * x_size +
                                                                  xit + ii].have_flag) {
                                                            std::vector<int> op{
                                                                    (zit + kk) * x_size * y_size + (yit + jj) * x_size +
                                                                    xit + ii};
                                                            while (!op.empty()) {
                                                                open_numbers(data, x_size, y_size, z_size, op);
                                                                op.erase(op.begin());
                                                            }
                                                        }


                                                    }

                                                }

                                            }
                                        } else{
                                            lose = true;
                                            data[jjj].data_.setFillColor(sf::Color::Red);
                                            for(int it = 0; it < x_size * y_size * z_size; it++){
                                                if(data[it].have_bomb){
                                                    data[it].activated_bomb = true;
                                                }
                                            }
                                        }
                                    }
                                }

                                data[(layer - 1) * x_size * y_size + i].touched = true;
                                if(data[(layer - 1) * x_size * y_size + i].have_bomb) {
                                    data[(layer - 1) * x_size * y_size + i].data_.setFillColor(sf::Color::Red);
                                    for(int it = 0; it < x_size * y_size * z_size; it++){
                                        if(data[it].have_bomb){
                                            data[it].activated_bomb = true;
                                        }
                                    }
                                    lose = true;
                                } else{
                                    std::vector<int> op{(layer - 1) * x_size * y_size + i};
                                    while (!op.empty()) {
                                        open_numbers(data, x_size, y_size, z_size,op);
                                        op.erase(op.begin());
                                    }
                                }

                            }
                        }
                    }

                }
            }

            if (ev.type == sf::Event::MouseButtonPressed) {

                if (ev.key.code == sf::Mouse::Right) {
                    for (int i = 0; i < x_size * y_size; i++) {
                        if (data[(layer - 1) * x_size * y_size + i].data_.getGlobalBounds().contains(
                                window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                            touched_rect_right = (layer - 1) * x_size * y_size + i;
                        }
                    }
                }

                if (ev.key.code == sf::Mouse::Left) {

                    if (textBombs.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                             window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                        bombPercentage++;
                        std::string str = std::to_string(bombPercentage);
                        valbomb.setString(str);
                    }

                    for (int i = 0; i < x_size * y_size; i++) {
                        if (data[(layer - 1) * x_size * y_size + i].data_.getGlobalBounds().contains(
                                window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                            data[(layer - 1) * x_size * y_size + i].data_.setFillColor(sf::Color(125, 125, 125));
                            touched_rect_left = (layer - 1) * x_size * y_size + i;
                        }
                    }

                    if (x_number.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                            window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                        xval++;
                        std::string str = std::to_string(xval);
                        X.setString(str);
                    }
                    if (y_number.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                            window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                        yval++;
                        std::string str = std::to_string(yval);
                        Y.setString(str);
                    }
                    if (z_number.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                            window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                        zval++;
                        std::string str = std::to_string(zval);
                        Z.setString(str);
                    }

                    if (change.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                          window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                        x_size = xval;
                        y_size = yval;
                        z_size = zval;
                        data = reroll_data(x_size, y_size, z_size);
                        vLayer.setString(L"1");
                        win = false;
                        lose = false;
                        first_touch = true;
                        layer = 1;
                        time_show = 0;
                        border.setSize(
                                sf::Vector2f(84 * static_cast<float>(x_size), 84 * static_cast<float>(y_size)));
                    }
                }


                if (ev.key.code == sf::Mouse::Right) {

                    if (textBombs.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                             window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                        bombPercentage--;
                        std::string str = std::to_string(bombPercentage);
                        valbomb.setString(str);
                    }

                    if (x_number.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                            window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                        xval--;
                        std::string str = std::to_string(xval);
                        X.setString(str);
                    }
                    if (y_number.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                            window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                        yval--;
                        std::string str = std::to_string(yval);
                        Y.setString(str);
                    }
                    if (z_number.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x,
                                                                window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
                        zval--;
                        std::string str = std::to_string(zval);
                        Z.setString(str);
                    }

                }
            }


        }



        if (textBombs.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x, window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
            textBombs.setCharacterSize(58);
            textBombs.setOrigin(textBombs.getLocalBounds().width / 2, textBombs.getLocalBounds().height / 2);
        } else{
            textBombs.setCharacterSize(50);
            textBombs.setOrigin(textBombs.getLocalBounds().width / 2, textBombs.getLocalBounds().height / 2);
        }

        if (x_number.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x, window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
            x_number.setCharacterSize(58);
            x_number.setOrigin(x_number.getLocalBounds().width / 2, x_number.getLocalBounds().height / 2);
        } else{
            x_number.setCharacterSize(50);
            x_number.setOrigin(x_number.getLocalBounds().width / 2, x_number.getLocalBounds().height / 2);
        }

        if (y_number.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x, window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
            y_number.setCharacterSize(58);
            y_number.setOrigin(y_number.getLocalBounds().width / 2, y_number.getLocalBounds().height / 2);
        } else{
            y_number.setCharacterSize(50);
            y_number.setOrigin(y_number.getLocalBounds().width / 2, y_number.getLocalBounds().height / 2);
        }

        if (z_number.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x, window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
            z_number.setCharacterSize(58);
            z_number.setOrigin(z_number.getLocalBounds().width / 2, z_number.getLocalBounds().height / 2);
        } else{
            z_number.setCharacterSize(50);
            z_number.setOrigin(z_number.getLocalBounds().width / 2, z_number.getLocalBounds().height / 2);
        }

        if (change.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition()).x, window.mapPixelToCoords(sf::Mouse::getPosition()).y)) {
            change.setCharacterSize(58);
            change.setOrigin(change.getLocalBounds().width / 2, change.getLocalBounds().height / 2);
        } else{
            change.setCharacterSize(50);
            change.setOrigin(change.getLocalBounds().width / 2, change.getLocalBounds().height / 2);
        }

        int count = 0;
        for(int i = 0; i < x_size * y_size * z_size; i++){
            if(!data[i].number_is_open){
                if(!data[i].have_bomb){
                    if(data[i].have_flag)
                        count++;
                }
                if(data[i].have_bomb){
                    if(!data[i].have_flag)
                        count++;
                }
            }
        }
        std::cout << count << std::endl;
        if(count == 0)
            win = true;
        else
            win = false;

        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 1000;

        if(!win && !lose)
            time_show += time;
        std::string str_time = std::to_string(static_cast<int>(time_show / 1000));
        timego.setString(str_time);

        viewMap(time, view);

        if(win){
            window.clear(sf::Color(140, 255, 140));
        }
        else if (lose){
            window.clear(sf::Color(255, 140, 140));
        }
        else if (epilepsy)
            window.clear(sf::Color(rand_uns(0, 255), rand_uns(0, 255), rand_uns(0, 255)));
        else
            window.clear(sf::Color(230, 210, 150));

        window.draw(border);
        window.draw(X);
        window.draw(Y);
        window.draw(Z);
        window.draw(x_number);
        window.draw(y_number);
        window.draw(z_number);
        window.draw(change);
        window.draw(textLayer);
        window.draw(vLayer);
        window.draw(textBombs);
        window.draw(valbomb);
        window.draw(Time);
        window.draw(timego);
        window.setView(view);

        for(int i = 0; i < x_size * y_size; i++){
            window.draw(data[(layer - 1) * x_size * y_size + i].data_);
            if (data[(layer - 1) * x_size * y_size + i].activated_bomb)
                window.draw(data[(layer - 1) * x_size * y_size + i].bombs_);
            if (data[(layer - 1) * x_size * y_size + i].have_flag)
                window.draw(data[(layer - 1) * x_size * y_size + i].flags_);
            if (data[(layer - 1) * x_size * y_size + i].number_is_open)
                window.draw(data[(layer - 1) * x_size * y_size + i].text_);
//            if (data[(layer - 1) * x_size * y_size + i].bombs_near > 0)
//                window.draw(data[(layer - 1) * x_size * y_size + i].text_);
        }


        window.display();
    }
}

