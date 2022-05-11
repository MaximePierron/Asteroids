#include "RessourceManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

template<>
std::unordered_map<std::string, sf::Texture> RessourceManager<sf::Texture>::ressources{};
template<>
std::unordered_map<std::string, sf::SoundBuffer> RessourceManager<sf::SoundBuffer>::ressources{};

