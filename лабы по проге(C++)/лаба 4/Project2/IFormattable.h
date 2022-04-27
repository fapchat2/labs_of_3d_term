#pragma once
#include <string>
__interface IFormattable
{
    virtual std::string format() const = 0;
};