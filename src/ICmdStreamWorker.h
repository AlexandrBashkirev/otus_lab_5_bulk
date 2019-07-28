#pragma once
#include <iostream>
#include "IImplementer.h"

class ICmdStreamWorker
{
protected:
	std::unique_ptr<IImplementer> impl;

public:
	ICmdStreamWorker(std::unique_ptr<IImplementer>&& _impl) : impl(std::move(_impl)) {}

	virtual void run(std::istream& _stream) = 0;
};