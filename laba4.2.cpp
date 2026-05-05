
#include <cmath>
#include <iostream>
#include <string>
#include <typeinfo>

// ─────────────────────────────────────────────
// ІНТЕРФЕЙС (всі методи — чисто віртуальні)
// ─────────────────────────────────────────────
class ICurve {
public:
  // Чи належить точка (x, y) кривій?
  virtual bool belongs(double x, double y) const = 0;
  // Вивести рівняння кривої
  virtual void printEquation() const = 0;
  // Назва кривої (для зручного виводу)
  virtual std::string name() const = 0;
  // Віртуальний деструктор
  virtual ~ICurve() = default;
};

// ─────────────────────────────────────────────
// ПРЯМА:  y = a*x + b
// ─────────────────────────────────────────────
class Line : public ICurve {
  double a_, b_;

public:
  Line(double a, double b) : a_(a), b_(b) {}

  bool belongs(double x, double y) const override {
    return std::abs(y - (a_ * x + b_)) < 1e-9;
  }

  void printEquation() const override {
    std::cout << "y = " << a_ << "*x + " << b_;
  }

  std::string name() const override { return "Пряма (Line)"; }
};

// ─────────────────────────────────────────────
// ЕЛІПС:  x²/a² + y²/b² = 1
// ─────────────────────────────────────────────
class Ellipse : public ICurve {
  double a_, b_;

public:
  Ellipse(double a, double b) : a_(a), b_(b) {}

  bool belongs(double x, double y) const override {
    return std::abs((x * x) / (a_ * a_) + (y * y) / (b_ * b_) - 1.0) < 1e-9;
  }

  void printEquation() const override {
    std::cout << "x²/" << a_ * a_ << " + y²/" << b_ * b_ << " = 1";
  }

  std::string name() const override { return "Еліпс (Ellipse)"; }
};

// ─────────────────────────────────────────────
// ГІПЕРБОЛА:  x²/a² – y²/b² = 1
// ─────────────────────────────────────────────
class Hyperbola : public ICurve {
  double a_, b_;

public:
  Hyperbola(double a, double b) : a_(a), b_(b) {}

  bool belongs(double x, double y) const override {
    return std::abs((x * x) / (a_ * a_) - (y * y) / (b_ * b_) - 1.0) < 1e-9;
  }

  void printEquation() const override {
    std::cout << "x²/" << a_ * a_ << " – y²/" << b_ * b_ << " = 1";
  }

  std::string name() const override { return "Гіпербола (Hyperbola)"; }
};

// ─────────────────────────────────────────────
// ГОЛОВНА ФУНКЦІЯ
// ─────────────────────────────────────────────
int main() {
  std::cout << "=== Лабораторна робота 4.2. Інтерфейси. Варіант 15 ==="
            << std::endl;
  std::cout << std::endl;

  // Масив поліморфних об'єктів (вказівники на інтерфейс ICurve)
  ICurve *curves[3];
  curves[0] = new Line(2, 3);      // y = 2x + 3
  curves[1] = new Ellipse(3, 2);   // x²/9 + y²/4 = 1
  curves[2] = new Hyperbola(2, 3); // x²/4 – y²/9 = 1

  // Тестові точки
  struct Point {
    double x, y;
  };
  Point pts[] = {
      {0, 3},   // пряма: y=2*0+3=3  ✓
      {3, 0},   // еліпс: 9/9+0/4=1  ✓
      {2, 0},   // гіпербола: 4/4-0/9=1 ✓
      {1, 5},   // довільна
      {0, 2},   // еліпс: 0+4/4=1    ✓
      {-1, -3}, // теж пряма ✓ (y=2*(-1)+3=1? ні, -3; не належить)
  };
  int nPts = sizeof(pts) / sizeof(pts[0]);

  for (int i = 0; i < 3; i++) {
    // ── Виводимо справжній тип поліморфного об'єкта ──
    std::cout << "──────────────────────────────────────" << std::endl;
    std::cout << "Об'єкт #" << (i + 1) << std::endl;
    std::cout << "  Справжній тип (typeid): " << typeid(*curves[i]).name()
              << std::endl;
    std::cout << "  Назва класу            : " << curves[i]->name()
              << std::endl;
    std::cout << "  Рівняння               : ";
    curves[i]->printEquation();
    std::cout << std::endl;

    std::cout << "  Перевірка точок:" << std::endl;
    for (int j = 0; j < nPts; j++) {
      bool res = curves[i]->belongs(pts[j].x, pts[j].y);
      std::cout << "    (" << pts[j].x << ", " << pts[j].y << ") -> "
                << (res ? "належить ✓" : "не належить") << std::endl;
    }
    std::cout << std::endl;
  }

  // Звільнення пам'яті
  for (int i = 0; i < 3; i++)
    delete curves[i];

  return 0;
}
