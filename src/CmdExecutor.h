#pragma once
#include "ICmdExecutor.h"
#include <list>
#include <string>
#include <algorithm>

class CmdExecutor : public ICmdExecutor
{
	void addCmd(const std::list<std::string>& cmds)
	{
		std::cout << "bulk: ";
		std::for_each(cmds.cbegin(), cmds.cend(), [](const std::string& l) { std::cout << l << " "; });
		std::cout << std::endl;
	};
};