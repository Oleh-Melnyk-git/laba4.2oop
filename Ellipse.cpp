#include "Ellipse.h"
#include <cmath>
#include <iostream>

Ellipse::Ellipse(double a, double b) : a_(a), b_(b) {}

bool Ellipse::belongs(double x, double y) const {
  return std::abs((x * x) / (a_ * a_) + (y * y) / (b_ * b_) - 1.0) < 1e-9;
}

void Ellipse::printEquation() const {
  std::cout << "x²/" << a_ * a_ << " + y²/" << b_ * b_ << " = 1";
}

std::string Ellipse::name() const { return "Еліпс (Ellipse)"; }
