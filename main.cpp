#include <iostream>
#include <SFML/Graphics.hpp>

sf::Vector2f lerp(sf::Vector2f p0, sf::Vector2f p1) {
    // Explique moi la ligne du dessous
    sf::Vector2f pointCoordinate( (p0.x + p1.x) / 2, (p0.y + p1.y) / 2);
    return pointCoordinate;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Bezier Curves");

    window.setFramerateLimit(60);

    sf::RectangleShape screen(sf::Vector2f(window.getSize()));
    screen.setFillColor(sf::Color (0x005A7578));
    screen.setPosition(0, 0);

    //axis
    sf::RectangleShape axisX(sf::Vector2f(window.getSize().x, 2));
    axisX.setFillColor(sf::Color::White);
    axisX.setPosition(0, window.getSize().y / 2);

    sf::RectangleShape axisY(sf::Vector2f(2, window.getSize().y));
    axisY.setFillColor(sf::Color::White);
    axisY.setPosition(window.getSize().x / 2, 0);

    sf::Vector2f center(window.getSize().x / 2, window.getSize().y / 2);

    sf::Vector2f p0(center.x + 100, center.y + 100);
    sf::Vector2f p1(center.x + 200, center.y - 300);
    sf::Vector2f p2(center.x + 800, center.y + 100);


    sf::Clock clock;



    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();

        window.draw(screen);
        window.draw(axisX);
        window.draw(axisY);

        sf::Vector2f lerp0_1 = lerp(p0, p1);
        sf::Vector2f lerp1_2 = lerp(p1, p2);

        sf::Vector2f lerpFinal = lerp(lerp0_1, lerp1_2);

        sf::CircleShape point0(5);
        point0.setFillColor(sf::Color::Red);
        point0.setPosition(p0.x, p0.y);

        sf::CircleShape point1(5);
        point1.setFillColor(sf::Color::Red);
        point1.setPosition(p1.x, p1.y);

        sf::CircleShape point2(5);
        point2.setFillColor(sf::Color::Red);
        point2.setPosition(p2.x, p2.y);

        sf::CircleShape point3(5);
        point3.setFillColor(sf::Color::Blue);
        point3.setPosition(lerp0_1.x, lerp0_1.y);

        sf::CircleShape point4(5);
        point4.setFillColor(sf::Color::Blue);
        point4.setPosition(lerp1_2.x, lerp1_2.y);

        sf::CircleShape point5(5);
        point5.setFillColor(sf::Color::Green);
        point5.setPosition(lerpFinal.x, lerpFinal.y);

        // draw points
        window.draw(point0);
        window.draw(point1);
        window.draw(point2);
        window.draw(point3);
        window.draw(point4);
        window.draw(point5);

        window.display();

        float time = clock.getElapsedTime().asSeconds();
        float sinValue = sin(time * 5) * 7;
        p0.y = p0.y + sinValue;
        p1.y = p1.y - sinValue * 1.5f;
        p2.y = p2.y + cos(time * 10 + 4) * 9;
    }
    return 0;
}
