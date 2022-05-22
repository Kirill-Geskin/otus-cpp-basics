#include "CMin.h"


CMin::CMin() : m_min{ std::numeric_limits<double>::max() } {}

CMin::~CMin() = default;

void CMin::update(double next) {
    if (next < m_min) {
        m_min = next;
    }
}

double CMin::eval() const {
    return m_min;
}

const char* CMin::name() const {
    return "min";
}