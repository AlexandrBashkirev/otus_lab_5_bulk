#pragma once

#include "ICmdStreamWorker.h"
#include <algorithm>

class CmdStreamWorker : public ICmdStreamWorker
{
public:
	CmdStreamWorker(std::unique_ptr<IImplementer>&& _impl) : ICmdStreamWorker(std::move(_impl)) {}

	void run(std::istream& _stream)
	{
		while (_stream)
		{
			std::string line;
			if (std::getline(_stream, line))
				impl->implementLine(line);
			else
				impl->end();
		}
	}
};