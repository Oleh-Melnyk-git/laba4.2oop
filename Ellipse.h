#pragma once
#include "ICurve.h"

// Еліпс: x²/a² + y²/b² = 1
class Ellipse : public ICurve {
  double a_, b_;

public:
  Ellipse(double a, double b);
  bool belongs(double x, double y) const override;
  void printEquation() const override;
  std::string name() const override;
};
