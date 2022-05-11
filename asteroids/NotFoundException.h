#pragma once
#include <exception>
#include <string>

class NotFoundException : public std::exception
{
public:
	NotFoundException(std::string const& path);
	virtual const char* what() const noexcept override;
private:
	std::string errorMessage{};
};

