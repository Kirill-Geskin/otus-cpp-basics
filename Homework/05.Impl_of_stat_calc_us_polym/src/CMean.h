#pragma once

#include "IStatistics.h"
#include <vector>

class CMean : public IStatistics {

public:
    CMean();
    ~CMean() override;
    void update(double next) override;
    double eval() const override;
    const char* name() const override;

private:
    double m_mean;
    std::vector<double> m_input_values;
};