#pragma once

#include <stdexcept>

class ThreadPoolException : std::runtime_error
{
	public:
		ThreadPoolException(const std::string& message) : std::runtime_error(message.c_str()) {}
		ThreadPoolException(const char* message) : std::runtime_error(message) {}
};