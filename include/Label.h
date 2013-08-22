#ifndef LABEL_H
#define LABEL_H

#include "../Main.hpp"

class Label
{
    public:
        Label();
        Label(sf::RenderWindow &window, sf::Texture imageTexture, sf::Vector2i labelPosition);
        void setImg(sf::Texture imageTexture);
        void setWindow(sf::RenderWindow &window);
        void setPosition(sf::Vector2i labelPosition);
        void setPosition(int x, int y);
        void show();
        virtual ~Label();
    protected:
    private:
        sf::RenderWindow *m_window;
        sf::Sprite   m_labelSprite;
        sf::Vector2i m_labelPosition;
};

#endif // LABEL_H
