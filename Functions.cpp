#include "Functions.hpp"
#include "Class.hpp"

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}


void viewMap(float time, sf::View& view){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        view.move(time, 0);//скроллим карту вправо
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        view.move(0, time);//скроллим карту вниз
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        view.move(-time, 0);//скроллим карту влево
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        view.move(0, -time);//скроллим карту вправо
    }
}


std::vector<Rectangle> reroll_data(int x_size, int y_size, int z_size){
    std::vector<Rectangle> data(x_size * y_size * z_size);
    float x0 = 400, y0 = 300;


    for(int i = 0; i < x_size; i++){
        for(int j = 0; j < y_size; j++){
            for(int k = 0; k < z_size; k++){
                data[k * x_size * y_size + j * x_size + i].data_.setSize(sf::Vector2f(80, 80));
                data[k * x_size * y_size + j * x_size + i].data_.setFillColor(sf::Color(150, 150, 150));
                data[k * x_size * y_size + j * x_size + i].data_.setOutlineThickness(2);
                data[k * x_size * y_size + j * x_size + i].data_.setOutlineColor(sf::Color(100, 100, 100));
                data[k * x_size * y_size + j * x_size + i].data_.setOrigin(40, 40);
                data[k * x_size * y_size + j * x_size + i].data_.setPosition(x0 + static_cast<float>(i) * 84, y0 + static_cast<float>(j) * 84);

                data[k * x_size * y_size + j * x_size + i].bombs_.setRadius(30);
                data[k * x_size * y_size + j * x_size + i].bombs_.setFillColor(sf::Color::Black);
                data[k * x_size * y_size + j * x_size + i].bombs_.setOrigin(30, 30);
                data[k * x_size * y_size + j * x_size + i].bombs_.setPosition(data[k * x_size * y_size + j * x_size + i].data_.getPosition());

                data[k * x_size * y_size + j * x_size + i].flags_.setRadius(30);
                data[k * x_size * y_size + j * x_size + i].flags_.setFillColor(sf::Color::Red);
                data[k * x_size * y_size + j * x_size + i].flags_.setPointCount(3);
                data[k * x_size * y_size + j * x_size + i].flags_.setOrigin(30, 30);
                data[k * x_size * y_size + j * x_size + i].flags_.setPosition(data[k * x_size * y_size + j * x_size + i].data_.getPosition());

//                data[k * x_size * y_size + j * x_size + i].text_.setString("0");
//                data[k * x_size * y_size + j * x_size + i].text_.setFillColor(sf::Color::Black);
//                data[k * x_size * y_size + j * x_size + i].text_.setPosition(data[k * x_size * y_size + j * x_size + i].data_.getPosition());
//                data[k * x_size * y_size + j * x_size + i].text_.setOrigin(data[k * x_size * y_size + j * x_size + i].text_.getLocalBounds().width / 2, data[k * x_size * y_size + j * x_size + i].text_.getLocalBounds().height / 2);

//                data[k * x_size * y_size + j * x_size + i].text_.setFillColor(sf::Color::Black);
//                data[k * x_size * y_size + j * x_size + i].text_.setPosition(data[k * x_size * y_size + j * x_size + i].data_.getPosition());
//                data[k * x_size * y_size + j * x_size + i].text_.setOrigin(data[k * x_size * y_size + j * x_size + i].text_.getLocalBounds().width / 2, data[k * x_size * y_size + j * x_size + i].text_.getLocalBounds().height / 2);
            }
        }
    }
    return data;
}


void generate_bombs(std::vector<Rectangle>& data, int bombPercentage, int unusable, int x_size, int y_size, int z_size, sf::Font& font){
    int number_of_bombs = static_cast<int>(static_cast<float>(data.size()) / 100.0 * bombPercentage);
    std::cout << number_of_bombs << std::endl;
    for(int i = 0; i < number_of_bombs; i++){
        bool try_again = true;
        while (try_again){
            int j = rand_uns(0, static_cast<int>(data.size()));


            if(j != unusable && !data[j].have_bomb){
                data[j].have_bomb = true;

                try_again = false;
            }
        }
    }
    if(true){
        int zit = unusable / (x_size * y_size), tmp = unusable % (x_size * y_size), yit = tmp / x_size, xit = tmp % x_size;
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
                        data[(zit + kk) * x_size * y_size + (yit + jj) * x_size + xit + ii].have_bomb = false;
                    }

                }

            }

        }
    }


    for(int j = 0; j < x_size * y_size * z_size; j++){
        if(data[j].have_bomb){
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

                        if(!data[(zit + kk) * x_size * y_size + (yit + jj) * x_size + xit + ii].have_bomb)
                            data[(zit + kk) * x_size * y_size + (yit + jj) * x_size + xit + ii].bombs_near++;

                    }

                }

            }

        }

    }

}


void open_numbers(std::vector<Rectangle>& data, int x_size, int y_size, int z_size, std::vector<int>& op){
    data[op[0]].number_is_open = true;
    data[op[0]].data_.setFillColor(sf::Color(125, 125, 125));

    if(data[op[0]].bombs_near == 0) {
        int zit = op[0] / (x_size * y_size), tmp = op[0] % (x_size * y_size), yit = tmp / x_size, xit = tmp % x_size;

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

//                    data[(zit + kk) * x_size * y_size + (yit + jj) * x_size + xit + ii].number_is_open = true;

                    if(op[0] != (zit + kk) * x_size * y_size + (yit + jj) * x_size + xit + ii)
                        if(!data[(zit + kk) * x_size * y_size + (yit + jj) * x_size + xit + ii].number_is_open)
                        op.push_back((zit + kk) * x_size * y_size + (yit + jj) * x_size + xit + ii);


                }

            }

        }
    }
}

