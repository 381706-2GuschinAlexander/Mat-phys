#include "lib.h"
#include <iostream>
#include <cmath>







int main()
{
  SimpleBasis basis({ 0.0, 0.5, 1 });

  //for (int j = 0; j < 4; ++j) {
  //  for (int i = 0; i <= 10; ++i)
  //    std::cout << basis.get_deriv(j, 0.1 * i) << " ";
  //  std::cout << "\n";

  //  for (int i = 0; i <= 10; ++i)
  //    std::cout << basis.get_value(j, 0.1 * i) << " ";
  //  std::cout << "\n";
  //  std::cout << "\n";
  //  std::cout << "\n";
  //}
  auto p = [](double x) {return 2 + 0.5 * sin(2 * x); };
  double q = 1.5;
  auto f = [](double x) { return x * (1 - x); };

  PQCalc calc(basis, p, f, q);
  
  PQCalc cl(basis, [](double x) {return sin(x); }, [](double x) { return x*(1 - x); },  1.0);

  calc.find_sol();

  //std::cout << integrate([](double x) {return sin(x); }, 0, 1, 1e-2) << "\n";
  return 0;
}
