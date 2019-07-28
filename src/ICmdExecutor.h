#pragma once
#include <list>
#include <string>
#include "Cmd.h"

class ICmdExecutor
{
public:
	virtual void addCmd(const std::list<Cmd>& cmds) = 0;
};