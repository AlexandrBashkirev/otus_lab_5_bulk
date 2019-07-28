#pragma once
#include <string> 
#include <chrono>
#include <ctime>

class ICmd
{
public:
	template<typename S>
	ICmd(S&& _line, std::chrono::seconds _timeStamp) : line(std::forward<S>(_line)), timeStamp(_timeStamp) {}

protected:
	std::string line;
	std::chrono::seconds timeStamp;
};
