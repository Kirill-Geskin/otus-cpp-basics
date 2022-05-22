#pragma once

#include "IStatistics.h"

#include <vector>
#include <cmath>

class CStdDev : public IStatistics {

public:
    CStdDev();
    ~CStdDev() override;
    void update(double next) override;
    double eval() const override;
    const char* name() const override;

private:
    double m_std_dev;
    std::vector<double> m_input_values;
};