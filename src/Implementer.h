#pragma once
#include "IImplementer.h"
#include <list>

class Implementer : public IImplementer
{
	int sicuensLength;
	std::list<std::string> cmds;

public:
	Implementer(int _sicuensLength = 3) : sicuensLength(_sicuensLength){}

	void implementLine(std::string line) {
		cmds.push_back(line);

		if (cmds.size() == sicuensLength)
		{
			std::for_each(executors.begin(), executors.end(), [=](std::unique_ptr<ICmdExecutor>& exec)
				{ 
					exec->addCmd(cmds);
				});
			cmds.clear();
		}
	};
	void end() {};
};