#include <iostream>
#include "moost/threads.hpp"

void f0(int i, int j)
{
  std::cout << i << " " << j << "\n";
}

void p()
{
  std::cout << "Pas d'arguments LOL !\n";
}

int  main(void)
{
  moost::Thread t0(f0, 2, 4);
  moost::Thread t1(p);

  t0.join();
  t1.join();
  std::cout << "OK" << std::endl;
  return (0);
}
