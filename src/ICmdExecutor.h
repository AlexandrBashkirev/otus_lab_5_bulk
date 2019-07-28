#pragma once
#include "ICmd.h"
#include <list>
#include <string>

class ICmdExecutor
{
public:
	virtual void addCmd(const std::list<std::string>& cmds) = 0;
};