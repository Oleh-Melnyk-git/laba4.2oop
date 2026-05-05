#include "Line.h"
#include <cmath>
#include <iostream>

Line::Line(double a, double b) : a_(a), b_(b) {}

bool Line::belongs(double x, double y) const {
  return std::abs(y - (a_ * x + b_)) < 1e-9;
}

void Line::printEquation() const { std::cout << "y = " << a_ << "*x + " << b_; }

std::string Line::name() const { return "Пряма (Line)"; }
