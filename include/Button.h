#ifndef BUTTON_H
#define BUTTON_H

#include "../Main.hpp"

class Button
{
    public:
        Button();
        void setPosition(sf::Vector2i  buttonPosition, sf::Vector2i buttonDimension);
        void setTexture(sf::Texture buttonTexture, sf::Texture buttonTextureFired);
        void setTexture(std::string textureFile, std::string textureFiredFile);
        void setRenderWindow(sf::RenderWindow &window);
        void show(sf::Vector2i mousePosition);
        bool isPressed(sf::Vector2i mousePosition);
        bool isFired(sf::Vector2i mousePosition);
        virtual ~Button();
    protected:
    private:
        sf::Vector2i m_buttonPosition;
        sf::Vector2i m_buttonDimension;
        sf::Texture  m_buttonTexture;
        sf::Texture  m_buttonTextureFired;
        sf::Sprite   m_buttonSprite;
        sf::Sprite   m_buttonSpriteFired;
        sf::RenderWindow *m_window;
};

#endif // BUTTON_H
