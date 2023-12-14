#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "MAVI - Unidad 6");
    window.setFramerateLimit(60);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(100, 100);

    sf::Vector2f tempPosition(400.0f, 300.0f);
    sf::Vector2f velocity(0.0f, 0.0f);

    float acceleration = 100.0f;
    float deltaTime = 1.0f / 60.0f;

    bool isRigth = false;
    bool isLeft = false;
    bool isUp = false;
    bool isDown = false;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
                window.close();

            if (Keyboard::isKeyPressed(Keyboard::Up) == true) {
                isUp = true;
                isDown = false;
                isLeft = false;
                isRigth = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Down) == true) {
                isUp = false;
                isDown = true;
                isLeft = false;
                isRigth = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Left) == true) {
                isUp = false;
                isDown = false;
                isLeft = true;
                isRigth = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right) == true) {
                isUp = false;
                isDown = false;
                isLeft = false;
                isRigth = true;
            }
        }

        if (isUp) {
            velocity.y -= acceleration * deltaTime;

            if (velocity.x > 0) {
                velocity.x -= acceleration * deltaTime;
            }
            else {
                velocity.x += acceleration * deltaTime;
            }
        }
        if (isDown) {
            velocity.y += acceleration * deltaTime;

            if (velocity.x > 0) {
                velocity.x -= acceleration * deltaTime;
            }
            else {
                velocity.x += acceleration * deltaTime;
            }
        }
        if (isLeft) {
            velocity.x -= acceleration * deltaTime;

            if (velocity.y > 0) {
                velocity.y -= acceleration * deltaTime;
            }
            else {
                velocity.y += acceleration * deltaTime;
            }
        }
        if (isRigth) {
            velocity.x += acceleration * deltaTime;

            if (velocity.y > 0) {
                velocity.y -= acceleration * deltaTime;
            }
            else {
                velocity.y += acceleration * deltaTime;
            }
        }

        tempPosition += velocity * deltaTime;

        if (tempPosition.x > 900.0f) {
            tempPosition.x = -100.0f;
        }
        else if (tempPosition.x < -100.0f) {
            tempPosition.x = 900.0f;
        }
        if (tempPosition.y > 700.0f) {
            tempPosition.y = -100;
        }
        else if (tempPosition.y < -100.0f) {
            tempPosition.y = 700;
        }

        shape.setPosition(tempPosition);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}