// matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CmdExecutor.h"
#include "CmdStreamWorker.h"
#include "Implementer.h"
#include "CmdLogger.h"

int main()
{
	auto impl = std::make_unique<Implementer>(2);
	impl->addCmdExecutor(std::move(std::make_unique<CmdExecutor>()));
	impl->addCmdExecutor(std::move(std::make_unique<CmdLogger>("log.log")));

	CmdStreamWorker worker(std::move(impl));

	worker.run(std::cin);

}