#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

class Player {
public:
    Player() {
       
    }

    void drawTo(sf::RenderWindow& window) {
        window.draw(player);
    }

    void move(sf::Vector2f distance) {
        player.move(distance);
    }

    void setPos(sf::Vector2f newPos) {
        player.setPosition(newPos);
    }

    int getY() {
        return player.getPosition().y;
    }

private:
    const float moveSpeed = 0.2;
    sf::RectangleShape player;

};
