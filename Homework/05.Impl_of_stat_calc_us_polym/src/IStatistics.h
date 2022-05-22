#pragma once

#include <iostream>
#include <limits>

class IStatistics {
public:
    virtual ~IStatistics() = default;

    virtual void update(double next) = 0;
    virtual double eval() const = 0;
    virtual const char* name() const = 0;
};