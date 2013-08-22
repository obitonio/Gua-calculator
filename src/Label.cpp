#include "../include/Label.h"

Label::Label()
{

}

Label::Label(sf::RenderWindow &window, sf::Texture imageTexture, sf::Vector2i labelPosition)
{
    m_window = &window;
    m_labelSprite.setTexture(imageTexture);
    m_labelPosition = labelPosition;
}

void Label::setWindow(sf::RenderWindow &window)
{
    m_window = &window;
}

void Label::setImg(sf::Texture imageTexture)
{
    m_labelSprite.setTexture(imageTexture);
}

void Label::setPosition(sf::Vector2i labelPosition)
{
    m_labelPosition = labelPosition;
}

void Label::setPosition(int x, int y)
{
    m_labelPosition.x = x;
    m_labelPosition.y = y;
}

void Label::show()
{
    m_labelSprite.setPosition(m_labelPosition.x, m_labelPosition.y);
    m_window->draw(m_labelSprite);
}

Label::~Label()
{

}
