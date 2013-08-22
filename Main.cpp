#include "Main.hpp"
#include "Class.hpp"

sf::RenderWindow window(sf::VideoMode(640, 360), "Gua calculator");

int main()
{
    std::cout << "===Gua Calculator===" << std::endl;

    // DECLARATION
    sf::Event event;
    sf::Texture backgroundTexture;
    sf::Texture buttonTexture;
    sf::Texture buttonTextureFired;
    sf::Sprite backgroundSprite;
    sf::Sprite buttonSprite;
    sf::Sprite buttonSpriteFired;
    sf::Vector2i buttonPosition;
    sf::Vector2i buttonDimension;
    Button buttonObject;
    // END

    // INIT
    buttonPosition.x = 488;
    buttonPosition.y = 261;
    buttonDimension.x = 105;
    buttonDimension.y = 49;

    backgroundTexture.loadFromFile("ressource/background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);
    buttonSprite.setTexture(buttonTexture);
    buttonSpriteFired.setTexture(buttonTextureFired);

    buttonSprite.setPosition(buttonPosition.x, buttonPosition.y);
    buttonSpriteFired.setPosition(buttonPosition.x, buttonPosition.y);
    buttonObject.setRenderWindow(window);
    buttonObject.setPosition(buttonPosition, buttonDimension);
    buttonObject.setTexture("ressource/boutton.jpg", "ressource/boutton2.jpg");
    // END

    Textbox textboxTest;
    textboxTest.setTexture("ressource/textbox.jpg", "ressource/textbox2.jpg");
    textboxTest.setPosition(0, 0, 180, 50);
    textboxTest.setWindow(window);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
                if (event.type == sf::Event::Closed)
                    window.close();

                textboxTest.event(event, sf::Mouse::getPosition(window));
        }

        if (buttonObject.isPressed(sf::Mouse::getPosition(window)) == true)
            window.close();

        window.clear();
        window.draw(backgroundSprite);
        buttonObject.show(sf::Mouse::getPosition(window));
        textboxTest.show(sf::Mouse::getPosition(window));
        window.display();
    }
}
