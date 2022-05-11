#pragma once
#include "NotFoundException.h"
#include <unordered_map>

template <typename T>
class RessourceManager
{
public:
	RessourceManager() = delete;
	static T const& getRessource(std::string const& path) {
		auto result = ressources.find(path);
		if (result == std::end(ressources)) {
			if (!ressources[path].loadFromFile(path)) {
				throw NotFoundException{ path };
			}
			return ressources[path];
		}
		return result->second;
	}
private:
	static std::unordered_map<std::string, T> ressources;
};

