#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using std::cout;
using std::cin;
using std::endl;

const char Field_Size = 9;
char Field[Field_Size]; //array for game scene

char player1 = '0', player2 = '0';

void field_display(RenderWindow& window, char player1, char player2){
    RectangleShape line1(Vector2f(300.f, 3.f)), line2(Vector2(300.f, 3.f));
    RectangleShape line3(Vector2f(300.f, 3.f)), line4(Vector2f(300.f, 3.f));

    for (auto &it : {&line1, &line2, &line3, &line4}){
        it ->setFillColor(Color::Black);
    }
    line1.rotate(90); line2.rotate(90);

    line1.move(150, 50); line2.move(250, 50);
    line3.move(50, 150); line4.move(50, 250);

    window.draw(line1); window.draw(line2);
    window.draw(line3); window.draw(line4);
}

int human_move(RenderWindow& window){
    Event event;
    while (window.pollEvent(event)){
        if (event.type == Event::Closed){
            window.close();
        }
    }
    if (IntRect(60, 60, 80, 80).contains(Mouse::getPosition(window)))
        if (Mouse::isButtonPressed(Mouse::Left)) return 0;

    return -1;
}


void RunWindow(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "TicTacToe");
    Image image;
    image.loadFromFile("fon.png");
    Texture texture;
    texture.loadFromImage(image);
    Sprite sprite(texture);
    sprite.setPosition(0, 0);
    sprite.setScale(2.7f, 2.0f);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        field_display(window, player1, player2);
        window.display();
        int move = 0;
        do {
            move = human_move(window);
        }while (move == -1);

    }
}

int main() {
    RunWindow();

    return 0;
}
