#include "NotFoundException.h"

using namespace std::string_literals;

NotFoundException::NotFoundException(std::string const& path) : errorMessage{"Error, ressource not found: "s + path} {

}

const char* NotFoundException::what() const noexcept {
	return errorMessage.c_str();
}