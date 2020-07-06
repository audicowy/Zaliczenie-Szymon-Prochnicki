#include <omp.h>
#include <iostream>
using namespace std;

int main () {

  int c = 100;
  int v = 0;

// Ponizszy blok rownolegly dziala zle, bo wspoldzieli
// zmienne c oraz v. Prowadzi to do data race.
// Gdyby nie konflikt, to na 4. watkach petla while
// wykonalaby sie 4 razy po 100 iteracji, czyli 
// poprawna koncowa wartosc zmiennej v bylaby 400.
// Uzupelnij ponizszy blok o odpowiednia klauzule firstprivate
// oraz klauzule lastprivate tak, zeby zmienne wspoldzielone
// byly przekazane jako prywatne, a koncowa wartosc v
// byla tez poprawnie odzyskana.

  #pragma omp parallel num_threads(4) 
  {
      #pragma omp parallel firstprivate(c)
      while (c--) {
        ++v;
      }
  }  

  cout << "Koncowa wartosc v = " << v << endl;

}