#pragma once

#include "IStatistics.h"

class CMax : public IStatistics {

public:
    CMax();
    ~CMax() override;
    void update(double next) override;
    double eval() const override;
    const char* name() const override;

private:
    double m_max;
};