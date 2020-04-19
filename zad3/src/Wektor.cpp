#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>
#include <cmath>

/*Konstruktory*/

Wektor::Wektor()
{
  for (int i=0; i<ROZMIAR; i++){
  this->tab[i] = 0;}
}
Wektor::Wektor(double tab[])
{   
    for(int i=0; i<ROZMIAR; i++)
    {
        this->tab[i] = tab[i];
    }
}

/*Operacje matematyczne*/

Wektor Wektor::operator + (const Wektor &W2) const {
  Wektor W3;
  for (int i=0; i<ROZMIAR; i++)
    W3[i] = tab[i] + W2[i];
  return W3;
} 

Wektor Wektor::operator - (const Wektor &W2) const {
  Wektor Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i] - W2[i];
  return Wynik;
} 
    
double Wektor::operator * (const Wektor &W2) const {
  double Wynik = 0;
  for (int i=0; i<ROZMIAR; i++)
    Wynik += tab[i] * W2[i];
  return Wynik;
}

Wektor Wektor::operator * (double l2) const{
  Wektor Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i] * l2;
  return Wynik;
}

Wektor operator * (double l1,const Wektor &W2) {
  Wektor Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = l1 * W2[i];
  return Wynik;
} 

Wektor Wektor::operator / (double l2) const{
  Wektor Wynik;
  if(l2 == 0){
        std::cerr << "Nie wolno dzielic przez zero!" << std::endl;
        exit(1);
    }else 
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i] / l2;
  return Wynik;
}

double Wektor::dlugosc() const{
  double l = 0;
  for (int i=0; i<ROZMIAR; i++)
    l = l + (tab[i] * tab[i]);
  l = sqrt(l);
  return l;
}

/*Operatory porownania*/

bool Wektor::operator == (const Wektor &W2) const{
  
  for(int i = 0; i<ROZMIAR; i++){
    if(this->tab[i]!=W2[i]){
      return false;
    }
  }
  return true;
}

bool Wektor::operator != (const Wektor &W2) const{
 
  for(int i = 0; i<ROZMIAR; i++){
    if(this->tab[i]==W2[i]){
      return false;
    }
  }
  return true;
}

/*Analog set i get*/

const double & Wektor::operator[] (int index) const{
    if (index < 0 || index >= ROZMIAR){
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    return tab[index];
  }

double& Wektor::operator[] (int index){
    if (index < 0 || index >= ROZMIAR){
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    return tab[index];
  }

/*Operatory wczytywania i wyswietlania*/

std::ostream & operator << (std::ostream &strm, const Wektor &W) {
  for (int i=0; i<ROZMIAR; i++)
    strm << W[i] << "  ";
  return strm;
}

std::istream & operator >> (std::istream &strm, Wektor &W) {
  for (int i=0; i<ROZMIAR; i++)
    strm >> W[i];
  return strm;
}