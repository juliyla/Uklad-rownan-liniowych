#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

class Macierz {
   Wektor tab[ROZMIAR];
  public:  
  Macierz();
  Macierz(Wektor A, Wektor B, Wektor C);

  double wyznacznik() const;
  Macierz zmien_kolumne(int kolum, Wektor wek);
  const Macierz & transponuj() const;
  /*const Macierz & odwroc() const;*/

  Macierz operator + (const Macierz & M) const;
  Macierz operator - (const Macierz & M) const;
  Macierz operator * (const Macierz & M) const;
  Wektor operator * (const Wektor & W) const;
  Macierz operator * (double l); const;

  bool operator == (const Macierz & M) const;
  bool operator != (const Macierz & M) const;

  const Wektor & operator[] (int index) const;
  Wektor & operator[] (int index);
  
};


std::istream& operator >> (std::istream &Strm, Macierz &M);

std::ostream& operator << (std::ostream &Strm, const Macierz &M);


#endif
