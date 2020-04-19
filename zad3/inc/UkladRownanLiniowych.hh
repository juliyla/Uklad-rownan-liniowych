#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

using namespace std;

class UkladRownanLiniowych {
  Macierz A;
  Wektor b;

public:
  UkladRownanLiniowych(): A(), b() {};
  UkladRownanLiniowych(Macierz AA, Wektor bb) : A(AA), B(bb) {} ;   

  const Macierz & get_A() const;
  const Wektor & get_b() const;
  Macierz & get_A();
  Wektor & get_b();
 
  
  Wektor Oblicz() const;
  Wektor blad() const;
  double dl_bledu() const;
};


std::istream& operator >> (std::istream &strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << (std::ostream &strm,const UkladRownanLiniowych &UklRown);


#endif
