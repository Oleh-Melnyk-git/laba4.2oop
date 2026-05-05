#pragma once
#include "ICurve.h"

// Гіпербола: x²/a² – y²/b² = 1
class Hyperbola : public ICurve {
  double a_, b_;

public:
  Hyperbola(double a, double b);
  bool belongs(double x, double y) const override;
  void printEquation() const override;
  std::string name() const override;
};
