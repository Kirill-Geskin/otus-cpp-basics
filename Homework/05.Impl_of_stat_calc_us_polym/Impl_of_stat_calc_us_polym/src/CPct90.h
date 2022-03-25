#pragma once

#include "IStatistics.h"

#include <vector>
#include <algorithm>
#include <cmath>

class CPct90 : public IStatistics {

public:
    CPct90();
    ~CPct90() override;
    void update(double next) override;
    double eval() const override;
    const char* name() const override;

private:
    double m_pct90;
    double const m_percentile = 90.0;
    std::vector<double> m_input_values;
};