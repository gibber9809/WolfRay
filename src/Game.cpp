#include "Player.h"
#include "GameMap.h"
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 1200

int main() {
    const double FOV = PI/3;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Window");
    GameMap gameMap;
    std::vector<std::pair<int,sf::Color> > columnHeights;
    Player player(8.5,8.5,0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Key::Left) {
                    player.rotateViewAngle(-0.1);
                } else if (event.key.code == sf::Keyboard::Key::Right) {
                    player.rotateViewAngle(0.1);
                } else if (event.key.code == sf::Keyboard::Key::W) {
                    player.moveForwards(0.1);
                } else if (event.key.code == sf::Keyboard::Key::S) {
                    player.moveForwards(-0.1);
                } else if (event.key.code == sf::Keyboard::Key::D) {
                    player.moveSideways(0.1);
                } else if (event.key.code == sf::Keyboard::Key::A) {
                    player.moveSideways(-0.1);
                }
            }
        }

        window.clear(sf::Color::Black);
        columnHeights = gameMap.scanColumns(player, FOV, WINDOW_WIDTH, WINDOW_HEIGHT);

        for (int i = 0; i < WINDOW_WIDTH; ++i) {
            if (columnHeights[i].first > 0) {
                sf::VertexArray column(sf::Lines, 2);
                column[0].position = sf::Vector2f(i,WINDOW_HEIGHT/2 - columnHeights[i].first / 2);
                column[1].position = sf::Vector2f(i,WINDOW_HEIGHT/2 + columnHeights[i].first / 2);
                column[0].color = columnHeights[i].second;
                column[1].color = columnHeights[i].second;
                window.draw(column);
            }
        }

        window.display();
    }
    return 0;
}
