#include "../include/Button.h"

Button::Button()
{
    //ctor
}

void Button::setPosition(sf::Vector2i  buttonPosition, sf::Vector2i buttonDimension)
{
    m_buttonPosition = buttonPosition;
    m_buttonDimension = buttonDimension;
    m_buttonSprite.setPosition(buttonPosition.x, buttonPosition.y);
    m_buttonSpriteFired.setPosition(buttonPosition.x, buttonPosition.y);
}

void Button::setTexture(sf::Texture buttonTexture, sf::Texture buttonTextureFired)
{
    m_buttonTexture = buttonTexture;
    m_buttonTextureFired = buttonTextureFired;

    m_buttonSprite.setTexture(m_buttonTexture);
    m_buttonSpriteFired.setTexture(m_buttonTextureFired);
}

void Button::setTexture(std::string textureFile, std::string textureFiredFile)
{
    m_buttonTexture.loadFromFile(textureFile);
    m_buttonTextureFired.loadFromFile(textureFiredFile);

    m_buttonSprite.setTexture(m_buttonTexture);
    m_buttonSpriteFired.setTexture(m_buttonTextureFired);
}

void Button::setRenderWindow(sf::RenderWindow &window)
{
    m_window = &window;
}

void Button::show(sf::Vector2i mousePosition)
{

    if ((mousePosition.x >= m_buttonPosition.x ) && ( mousePosition.y >= m_buttonPosition.y ) && (mousePosition.x <= (m_buttonPosition.x + m_buttonDimension.x)) && (mousePosition.y <= (m_buttonPosition.y + m_buttonDimension.y)))
        m_window->draw(m_buttonSpriteFired);
    else
        m_window->draw(m_buttonSprite);
}

bool Button::isPressed(sf::Vector2i mousePosition)
{
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) && (mousePosition.x >= m_buttonPosition.x ) && ( mousePosition.y >= m_buttonPosition.y ) && (mousePosition.x <= (m_buttonPosition.x + m_buttonDimension.x)) && (mousePosition.y <= (m_buttonPosition.y + m_buttonDimension.y)))
        return true;
    else
        return false;
}

bool Button::isFired(sf::Vector2i mousePosition)
{
    if ((mousePosition.x >= m_buttonPosition.x ) && ( mousePosition.y >= m_buttonPosition.y ) && (mousePosition.x <= (m_buttonPosition.x + m_buttonDimension.x)) && (mousePosition.y <= (m_buttonPosition.y + m_buttonDimension.y)))
        return true;
    else
        return false;
}

Button::~Button()
{

}
