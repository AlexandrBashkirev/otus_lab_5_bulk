#pragma once
#include "ICmdExecutor.h"
#include <list>
#include <string>
#include <algorithm>

class CmdLogger : public ICmdExecutor
{
public:
	CmdLogger(std::string path)
	{

	}
	void addCmd(const std::list<std::string>& cmds)
	{
	};
};