#include "UkladRownanLiniowych.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"

using namespace std;

//Wektor błędu
Wektor UkladRownanLiniowych::w_bledu() const {
  Wektor wynik;

  wynik = get_A() * Oblicz() - get_b();

  return wynik;
}

//Dlugosc Wektora błędu
double UkladRownanLiniowych::dl_bledu() const {
  double wynik = w_bledu().dlugosc();

  return wynik;
}

Wektor UkladRownan::Oblicz() const {
  Wektor wynik;
  Macierz mpom = get_A(); 
  double wyznaczniki[ROZMIAR]; 
  double gl_wyznacznik = get_A().wyznacznik();
  Wektor wolne = get_b(); 
  
  if(abs(gl_wyznacznik) > dokladnosc) {
  
  for(int i = 0; i < ROZMIAR; i++) {
    mpom = mpom.zmien_kolumne(i, wolne);
    wyznaczniki[i] = mpom.wyznaczniki();
    wyznaczniki[i] = wyznaczniki[i] / gl_wyznacznik; 
    mpom = get_A();
    }
  }
  else
    {
      cerr << "Wyznacznik macierzy głównej wynosi 0. Uklad równań nie ma rozwiązania." << endl;
      exit(0);
    }
  return Wektor(wyznaczniki);
}


istream & operator >> (istream &strm, UkladRownanLiniowych & UklRown) {
  Wektor wpom;
  Macierz mpom;

  strm>> wpom;
  strm>> mpom;

  UklRown = UkladRownanLiniowych(wpom, mpom);
  return strm;
}

ostream & operator << (ostream &strm, const UkladRownanLiniowych & UklRown) {
  cout << "Macierz: " << endl << UklRown.get_A() << endl;
  cout << "Wektor wyrazow wolnych b: " << endl << UklRown.get_b() << endl;
  cout << "Rozwiązanie x=(x1, x2, x3): " << endl << UklRown.Oblicz() << endl;
  cout << "Wektor bledu: Ax-b = " << UklRown.w_bledu() << endl;
  cout << "Dlugosc wektora bledu: |Ax-b| = " << UklRown.dl_bledu() << endl;
  return strm;
}