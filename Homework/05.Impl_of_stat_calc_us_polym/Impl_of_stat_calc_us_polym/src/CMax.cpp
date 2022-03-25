#include "CMax.h"


CMax::CMax() : m_max{ std::numeric_limits<double>::min() } {}

CMax::~CMax() = default;

void CMax::update(double next) {
    if (next > m_max) {
        m_max = next;
    }
}

double CMax::eval() const {
    return m_max;
}

const char* CMax::name() const {
    return "max";
}