#include "Ellipse.h"
#include "Hyperbola.h"
#include "ICurve.h"
#include "Line.h"
#include <iostream>
#include <typeinfo>

int main() {
  std::cout << "=== Лабораторна робота 4.2. Інтерфейси. Варіант 15 ==="
            << std::endl
            << std::endl;

  // Масив вказівників на інтерфейс (поліморфні об'єкти)
  ICurve *curves[3];
  curves[0] = new Line(2, 3);      // y = 2x + 3
  curves[1] = new Ellipse(3, 2);   // x²/9 + y²/4 = 1
  curves[2] = new Hyperbola(2, 3); // x²/4 – y²/9 = 1

  // Тестові точки
  struct Point {
    double x, y;
  };
  Point pts[] = {
      {0, 3}, {3, 0}, {2, 0}, {1, 5}, {0, 2}, {-1, -3},
  };
  int nPts = sizeof(pts) / sizeof(pts[0]);

  for (int i = 0; i < 3; i++) {
    std::cout << "──────────────────────────────────────" << std::endl;
    std::cout << "Об'єкт #" << (i + 1) << std::endl;
    // Виводимо справжній тип поліморфного об'єкта
    std::cout << "  Справжній тип (typeid): " << typeid(*curves[i]).name()
              << std::endl;
    std::cout << "  Назва класу            : " << curves[i]->name()
              << std::endl;
    std::cout << "  Рівняння               : ";
    curves[i]->printEquation();
    std::cout << std::endl << "  Перевірка точок:" << std::endl;

    for (int j = 0; j < nPts; j++) {
      bool res = curves[i]->belongs(pts[j].x, pts[j].y);
      std::cout << "    (" << pts[j].x << ", " << pts[j].y << ") -> "
                << (res ? "належить ✓" : "не належить") << std::endl;
    }
    std::cout << std::endl;
  }

  for (int i = 0; i < 3; i++)
    delete curves[i];
  return 0;
}
