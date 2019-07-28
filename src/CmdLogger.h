#pragma once
#include "ICmdExecutor.h"
#include "Cmd.h"
#include <list>
#include <string>
#include <algorithm>
#include <fstream>


class CmdLogger : public ICmdExecutor
{
public:
	void addCmd(const std::list<Cmd>& cmds)
	{
		if (cmds.size() > 0)
		{
			std::ofstream log(std::string("bulk") + std::to_string(cmds.begin()->getTimeStamp().count()) + ".log");
			log << "bulk: ";
			std::for_each(cmds.cbegin(), cmds.cend(), [&log](const Cmd& l) { log << l.getLine() << " "; });
			log << std::endl;
		}
	}
};