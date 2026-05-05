#pragma once
#include <string>

// ІНТЕРФЕЙС: всі методи — чисто віртуальні
class ICurve {
public:
  virtual bool belongs(double x, double y) const = 0;
  virtual void printEquation() const = 0;
  virtual std::string name() const = 0;
  virtual ~ICurve() = default;
};
