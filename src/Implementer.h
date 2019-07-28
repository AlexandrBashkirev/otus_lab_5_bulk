#pragma once
#include "IImplementer.h"
#include <list>
#include <chrono>
#include <ctime>

class Implementer : public IImplementer
{
	enum ImplementState{
		RegularCmd,
		BlockCmd,
	};
	ImplementState state = RegularCmd;

	int siquensLength;
	std::list<Cmd> cmds;
	int depthBrace = 0;

public:
	Implementer(int _siquensLength = 3) : siquensLength(_siquensLength){}

	void implementLine(std::string line) {
		// ugly code :( but how do it better?
		bool openBrace = line == "{";
		bool closeBrace = line == "}";

		if (openBrace)
			++depthBrace;
		if (closeBrace)
			--depthBrace;

		if (state == RegularCmd && openBrace)
		{
			executeBuffer();
			state = BlockCmd;
		}
		if (state == BlockCmd && closeBrace && depthBrace == 0)
		{
			executeBuffer();
			state = RegularCmd;
		}

		if (!openBrace && !closeBrace)
			cmds.push_back(Cmd( line, std::chrono::seconds(std::time(NULL))));

		if (cmds.size() == siquensLength && state == RegularCmd)
			executeBuffer();
	};
	void end() {};

private:
	void executeBuffer()
	{
		if (cmds.size() == 0)
			return;

		std::for_each(executors.begin(), executors.end(), [=](std::unique_ptr<ICmdExecutor>& exec)
			{
				exec->addCmd(cmds);
			});
		cmds.clear();
	}
};