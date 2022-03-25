#include "CPct90.h"

 //The CPct90 class encapsulates calculation of Percentile 90 value from given sequence
 
CPct90::CPct90() : m_pct90{ 0.0 } {}

CPct90::~CPct90() = default;

void CPct90::update(double next) {
   
    m_input_values.push_back(next);
    std::sort(m_input_values.begin(), m_input_values.end());

    double rank = (m_percentile / 100.0) * (static_cast<double>(m_input_values.size()) - 1) + 1;

    double fractional_part, integer_part;
    fractional_part = std::modf(rank, &integer_part);

    auto ip = static_cast<unsigned long>(integer_part);
    if (m_input_values.size() >= 2) {
        m_pct90 = m_input_values.at(ip - 1) + fractional_part * (m_input_values.at(ip) - m_input_values.at(ip - 1));
    }
}

double CPct90::eval() const {
    return m_pct90;
}

const char* CPct90::name() const {
    return "pct90";
}