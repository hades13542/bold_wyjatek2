/*
 Celem zadania jest napisanie klasy wyjatkow ulozone w hierarchi takiej
 by ponizszy kod zadzialal poprawnie. W komentarzu nalezy
 uzasadnic dlaczego hierarchia musi byc taka a nie inna.
 np. z powodu kodu w linii gdzie ... wyjatek XXX musi dziedziczyc po AAA

 Dodatkowo nalezy napisac uchwyt obslugujacy 3 typy wyjatkow.
 A takze naglowek do pliku moje_obliczenia.C

 Kompilowac z opcja -Wall -g do pliku wyk. o nazwie "exc".
 Prosze nie zmieniac nazw plikow.

 << zawartosc pliku moje_obliczenia.C
---
#include "myexcept.h"
#include "moje_obliczenia.h"

// kompletnie trywialny kod
void m::moje_obliczenia(int arg) {
  if ( arg > 0 && arg < 2 ) throw numerical_exception(" nieporzadany zakres argumentow 0 a mniejszy niz 2 ",__FILE__, __LINE__);
  if ( arg%2 == 0 ) throw calculation_exception(" argument nie moze byc podzielny przez dwa ",__FILE__, __LINE__);
  throw std::runtime_error(" jakis inny blad ");
}
---



*/

#include <iostream>
#include "myexcept.h"
#include "myexcept.h"
#include "moje_obliczenia.h"


using namespace std;
int main(int argc, char** argv) {


  try {
    throw numerical_exception("double value overflow");
  } catch ( const std::runtime_error& err) {
    cout << "runtime_error: " << err.what() << endl;
  }


  try {
    throw calculation_exception("cos nie tak z obliczeniami");
  } catch ( const std::runtime_error& err) {
    cout << "runtime_error: " << err.what() << endl;
  }

  try {
    throw calculation_exception("znow cos nie tak z obliczeniami");
  } catch ( const numerical_exception& err) {
    cout << "numerical_exception: " << err.what() << endl;
  }

  // teraz kawalek  z jednym handlerem wyjatkow
  try {
    m::moje_obliczenia(1); // wyrzuca wyjatek typu numerical_exception
  } catch (...) {
    cout << "obsluga" << endl;
    myexcept::handler("oblicznia z zrg. 1");
  }

  try {
    m::moje_obliczenia(4); // wyrzuca wyjatek calculation_exception
  } catch (...) {
    cout << "obsluga" << endl;
    myexcept::handler("obliczenia z arg. 4");
  }

  try {
    m::moje_obliczenia(7); // wyrzuca wyjatek runtime_error
  } catch (...) {
    cout << "obsluga" << endl;
    myexcept::handler("obliczenia z arg. 7");
  }

}
/* wynik
runtime_error: double value overflow
runtime_error: cos nie tak z obliczeniami
numerical_exception: znow cos nie tak z obliczeniami
obsluga
plik: moje_obliczenia.C linia: 6 kontekst: (oblicznia z zrg. 1) numerical exception:  nieporzadany zakres argumentow 0 a mniejszy niz 2
obsluga
plik: moje_obliczenia.C linia: 7 kontekst: (obliczenia z arg. 4) calculation exception:  argument nie moze byc podzielny przez dwa
obsluga
kontekst: (obliczenia z arg. 7) runtime_error:  jakis inny blad

 */
