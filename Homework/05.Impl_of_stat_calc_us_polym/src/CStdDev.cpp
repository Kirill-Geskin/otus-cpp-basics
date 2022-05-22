#include "CStdDev.h"
//The CStdDev class encapsulates calculation of standard deviation 

CStdDev::CStdDev() : m_std_dev{ 0.0 } {}

CStdDev::~CStdDev() = default;

void CStdDev::update(double next) {
    m_input_values.push_back(next);
    double sum_of_inputs = 0.0;
    for (double& input_value : m_input_values) {
        sum_of_inputs += input_value;
    }
    double mean_of_inputs = sum_of_inputs / static_cast<double>(m_input_values.size());

    double sum_of_squared_deviations = 0.0;
    for (double& input_value : m_input_values) {
        sum_of_squared_deviations += pow((input_value - mean_of_inputs), 2);
    }

    double variance = sum_of_squared_deviations / static_cast<double>(m_input_values.size());
    m_std_dev = sqrt(variance);
}

double CStdDev::eval() const {
    return m_std_dev;
}

const char* CStdDev::name() const {
    return "std_dev";
}