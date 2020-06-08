#include <iostream>
#include <chrono>
#include <cmath>
#include <ctime>
#include <ratio>
#include <thread>
using namespace std;

void function()
{   // funkcja wykonuje jakies bezsensowne, ale obciazajace obliczenia
    double number { 0. };
    #pragma omp parallel for reduction(+:number) num_threads(4)
    for( long long i = 0; i != 200000000; ++i )
    {
       number += sin( static_cast<double>(i) / (i+1) );
    }
}

int main()
{
    using namespace std::chrono;
    //auto t1 = clock();
    // odczytaj czas poczatkowy
    high_resolution_clock::time_point  t1 = high_resolution_clock::now();
    function();
    high_resolution_clock::time_point  t2 = high_resolution_clock::now();
    //auto t2 = clock();
    // odczytaj czas koncowy
    duration<double> time_span = duration_cast<duration<double>>(t2-t1);
    //auto duration = 0; // w miejsce 0 wpisz odpowiednie wyrazenie z duration przeliczajacym na minuty
    //auto duration = ((double(t2 - t1 )) /CLOCKS_PER_SEC)/100;

    std::cout << "Czas wykonania: = " << time_span.count() << "  sekund" <<endl;
    return 0;
}

