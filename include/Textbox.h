#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "../Main.hpp"

class Textbox
{
    public:
        Textbox();
        void setWindow(sf::RenderWindow &window);
        void setPosition(sf::Vector2i textboxPosition, sf::Vector2i textboxDimension);
        void setPosition(int x, int y, int dimensionX, int dimensionY);
        void setTexture(sf::Texture textboxTexture, sf::Texture textboxTextureFired);
        void setTexture(std::string textboxTextureLink, std::string textboxTextureFiredLink);
        void setMaxLenght(int maxLenght);
        void event(sf::Event event, sf::Vector2i mousePosition);
        void show(sf::Vector2i mousePosition);
        virtual ~Textbox();
    protected:
    private:
        sf::RenderWindow *m_window;
        sf::Vector2i      m_textboxPosition;
        sf::Vector2i      m_textboxDimension;
        sf::Vector2i      m_textboxTextPosition;
        sf::Texture       m_textboxTexture;
        sf::Texture       m_textboxTextureFired;
        sf::Sprite        m_textboxSprite;
        sf::Text          m_textboxText;
        sf::Font          m_textboxFont;
        sf::String        m_textboxString;
        bool               m_lock;
        unsigned int               m_i;
        unsigned int               m_maxLenght;
};

#endif // TEXTBOX_H
