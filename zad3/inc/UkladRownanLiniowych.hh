#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>

class UkladRownanLiniowych {
  Macierz A;
  Wektor b;
  public:
      
};


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << (std::ostream &Strm,const UkladRownanLiniowych &UklRown);


#endif
