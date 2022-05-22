#include "CMean.h"

CMean::CMean() : m_mean{ 0.0 } {}

CMean::~CMean() = default;

void CMean::update(double next) {
    m_input_values.push_back(next);
    double sum_of_inputs = 0.0;
    for (double& input_value : m_input_values) {
        sum_of_inputs += input_value;
    }
    m_mean = sum_of_inputs / static_cast<double>(m_input_values.size());
}

double CMean::eval() const {
    return m_mean;
}

const char* CMean::name() const {
    return "mean";
}