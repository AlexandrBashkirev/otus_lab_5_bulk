#pragma once
#include "ICmdExecutor.h"
#include "Cmd.h"
#include <list>
#include <string>
#include <algorithm>

class CmdExecutor : public ICmdExecutor
{
	void addCmd(const std::list<Cmd>& cmds)
	{
		std::cout << "bulk: ";
		std::for_each(cmds.cbegin(), cmds.cend(), [](const Cmd& l) { std::cout << l.getLine() << " "; });
		std::cout << std::endl;
	}
};