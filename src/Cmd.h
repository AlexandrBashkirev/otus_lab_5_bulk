#pragma once
#include "ICmd.h"
#include <string> 
#include <chrono>
#include <ctime>

class Cmd : public ICmd
{
public:
	template<typename S>
	Cmd(S&& _line, std::chrono::seconds _timeStamp) : ICmd(std::forward<S>(_line), _timeStamp) {}

	auto getTimeStamp() const
	{
		return timeStamp;
	}
	auto getLine() const
	{
		return line;
	}
};
