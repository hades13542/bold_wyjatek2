#include "myexcept.h"
#include "moje_obliczenia.h"

// kompletnie trywialny kod
void m::moje_obliczenia(int arg) {
  if ( arg > 0 && arg < 2 ) throw numerical_exception(" nieporzadany zakres argumentow 0 a mniejszy niz 2 ",__FILE__, __LINE__);
  if ( arg%2 == 0 ) throw calculation_exception(" argument nie moze byc podzielny przez dwa ",__FILE__, __LINE__);
  throw std::runtime_error(" jakis inny blad ");
}