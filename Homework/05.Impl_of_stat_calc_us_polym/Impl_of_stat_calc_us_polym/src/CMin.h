#pragma once

#include "IStatistics.h"

class CMin : public IStatistics {

public:
    CMin();
    ~CMin() override;
    void update(double next) override;
    double eval() const override;
    const char* name() const override;

private:
    double m_min;
};