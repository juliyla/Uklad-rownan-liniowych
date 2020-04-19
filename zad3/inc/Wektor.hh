#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

class Wektor {
  double tab[ROZMIAR];
public:
  Wektor();
  Wektor(double tab[]);
 
  Wektor operator + (const Wektor &W2) const;
  Wektor operator - (const Wektor &W2) const;
  double operator * (const Wektor &W2) const;
  Wektor operator * (double l) const;
  Wektor operator / (double l) const;
  Wektor operator * (double l,const Wektor &W2);
    
  double dlugosc() const;

  bool operator == (const Wektor &W2) const;
  bool operator != (const Wektor &W2) const;
  
  const double & operator [] (int index) const;
  double & operator [] (int index);
    
};


std::istream & operator >> (std::istream &Strm, Wektor &W);

std::ostream & operator << (std::ostream &Strm, const Wektor &W);

#endif
