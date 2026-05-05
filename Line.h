#pragma once
#include "ICurve.h"

// Пряма: y = a*x + b
class Line : public ICurve {
  double a_, b_;

public:
  Line(double a, double b);
  bool belongs(double x, double y) const override;
  void printEquation() const override;
  std::string name() const override;
};
