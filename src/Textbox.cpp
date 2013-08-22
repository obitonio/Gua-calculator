#include "../include/Textbox.h"
#include <locale>

Textbox::Textbox()
:m_window(0), m_textboxPosition(), m_textboxDimension(), m_textboxTextPosition(), m_textboxTexture(), m_textboxTextureFired(), m_textboxSprite(), m_textboxText(), m_textboxFont(), m_textboxString(),
m_lock(0), m_i(00), m_maxLenght(32)
{
    m_textboxFont.loadFromFile("angelina.TTF");
    m_textboxText.setFont(m_textboxFont);
    m_textboxText.setColor(sf::Color::Black);
    m_textboxText.setString("Default");
}

void Textbox::setWindow(sf::RenderWindow &window)
{
    m_window = &window;
}

void Textbox::setPosition(sf::Vector2i textboxPosition, sf::Vector2i textboxDimension)
{
    m_textboxPosition = textboxPosition;
    m_textboxDimension = textboxDimension;

    m_textboxTextPosition = textboxPosition;
    m_textboxTextPosition.x += 15;

    m_textboxText.setPosition(m_textboxTextPosition.x, m_textboxTextPosition.y);
}

void Textbox::setPosition(int x, int y, int dimensionX, int dimensionY)
{
    m_textboxPosition.x = x;
    m_textboxPosition.y = y;

     m_textboxTextPosition.x += 5;

    m_textboxText.setPosition(m_textboxTextPosition.x, m_textboxTextPosition.y);
}

void Textbox::setTexture(sf::Texture textboxTexture, sf::Texture textboxTextureFired)
{
    m_textboxTexture = textboxTexture;
    m_textboxTextureFired = textboxTextureFired;
}

void Textbox::setTexture(std::string textboxTextureLink, std::string textboxTextureFiredLink)
{
    m_textboxTexture.loadFromFile(textboxTextureLink);
    m_textboxTextureFired.loadFromFile(textboxTextureFiredLink);
}

void Textbox::setMaxLenght(int maxLenght)
{
    m_maxLenght = maxLenght;
}

void Textbox::event(sf::Event event, sf::Vector2i mousePosition)
{

    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) && (mousePosition.x >= m_textboxPosition.x ) && ( mousePosition.y >= m_textboxPosition.y ) && (mousePosition.x <= (m_textboxPosition.x + m_textboxDimension.x)) && (mousePosition.y <= (m_textboxPosition.y + m_textboxDimension.y)))
    {
        m_lock = true;
    }
    else if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) && (!mousePosition.x >= m_textboxPosition.x ) && (!mousePosition.y >= m_textboxPosition.y ) && (!mousePosition.x <= (m_textboxPosition.x + m_textboxDimension.x)) && (!mousePosition.y <= (m_textboxPosition.y + m_textboxDimension.y)))
    {
        m_lock = false;
    }

    if (event.text.unicode > /*32*/48 && event.text.unicode < /*128*/57 && m_lock && m_i < m_maxLenght)
    {
        std::cout << "m_i = " << m_i << std::endl;
        std::cout << "Char: " << event.text.unicode << std::endl;
        m_textboxString.insert(m_i, event.text.unicode);
        m_i++;
    }
    else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::BackSpace) && (m_lock) && (m_i > 0))
    {
        m_textboxString.erase(m_i - 1);
        m_i--;
    }
}

void Textbox::show(sf::Vector2i mousePosition)
{
    m_textboxDimension.x = m_textboxSprite.getLocalBounds().width;
    m_textboxDimension.y = m_textboxSprite.getLocalBounds().height;


    if (m_lock)
        m_textboxSprite.setTexture(m_textboxTextureFired);
    else
        m_textboxSprite.setTexture(m_textboxTexture);


    m_window->draw(m_textboxSprite);
    m_textboxText.setString(m_textboxString);
    m_window->draw(m_textboxText);
}

Textbox::~Textbox()
{

}
