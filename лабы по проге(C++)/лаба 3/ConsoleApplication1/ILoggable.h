#pragma once

#include <string>
__interface ILoggable
{
	virtual void logToScreen() = 0;
	virtual void logToFile(const std::string& filename) = 0;
};