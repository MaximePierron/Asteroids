#include <SFML/Graphics.hpp>
#include "Space.h"
#include "Game.h"
#include <exception>

using namespace std;
constexpr int WINDOW_LENGTH = 800;
constexpr int WINDOW_HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT), "Asteroids");
    Coordinates::initiateSpace(WINDOW_LENGTH, WINDOW_HEIGHT);
    auto space = Space{};
    auto game = Game{ space };
    while (window.isOpen())
    {
        try {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && !game.isPlaying()) {
                    game.start();
                }
            }
            space.refresh();
            space.handleCollision();
            space.clean();

            window.clear();
            space.print(window);
            game.print(window);
            window.display();
        }
        catch (std::exception const& exception) {
            game.initException(exception);
        }

    }

    return 0;
}
