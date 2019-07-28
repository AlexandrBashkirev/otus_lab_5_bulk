#pragma once
#include "ICmdExecutor.h"
#include <list>
#include <string>
#include <memory>

class IImplementer
{
protected:
	std::list<std::unique_ptr<ICmdExecutor>> executors;
public:
	void addCmdExecutor(std::unique_ptr<ICmdExecutor>&& executor)
	{
		executors.push_back(std::move(executor));
	}

	virtual void implementLine(std::string line) = 0;
	virtual void end() = 0;
};